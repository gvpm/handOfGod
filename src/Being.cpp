#include "Being.h"

Being::Being(){
//----------------------------------------------------


    ofDirectory dirRight;
    ofDirectory dirLeft;

    ofDirectory dirRightChild;
    ofDirectory dirLeftChild;

//LOAD FRONT IMAGE
    beingFront.load("front.png");
//LOAD TOMB IMAGE
    tomb.load("tomb.png");

    //LOAD FRONT IMAGE Child
        beingFrontChild.load("frontChild.png");

        beingBackChild.load("backChild.png");

        beingBack.load("back.png");



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





    //LOAD RIGHT IMAGES Child
        nFiles = dirRightChild.listDir("movingRightChild");
        if(nFiles) {

            for(int i=0; i<dirRightChild.size(); i++) {

                // add the image to the vector
                string filePath = dirRightChild.getPath(i);
                imagesRightChild.push_back(ofImage());
                imagesRightChild.back().load(filePath);

            }

        }
        else ofLog(OF_LOG_WARNING) << "Could not find folder";

    //LOAD LEFT IMAGES Child
        nFiles = dirLeftChild.listDir("movingLeftChild");
        if(nFiles) {

            for(int i=0; i<dirLeftChild.size(); i++) {

                // add the image to the vector
                string filePath = dirLeftChild.getPath(i);
                imagesLeftChild.push_back(ofImage());
                imagesLeftChild.back().load(filePath);

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
    //maxHeight = 31;
    //maxWidth = 18;
    maxHeight = beingFront.getHeight();
    maxWidth= beingFront.getWidth();
    childHeight = beingFrontChild.getHeight();
    childWidth = beingFrontChild.getWidth();
    speed = 1;
    direction = 0;

    c.r=ofRandom(255);
    c.g=ofRandom(255);
    c.b=ofRandom(255);



}
//--------------------------------------------------------------

//void Being::setup(float height,float width,float floor,int yearInMs,vector<Being> &_beings){
void Being::setup(float height,float width,float floor,int yearInMs,float gravity){
    //beings = _beings;
    this-> yearInMs = yearInMs;
    alive = true;
    this->height = height;
    this->width = width;
    this->floor = floor;

    x=ofRandom(this->width-myWidth);
    y=ofRandom(this->height);
    //y=floor-myHeight);

    //y=ofRandom(this->height);
    birthTime =  ofGetElapsedTimeMillis();
    deathAge = ofRandom(60,100);
    deathTime = birthTime +(deathAge*yearInMs);
    pregnant=false;
    childReady = false;
    //yLimit = floor-myHeight;
    yearsDead =0;
    fertile = true;
    this->gravity=gravity;
    youngAge = 12;
    starving = false;
    closeTreeX = -1;

    agesWithoutMeal =0;
    agesStarving = 0;
    ageOfLastMeal = 0;
    lastAgeChecked = 0;

    eatEveryXAges=10;
    maxAgesStarving=30;

    treeLock = false;



}



//--------------------------------------------------------------
void Being::update(){

    myHeight=maxHeight;
    myWidth = maxWidth;
    if(age<youngAge){
        myHeight=childHeight;
        myWidth = childWidth;

    }
    //y=yLimit;
    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - birthTime;
    age = timeElapsed/yearInMs;







    if(age >=deathAge){
        alive = false;

    }

    if(alive){
        if(lastAgeChecked!=age){
            agesWithoutMeal = age-ageOfLastMeal;
            if(agesWithoutMeal>eatEveryXAges){
                if(!starving){
                starving=true;
                }
                agesStarving = agesWithoutMeal-eatEveryXAges;
            }
            if(agesStarving>maxAgesStarving){
                //if(alive){
                deathAge --;
                if(deathAge<=age){
                    //deathAge = age;
                    kill();
                }
                killedByStarvation = true;
                //}
            }

        }

        lastAgeChecked = age;



        if(ofRandom(10000)>9997 && !isPregnant()&& age>youngAge){
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
    //imagesRight[frameIndex].resize(myWidth,myHeight);


    if(direction == -1){
        ofSetColor(255);
        if(age<youngAge){
           ofSetColor(238,232,170);
        }
        if(!fertile){
           ofSetColor(178,255,102);
        }

        if(isPregnant()){
            ofSetColor(255,102,102);
        }
        //imagesLeft[frameIndex].resize(myWidth,myHeight);
        if(age<youngAge){
            imagesLeftChild[frameIndex].draw(x, y);
        }else{
            imagesLeft[frameIndex].draw(x, y);
        }
    }else if(direction == 1){
        ofSetColor(255);
        if(age<youngAge){
           ofSetColor(238,232,170);
        }
        if(!fertile){
           ofSetColor(178,255,102);
        }
        if(isPregnant()){
           ofSetColor(255,102,102);
        }
        if(age<youngAge){

            imagesRightChild[frameIndex].draw(x, y);
        }else{
            imagesRight[frameIndex].draw(x, y);
        }
    }else if (direction==0){
        ofSetColor(255);
        if(age<youngAge){
           ofSetColor(238,232,170);
        }
        if(!fertile){
           ofSetColor(178,255,102);
        }
        if(isPregnant()){
            ofSetColor(255,102,102);
        }
        //beingFront.resize(myWidth,myHeight);
        if(age<youngAge){
            if(onTree){
                beingBackChild.draw(x,y);
            }else{
                beingFrontChild.draw(x, y);
            }

        }else{
            if(onTree){
                beingBack.draw(x,y);

            }else{
                beingFront.draw(x, y);
            }

        }
        //ofRect(x,y,myWidth,myHeight);


    }


    //DRAW WHEN DEAD
    }else{
        ofSetColor(255);
        if(killedByStarvation){
            ofSetColor(200);
        }
        myHeight = 26;
        y = floor-myHeight;
        tomb.draw(x,y+2);


    }




}
void Being::move(){
    //y = floor-myHeight;



    y = y+gravity;
    if(y>floor-myHeight){
      y = floor-myHeight;
    }


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

    if(y<floor-myHeight){
        onTree=false;
        direction = 0;
    }else if(starving && closeTreeX !=-1){
        //float treeX = closeTree.getX();
        //onTree=false;
        float treeX = closeTreeX;
        float rand = ofRandom(2,10);
        if((treeX+40)-x>2){
            setDirection(1);
            onTree=false;
        }else if((treeX+40)-x<-2){
            setDirection(-1);
            onTree=false;
        }else{
            setDirection(0);
            onTree = true;
            /*
            if(closeTree.eatApple()){
                starving =  false;
            }
            */
        }


    }else if(ofRandom(1000)>990){
        onTree=false;
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

void Being::setGravity(float gravity){
    this->gravity = gravity;



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
    if(fertile&&age>youngAge){
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
void Being::kill(){
    deathAge = age;

}


void Being::killSlowly(int alives){
    //alive=false;
    int division = (int)(alives/100);
    if(division<5){
        division = 5;
    }
    deathAge = age+ofRandom(division);
    //deathAge = age;

}

void Being::setCloseTreeX(float  x){
    if(x!=-1){
    treeLock = true;
    closeTreeX = x;
    }else{
        closeTreeX = x;
    }

}
bool Being:: isTreeLock(){
    return treeLock;

}

void Being::setCloseTree(Tree  t){
    closeTree = t;

}

bool Being::isStarving(){
    return starving;

}
void Being::feed(){
    starving = false;
    ageOfLastMeal=age;

}

bool Being::isOnTree(){
    return onTree;


}
float Being::getCloseTreeX(){
    return closeTreeX;

}

int Being::getMaxAgesStarving(){
    return maxAgesStarving;
}

int Being::getAgesStarving(){
    return agesStarving;

}

void Being::setGaveUpX(float x){
    gaveUpX = x;


}
float Being::getGaveUpX(){
    return gaveUpX;


}
void Being::removeTreeLock(){
    treeLock = false;

}









