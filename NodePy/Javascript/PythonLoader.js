'use strict';

var defs  = require ('./defs.js');

var spawn = require('child_process').spawn;

class PythonLoader {
	constructor(){
		this.dataCallback = null;
	}

	start (data){
		var py = spawn ('python', defs.PYTHON_FILES, {shell: true});

		py.stdout.on('data', function(data){
			PythonReader.addData (data);
		});
		py.stdout.on ('end', (d)=>{PythonReader.sendData()});

		py.stdin.write (data || defs.START_DATA);
		py.stdin.end ();

	}
}

class PythonReader {
	static setCallback (cb) {
		this.readCallback = cb;
		this.data         = "";
	}

	static sendData () {
		if (!this.readCallback) return;
		this.readCallback (this.data);

		this.data = "";
	}

	static addData (data) {
		this.data += data;
	}
}

module.exports.Loader = PythonLoader;
module.exports.Reader = PythonReader;