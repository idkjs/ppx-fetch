// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var API$PpxFetch = require("./API.bs.js");
var Query$PpxFetch = require("./Query.bs.js");
var DocsQuery$PpxFetch = require("./DocsQuery.bs.js");

function handleData(response) {
  var data = response.data;
  var parsedData = DocsQuery$PpxFetch.parse(data);
  var match = parsedData.user;
  var username = match !== undefined ? match.username : "Anonymous";
  var match$1 = parsedData.user;
  var id = match$1 !== undefined ? match$1.id : undefined;
  var match$2 = parsedData.user;
  var email = match$2 !== undefined ? match$2.email : undefined;
  var match$3 = parsedData.user;
  var phone = match$3 !== undefined ? match$3.phone : undefined;
  var match$4 = parsedData.user;
  var website = match$4 !== undefined ? match$4.website : undefined;
  var user = {
    id: id,
    username: username,
    email: email,
    phone: phone,
    website: website
  };
  console.log("user's id is: ", id);
  console.log("user is: ", user);
  return user;
}

var test = API$PpxFetch.handleQuery(Query$PpxFetch.query).then(function (response) {
      return Promise.resolve(handleData(response));
    });

exports.handleData = handleData;
exports.test = test;
/* test Not a pure module */