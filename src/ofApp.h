#pragma once

#include "ofMain.h"
#include "Environment.h"
#include "ofxOsc.h"
#include "Menu.h"
//#include "ofxLeapMotion2.h"



class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    Environment e;
    Menu menu;

    ofxOscReceiver receiver;

    ofTrueTypeFont		font;

    string lastAction;    
    string actionSelected;

    int lastWheelValue;
    int wheelValue;


    ofImage topBar;

//ofxLeapMotion leap;


};
