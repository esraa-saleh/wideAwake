'use strict';

class DateMagic {
	static convertTime (timeString) {
		var params  = timeString.match(/[^:]+/g);
		var hours   = params [0];
		var minutes = params [1];
		var seconds = 0;

		var currentDate = new Date ();
		currentDate.setHours (hours);
		currentDate.setMinutes (minutes);
		currentDate.setSeconds (seconds);

		return currentDate;
	}

	static msToNext (date) {
		var now = new Date ();
		var ms  = date - now;

		if (ms > 0) return ms;

		this.increment (date);
		return date - now;
	}

	static increment (date) {
		date.setDate (date.getDate () + 1);
	}
}

module.exports = DateMagic;