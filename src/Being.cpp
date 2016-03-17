#include "Being.h"

Being::Being(){
//----------------------------------------------------


    ofDirectory dirRight;
    ofDirectory dirLeft;
//LOAD FRONT IMAGE
    beingFront.load("front.png");
//LOAD TOMB IMAGE
    tomb.load("tomb.png");

//LOAD RIGHT IMAGES
    int nFiles = dirRight.listDir("movingRight");
    if(nFiles) {

        for(int i=0; i<dirRight.size(); i++) {

            // add the image to the vector
            string filePath = dirRight.getPath(i);
            imagesRight.push_back(ofImage());
            imagesRight.back().load(filePath);

        }

    }
    else ofLog(OF_LOG_WARNING) << "Could not find folder";

//LOAD LEFT IMAGES
    nFiles = dirLeft.listDir("movingLeft");
    if(nFiles) {

        for(int i=0; i<dirLeft.size(); i++) {

            // add the image to the vector
            string filePath = dirLeft.getPath(i);
            imagesLeft.push_back(ofImage());
            imagesLeft.back().load(filePath);

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
//----------------------------------------------------
//Inicial size setupus
    maxHeight = 31;
    maxWidth = 18;
    speed = 1;
    direction = 0;
    g=-1;
    c.r=ofRandom(255);
    c.g=ofRandom(255);
    c.b=ofRandom(255);



}
//--------------------------------------------------------------

//void Being::setup(float height,float width,float floor,int yearInMs,vector<Being> &_beings){
void Being::setup(float height,float width,float floor,int yearInMs){
    //beings = _beings;
    this-> yearInMs = yearInMs;
    alive = true;
    this->height = height;
    this->width = width;
    this->floor = floor;
    x=ofRandom(this->width-myWidth);
    y=floor-myHeight;
    //y=ofRandom(this->height);
    birthTime =  ofGetElapsedTimeMillis();
    deathAge = ofRandom(60,100);
    deathTime = birthTime +(deathAge*yearInMs);
    pregnant=false;
    childReady = false;
    //yLimit = floor-myHeight;
    yearsDead =0;
    fertile = true;




}



//--------------------------------------------------------------
void Being::update(){
    y = floor-myHeight;
    myHeight=maxHeight;
    myWidth = maxWidth;
    //y=yLimit;
    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - birthTime;
    age = timeElapsed/yearInMs;
    /*
    if(y<yLimit){
        direction = 0;
    }
    */




    //cout<< pregnant;

    /*
    if(age<12){
        myHeight=maxHeight;
        myWidth = maxWidth;


    }else if(age>=12 && age<19){
        myHeight=maxHeight;
        myWidth = maxWidth;

    }else if (age >=19){
        myHeight=maxHeight;
        myWidth = maxWidth;

    }

    */



    if(age >=deathAge){
        alive = false;

    }

    if(alive){

        if(ofRandom(10000)>9997 && !isPregnant()&& age>12){
            impregnate();

        }
        if(isPregnant()){
            giveBirth();

        }


        //if(y=yLimit){
        changeDirection();
        //}
        move();
    }else{
        yearsDead = age-deathAge;

    }




}

//--------------------------------------------------------------
void Being::draw(){

    uint64_t frameIndex = 0;
    if(bFrameIndependent) {
        // calculate the frame index based on the app time
        // and the desired sequence fps. then mod to wrap
        frameIndex = (int)(ofGetElapsedTimef() * sequenceFPS) % imagesRight.size();
    }
    else {
        // set the frame index based on the app frame
        // count. then mod to wrap.
        frameIndex = ofGetFrameNum() % imagesRight.size();
    }

//DRAW WHEN ALIVE
    if(alive){
    ofSetColor(c);
    //ofRect(x,y,myWidth,myHeight);

    ofSetColor(255);
    imagesRight[frameIndex].resize(myWidth,myHeight);


    if(direction == -1){
        ofSetColor(255);
        if(age<5){
           ofSetColor(0,0,255);
        }
        if(!fertile){
           ofSetColor(0,255,0);
        }

        if(isPregnant()){
            ofSetColor(255,0,0);
        }
        imagesLeft[frameIndex].resize(myWidth,myHeight);
        imagesLeft[frameIndex].draw(x, y);
    }else if(direction == 1){
        ofSetColor(255);
        if(age<5){
           ofSetColor(0,0,255);
        }
        if(!fertile){
           ofSetColor(0,255,0);
        }
        if(isPregnant()){
           ofSetColor(255,0,0);
        }
        imagesRight[frameIndex].resize(myWidth,myHeight);
        imagesRight[frameIndex].draw(x, y);
    }else if (direction==0){
        ofSetColor(255);
        if(age<5){
           ofSetColor(0,0,255);
        }
        if(!fertile){
           ofSetColor(0,255,0);
        }
        if(isPregnant()){
            ofSetColor(255,0,0);
        }
        beingFront.resize(myWidth,myHeight);
        beingFront.draw(x, y);
        //ofRect(x,y,myWidth,myHeight);


    }


    //DRAW WHEN DEAD
    }else{
        ofSetColor(255);
        myHeight = 26;
        tomb.draw(x,y+2);


    }




}
void Being::move(){
    y = floor-myHeight;
    /*
    y = y-g;
    if(y>floor-myHeight){
      y=yLimit;
    }
    */

//Will move acording to direction and speed
    setX(getX()+(getDirection()*getSpeed()));

//If goes beyong screen, change direction

    if(getX()<0){
        setX(0);
        setDirection(getDirection()*-1);

    }
    if(getX()>width-myWidth){
        setX(width-myWidth);
        setDirection(getDirection()*-1);

    }


    /*
    if(getX()<0-width){
        setX(width);
    }
    if(getX()>width){
        setX(0-myWidth);
    }
    */






}

void Being::changeDirection(){

    if(ofRandom(1000)>990){
    float random = ofRandom(1000);
        if(random<333){
            setDirection(1);

        }else if(random<666){
            setDirection(-1);
        }else if(random>=666){
            setDirection(0);

        }

    }

}



//Gets and Sets

void Being::setX(float x){
    this->x = x;



}
void Being::setY(float y){
    this->y = y;


}

float Being::getX(){
    return x;


}
float Being::getY(){
    return y;


}
float Being::getMyHeight(){
    return myHeight;


}
float Being::getMyWidth(){
    return myWidth;


}
int Being::getYearsDead(){
    return yearsDead;


}

void Being::setDirection(int d){
    direction=d;


}

int Being::getDirection(){
    return direction;


}

void Being::setSpeed(float s){
    speed=s;


}

float Being::getSpeed(){
    return speed;


}
void Being::setYearInMs(int i){
   yearInMs = i;


}

bool Being::encountered(Being b){
    /*
    float otherX = b.getX();
    float otherY = b.getY();
    float otherHeight = b.getMyHeight();
    float otherWidth = b.getMyWidth();

    if((x>otherX && x<(otherX+otherWidth))||(x+myWidth>otherX && x+myWidth<(otherX+otherWidth))){

       return true;
    }
    */
    return false;
}

bool Being::isPregnant(){

    return pregnant;
}
void Being::impregnate(){
    if(fertile){
    pregAge=age;
    pregnant = true;
    }
}

void Being::giveBirth(){
    if(pregAge<age){


        childReady = true;

      pregnant=false;
    }

}

bool Being::isChildReady(){

    return childReady;
}

bool Being::isAlive(){

    return alive;
}
void Being::removeChild(){
    childReady = false;
}

void Being::makeFertile(){
    fertile = true;
}
void Being::makeInfertile(){
    fertile = false;
}


void Being::killSlowly(int alives){
    //alive=false;
    deathAge = age+ofRandom((int)alives/100);
    //deathAge = age;

}







