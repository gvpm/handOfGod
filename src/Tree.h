#pragma once

#include "ofMain.h"

class Tree
{
public:
    Tree();


    void setup(float height,float width,float floor);
    void update();
    void draw();


    //Gets and Sets


    void setX(float x);
    void setY(float x);
    float getX();
    float getY();
    int getDirection();
    float getSpeed();

    //

    float height;
    float width;
    float floor;
    int direction;
    float x;
    float y;
    float myHeight;
    float myWidth;
    ofColor c;
    int nOfApples;
    int maxNOfApples;
    vector <ofPoint> applePositions;
    ofImage tree;
    ofImage apple;

};
