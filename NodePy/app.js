
var spawn = require('child_process').spawn,
    py    = spawn('python', ['test.py']),
    data = "start";
    dataString = '';

py.stdout.on('data', function(data){
  dataString += data.toString();
});
py.stdout.on('end', function(){
  console.log('s=',dataString);
});

py.stdin.write ('start');
py.stdin.end ();