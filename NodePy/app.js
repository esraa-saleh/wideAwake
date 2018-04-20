const JS = "./Javascript";
const PUBLIC = "./public";

var Control = require (JS + "/Control.js");
var control = new Control ();

var express = require ("express");
var app     = express ();

var bodyParser = require ("body-parser");

app.get ("/", function (req,res){
  res.sendStatus(200);
});

app.use ("/alarm/set", bodyParser.urlencoded({extended: true}));
app.post ("/alarm/set", function (req, res){
  var time = req.body.time;
  if (!time)
    res.sendStatus (400);
  else {
    control.setAlarm (time);
    res.sendStatus (200);
  }
})

app.use (express.static ("./public"));

app.listen (2404, function(){ console.log("The fox is waiting for you"); });
