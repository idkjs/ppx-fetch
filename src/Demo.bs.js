// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Fetch = require("bs-fetch/src/Fetch.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");

require('isomorphic-fetch')
;

var UnFetch = Fetch;

var gql = "https://json-placeholder-graphql.herokuapp.com/graphql";

var API = {
  rest: "https://jsonplaceholder.typicode.com/",
  gql: gql
};

var Raw = {};

var query = "query   {\nuser(id: 1)  {\nid  \nusername  \nemail  \nphone  \nwebsite  \n}\n\n}\n";

function parse(value) {
  var value$1 = value.user;
  var tmp;
  if (value$1 == null) {
    tmp = undefined;
  } else {
    var value$2 = value$1.id;
    var value$3 = value$1.username;
    var value$4 = value$1.email;
    var value$5 = value$1.phone;
    var value$6 = value$1.website;
    tmp = {
      id: !(value$2 == null) ? value$2 : undefined,
      username: !(value$3 == null) ? value$3 : undefined,
      email: !(value$4 == null) ? value$4 : undefined,
      phone: !(value$5 == null) ? value$5 : undefined,
      website: !(value$6 == null) ? value$6 : undefined
    };
  }
  return {
          user: tmp
        };
}

function serialize(value) {
  var value$1 = value.user;
  var user;
  if (value$1 !== undefined) {
    var value$2 = value$1.website;
    var website = value$2 !== undefined ? value$2 : null;
    var value$3 = value$1.phone;
    var phone = value$3 !== undefined ? value$3 : null;
    var value$4 = value$1.email;
    var email = value$4 !== undefined ? value$4 : null;
    var value$5 = value$1.username;
    var username = value$5 !== undefined ? value$5 : null;
    var value$6 = value$1.id;
    var id = value$6 !== undefined ? value$6 : null;
    user = {
      id: id,
      username: username,
      email: email,
      phone: phone,
      website: website
    };
  } else {
    user = null;
  }
  return {
          user: user
        };
}

function serializeVariables(param) {
  
}

function makeVariables(param) {
  
}

function makeDefaultVariables(param) {
  
}

var Query = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  serializeVariables: serializeVariables,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables
};

function makeErrorJson(err) {
  var error = String(err);
  var json = {};
  json["error"] = error;
  return json;
}

function handleQuery(q) {
  return fetch(gql, Fetch.RequestInit.make(/* Post */2, {
                          "Content-Type": "application/graphql"
                        }, Caml_option.some(q), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(undefined)).then(function (prim) {
                  return prim.json();
                }).then(function (json) {
                return Promise.resolve(json);
              }).catch(function (err) {
              return Promise.resolve(makeErrorJson(err));
            });
}

var data = handleQuery(query).then(function (res) {
      return Promise.resolve((console.log(res), undefined));
    });

function handleData(data) {
  console.log("handleData");
  console.log("handleData", data);
  console.log(data.user);
  console.log(Caml_option.nullable_to_opt(data.user));
  var user = data.user;
  var id = !(user == null) ? user.id : undefined;
  console.log("id", id);
  
}

function handleData2(user) {
  var user$1 = user.user;
  var user$2 = (user$1 !== undefined ? console.log(user$1.id) : console.log("None"), undefined);
  console.log("handleuser");
  console.log("handleuser", user$2);
  console.log(user$2);
  console.log((user$2 == null) ? undefined : Caml_option.some(user$2));
  
}

function parseJsonData(data) {
  return handleData2(parse(data));
}

handleQuery(query).then(function (data) {
      return Promise.resolve(handleData2(parse(data)));
    });

exports.UnFetch = UnFetch;
exports.API = API;
exports.Query = Query;
exports.makeErrorJson = makeErrorJson;
exports.handleQuery = handleQuery;
exports.data = data;
exports.handleData = handleData;
exports.handleData2 = handleData2;
exports.parseJsonData = parseJsonData;
/*  Not a pure module */