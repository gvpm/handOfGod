///////////////////////////////////////////////////////
///CLASS - Tree
///
///
///////////////////////////////////////////////////////
#include "Tree.h"

Tree::Tree(){


c.r=ofRandom(0);
c.g=ofRandom(255);
c.b=ofRandom(0);

maxNOfApples=20;
tree.load("tree.png");

myHeight = 100;
myWidth = 105;



}

///////////////////////////////////////////////////////
///SETUP
///////////////////////////////////////////////////////


void Tree::setup(float height,float width,float floor,int yearInMs){
    this->yearInMs = yearInMs;
    this->height = height;
    this->width = width;
    this->floor = floor;
    x=ofRandom(this->width-myWidth);
    y=floor-myHeight;
    //loads apple image
    apple.load("apple.png");
    //time variables
    birthTime =  ofGetElapsedTimeMillis();
    age = 0;
    timeElapsed=0;

    lastAge = 0;

    empty = true;


}

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////


void Tree::update(){

    //updates time variables
    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - birthTime;
    age = timeElapsed/yearInMs;

    if(applePositions.size()>0){
        empty= false;
    }else{
        empty  = true;
    }

    if(age%1==0  && age!=lastAge){
        lastAge = age;
        //creates 2 apples in each second
        if(applePositions.size()<maxNOfApples-1){
            ofPoint applePoint;
            applePoint.x=ofRandom(x+12,x+myWidth-20);
            applePoint.y = ofRandom(y+15,y+myHeight-50);
            applePositions.push_back(applePoint);
            ofPoint applePoint2;
            applePoint2.x=ofRandom(x+12,x+myWidth-20);
            applePoint2.y = ofRandom(y+15,y+myHeight-50);
            applePositions.push_back(applePoint2);

        }

    }


}


///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void Tree::draw(){
    /*
    ofSetColor(165,42,41);
    ofRect(x,y,myWidth,myHeight);
    ofSetColor(c);
    ofRect(x-20,y-40,60,60);
    */
    ofSetColor(255);
    tree.draw(x,y);
    //draws all the apples on the set potitions
    for(int i=0;i<applePositions.size();i++){
        ofSetColor(250);
        apple.draw(applePositions[i]);

        //ofCircle(applePositions[i],3);

    }




}

///////////////////////////////////////////////////////
///GETS AND SETS
///////////////////////////////////////////////////////

float Tree::getX(){
    return x;

}
float Tree::getY(){
    return y;

}

float Tree::getWidth(){
    return myWidth;

}

int Tree::getMaxNOfApples(){
    return maxNOfApples;

}
int Tree::getNOfApples(){
    return applePositions.size();

}

void Tree::setX(float x){
    this->x = x;



}
void Tree::setY(float y){
    this->y = y;


}

///////////////////////////////////////////////////////
///OTHER
///////////////////////////////////////////////////////



bool Tree::isEmpty(){

    return empty;


}

//removes an apple from the vector and sets tree empty if it became empty
void Tree::eatApple(){

     applePositions.pop_back();
     if(applePositions.size()>0){
         empty= false;
     }else{
         empty  = true;
     }



}





