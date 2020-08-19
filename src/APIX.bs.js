// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Fetch = require("bs-fetch/src/Fetch.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var UnFetch$PpxFetch = require("./UnFetch.bs.js");

var gql = "https://json-placeholder-graphql.herokuapp.com/graphql";

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
                }).then(function (response) {
                return Promise.resolve(response);
              }).catch(function (err) {
              var error = makeErrorJson(err);
              console.log("ERROR", error);
              return Promise.resolve(error);
            });
}

var rest = "https://jsonplaceholder.typicode.com/";

var $$AbortController = UnFetch$PpxFetch.$$AbortController;

var HeadersInit = UnFetch$PpxFetch.HeadersInit;

var $$Headers = UnFetch$PpxFetch.$$Headers;

var BodyInit = UnFetch$PpxFetch.BodyInit;

var Body = UnFetch$PpxFetch.Body;

var RequestInit = UnFetch$PpxFetch.RequestInit;

var $$Request = UnFetch$PpxFetch.$$Request;

var $$Response = UnFetch$PpxFetch.$$Response;

var $$FormData = UnFetch$PpxFetch.$$FormData;

exports.rest = rest;
exports.gql = gql;
exports.$$AbortController = $$AbortController;
exports.HeadersInit = HeadersInit;
exports.$$Headers = $$Headers;
exports.BodyInit = BodyInit;
exports.Body = Body;
exports.RequestInit = RequestInit;
exports.$$Request = $$Request;
exports.$$Response = $$Response;
exports.$$FormData = $$FormData;
exports.makeErrorJson = makeErrorJson;
exports.handleQuery = handleQuery;
/* UnFetch-PpxFetch Not a pure module */
