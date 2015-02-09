function boid(p,v){
 this.pos=p;
 this.vel=v;
 this.goal=new vector(0,0);
 this.rules=[];
 this.time;
 this.angle=0;
 
 this.separation=function(boidset, c){
  var ans=new vector(0,0);
  var i;
  for(var name in boidset){//i=0; i<boidset.length;i++){
   //var current=boidset[i];
   if (boidset.hasOwnProperty(name)){
    var current = boidset[name];
    if (current != this){
     if (vectorDist(current.pos, this.pos)<5){
      ans.sub(vectorSub(current.pos, this.pos));
     }
    }
   }
  }
  this.rules.push(ans);
 }
 
 this.cohesion=function(boidset, c){
  var ans = new vector(0,0);
  var count = 0;
  var i;
  for(var name in boidset){//i=0; i<boidset.length;i++){
   //var current=boidset[i];
   if (boidset.hasOwnProperty(name)){
    var current = boidset[name];
    if (current != this){
     if (vectorDist(current.pos,this.pos)<80){
      count++;
      ans.add(current.pos);
     }
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
  for(var name in boidset){//i=0; i<boidset.length;i++){
   //var current=boidset[i];
   if (boidset.hasOwnProperty(name)){
    var current = boidset[name];
    if (current != this){
     if (vectorDist(current.pos,this.pos)<50){
      count++;
      ans.add(current.vel);
     }
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
  if (this.pos.x > 1700){
   ans.add(new vector(170-this.pos.x/10,0));
  }
  if (this.pos.x < 100){
   ans.add(new vector(10-this.pos.x/10,0));
  }
  if (this.pos.y > 800){
   ans.add(new vector(0,80-this.pos.y/10));
  }
  if (this.pos.y < 100){
   ans.add(new vector(0,10-this.pos.y/10));
  }
  this.rules.push(ans.mult(c));
 }
 this.toGoal=function(c){
  var ans = this.goal.get();
  if ((this.goal.x==0 && this.goal.y==0)){//||(new Date().getTime()-time)>140){
   return;
  } else {
   console.log('towards goal');
   ans.sub(this.pos.get());
   this.rules.push(ans.mult(c));
  }
 }
 
 this.interact=function(boidset,delta){
  this.rules = [];
  this.separation(boidset,1.2);
  this.cohesion(boidset,0.01);
  this.adhesion(boidset,0.3);
  this.boundary(3.6);
  this.toGoal(0.1);
  var i;
  for (i=0;i<this.rules.length;i++){
   this.vel.add(this.rules[i]);
  }
  this.vel.limit(0,20);
  var velDelt=this.vel.get();
  //console.log(this.vel.x+" "+delta);
  //console.log(velDelt.x);
  velDelt.mult(delta);
  //console.log(velDelt.x);
  velDelt.div(30);
  //console.log(velDelt.x);
  this.pos.add(velDelt);
 }
 
 this.draw=function(ctx){
  ctx.moveTo(this.pos.x,this.pos.y);
  ctx.lineTo(this.pos.x-this.vel.x,this.pos.y-this.vel.y);
  ctx.stroke();
 }
 
 this.set=function(p,v){
  this.pos=p;
  this.vel=p;
 }
 this.set=function(b){
  this.pos=new vector(b.xpos,b.ypos);
  this.vel=new vector(b.xvel,b.yvel);
  this.angle=b.angle;
 }
 this.setGoal=function(x,y){
  this.goal.set(x,y);
  this.time=new Date().getTime();
 }
}
