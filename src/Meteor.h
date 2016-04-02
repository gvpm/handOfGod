#pragma once
#include "ofMain.h"

class Meteor
{
public:
    Meteor();

    void setup(float height,float width,float floor,int yearInMs,float gravity);

    void update();
    void draw();
    void move();

    bool isAlive();


///GETS AND SETS

    float getX();
    float getY();
    int getYearsDead();
    float getWidth();

    void setX(float x);
    void setY(float x);
    void setYearInMs(int i);


///
    ofImage onFire;
    ofImage meteor;
    vector <ofImage> imagesOnFire;

    float height;
    float width;
    float floor;
    int yearInMs;
    float gravity;

    float myHeight;
    float myWidth;

    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;

    float x;
    float y;

    bool alive;
    int currentTime;
    int deathTime;
    int birthTime;
    int timeElapsed;
    int age;
    int deathAge;

    int yearsDead;




};

