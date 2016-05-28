#define OFX_ADDON "ofxLowLevelEvents"

#include "ofxLowLevelEvents.h"
#include "ofLog.h"



HHOOK LowLevelMouseHook;

LRESULT CALLBACK LowLevelMouseHookProc(int nCode, WPARAM wParam, LPARAM lParam){
    if(nCode == HC_ACTION){
        MOUSEHOOKSTRUCT * pMouseStruct = (MOUSEHOOKSTRUCT *)(lParam);
        if(pMouseStruct != NULL){
            if(wParam == WM_LBUTTONDOWN){
                ofLogNotice() <<  "clicked";
            }

            if(wParam == WM_RBUTTONDOWN){
                ofLogNotice() <<  "Right clicked";
            }
            if(wParam == WM_MOUSEMOVE){
                POINT mousePosition = pMouseStruct->pt;
                ofMouseEventArgs mouseEventArgs(ofMouseEventArgs::Moved, mousePosition.x, mousePosition.y, 0);
                ofNotifyEvent(ofLowLevelEvents().mouseMoved, mouseEventArgs);
            }
        }
    }
    // Call the next hook in the chain
    return CallNextHookEx(LowLevelMouseHook, nCode, wParam, lParam);
}

 //WM_LBUTTONDOWN, WM_LBUTTONUP, WM_MOUSEMOVE, WM_MOUSEWHEEL, WM_MOUSEHWHEEL, WM_RBUTTONDOWN, or WM_RBUTTONUP.
/*switch(mouseEvent.type){
	case ofMouseEventArgs::Moved:
		notifyMouseMoved(mouseEvent.x,mouseEvent.y);
		break;
	case ofMouseEventArgs::Dragged:
		notifyMouseDragged(mouseEvent.x,mouseEvent.y,mouseEvent.button);
		break;
	case ofMouseEventArgs::Pressed:
		notifyMousePressed(mouseEvent.x,mouseEvent.y,mouseEvent.button);
		break;
	case ofMouseEventArgs::Released:
		notifyMouseReleased(mouseEvent.x,mouseEvent.y,mouseEvent.button);
		break;
	case ofMouseEventArgs::Scrolled:
		notifyMouseScrolled(mouseEvent.x,mouseEvent.y,mouseEvent.scrollX,mouseEvent.scrollY);
		break;
	case ofMouseEventArgs::Entered:
		notifyMouseEntered(mouseEvent.x,mouseEvent.y);
		break;
	case ofMouseEventArgs::Exited:
		notifyMouseExited(mouseEvent.x,mouseEvent.y);
		break;
}*/









ofxLowLevelWinEvents::ofxLowLevelWinEvents(){}


ofxLowLevelWinEvents::~ofxLowLevelWinEvents(){
	disable();
}


void ofxLowLevelWinEvents::enable(){
	if(LowLevelMouseHook){
		return;	// already hooked
	}

	//Register Low Level Mouse hook
	LowLevelMouseHook = SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseHookProc, GetModuleHandle(NULL), 0);
	if(LowLevelMouseHook){
		ofLogNotice(OFX_ADDON) << "Capturing low level mouse events";
	}else{
		ofLogError(OFX_ADDON) << "Cannot capture low level mouse events";
	}
}

void ofxLowLevelWinEvents::disable(){
	if(LowLevelMouseHook){
		UnhookWindowsHookEx(LowLevelMouseHook);
		LowLevelMouseHook = (HHOOK)0;
	}
}


ofxLowLevelWinEvents lowLevelEvents;

ofxLowLevelWinEvents & ofLowLevelEvents(){
	return lowLevelEvents;
}

