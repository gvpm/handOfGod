#pragma once
#include "ofMain.h"
#include "Tree.h"


class Being
{
public:
    Being();

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

    void feed();
    bool isOnTree();
    bool isTreeLock();
    bool isStarving();

    void removeTreeLock();
    bool onTree;
    bool treeLock;    
    bool killedByStarvation;
    float closeTreeX;
    Tree closeTree;

    int agesWithoutMeal;
    int agesStarving;
    int ageOfLastMeal;
    int lastAgeChecked;
    int eatEveryXAges;

    int maxAgesStarving;


///GETS AND SETS


    void setX(float x);
    void setY(float x);
    void setYearInMs(int i);
    void setDirection(int d);
    void setSpeed(float s);
    void setGravity(float gravity);
    void setGaveUpX(float x);
    void setCloseTreeX(float x);
    void setCloseTree(Tree t);

    float getX();
    float getY();    
    int getDirection();    
    float getSpeed();
    float getMyHeight();
    float getMyWidth();
    int getYearsDead();    
    float getGaveUpX();
    int getMaxAgesStarving();
    int getAgesStarving();
    float getCloseTreeX();


///

    ofImage walking;
    ofImage stop;
    ofImage beingFrontChild;
    ofImage beingBackChild;
    ofImage beingBack;
    ofImage beingFront;
    ofImage tomb;

    vector <ofImage> imagesRight;
    vector <ofImage> imagesLeft;
    vector <ofImage> imagesStandFront;
    vector <ofImage> imagesRightChild;
    vector <ofImage> imagesLeftChild;
    vector <ofImage> imagesStandBack;
    vector <Being> beings;



    float gaveUpX;

    bool  childReady;
    int pregAge;

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

    int id;

    bool starving;


};

