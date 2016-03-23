#include "Environment.h"

Environment::Environment(){
    ofBackground(160, 216, 241);
    font.loadFont("franklinGothic.otf", 9);
    startTime = ofGetElapsedTimeMillis();
    yearInMs = 1000;
    year = 0;
    gravity = 3.9;
    wind = 0.5;
    raining = false;

    //Inicial beings
    for(int i = 0 ;i<10;i++){
    Being b;
    //b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs, beings);
    b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    beings.push_back(b);
    }
    //Inicial trees
    for(int i = 0 ;i<3;i++){
    Tree t;
    t.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70);
    trees.push_back(t);
    }
    //inicial clouds
    for(int i = 0 ;i<ofRandom(4,15);i++){
    Cloud c;
    c.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,wind,gravity);
    clouds.push_back(c);
    }


    birthsToGive = 0;


}

//--------------------------------------------------------------
void Environment::update(){
    ofBackground(160, 216, 241);
    if(raining){
        ofBackground(170, 226, 251);

    }

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

    updateClouds();

    updateBeings();

    updateTrees();

}

//--------------------------------------------------------------
void Environment::draw(){


        ofSetColor(0,150,0);
        ofRect(0,ofGetHeight()-70,ofGetWidth(),70);
        //beings[4].draw();

        drawClouds();
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

void Environment::drawClouds(){
    for(int i = 0;i<clouds.size() ;i++){

        clouds[i].draw();
    }

}
void Environment::updateClouds(){
    for(int i = 0;i<clouds.size() ;i++){

        clouds[i].update();
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

void Environment::rain(){
    for(int i = 0 ;i<clouds.size();i++){

            clouds[i].rain();

    }
    raining = true;


}

void Environment::stopRain(){
    for(int i = 0 ;i<clouds.size();i++){

            clouds[i].stopRain();

    }
    raining =false;


}

void Environment::makeInfertile(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].makeInfertile();

        }
    }


}
void Environment::makeFertile(int percentage){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()&&ofRandom(100)<percentage){
            beings[i].makeFertile();

        }
    }


}
void Environment::addBeing(){
    Being b;
    b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    beings.push_back(b);


}

void Environment::setGravity(){


}

void Environment::invertGravity(){
    gravity = -gravity;
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive()){
            beings[i].setGravity(gravity);

        }
    }

}

void Environment::giveBirths(){
    int size = beings.size();
    for(int i =0; i<size;i++){
        if(beings[i].isChildReady()){
            birthsToGive++;
            Being b;
            b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
            b.setX(beings[i].getX());
            b.setY(beings[i].getY());
            beings.push_back(b);
            beings[i].removeChild();
        }

    }
}

