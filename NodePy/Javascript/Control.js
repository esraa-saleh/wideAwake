'use strict';

var Python       = require ("./PythonLoader.js");
var Timeout      = require ("./UserTimeout.js");

var PythonLoader = Python.Loader;
var PythonReader = Python.Reader;

class Control {
	constructor () {
		this.python  = new PythonLoader ();
		this.timeout = new Timeout ().setCallback (()=>{
			this.start ();
		});

		this.reader  = PythonReader;
		this.reader.setCallback ((data) => { this.received(data); })
	}

	start () {
		this.python.start ();
	}

	received (data) {
		console.log (data);
	}

	setAlarm (time) {
		this.timeout.startCountdown (time);
	}
};

module.exports = Control;