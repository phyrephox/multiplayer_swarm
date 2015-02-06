var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var path = require('path');
var UUID = require('node-uuid');
var boid = require('./boid');
var vector = require('./vector');
var addon = require('./build/Release/addon');



var obj = new addon.Boids();
var objList = {};
var time = new Date().getTime();
function gameLoop(){
 var now = new Date().getTime();
 if (time + 33 < now){
  var delta = now-time;
  objList = obj.getNextFrame(delta);
  time=now;
  //console.log(delta);
 }
 if(now-time<16){
  setTimeout(gameLoop);
 } else {
  setImmediate(gameLoop);
 }
}
setImmediate(gameLoop);

var index=0;
var sendSize=25;

app.get('/boid.js', function(req,res){
 res.sendFile(__dirname+'/boid.js');
});
app.get('/vector.js', function(req,res){
 res.sendFile(__dirname+'/vector.js');
});
app.get('/', function(req,res){
 res.sendFile(__dirname+'/index.html');
});

io.on('connection', function(socket){
 socket.userid = UUID();
 socket.emit('onconnected', {id: socket.userid});
 console.log('a user connected');
 socket.on('disconnect', function(){
    console.log('user disconnected');
 });
 socket.on('total', function(msg){
  socket.emit('total', objList);
 });
 socket.on('click', function(msg){
  console.log('click');
  io.emit('click',msg);
 });
 socket.on('key', function(msg){
  io.emit('key',msg);
 });
 socket.on('frame', function(msg){
  //gameLoop();
  var data = {};
  for (var i=0;i<sendSize;i++){
   data["Boid"+(index+i)]=objList["Boid"+(index+i)];
   //console.log("Boid"+(index+i));
  }
  //console.log(data);
  index+=sendSize;
  index%=800;
  socket.emit('data', data);
 });
 
 /*function sendLoop(){
  io.emit('data',objList);
 }
  
 setInterval(sendLoop,66)*/
  
});

http.listen(3000, function(){
 console.log('listening on 3000');
});
