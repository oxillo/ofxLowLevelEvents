ofxLowLevelEvents
=================

Description
-----------
ofxLowLevelEvents is an Open Frameworks addon that provides  capture the low level mouse and keyboard events.
This allows to receive mouse and keyboard events even if the event doesn't target your application (click/move outside the application window, application is minimized).
This is currently only tested with MSYS2.


Running the Example Project
---------------------------
TODO


Adding ofxLowLevelEvents to your project
----------------------------------------
add ofxLowLevelEvents to your addons.make file.
Add ofxLowLevelEvents.h to your ofApp.cpp file
Define the function to handle the event
void ofApp::mouseMovedLL(ofMouseEventArgs & event){
	ofLogNotice() << "Low Level Mouse Moved at (" << event.x << "," << event.y <<")";
}
Add event listener(s) in your setup() function
	ofAddListener(ofLowLevelEvents().mouseMoved, this, &ofApp::mouseMovedLL);

Enable low level events firing.
	ofLowLevelEvents().enable();

Notes
-----

Contributing 
------------

ofxLowLevelEvents was originally developped by Olivier XILLO (oxillo@hotmail.com)
Feel free to reports bugs and issues to him
