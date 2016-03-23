#include "RainDrop.h"

RainDrop::RainDrop(){

}

void RainDrop::setup(float  x, float y,float gravity, float wind,float floor){


    this->floor = floor;
    this->wind = wind;
    this-> gravity = gravity;
    this-> x =x;
    this-> y =y;
    alive=true;




}

void RainDrop::update(){
    move();

}

void RainDrop::draw(){
    if(alive){
        ofSetColor(0,0,250);
        ofRect(x,y,1,1);
    }

}

void RainDrop::move(){
  setY(getY()+gravity);
  setX(getX()+wind);

  if(y>=floor){
      alive=false;
  }

}



//Gets and Sets

void RainDrop::setX(float x){
    this->x = x;


}

float RainDrop::getX(){
    return x;


}
float RainDrop::getY(){
    return y;


}
void RainDrop::setY(float y){
    this->y = y;


}

bool RainDrop::isAlive(){
    return alive;


}

