#pragma once
#include "ofMain.h"
#include "Being.h"
#include "Tree.h"
#include "Cloud.h"
#include "Meteor.h"


class Environment
{
public:
    Environment();
    void update();
    void draw();

    void drawBeings();
    void drawTrees();
    void drawClouds();
    void drawMeteors();

    void updateTrees();    
    void updateBeings();
    void updateClouds();    
    void updateMeteors();

    void updateBeingsSpeed(int ms);


    void speedUp();
    void slowDown();
    void giveBirths();
    void decimate(int percentage);
    void impregnate(int percentage);
    void makeInfertile(int percentage);
    void makeFertile(int percentage);
    void addBeing();
    void rain();
    void stopRain();
    bool isRaining();
    void addMeteor();
    void invertGravity();

    void removeLock(float x);

    void guideStarving();
    void feedStarving();
    float discoverCloseTreeX(float x);

    void loopOnBeings();
    void loopOnMeteors();

    ofTrueTypeFont font;
    vector<Being> beings;
    vector<Tree> trees;
    vector<Cloud> clouds;
    vector<Meteor> meteors;

    string getCurrentYear();
    string getAlives();

    string currentYear;
    string alivess;

    ofColor nightColor;
    ofColor dayColor;

    float wind;
    float gravity;
    int yearInMs;
    int startTime;
    int currentTime;
    int timeElapsed;
    int year;
    int birthsToGive;
    int alives;

    bool raining;

    int maxNOfTrees;

    int yearsInDay;
    int lastYearChecked;

    int currentPeriod;






};
