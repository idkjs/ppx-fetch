// module Query = DocsQuery;

// The shape of the data that we get back from the server has the type UserQuery.Raw.t. This represents the data exactly like the response type. The type that is being generated by graphql-ppx is:

// module Raw = {
//   type t = {
//     user: t_user
//   } and t_user = {
//     id: string,
//     name: Js.Nullable.t(string)
//   }
// }

let handleData = (response: Js.Json.t) => {
  //  Js.log2("response", response);
  //  Response is:
  // data: {
  //     user: {
  //     id: 1,
  //     username: 'Bret',
  //     email: 'Sincere@april.biz',
  //     phone: '1-770-736-8031 x56442',
  //     website: 'hildegard.org'
  //     }
  // }

  // get data object off of response
  let data = Obj.magic(response)##data;
  //  Convert Js.Json.t to DocsQuery.Raw.t which is of type
  // `type t = {user: Js.Nullable.t(t_user)}`
  let typedResponse: DocsQuery.Raw.t = DocsQuery.unsafe_fromJson(data);
  //   convert DocsQuery.Raw.t to DocsQuery.t
  let parsedData: DocsQuery.t = DocsQuery.parse(typedResponse);
  let username =
    switch (parsedData) {
    | {user: Some({username})} => username
    /* the user's name is null */
    | _ => Some("Anonymous")
    };
  let id =
    switch (parsedData) {
    | {user: Some({id})} => id
    | _ => None
    };
  let email =
    switch (parsedData) {
    | {user: Some({email})} => email
    | _ => None
    };
  let phone =
    switch (parsedData) {
    | {user: Some({phone})} => phone
    | _ => None
    };
  let website =
    switch (parsedData) {
    | {user: Some({website})} => website
    | _ => None
    };
  let user: Query.t_user = {username, id, email, phone, website};

  Js.log2("user's id is: ", user.id);
  Js.log2("user is: ", user);
  user;
};

let test =
  Query.query->API.handleQuery
  |> Js.Promise.then_(response => {
       response |> handleData |> Js.Promise.resolve
     });