// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var API$PpxFetch = require("./API.bs.js");
var Query$PpxFetch = require("./Query.bs.js");

function handleUser(user) {
  var user$1 = user.user;
  if (user$1 !== undefined) {
    console.log("uzer()", user$1);
  } else {
    console.log("None");
  }
  var user$2 = user.user;
  var uzer = user$2 !== undefined ? user$2 : undefined;
  console.log("uzer", uzer);
  var user$3 = user.user;
  var userId = user$3 !== undefined ? Caml_option.some(user$3.id) : undefined;
  console.log("userId", userId);
  var user$4 = user.user;
  var userName = user$4 !== undefined ? Caml_option.some(user$4.username) : undefined;
  console.log("userName", userName);
  var user$5 = user.user;
  var user$6;
  if (user$5 !== undefined) {
    var user_id = user$5.id;
    var user_username = user$5.username;
    var user_email = user$5.email;
    var user_phone = user$5.phone;
    var user_website = user$5.website;
    var user$7 = {
      id: user_id,
      username: user_username,
      email: user_email,
      phone: user_phone,
      website: user_website
    };
    console.log("user.id in switch", user_id);
    user$6 = user$7;
  } else {
    user$6 = undefined;
  }
  console.log("user", user$6);
  console.log("Nulled", Belt_Option.getWithDefault(undefined, (user$6 == null) ? undefined : Caml_option.some(user$6)));
  console.log("-------------");
  console.log("(user: Query.t):END");
  console.log("-------------");
  
}

var data = API$PpxFetch.handleQuery(Query$PpxFetch.query).then(function (response) {
      return Promise.resolve(handleUser(Query$PpxFetch.parse(response.data)));
    });

exports.handleUser = handleUser;
exports.data = data;
/* data Not a pure module */
