#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(6448);
    font.loadFont("franklinGothic.otf", 9);
    wheelValue = 50;
    lastAction = "No Action";
    lastWheelValue = 0;

}
//--------------------------------------------------------------
void ofApp::update(){
    e.update();

    while(receiver.hasWaitingMessages()){
            // get the next message
            ofxOscMessage m;
            receiver.getNextMessage(&m);

            if(m.getAddress() == "/tap"){
                        string pos = m.getArgAsString(0);
                        if(pos == "center"){
                            e.invertGravity();
                            lastAction = "Invert Gravity";

                        }else if(pos ==  "north"){

                        }else if(pos ==  "east"){

                        }else if(pos ==  "south"){
                            e.addBeing();
                            lastAction = "Add Being";

                        }else if(pos ==  "west"){

                        }

            }

            if(m.getAddress() == "/flick"){
                        string from = m.getArgAsString(0);
                        string to = m.getArgAsString(1);
                        if(from == "west"&& to== "east"){
                            e.decimate((int)wheelValue);
                            lastAction = "Decimate";
                            lastWheelValue = wheelValue;

                        }else if(from == "east"&& to== "west"){
                            e.impregnate((int)wheelValue);
                            lastAction = "Impregnate";
                            lastWheelValue = wheelValue;

                        }else if(from == "north"&& to== "south"){
                            e.makeInfertile((int)wheelValue);
                            lastAction = "Make Infertile";
                            lastWheelValue = wheelValue;


                        }else if(from == "south"&& to== "north"){
                            e.makeFertile((int)wheelValue);
                            lastAction = "Make Fertile";
                            lastWheelValue = wheelValue;

                        }

            }


            if(m.getAddress() == "/airwheel"){
                         wheelValue = m.getArgAsFloat(0);


            }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    e.draw();
    string sWheelValue = ofToString((int)wheelValue);
    string sLastWheelValue = ofToString((int)lastWheelValue);
    font.drawString("WheelValue: "+sWheelValue, 300, 25);

    if(lastAction=="Decimate" ||lastAction=="Impregnate" || lastAction=="Make Fertile" || lastAction=="Make Infertile" ){

        font.drawString("Last Action: "+lastAction+" "+sLastWheelValue+ "% of the population.", 500, 25);
    }else{
        font.drawString("Last Action: "+lastAction, 500, 25);
    }




}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1') {
       e.decimate(50);
    }
    if(key == '2') {
       e.impregnate(50);
    }
    if(key == '3') {
       e.makeInfertile(50);
    }
    if(key == '4') {
       e.makeFertile(50);
    }
    if(key == '5') {
       e.addBeing();
    }
    if(key == '0') {
       e.invertGravity();
    }




}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

