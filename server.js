var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var UUID = require('node-uuid');

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
});

http.listen(3000, function(){
 console.log('listening on 3000');
});
