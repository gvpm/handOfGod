///////////////////////////////////////////////////////
///CLASS - Cloud
///
///
///////////////////////////////////////////////////////
#include "Cloud.h"

Cloud::Cloud(){

    cloud.load("cloud1.png");

}

///////////////////////////////////////////////////////
///SETUP
///////////////////////////////////////////////////////

void Cloud::setup(float height,float width,float floor,int yearInMs,float wind,float gravity){
    //loads cloud image
    cloud.load("cloud1.png");
    //setup of initial values
    this-> yearInMs = yearInMs;
    this->height = height;
    this->width = width;
    this->floor = floor;
    this->wind = wind;
    this-> gravity = gravity;
    //gets its size from the image loaded
    myHeight = cloud.getHeight();
    myWidth = cloud.getWidth();
    //sets up a random position in the sky
    x=ofRandom(this->width-myWidth);
    y=ofRandom(this->height/2);
    //state of rain
    raining = false;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void Cloud::update(){
    //if its raining, it creates raindrops and adds to the raindrops vector
    //raindrops behave independtly
    if(raining){
        for(int i = 0; i<5;i++){
            RainDrop rd;
            rd.setup(ofRandom(x,x+myWidth),y+myHeight/2,gravity,wind,floor);
            rainDrops.push_back(rd);


        }


    }
    //update the raindrops
    updateRainDrops();
    //moves itself
    move();

}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void Cloud::draw(){

    //draws the reindrops
    drawRainDrops();
    ofSetColor(255);
    //gets a bit darker if ots raining
    if(raining){
        ofSetColor(200);
    }
    //draws itself
    cloud.draw(x,y);
    //loops on the raindrops vector and remove the ones that already hit the floor
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
//moves the cloud
void Cloud::move(){
    //moves according to the wind
    setX(getX()+wind);
    //once they get to the end they will come from the beggining of the screen with another y position
    if(x>width){
        setX(ofRandom(0-(myWidth*2),0-myWidth));
        y=ofRandom(this->height/2);

    }

}


bool Cloud::isRaining(){
    return raining;

}
//updates rainign status
void Cloud::rain(){
    raining = true;


}
//updates rainign status
void Cloud::stopRain(){
    raining = false;


}
//loops on all the raindrops drawing them
void Cloud::drawRainDrops(){
    for(int i = 0;i<rainDrops.size() ;i++){

        rainDrops[i].draw();
    }

}
//loops on all the raindrops updating them
void Cloud::updateRainDrops(){
    for(int i = 0;i<rainDrops.size() ;i++){

        rainDrops[i].update();
    }

}



