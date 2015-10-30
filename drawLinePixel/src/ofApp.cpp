#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(37);
    
}
//--------------------------------------------------------------
void ofApp::drawLinePixel(float X1, float Y1,float X2, float Y2, float linewidth,ofColor col){
    float t;
    pointX,pointY = 0;
    
    // if slope does not exsists
    if ( X1 == X2) {
        pointX = X1;
        for ( t = 0; t <= Y2; t++) {
            pointY = pointY + Y1;
//            ofSetColor(0);
//            ofPoint(t,pointY);
            ofSetColor(mycolor);
            ofCircle(pointX, pointY,linewidth );
        }
    }
    // the slope exsist
    else {
        float slopeK = ( Y2 - Y1 ) / ( X2- X1 );//calculate the slope
        for ( t = X1; t <= X2; t++) {
            pointX = t;
            pointY = slopeK * (t - X1) + Y1;
//            ofSetColor(0);
//            drawImage1(X1, Y1, X2, Y2, 160, 200, 0);
            ofSetColor(mycolor);
            ofCircle(pointX, pointY,ofMap(ofNoise(t), X1, X2, 0.3, linewidth) );
//            ofEllipse(pointX, pointY, ofMap(ofNoise(t+3), X1 , X2, 0.2,  linewidth), ofMap(ofNoise(t), X1 , X2, 0.2, 23 * linewidth));
        }
    }
}
//--------------------------------------------------------------
void ofApp::Lissajous(){
    
    for (float i = 0; i <= 6 * PI; i += PI/600) {
        
        X1 = 350 * cos(ofMap(mouseX, ofGetWidth(), ofGetElapsedTimef(), 0.5, 3.5)* i + PI+mouseY)+ofGetWidth()/2;
        Y1 = 350 * sin(2* i + PI+mouseX)+ofGetHeight()/2;
//        Y1 = 350 * sin(ofMap(mouseX, ofGetWidth(), ofGetHeight(), 0.5, 4)* i + ofNoise(ofGetElapsedTimef()))+ofGetHeight()/2;
//        Y1 = 350 * sin(2* i + ofGetElapsedTimef())+ofGetHeight()/2;
//        X2 = 450 * cos(ofRandom(i*2)* acos(cos(i)) + PI)+ofGetWidth()/2;
//        X2 = 450 * cos(4.3* i + PI+ mouseX)+ofGetWidth()/2;
//        Y2 = 300 * sin(4.5* i + PI+ mouseY)+ofGetHeight()/2;
        X2 = 450 * cos(4.3* i + PI+ mouseX)+ofGetWidth()/2;
        Y2 = 300 * sin(4.5* i + PI+ mouseY)+ofGetHeight()/2;
        //        Y2 = 500 * tan(4.5* ofRandom(i) + PI)+ofGetHeight()/2;
        //        float hue = ofMap(sin(i*(2*PI/(ofGetWidth()/4))), -1, 1, 0, 255);
        float hue = ofMap(6*sin(0.5*i), 0, 6, 0, 360);
        
        mycolor.setHsb(hue, 255, 255);
        mycolor.a = ofMap(i, 0, ofGetWidth(), 17, 220);
//        ofSetColor(mycolor);
//        ofLine(X1, Y1, X2, Y2);
//        ofPixels_<ofLine(X1, Y1, X2, Y2)>();
        drawLinePixel(X1, Y1, X2, Y2, 1.1,mycolor);
        
        
        
    }
}

//--------------------------------------------------------------
//void ofApp::drawImage1(float ptX1,float ptY1,float ptX2,float ptY2,int hues,int saturation,int brightness){
//    int w = ofGetWidth();
//    int h = ofGetHeight();
//    img.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
//    //img setting up
//    for (int x = 0; x < w; x++){
//		for (int y = 0; y < h; y++){
//            if ( (x - ptX1)*(x - ptX2) > 0){
//                brightness = 0; // means dont draw anything keep it black
//            } else{
//                
//                if ((y - ptY1)*(y - ptY2) > 0){
//                    brightness = 0;
//                }else{
//                    brightness = 225;
//                }
//            }
//                
//            hues = 160;
//            saturation = 200;
//
////            saturation = ofMap(dist, 0, 150, 255, 0, true);
//
//            ofColor pixCol(hues, saturation, brightness);
//            pixCol.a = 170;
//            img.setColor(x, y, pixCol);
//		}
//	}
//    img.update();
//
//
//}
//-----------------------BACKUP------------------------------
//void ofApp::drawImage1(int w, int h){
//    img.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
//    for (int x = 0; x < w; x++){
//        for (int y = 0; y < h; y++){
//            
//            int red = x;
//            
//            int green = y;
//            
//            ofVec2f point, center;
//            
//            point.set(x, y);
//            center.set(w*0.5,h*0.5);
//            float dist = point.distance(center);
//            int blue = ofMap(dist, 0, 150, 255, 0, true);
//            
//            ofColor pixCol(red, green, blue);
//            pixCol.a = 170;
//            img.setColor(x, y, pixCol);
//        }
//    }
//    img.update();
//    
//}


//--------------------------------------------------------------
void ofApp::update(){
    

}


//--------------------------------------------------------------
void ofApp::draw(){
//    drawImage1(255,255,);
//    
//    img.draw(ofGetWidth()/2 -10,ofGetHeight()/2-20);
//    drawImage1(10, 20,400,500,255,260,200);
//    img.draw(ofGetWidth()/2 ,ofGetHeight()/2);
//    creatImage(1024, 1024);
//    //ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
//    drawLinePixel(10, 10, 500, 500,0.5);
//    ofLine(10, 10, 500, 500);
    Lissajous();
}

//--------------------------------------------------------------
void ofApp::creatImage(int w, int h){
//    //Creating image
//    //Allocate array for filling pixels data
//    unsigned char * data = new unsigned char[w * h * 4];
//    
//    //Fill array for each pixel (x,y)
//    for (int x = 0 ; x < h ;x++){
//        for (int y = 0;  y < w; y++) {
//            //Compute preliminary values,
//            //needed for our pixel color calculation:
//
//            float time = ofGetElapsedTimef();     //1.Time from application start
//            
//            //2.Level of hyperbola value of x and y with
//            //center in w/2 h/2
//            float v = ( x - w/2) *( y-h/2);
//            
//            //3.Combining v with time for motion effect
//            float u = v * 0.00025 +time; // 0.00025 was chosen empirically
//            
//            //4.Compute color components as periodical
//            //funcion of u, and streched to [0..255]
//            int red = ofMap(sin( u ), -1, 1, 0, 255);
//            int green = ofMap(sin( u * 2), -1, 1, 1, 255);
//            int blue = 255 - green;
//            int alpha = 255;//just constant for simplicity
//            //Fill array components for pixel (x,y):
//            int index = 4 * (x + w * y);
//            data[ index ] = red;
//            data[ index + 1] = green;
//            data[ index + 2] = blue;
//            data[ index + 3] = alpha;
//        }
//    }
//    
//    //Load array to image
//    //    image.setFromPixels(data, w, h, OF_IMAGE_COLOR_ALPHA);
//    
//    //Aarray is not needed anymore, so clear memory
//    delete [] data;
}
//------------------------BACKUP--------------------------------
//void ofApp::creatImage(int w, int h){
//    //    //Creating image
//    //
//    //    //Allocate array for filling pixels data
//    //    unsigned char * data = new unsigned char[w * h * 4];
//    //
//    //    //Fill array for each pixel (x,y)
//    //    for (int y = 0 ; y < h ;y++){
//    //        for (int x = 0;  x < w; x++) {
//    //            //Compute preliminary values,
//    //            //needed for our pixel color calculation:
//    //
//    //            float time = ofGetElapsedTimef();     //1.Time from application start
//    //
//    //            //2.Level of hyperbola value of x and y with
//    //            //center in w/2 h/2
//    //            float v = ( x - w/2) *( y-h/2);
//    //
//    //            //3.Combining v with time for motion effect
//    //            float u = v * 0.00025 +time; // 0.00025 was chosen empirically
//    //
//    //            //4.Compute color components as periodical
//    //            //funcion of u, and streched to [0..255]
//    //            int red = ofMap(sin( u ), -1, 1, 0, 255);
//    //            int green = ofMap(sin( u * 2), -1, 1, 1, 255);
//    //            int blue = 255 - green;
//    //            int alpha = 255;//just constant for simplicity
//    //
//    //            //Fill array components for pixel (x,y):
//    //            int index = 4 * (x + w * y);
//    //            data[ index ] = red;
//    //            data[ index + 1] = green;
//    //            data[ index + 2] = blue;
//    //            data[ index + 3] = alpha;
//    //        }
//    //    }
//    //
//    //    //Load array to image
//    //    //    image.setFromPixels(data, w, h, OF_IMAGE_COLOR_ALPHA);
//    //    
//    //    //Aarray is not needed anymore, so clear memory
//    //    delete [] data;
//}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
