function Submit () {
  var timeVal = $("#timeInput").val ();
  $.post ("/alarm/set", {
    time: timeVal
  }, function(data){
    console.log(data);
  })
}
