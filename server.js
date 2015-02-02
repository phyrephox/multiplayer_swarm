var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var UUID = require('node-uuid');
var boid = require('./boid');
var vector = require('./vector');
var addon = require('./build/Release/addon');


/*var boids=[];
for (var i=0;i<200;i++){
 boids.push(new boid(new vector(Math.random()*50+250,Math.random()*50+250),
                     new vector(Math.random()*5-2,Math.random()*5-2)));
}*/
var obj = new addon.Boids();
var objList = [];
var time = new Date().getTime();
function gameLoop(){
 objList = obj.getNextFrame();
 //console.log(objList);
 var newTime = new Date().getTime();
 //console.log('gameLoop '+(newTime-time));
 time=newTime;
 
 //setImmediate(gameLoop);
}

//setImmediate(gameLoop);
setInterval(gameLoop,10);

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
  socket.on('click', function(msg){
   console.log('click');
   io.emit('click',msg);
  });
  socket.on('key', function(msg){
   io.emit('key',msg);
  });
  
  function sendLoop(){
   /*var data=[];
   for (var i=0;i<boids.length;i++){
    data[i]={pos:boids[i].pos,vel:boids[i].vel};
   }*/
   io.emit('data',objList);
   //console.log(objList);
  }
  
  setInterval(sendLoop,10)
  
});

http.listen(3000, function(){
 console.log('listening on 3000');
});
