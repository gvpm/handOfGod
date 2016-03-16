#include "Environment.h"

Environment::Environment(){
    ofBackground(160, 216, 241);
    font.loadFont("franklinGothic.otf", 9);
    startTime = ofGetElapsedTimeMillis();
    yearInMs = 1000;
    year = 0;


    for(int i = 0 ;i<10;i++){
    Being b;
    //b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs, beings);
    b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
    beings.push_back(b);
    }
    for(int i = 0 ;i<3;i++){
    Tree t;
    t.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70);
    trees.push_back(t);
    }
    birthsToGive = 0;


}

//--------------------------------------------------------------
void Environment::update(){

    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - startTime;
    year = timeElapsed/yearInMs;

    //int size = beings.size();

/*
    for(int i =0; i<size;i++){
        if(beings[i].isChildReady()){
            birthsToGive++;
            Being b;
            b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
            b.setX(beings[i].getX());
            b.setY(beings[i].getY());
            beings.push_back(b);
            beings[i].removeChild();
        }

    }
 */


    giveBirths();

    updateBeings();


    updateTrees();

}

//--------------------------------------------------------------
void Environment::draw(){
        ofSetColor(0,150,0);
        ofRect(0,ofGetHeight()-70,ofGetWidth(),70);
        //beings[4].draw();

        drawTrees();
        drawBeings();

        ofSetColor(0);
        string currentYear = ofToString(year);
        font.drawString("Years Running: "+currentYear, ofGetWidth()-135, 25);
        //vector <Being> beingsAux;





        alives=0;
        /*
        for(int i = 0; i<beings.size();i++){
            if(beings[i].isAlive()){
                alives++;

            }

        }
        */

        int j= 0;
        while ( j < beings.size() ) {
            if ( !beings[j].isAlive() /*&& (year%1==0)*/ &&beings[j].getYearsDead()>=5) {
                beings.erase( beings.begin() + j );
            } else if (beings[j].isAlive()) {
                ++j;
                alives++;
            }else{
                ++j;
            }
        }


/*

//DELETE TOMBSTONES EVERY 10 YEARS
        //if(year%10==0){
        int j= 0;
        while ( j < beings.size() ) {
            if ( !beings[j].isAlive() && (year%2==0)) {
                beings.erase( beings.begin() + j );
            } else if (beings[j].isAlive()) {
                ++j;
                alives++;
            }else{
                ++j;
            }
        }
        //}
        */

        string alivess = ofToString(alives);
        font.drawString("Beings Alive: "+alivess, 30, 25);


}
void Environment::drawBeings(){
    for(int i = 0;i<beings.size() ;i++){

        beings[i].draw();
    }

}
void Environment::updateBeings(){
    for(int i = 0;i<beings.size() ;i++){

        beings[i].update();
    }

}

void Environment::drawTrees(){
    for(int i = 0;i<trees.size() ;i++){

        trees[i].draw();
    }

}
void Environment::updateTrees(){
    for(int i = 0;i<trees.size() ;i++){

        trees[i].update();
    }

}
void Environment::slowDown(){
    yearInMs = yearInMs*10;
    updateBeingsSpeed(yearInMs);



}
void Environment::speedUp(){
    yearInMs = yearInMs/10;
    updateBeingsSpeed(yearInMs);

}

void Environment::updateBeingsSpeed(int ms){
    for(int i = 0 ;i<beings.size();i++){
        beings[i].setYearInMs(ms);
    }


}

void Environment::decimate(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].killSlowly(alives);

        }
    }


}
void Environment::impregnate(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].impregnate();

        }
    }


}

void Environment::infertilize(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].infertilize();

        }
    }


}
void Environment::fertilize(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].fertilize();

        }
    }


}
void Environment::giveBirths(){
    int size = beings.size();
    for(int i =0; i<size;i++){
        if(beings[i].isChildReady()){
            birthsToGive++;
            Being b;
            b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
            b.setX(beings[i].getX());
            b.setY(beings[i].getY());
            beings.push_back(b);
            beings[i].removeChild();
        }

    }
}

