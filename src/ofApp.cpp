#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(6448);
    font.loadFont("franklinGothic.otf", 9);
    wheelValue = 50;
    lastAction = "No Action";
    lastWheelValue = 0;
    topBar.load("topBar.png");
    //leap.open();

}
//--------------------------------------------------------------
void ofApp::update(){
    e.update();
    menu.update();

    while(receiver.hasWaitingMessages()){
            // get the next message
            ofxOscMessage m;

            receiver.getNextMessage(&m);

            if(m.getAddress() == "/keyTap"){

                string selection = menu.select();
                if(selection == "Decimate") {
                   e.decimate(wheelValue);
                   lastAction = "Decimate";
                   lastWheelValue = wheelValue;
                }
                if(selection == "Impregnate") {
                   e.impregnate(wheelValue);
                   lastAction = "Impregnate";
                   lastWheelValue = wheelValue;
                }
                if(selection == "Make Infertile") {
                   e.makeInfertile(wheelValue);
                   lastAction = "Make Infertile";
                   lastWheelValue = wheelValue;
                }
                if(selection == "Make Fertile") {
                   e.makeFertile(wheelValue);
                   lastAction = "Make Fertile";
                   lastWheelValue = wheelValue;
                }
                if(selection == "Add Being") {
                   e.addBeing();
                   lastAction = "Add Being";
                   lastWheelValue = wheelValue;
                }
                if(selection == "Invert Gravity") {
                   e.invertGravity();
                   lastAction = "Invert Gravity";
                   lastWheelValue = wheelValue;
                }
                if(selection == "Start/Stop Rain") {
                   if(!e.isRaining()){
                        e.rain();
                        lastAction = "Rain";
                        lastWheelValue = wheelValue;
                   }else{
                       e.stopRain();
                       lastAction = "Stop Rain";
                       lastWheelValue = wheelValue;

                   }
                }
                if(selection == "Meteor") {
                   e.addMeteor();
                   lastAction = "Meteor";
                   lastWheelValue = wheelValue;
                }


                //e.addBeing();
                //lastAction = "Add Being";


            }

            if(m.getAddress() == "/swipe"){
                        string direction = m.getArgAsString(0);

                        if(direction == "right"){
                            menu.swipeRight();
                            actionSelected = menu.select();
                            //e.decimate((int)wheelValue);
                            //lastAction = "Decimate";
                            //lastWheelValue = wheelValue;

                        }else if(direction == "left"){
                            menu.swipeLeft();
                            actionSelected = menu.select();
                           // e.impregnate((int)wheelValue);
                            //lastAction = "Impregnate";
                            //lastWheelValue = wheelValue;

                        }

            }


            if(m.getAddress() == "/circle"){
                         wheelValue = m.getArgAsFloat(0);


            }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    e.draw();
    menu.draw();
    ofSetColor(255);
    topBar.draw(0,0);
    ofSetColor(255);
    string sWheelValue = ofToString((int)wheelValue);
    string sLastWheelValue = ofToString((int)lastWheelValue);
    font.drawString("Percentage For Action: "+sWheelValue+"%", 230, 30);

    if(lastAction=="Decimate" ||lastAction=="Impregnate" || lastAction=="Make Fertile" || lastAction=="Make Infertile" ){

        font.drawString("Last Action: "+lastAction+" "+sLastWheelValue+ "% of the population.", 500, 30);
    }else{
        font.drawString("Last Action: "+lastAction, 500, 30);

    }

    font.drawString("Action Selected: "+actionSelected, 840, 30);

    font.drawString("Years Running: "+e.getCurrentYear(), ofGetWidth()-135, 30);
    font.drawString("Beings Alive: "+e.getAlives(), 40, 30);




}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    /*
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
    if(key == '6') {
       e.rain();
    }
    if(key == '7') {
       e.stopRain();
    }
    if(key == '8') {
       e.addMeteor();
    }
    */

    if(key == OF_KEY_UP){
        wheelValue++;
        if(wheelValue>100){
            wheelValue=100;
        }



    }
    if(key == OF_KEY_DOWN){
        wheelValue--;
        if(wheelValue<0){
            wheelValue=0;
        }



    }

    if(key == OF_KEY_TAB){

        string selection = menu.select();
        if(selection == "Decimate") {
           e.decimate(wheelValue);
           lastAction = "Decimate";
           lastWheelValue = wheelValue;
        }
        if(selection == "Impregnate") {
           e.impregnate(wheelValue);
           lastAction = "Impregnate";
           lastWheelValue = wheelValue;
        }
        if(selection == "Make Infertile") {
           e.makeInfertile(wheelValue);
           lastAction = "Make Infertile";
           lastWheelValue = wheelValue;
        }
        if(selection == "Make Fertile") {
           e.makeFertile(wheelValue);
           lastAction = "Make Fertile";
           lastWheelValue = wheelValue;
        }
        if(selection == "Add Being") {
           e.addBeing();
           lastAction = "Add Being";
           lastWheelValue = wheelValue;
        }
        if(selection == "Invert Gravity") {
           e.invertGravity();
           lastAction = "Invert Gravity";
           lastWheelValue = wheelValue;
        }
        if(selection == "Start/Stop Rain") {
           if(!e.isRaining()){
                e.rain();
                lastAction = "Rain";
                lastWheelValue = wheelValue;
           }else{
               e.stopRain();
               lastAction = "Stop Rain";
               lastWheelValue = wheelValue;

           }
        }

        if(selection == "Meteor") {
           e.addMeteor();
           lastAction = "Meteor";
           lastWheelValue = wheelValue;
        }


        //e.addBeing();
        //lastAction = "Add Being";


    }




    if(key == OF_KEY_RIGHT){
        menu.swipeRight();
        actionSelected = menu.select();
                    //e.decimate((int)wheelValue);
                    //lastAction = "Decimate";
                    //lastWheelValue = wheelValue;
    }
    if(key == OF_KEY_LEFT){
         menu.swipeLeft();
         actionSelected = menu.select();
                   // e.impregnate((int)wheelValue);
                    //lastAction = "Impregnate";
                    //lastWheelValue = wheelValue;
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

