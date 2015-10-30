#pragma once

#include "ofMain.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage img;
//    ofImage image;
    void drawLinePixel(float X1,float Y1,float X2, float Y2, float linewidth, ofColor col);
    void drawImage1(float ptX1,float ptY1,float ptX2,float ptY2,int hues,int saturation,int brightness);
    void creatImage(int w, int h);
    float pointX,pointY;
    void Lissajous();
    float X1;
    float Y1;
    float X2;
    float Y2;
    ofColor mycolor;
    float hue;
    
    
};
