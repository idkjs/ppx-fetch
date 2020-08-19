  let rest = "https://jsonplaceholder.typicode.com/";
  let gql = "https://json-placeholder-graphql.herokuapp.com/graphql";

include UnFetch;
let makeErrorJson = err => {
  let error = Js.String.make(err);
  let json = Js.Dict.empty();
  Js.Dict.set(json, "error", Js.Json.string(error));
  Js.Json.object_(json);
};
  let handleQuery = q =>
  Js.Promise.(
    
      fetchWithInit(
        gql,
        RequestInit.make(
          ~method_=Post,
          ~headers=HeadersInit.make({"Content-Type": "application/graphql"}),
          ~body=BodyInit.make(q),
          (),
        ),
      )
    
    |> then_(Response.json)
    |> then_(response => response |> resolve)
    |> catch(err => {
         let error = makeErrorJson(err->Obj.magic);
         Js.log2("ERROR", error);

         Js.Promise.resolve(error);
       })
  );