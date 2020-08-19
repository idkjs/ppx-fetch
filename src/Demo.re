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
  Js.log2("uzer", uzer);

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

  Js.log(user);
  Js.log("-------------");
  Js.log("(user: Query.t):END");
  Js.log("-------------");
};

let data =
  Query.query->API.handleQuery
  |> Js.Promise.then_(response => {
       Obj.magic(response)##data
       |> Query.unsafe_fromJson
       |> Query.parse
       |> handleUser
       |> Js.Promise.resolve
     });

let toTypedData = user => {
  let userx: Query.t_user = user;
  let value =
    switch (userx) {
    | {id: Some(id)} => Some(id)
    | _ => None
    };
  // let user: Query.t_user = >Obj.magic(user)->Query.parse;
  value->Js.log;
  user.id->Js.log;
  user->Js.log;
};

let test =
  Query.query->API.handleQuery
  |> Js.Promise.then_(response => {
       Obj.magic(response)##data
       |> toTypedData
       |> Js.log
       |> Js.Promise.resolve
     });
