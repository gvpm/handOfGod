#include "RainDrop.h"

RainDrop::RainDrop(){

}

///////////////////////////////////////////////////////
///SETUP
///////////////////////////////////////////////////////

void RainDrop::setup(float  x, float y,float gravity, float wind,float floor){


    this->floor = floor;
    this->wind = wind;
    this-> gravity = gravity;
    this-> x =x;
    this-> y =y;
    alive=true;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void RainDrop::update(){
    move();

}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void RainDrop::draw(){
    if(alive){
        ofSetColor(0,0,250);
        ofRect(x,y,1,1);
    }

}



///////////////////////////////////////////////////////
///GETS AND SETS
///////////////////////////////////////////////////////

float RainDrop::getX(){
    return x;


}
float RainDrop::getY(){
    return y;


}

void RainDrop::setX(float x){
    this->x = x;

}

void RainDrop::setY(float y){
    this->y = y;


}

///////////////////////////////////////////////////////
///OTHER
///////////////////////////////////////////////////////


bool RainDrop::isAlive(){
    return alive;


}

void RainDrop::move(){
  setY(getY()+gravity);
  setX(getX()+wind);

  if(y>=floor){
      alive=false;
  }

}

