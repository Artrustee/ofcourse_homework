#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetBackgroundAuto(false);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

 //version 1
    for (float i = 0; i <= 6 * PI; i += PI/2600) {

        X1 = 350 * cos(2* i + PI+mouseY)+ofGetWidth()/2;
        Y1 = 350 * sin(2* i + PI+mouseX)+ofGetHeight()/2;
        X2 = 450 * cos(ofSignedNoise(i*2)* acos(cos(i)) + PI)+ofGetWidth()/2;
//        X2 = 450 * cos(4.3* i + PI+ mouseX)+ofGetWidth()/2;
//        Y2 = 300 * sin(4.5* i + PI+ mouseY)+ofGetHeight()/2;
//        X2 = 450 * cos(4.3* i + PI+ mouseX)+ofGetWidth()/2;
        Y2 = 300 * sin(4.5* i + PI+ mouseY)+ofGetHeight()/2;
//        Y2 = 500 * tan(4.5* ofRandom(i) + PI)+ofGetHeight()/2;
//        float hue = ofMap(sin(i*(2*PI/(ofGetWidth()/4))), -1, 1, 0, 255);
        float hue = ofMap(6*sin(0.5*i), 0, 6, 0, 360);

        mycolor.setHsb(hue, 255, 255);
        mycolor.a = ofMap(i, 0, ofGetWidth(), 20, 220);
        ofSetColor(mycolor);
        ofLine(X1, Y1, X2, Y2);
        
    }

 
// version 1
//    for (float i = 0; i <= 6 * PI; i += PI/2000) {
//        X1 = 100 * cos(2* i + PI)+ofGetWidth()/2;
//        Y1 = 100 * sin(2* i + PI)+ofGetHeight()/2;
//        X2 = 450 * cos(ofRandom(i)* acos(cos(i)) + PI)+ofGetWidth()/2;
//        //        X2 = 450 * cos(4.3* i + PI)+ofGetWidth()/2;
//        Y2 = 300 * sin(4.5* i + PI)+ofGetHeight()/2;
//        float h = ofMap(6*sin(0.5*i), 0, 6, 0, 360);
//        //        float s = ofMap(<#float value#>, <#float inputMin#>, <#float inputMax#>, <#float outputMin#>, <#float outputMax#>);
//        //        float b = ofMap(<#float value#>, <#float inputMin#>, <#float inputMax#>, <#float outputMin#>, <#float outputMax#>);
//        mycolor.setHsb(h, 150, 300);
//        ofSetColor(mycolor);
//        //        mycolor.a =ofMap(6*sin(0.5*i), 0, 6 , 0, 230);
//        mycolor.a = 100;
//        ofLine(X1, Y1, X2, Y2);
//    }



    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    cout << "mousex,y" << mouseX,mouseY << endl ;
    cout << "x" << mouseX << endl;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
