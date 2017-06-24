'use strict';

var DateMagic = require ("./DateMagic.js");

class UserTimeout {
	constructor(){
		this.timeout = undefined;
		this.cb      = undefined;
	}

	stopTimeout () {
		if (this.timeout === undefined) return false;
		clearTimeout (this.timeout);
	}

	startCountdown (time) {
		this.stopTimeout ();
		this.timeout = setTimeout (() => {
			this.callback ();
		}, this.getTimeTo (time))
	}

	getTimeTo (timeStr) {
		var date = DateMagic.convertTime (timeStr);
		var time = DateMagic.msToNext (date);

		console.log ("WILL START IN ", time);
		return time;
	}

	callback () {
		if (!this.cb) return false;
		return this.cb ();
	}

	setCallback (cb) {
		this.cb = cb;
		return this;
	}
}

module.exports = UserTimeout;