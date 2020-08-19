module UnFetch = {
  %raw
  {|require('isomorphic-fetch')|};
  include Fetch;
};
module API = {
  let rest = "https://jsonplaceholder.typicode.com/";
  let gql = "https://json-placeholder-graphql.herokuapp.com/graphql";
};

module Query = {
  [%graphql
    {|
   {
    user(id: 1) {
    id
    username
    email
    phone
    website
  }
  }
|}
  ];
};
let makeErrorJson = err => {
  let error = Js.String.make(err);
  let json = Js.Dict.empty();
  Js.Dict.set(json, "error", Js.Json.string(error));
  Js.Json.object_(json);
};

let handleQuery = q =>
  Js.Promise.(
    UnFetch.(
      fetchWithInit(
        API.gql,
        RequestInit.make(
          ~method_=Post,
          ~headers=HeadersInit.make({"Content-Type": "application/graphql"}),
          ~body=BodyInit.make(q),
          (),
        ),
      )
    )
    |> then_(UnFetch.Response.json)
    |> then_(json => json |> resolve)
    |> catch(err => {
         let error = makeErrorJson(err->Obj.magic);

         Js.Promise.resolve(error);
       })
  );

let data =
  Query.query->handleQuery
  |> Js.Promise.then_(res =>
       {
         //  Js.log(Query.serialize(res));
         Js.log(res);
       }
       |> Js.Promise.resolve
     );

let handleData = (data: Query.Raw.t) => {
  Js.log("handleData");
  Js.log2("handleData", data);
  Js.log(data.user);
  Js.log(Js.Nullable.toOption(Js.Nullable.return(data.user)));
  let id =
    switch (Js.Nullable.toOption(data.user)) {
    | Some(user) =>
      switch (user.id) {
      | id => Js.Nullable.return(id)
      }
    | None => Js.Nullable.undefined
    };
  Js.log2("id", id);
};
let handleData2 = (user: Query.t) => {
  let user =
    switch (user) {
    | {user: Some(user)} => Js.log(user.id)
    | _ => Js.log("None")
    };
  // Js.log2("user", user);
  Js.log("handleuser");
  Js.log2("handleuser", user);
  Js.log(user);
  Js.log(Js.Nullable.toOption(Js.Nullable.return(user)));
  // let id =
  //   switch (user) {
  //   | {user: Some(user)} => Some(user)
  //   | _ => None
  //   };
  // Js.log2("id", id);
};

let parseJsonData = (data: Js.Json.t) =>
  data |> Query.unsafe_fromJson |> Query.parse |> handleData2;
// let parseJsonData = (data: Js.Json.t) =>
//   data |> Query.parse |> handleData2;

Query.query->handleQuery
|> Js.Promise.then_(data
     /* Need to return a Promise to fullfil expected function signature in then_(...) */
     => Js.Promise.resolve(parseJsonData(data)));
