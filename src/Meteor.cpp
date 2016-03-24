#include "Meteor.h"

Meteor::Meteor(){

    ofDirectory meteorFire;
    meteor.load("meteor.png");

//LOAD RIGHT IMAGES
    int nFiles = meteorFire.listDir("meteorFire");
    if(nFiles) {

        for(int i=0; i<meteorFire.size(); i++) {

            // add the image to the vector
            string filePath = meteorFire.getPath(i);
            imagesOnFire.push_back(ofImage());
            imagesOnFire.back().load(filePath);

        }

    }
    else ofLog(OF_LOG_WARNING) << "Could not find folder";

    // this toggle will tell the sequence
    // be be indepent of the app fps
    bFrameIndependent = true;

    // this will set the speed to play
    // the animation back we set the
    // default to 24fps
    sequenceFPS = 10;
    appFPS = 60;
    ofSetFrameRate(appFPS);


}

void Meteor::setup(float height,float width,float floor,int yearInMs,float gravity){

    onFire.load("cloud1.png");
    this-> yearInMs = yearInMs;
    this->height = height;
    this->width = width;
    this->floor = floor;
    this-> gravity = gravity;

    myHeight = imagesOnFire[0].getHeight();
    myWidth = imagesOnFire[0].getWidth();

    x=ofRandom(this->width-myWidth);
    y=ofRandom(0);
    alive = true;
    deathAge;
    yearsDead=0;
    birthTime =  ofGetElapsedTimeMillis();




}

void Meteor::draw(){

    uint64_t frameIndex = 0;
    if(bFrameIndependent) {
        // calculate the frame index based on the app time
        // and the desired sequence fps. then mod to wrap
        frameIndex = (int)(ofGetElapsedTimef() * sequenceFPS) % imagesOnFire.size();
    }
    else {
        // set the frame index based on the app frame
        // count. then mod to wrap.
        frameIndex = ofGetFrameNum() % imagesOnFire.size();
    }
    if(alive){
        ofSetColor(255);

    imagesOnFire[frameIndex].draw(x, y);
    }else{
        ofSetColor(255);

        //y = floor;
        meteor.draw(x,y);


    }


}

void Meteor::update(){
    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - birthTime;
    age = timeElapsed/yearInMs;


    yearsDead = age-deathAge;

    move();


}
void Meteor::move(){
    if(alive){
    setY(getY()+gravity);
    }

    float deep=ofRandom(20,40);
    if(y+myHeight-30>floor){
        alive=false;
        deathAge=age;

        myHeight = meteor.getHeight();
        myWidth = meteor.getWidth();

        y=floor-myHeight+30;
        //floor= y+myHeight-(myHeight/10);
        //y=y+myHeight-(myHeight/10);
    }


}


//Gets and Sets

void Meteor::setX(float x){
    this->x = x;


}

float Meteor::getX(){
    return x;


}
float Meteor::getY(){
    return y;


}
void Meteor::setY(float y){
    this->y = y;


}

bool Meteor::isAlive(){
    return alive;


}
int Meteor::getYearsDead(){
    return yearsDead;


}
float Meteor::getWidth(){
    return myWidth;


}





