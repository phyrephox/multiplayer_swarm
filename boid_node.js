var vector = require('./vector');
function boid(p,v){
 this.pos=p;
 this.vel=v;
 this.rules=[];
 this.separation=function(boidset, c){
  var ans=new vector(0,0);
  var i;
  for(i=0; i<boidset.length;i++){
   var current=boidset[i];
   if (current != this){
    if ((new vector).vectorDist(current.pos, this.pos)<5){
     ans.sub((new vector).vectorSub(current.pos, this.pos));
    }
   }
  }
  this.rules.push(ans);
 }
 
 this.cohesion=function(boidset, c){
  var ans = new vector(0,0);
  var count = 0;
  var i;
  for(i=0;i<boidset.length;i++){
   var current=boidset[i];
   if (current != this){
    if ((new vector).vectorDist(current.pos,this.pos)<80){
     count++;
     ans.add(current.pos);
    }
   }
  }
  if (count > 0){
   ans.div(count);
   ans.sub(this.pos);
  }
  this.rules.push(ans.mult(c));
 }
 
 this.adhesion=function(boidset, c){
  var ans = new vector(0,0);
  var count = 0;
  var i;
  for (i=0;i<boidset.length;i++){
   var current = boidset[i];
   if (current != this){
    if ((new vector).vectorDist(current.pos,this.pos)<50){
     count++;
     ans.add(current.vel);
    }
   }
  }
  if (count>0){
   ans.div(count);
   ans.sub(this.vel);
  }
  this.rules.push(ans.mult(c));
 }
 
 this.boundary=function(c){
  var ans = new vector(0,0);
  if (this.pos.x > 500){
   ans.add(new vector(50-this.pos.x/10,0));
  }
  if (this.pos.x < 0){
   ans.add(new vector(-this.pos.x/10,0));
  }
  if (this.pos.y > 500){
   ans.add(new vector(0,50-this.pos.y/10));
  }
  if (this.pos.y < 0){
   ans.add(new vector(0,-this.pos.y/10));
  }
  this.rules.push(ans.mult(c));
 }
 
 this.interact=function(boidset){
  this.rules = [];
  this.separation(boidset,1.2);
  this.cohesion(boidset,0.01);
  this.adhesion(boidset,0.3);
  this.boundary(3.6);
  //console.log(this.rules);
  var i;
  for (i=0;i<this.rules.length;i++){
   this.vel.add(this.rules[i]);
  }
  this.vel.limit(4,30);
  this.pos.add(this.vel);
 }
 this.draw=function(ctx){
  ctx.moveTo(this.pos.x,this.pos.y);
  ctx.lineTo(this.pos.x-this.vel.x,this.pos.y-this.vel.y);
  ctx.stroke();
 }
 return this;
}

module.exports=boid;
