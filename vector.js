function vector(x,y){
 this.x=x;
 this.y=y;
 this.set=function(x,y){
  this.x=x;
  this.y=y;
 }
 this.get=function(){
  return new vector(x,y);
 }
 this.mag=function(){
  return Math.sqrt(x*x+y*y);
 }
 this.angle=function(){
  return Math.atan2(y,x);
 }
 this.add=function(other){
  this.x+=other.x;
  this.y+=other.y;
  return this;
 }
 this.sub=function(other){
  this.x-=other.x;
  this.y-=other.y;
  return this;
 }
 this.mult=function(n){
  this.x*=n;
  this.y*=n;
  return this;
 }
 this.div=function(n){
  this.x/=n;
  this.y/=n;
 }
 this.dist=function(other){
  var dx=this.x-other.x;
  var dy=this.y-other.y;
  return Math.sqrt(dx*dx+dy*dy);
 }
 this.norm=function(){
  var m=thisi.mag();
  if(m!=0&&m!=1){
   this.div(m);
  }
  return this;
 }
 this.limit=function(min, max){
  if (this.mag()>max){
   this.norm();
   this.mult(max);
  } else if(this.mag<min){
   this.norm();
   this.mult(min);
  }
  
 }
}
function vectorAdd(v1,v2){
 return new vector(v1.x+v2.x,v1.y+v2.y);
}
function vectorSub(v1,v2){
 return new vector(v1.x-v2.x,v1.y-v2.y);
}
function vectorDist(v1,v2){
 var dx=v1.x-v2.x;
 var dy=v1.y-v2.y;
 return Math.sqrt(dx*dx+dy*dy);
}

