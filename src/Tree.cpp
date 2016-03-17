#include "Tree.h"

Tree::Tree(){

myHeight = 100;
myWidth = 105;

c.r=ofRandom(0);
c.g=ofRandom(255);
c.b=ofRandom(0);

maxNOfApples=20;
tree.load("tree.png");



}


void Tree::setup(float height,float width,float floor){
    this->height = height;
    this->width = width;
    this->floor = floor;
    x=ofRandom(this->width-myWidth);
    y=floor-myHeight;


}



//--------------------------------------------------------------
void Tree::update(){
    if(applePositions.size()<maxNOfApples-1){
        ofPoint applePoint;
        applePoint.x=ofRandom(x+15,x+myHeight-15);
        applePoint.y = ofRandom(y+15,y+myWidth-45);
        //applePositions.push_back(applePoint);

    }


}

//--------------------------------------------------------------
void Tree::draw(){
    /*
    ofSetColor(165,42,41);
    ofRect(x,y,myWidth,myHeight);
    ofSetColor(c);
    ofRect(x-20,y-40,60,60);
    */
    ofSetColor(255);
    tree.draw(x,y);

    for(int i=0;i<applePositions.size();i++){
        ofSetColor(250,0,0);
        ofCircle(applePositions[i],3);

    }




}

//Gets and Sets

void Tree::setX(float x){
    this->x = x;



}
void Tree::setY(float y){
    this->y = y;


}

float Tree::getX(){
    return x;


}
float Tree::getY(){
    return y;


}


