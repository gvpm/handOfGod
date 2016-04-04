///////////////////////////////////////////////////////
///CLASS - RainDrop
///
///
///////////////////////////////////////////////////////
#include "RainDrop.h"

RainDrop::RainDrop(){

}

///////////////////////////////////////////////////////
///SETUP
///////////////////////////////////////////////////////

void RainDrop::setup(float  x, float y,float gravity, float wind,float floor){

    //to know when to kill itself
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
    //draws itself if its alive, its only a really small rectangle
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
//falls according to the gravity and moveson the x cordinate according to the wind
void RainDrop::move(){
  setY(getY()+gravity);
  setX(getX()+wind);
    //kills itself if it hits the floor



  if(y>=floor){
      alive=false;
  }

}

