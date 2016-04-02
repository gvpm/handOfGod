#pragma once

#include "ofMain.h"

class Tree
{
public:
    Tree();


    void setup(float height,float width,float floor,int yearInMs);
    void update();
    void draw();

     bool isEmpty();

     void eatApple();

///GETS AND SETS

    float getX();
    float getY();
    int getDirection();
    float getWidth();
    float getSpeed();
    int getMaxNOfApples();
    int getNOfApples();

    void setX(float x);
    void setY(float x);

///

    ofImage tree;
    ofImage apple;
    vector <ofPoint> applePositions;
    ofColor c;

    float height;
    float width;
    float floor;
    int direction;
    float x;
    float y;
    float myHeight;
    float myWidth;

    int nOfApples;
    int maxNOfApples;

    int currentTime;
    int birthTime;
    int age;
    int timeElapsed;
    int yearInMs;
    int lastAge;
    bool empty;



};
