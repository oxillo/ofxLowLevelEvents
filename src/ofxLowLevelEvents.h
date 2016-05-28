#pragma once

#include "ofEvent.h"
#include "ofEvents.h"	// for ofMouseEventArgs

class ofxLowLevelWinEvents{
	public:
		ofxLowLevelWinEvents();
		~ofxLowLevelWinEvents();
		//void setup();
		void enable();
		void disable();

		ofEvent<ofMouseEventArgs> mouseMoved;
};

ofxLowLevelWinEvents & ofLowLevelEvents();
