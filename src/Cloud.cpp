#include "Cloud.h"

Cloud::Cloud(){

    cloud.load("cloud1.png");

}

///////////////////////////////////////////////////////
///SETUP
///////////////////////////////////////////////////////

void Cloud::setup(float height,float width,float floor,int yearInMs,float wind,float gravity){

    cloud.load("cloud1.png");
    this-> yearInMs = yearInMs;
    this->height = height;
    this->width = width;
    this->floor = floor;
    this->wind = wind;
    this-> gravity = gravity;

    myHeight = cloud.getHeight();
    myWidth = cloud.getWidth();

    x=ofRandom(this->width-myWidth);
    y=ofRandom(this->height/2);

    raining = false;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void Cloud::update(){
    if(raining){
        for(int i = 0; i<5;i++){
            RainDrop rd;
            rd.setup(ofRandom(x,x+myWidth),y+myHeight/2,gravity,wind,floor);
            rainDrops.push_back(rd);


        }


    }
    updateRainDrops();
    move();

}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void Cloud::draw(){


    drawRainDrops();
    ofSetColor(255);
    if(raining){
        ofSetColor(200);
    }
    cloud.draw(x,y);
    int j =0;
    while ( j < rainDrops.size() ) {
        if ( !rainDrops[j].isAlive()) {
            rainDrops.erase( rainDrops.begin() + j );
        } else{
            ++j;
        }
    }


}

///////////////////////////////////////////////////////
///GETS AND SETS
///////////////////////////////////////////////////////

float Cloud::getX(){
    return x;

}
float Cloud::getY(){
    return y;

}

void Cloud::setX(float x){
    this->x = x;

}


void Cloud::setY(float y){
    this->y = y;

}

void Cloud::setWind(float wind){
    this->wind = wind;

}

///////////////////////////////////////////////////////
///OTHERS
///////////////////////////////////////////////////////

void Cloud::move(){
    setX(getX()+wind);

    if(x>width){
        setX(ofRandom(0-(myWidth*2),0-myWidth));
        y=ofRandom(this->height/2);

    }

}


bool Cloud::isRaining(){
    return raining;

}

void Cloud::rain(){
    raining = true;


}
void Cloud::stopRain(){
    raining = false;


}

void Cloud::drawRainDrops(){
    for(int i = 0;i<rainDrops.size() ;i++){

        rainDrops[i].draw();
    }

}
void Cloud::updateRainDrops(){
    for(int i = 0;i<rainDrops.size() ;i++){

        rainDrops[i].update();
    }

}



