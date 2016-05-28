#include "ofApp.h"
#include "ofxLowLevelEvents.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// Center the window on the screen
	screenSize.x = ofGetScreenWidth();
	screenSize.y = ofGetScreenHeight();
	windowSize.x = ofGetWidth();
	windowSize.y = ofGetHeight();

	windowCenter = screenSize * 0.5;

	ofPoint topLeftCorner = windowCenter - (windowSize * 0.5);
	ofSetWindowPosition(topLeftCorner.x, topLeftCorner.y);
	ofSetWindowTitle("Cat assistant / Mouse finder");


	ofLowLevelEvents().enable();
	ofAddListener(ofLowLevelEvents().mouseMoved, this, &ofApp::mouseMovedLL);

	//ofBackground(40, 40, 40);
	mouseDirection = 0;

	//
}

//--------------------------------------------------------------
void ofApp::update(){
    // Update the center in update as there is no event for window position
    windowCenter.x = ofGetWindowPositionX() + (0.5 * windowSize.x);
    windowCenter.y = ofGetWindowPositionY() + (0.5 * windowSize.y);
    circleSize = 0.5 * min(windowSize.x, windowSize.y); // Biggest circle that fits in the window
    triangleSize = 0.8 * circleSize; // 80% of the circle size

	ofVec3f yAxis(0,1,0);
	mouseDirection = yAxis.angle(mousePosition - windowCenter);
	// angle is unsigned so we set the sign depending on which side of the y-Axis the mouse is
	if(mousePosition.x >= windowCenter.x){
		mouseDirection = -mouseDirection;
	}
	// Increase circle resolution for smoother circles
	ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,0,0);
    ofFill();
    //ofTranslate(240,240,0);
    ofTranslate(windowSize * 0.5);
    ofDrawCircle(0,0,circleSize);
    ofSetColor(100,100,100);
    ofDrawCircle(0,0,triangleSize);
    ofPushMatrix();
        ofRotate(mouseDirection);
        ofSetColor(255,0,0);
        ofDrawTriangle(-triangleSize * 0.3 , 0, 0, triangleSize, triangleSize * 0.3, 0.0);
    ofPopMatrix();
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

void ofApp::mouseMovedLL(ofMouseEventArgs & event){
    mousePosition.x = event.x;
    mousePosition.y = event.y;
}


void ofApp::windowResized(int w, int h){
    windowSize.x = w;
    windowSize.y = h;
}

