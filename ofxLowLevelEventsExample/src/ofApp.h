#pragma once

#include "ofMain.h"

//--------------------------------------------------------
class ofApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();

		void mouseMoved(int x, int y);
		void mouseMovedLL(ofMouseEventArgs & event);
		void windowResized(int w, int h);

        ofPoint windowCenter;
        ofPoint mousePosition;
        ofPoint screenSize;
        ofPoint windowSize;
        float mouseDirection;
        float circleSize;
        float triangleSize;
};

