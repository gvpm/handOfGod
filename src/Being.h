#pragma once
#include "ofMain.h"
#include "Tree.h"


class Being
{
public:
    Being();
    //void setup(float height,float width,float floor,int yearInMs, vector <Being> &);
    void setup(float height,float width,float floor,int yearInMs,float gravity);
    void update();
    void draw();
    void move();
    void changeDirection();
    bool encountered(Being b);
    bool isPregnant();
    bool isChildReady();
    bool isAlive();
    void impregnate();
    void giveBirth();
    void removeChild();
    void killSlowly(int alives);
    void kill();

    void makeInfertile();
    void makeFertile();
    void setCloseTreeX(float x);

    void setCloseTree(Tree t);
    Tree closeTree;


    //Gets and Sets


    void setX(float x);
    void setY(float x);
    void setYearInMs(int i);
    float getX();
    float getY();
    void setDirection(int d);
    int getDirection();
    void setSpeed(float s);
    float getSpeed();
    float getMyHeight();
    float getMyWidth();
    int getYearsDead();
    void setGravity(float gravity);




    bool isStarving();





    //
    float closeTreeX;

    bool  childReady;
    int pregAge;
    ofImage walking;
    ofImage stop;
    int currentTime;
    int birthTime;
    int deathTime;
    int age;
    int deathAge;
    float birthSize;
    float maxSize;
    int timeElapsed;
    int yearsDead;

    int youngAge;

    bool fertile;
    bool alive;
    bool pregnant;

    int yearInMs;

    float gravity;
    float height;
    float width;
    float floor;
    int direction;
    float x;
    float y;
    float yLimit;
    float myHeight;
    float myWidth;
    float maxHeight;
    float maxWidth;
    float childHeight;
    float childWidth;


    float speed;

    ofColor c;

    int   appFPS;
    float sequenceFPS;
    bool  bFrameIndependent;
    vector <ofImage> imagesRight;
    vector <ofImage> imagesLeft;
    vector <ofImage> imagesStandFront;

    vector <ofImage> imagesRightChild;
    vector <ofImage> imagesLeftChild;
    ofImage beingFrontChild;


    vector <ofImage> imagesStandBack;
    ofImage beingFront;
    ofImage tomb;
    vector <Being> beings;
    int id;

    bool starving;


};

