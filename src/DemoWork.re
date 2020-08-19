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
    |> then_(response => response |> resolve)
    |> catch(err => {
         let error = makeErrorJson(err->Obj.magic);
         Js.log2("ERROR", error);

         Js.Promise.resolve(error);
       })
  );

// let data =
//   Query.query->handleQuery
//   |> Js.Promise.then_(res =>
//        {
//          //  Js.log(Query.serialize(res));
//          Js.log2("data",res);
//        }
//        |> Js.Promise.resolve
//      );

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
let handleQueryt = (user: Query.t) => {
  Js.log("-------------");
  Js.log("handleQueryt:(user: Query.t):BEGIN");
  Js.log("-------------");
  Js.log2("user: Query.t", user);
  let () =
    switch (user) {
    | {user: Some(user)} => Js.log2("uzer()", user)
    | _ => Js.log("None")
    };
  let uzer =
    switch (user) {
    | {user: Some(user)} => Some(user)
    | {user: None} => None
    };
  Js.log2("uzer", Some(uzer));
  let () =
    switch (user) {
    | {user: Some(user)} => Js.log2("userId()", user.id)
    | _ => Js.log("None")
    };
  let userId =
    switch (user) {
    | {user: Some(user)} => Some(user.id)
    | {user: None} => None
    };

  Js.log2("userId", userId);
  let userName =
    switch (user) {
    | {user: Some(user)} => Some(user.username)
    | {user: None} => None
    };

  Js.log2("userName", userName);
  let nulled = () =>
    Js.Nullable.toOption(Js.Nullable.return(user))
    |> Belt.Option.getWithDefault(None);

  Js.log2("Nulled", nulled());
  // let id =
  //   switch (user) {
  //   | {user: Some(user)} => Some(user)
  //   | _ => None
  //   };
  // Js.log2("id", id);
  Js.log("-------------");
  Js.log("(user: Query.t):END");
  Js.log("-------------");
};
let handleUser = (user: Query.t) => {
  let () =
    switch (user) {
    | {user: Some(user)} => Js.log2("uzer()", user)
    | _ => Js.log("None")
    };
  let uzer =
    switch (user) {
    | {user: Some(user)} => Some(user)
    | {user: None} => None
    };
  Js.log2("uzer", Some(uzer));
  let () =
    switch (user) {
    | {user: Some(user)} => Js.log2("userId()", user.id)
    | _ => Js.log("None")
    };
  let userId =
    switch (user) {
    | {user: Some(user)} => Some(user.id)
    | {user: None} => None
    };

  Js.log2("userId", userId);
  let userName =
    switch (user) {
    | {user: Some(user)} => Some(user.username)
    | {user: None} => None
    };

  Js.log2("userName", userName);
  let user =
    switch (user) {
    | {user: Some(user)} =>
      let user: Query.t_user = {
        id: user.id,
        username: user.username,
        email: user.email,
        phone: user.phone,
        website: user.website,
      };
      Js.log2("user.id in switch", user.id);
      Some(user);

    | {user: None} => None
    };

  Js.log2("user", user);
  let nulled = () =>
    Js.Nullable.toOption(Js.Nullable.return(user))
    |> Belt.Option.getWithDefault(None);

  Js.log2("Nulled", nulled());
  // let id =
  //   switch (user) {
  //   | {user: Some(user)} => Some(user)
  //   | _ => None
  //   };
  // Js.log2("id", id);
  Js.log("-------------");
  Js.log("(user: Query.t):END");
  Js.log("-------------");
};

let parseQueryRaw: Query.Raw.t => Query.t = parsed => Query.parse(parsed);

let parseJsonData = (data: Js.Json.t) =>
  data |> Query.unsafe_fromJson |> Query.parse |> handleQueryt;

// let queryParse = data => data |> Query.unsafe_fromJson;
// let parseJsonData = (data: Js.Json.t) =>
//   data |> Query.parse |> handleData2;
// let objMagic = (response): Js.Json.t => Obj.magic(response)##data;
// let queryT = response =>
// objMagic(response) |> Query.unsafe_fromJson |> Query.parse |> handleQueryt;
let test =
  Query.query->handleQuery
  |> Js.Promise.then_(response => {
       /* Need to return a Promise to fullfil expected function signature in then_(...) */
       //  Js.log2("test:data", Obj.magic(response)##data);
       //  Js.log2("test:objMagic", objMagic(response));
       //  Js.log2(
       //    "test:objMagic",
       //    objMagic(response) |> Query.unsafe_fromJson |> Query.parse,
       //  );
       //  Js.log2("test:queryT", queryT(response));
       //  Js.log2("test:queryParse", queryParse(data));
       //  Js.log2("test:serialize", Query.serialize(data));
       //  Js.log2("test:unsafe_fromJson", Query.unsafe_fromJson(response));
       Obj.magic(response)##data
       |> Query.unsafe_fromJson
       |> Query.parse
       |> handleUser
       |> Js.Promise.resolve
     });
// let x:Js.Json.t=> Query.t= response => Obj.magic(response)##data->Query.unsafe_fromJson(data) .->Query.parse;
let test2 = response =>
  response
  |> Js.Promise.then_(data
       /* Need to return a Promise to fullfil expected function signature in then_(...) */
       => Js.Promise.resolve(parseJsonData(data)));
// let test3 = response =>
//   response
//   |> Js.Promise.then_(response => {
//        /* Need to return a Promise to fullfil expected function signature in then_(...) */
//        Js.log("test3");
//        //  let data2 = Obj.magic(response)##data->parseJsonData;
//        //  Js.log2("test:data2", data2);
//        let data = Obj.magic(response)##data;
//        Js.log2("test:data2", data);
//        Js.Promise.resolve(parseJsonData(data));
//      }) /* Query.query->handleQuery->tes*/;

// let test4 =
//   Query.query->handleQuery
//   |> (response => {
//     Js.log2("response",response->Js.Promise.resolve(_))
//     let d = Obj.magic(response)##data;
//     d->Js.log2("D",_)->ignore;
//     Js.Promise.resolve(Obj.magic(response)##data)});
