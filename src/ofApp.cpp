#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}
//--------------------------------------------------------------
void ofApp::update(){
    e.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    e.draw();


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

