///////////////////////////////////////////////////////
///CLASS - Being
///
///
///////////////////////////////////////////////////////
#include "Being.h"

Being::Being(){


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

///////////////////////////////////////////////////////
///SETUP
///////////////////////////////////////////////////////


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
    //sets initial time
    birthTime =  ofGetElapsedTimeMillis();

    //determines when it is going to die
    deathAge = ofRandom(60,100);
    deathTime = birthTime +(deathAge*yearInMs);

    pregnant=false;
    //to be change after one year pregnant
    childReady = false;
    //yLimit = floor-myHeight;
    yearsDead =0;
    fertile = true;
    this->gravity=gravity;
    //determines what is young age
    youngAge = 12;
    starving = false;
    closeTreeX = -1;

    agesWithoutMeal =0;
    agesStarving = 0;
    ageOfLastMeal = 0;
    lastAgeChecked = 0;

    //Eating main settings
    eatEveryXAges=10;
    maxAgesStarving=30;

    treeLock = false;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////


void Being::update(){

    myHeight=maxHeight;
    myWidth = maxWidth;
    //case when is is still a child
    if(age<youngAge){
        myHeight=childHeight;
        myWidth = childWidth;

    }
    //y=yLimit;

    //updates time variables
    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - birthTime;
    age = timeElapsed/yearInMs;

    //kills itself when reaches death age
    if(age >=deathAge){
        alive = false;

    }
    //does  everything only if it is alive
    if(alive){//checks once every age
        if(lastAgeChecked!=age){
            agesWithoutMeal = age-ageOfLastMeal;
            //sets starving status
            if(agesWithoutMeal>eatEveryXAges){
                if(!starving){
                starving=true;
                }
                agesStarving = agesWithoutMeal-eatEveryXAges;
            }//it decreases its life time if its starving for too long
            if(agesStarving>maxAgesStarving){
                //if(alive){
                deathAge --;
                if(deathAge<=age){
                    //deathAge = age;
                    kill();
                }//sets if it lost any time of life because of starvation
                killedByStarvation = true;
                //}
            }

        }

        lastAgeChecked = age;


        //has a chance of getting pregnant each frame
        if(ofRandom(10000)>9997 && !isPregnant()&& age>youngAge){
            impregnate();

        }
        //gives birth if its pregnant
        //basically removes pregnant status and updates child ready
        if(isPregnant()){
            giveBirth();

        }


        //changes direction
        changeDirection();
        //moves
        move();
    }else{//if its dead will increase the amount of years dead
        yearsDead = age-deathAge;

    }



}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

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

////DRAW WHEN ALIVE

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


////DRAW WHEN DEAD

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




///////////////////////////////////////////////////////
///GETS AND SETS
///////////////////////////////////////////////////////

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
int Being::getDirection(){
    return direction;

}
float Being::getSpeed(){
    return speed;

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


float Being::getGaveUpX(){
    return gaveUpX;


}

void Being::setGaveUpX(float x){
    gaveUpX = x;


}

void Being::setX(float x){
    this->x = x;

}

void Being::setGravity(float gravity){
    this->gravity = gravity;


}
void Being::setY(float y){
    this->y = y;

}


void Being::setDirection(int d){
    direction=d;

}


void Being::setSpeed(float s){
    speed=s;

}

void Being::setYearInMs(int i){
   yearInMs = i;


}

void Being::setCloseTreeX(float  x){
    if(x!=-1){
    treeLock = true;
    closeTreeX = x;
    }else{
        closeTreeX = x;
    }

}

void Being::setCloseTree(Tree  t){
    closeTree = t;

}
///////////////////////////////////////////////////////
///OTHERS
///////////////////////////////////////////////////////
//not implemented and not in use
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
//impregnate if fertile
void Being::impregnate(){
    if(fertile&&age>youngAge){
    pregAge=age;
    pregnant = true;
    }
}
//sets child ready and remove pregnance, environment will deal with birth
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

//it will kill the being in a random number of years between 0 and a given division
//that division is calculated acordind to the number of beings alive
//this is to reduce lag and improve performance when the world is crowded
void Being::killSlowly(int alives){
    //alive=false;
    int division = (int)(alives/100);
    if(division<5){
        division = 5;
    }
    deathAge = age+ofRandom(division);
    //deathAge = age;

}

bool Being:: isTreeLock(){
    return treeLock;

}

bool Being::isStarving(){
    return starving;

}
//removes starving status and sets up the age of last meal
void Being::feed(){
    starving = false;
    ageOfLastMeal=age;

}

bool Being::isOnTree(){
    return onTree;

}

void Being::removeTreeLock(){
    treeLock = false;

}
//changes direction
//will go towards the designated tree when starving (if there  is one)
//it will stop when it reaches the tree

//if not starving will just change randomly with a  chance of doing so
void Being::changeDirection(){

    if(y<floor-myHeight){
        onTree=false;
        direction = 0;
    }else if(starving && closeTreeX !=-1){
        //float treeX = closeTree.getX();
        //onTree=false;
        float treeX = closeTreeX;
        float rand = ofRandom(2,10);
        if((treeX+40)-x>20){
            setDirection(1);
            onTree=false;
        }else if((treeX+40)-x<-20){
            setDirection(-1);
            onTree=false;
        }else{
            setDirection(0);
            onTree = true;

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
//moves the being acording to the direction
//makes the being fall or fly acording to gravity
//makes the being stop on floor
//change direction when it reaches sreen borders


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



}









