#include "Environment.h"

Environment::Environment(){

    font.loadFont("franklinGothic.otf", 9);
    startTime = ofGetElapsedTimeMillis();
    yearInMs = 1000;
    year = 0;
    gravity = 3.9;
    wind = 0.5;
    raining = false;
    maxNOfTrees = 10;

    yearsInDay==20;
    lastYearChecked=0;

    //nightColor=(72, 48, 120);
    nightColor.r=72;
    nightColor.g=48;
    nightColor.b=120;

    dayColor.r=160;
    dayColor.g=216;
    dayColor.b=241;

    //dayColor(160, 216, 241);
    currentPeriod = 1;

    //Inicial beings
    for(int i = 0 ;i<10;i++){
    Being b;
    //b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs, beings);
    b.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    beings.push_back(b);
    }
    //Inicial trees
    for(int i = 0 ;i<1;i++){
    Tree t;
    t.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
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

///////////////////////////////////////////////////////
///UPDATE
///////////////////////////////////////////////////////

void Environment::update(){


    currentTime = ofGetElapsedTimeMillis();
    timeElapsed = currentTime - startTime;
    year = timeElapsed/yearInMs;

    if(currentPeriod==1){
        //ofBackground(72, 48, 120);
        ofBackground(160, 216, 241);

    }else if(currentPeriod==-1){
        ofBackground(72, 48, 120);

    }

    if(lastYearChecked!=year && year%30==0){
        currentPeriod = -currentPeriod;

    }
    lastYearChecked=(int)year;


    guideStarving();
    feedStarving();

    giveBirths();

    updateClouds();

    updateBeings();

    updateTrees();

    updateMeteors();

    if(raining&&ofRandom(1000)>990&&trees.size()<maxNOfTrees){
        Tree t;
        t.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs);
        trees.push_back(t);

    }

}

///////////////////////////////////////////////////////
///DRAW
///////////////////////////////////////////////////////

void Environment::draw(){


        ofSetColor(0,150,0);
        ofRect(0,ofGetHeight()-70,ofGetWidth(),70);
        //beings[4].draw();

        drawClouds();
        drawTrees();
        drawBeings();
        drawMeteors();

        ofSetColor(0);
        currentYear = ofToString(year);


        loopOnBeings();
        loopOnMeteors();


        alivess = ofToString(alives);
        //font.drawString("Beings Alive: "+alivess, 30, 25);


}

///////////////////////////////////////////////////////
///OTHERS
///////////////////////////////////////////////////////

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

void Environment::drawMeteors(){
    for(int i = 0;i<meteors.size() ;i++){

        meteors[i].draw();
    }

}
void Environment::updateMeteors(){
    for(int i = 0;i<meteors.size() ;i++){

        meteors[i].update();
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

void Environment::addMeteor(){
    Meteor m;
    m.setup(ofGetHeight(),ofGetWidth(),ofGetHeight()-70,yearInMs,gravity);
    meteors.push_back(m);


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

bool Environment::isRaining(){
    return raining;

}
string Environment::getCurrentYear(){
    return currentYear;

}
string Environment::getAlives(){
    return alivess;

}

void Environment::guideStarving(){

    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isStarving()){
            float x = discoverCloseTreeX(beings[i].getX());

            if(!beings[i].isTreeLock()){
            beings[i].setCloseTreeX(x);
            }


        }

    }


}

void Environment:: removeLock(float x){
    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isAlive() && beings[i].isTreeLock() && beings[i].getCloseTreeX()==x){
            beings[i].removeTreeLock();
            beings[i].setCloseTreeX(-1);
        }

    }


}

float Environment::discoverCloseTreeX(float x){
    if(trees.size()>0){
    float index = ofRandom(0,trees.size());
    return trees[index].getX();
    }else{
        return -1;
    }


}

void Environment::feedStarving(){

    for(int i = 0 ;i<beings.size();i++){
        if(beings[i].isStarving() && beings[i].isOnTree()){
            for(int j = 0 ;j<trees.size();j++){
                if(trees[j].getX()==beings[i].getCloseTreeX()){
                    if(!trees[j].isEmpty()){
                        trees[j].eatApple();
                        beings[i].feed();
                    }

                }

            }

        }

    }


}

void Environment::loopOnBeings(){

    alives=0;
    int j= 0;
    while ( j < beings.size() ) {
        if ( !beings[j].isAlive()  && beings[j].getYearsDead()>=5 ||!beings[j].isAlive()  && beings[j].getAgesStarving()>=beings[j].getMaxAgesStarving()+5) {
            beings.erase( beings.begin() + j );
        } else if (beings[j].isAlive()) {
            ++j;
            alives++;
        }else{
            ++j;
        }
    }



}
void Environment::loopOnMeteors(){
    for(int i = meteors.size()-1;i>=0;i--){
        if(!meteors[i].isAlive()){
            float x = meteors[i].getX();
            for(int z=0;z<beings.size();z++){
                float beingX = beings[z].getX();
               if (x < beingX && beingX < x+meteors[i].getWidth() &&beings[z].isAlive()){
                   beings[z].kill();

               }

            }

            int j= 0;
            while ( j < trees.size() ) {
                float treeX = trees[j].getX();
                if (x < treeX+trees[j].getWidth()/2 && treeX+trees[j].getWidth()/2 < x+meteors[i].getWidth()) {
                    trees.erase(trees.begin() + j );
                    removeLock(treeX);
                } else{
                    ++j;
                }
            }

            if (meteors[i].getYearsDead()>=2) {
                            meteors.erase( meteors.begin() + i );
                        }

        }

    }


}


