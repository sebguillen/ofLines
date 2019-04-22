#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    

	public:
    
    
		void setup();
		void update();
		void draw();
        void stripePattern();
        void exit();
        void matrixPattern();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    private :
    
    // GUI PANEL
    ofxPanel gui; // declare the container for all Graphic User Interface elements (GUI panel)
    ofxIntSlider countX; // slider that holds integer values
    ofxFloatSlider stepX; // slider that holds float values
    ofxFloatSlider twistX;
    ofxFloatSlider scaleX;
    ofxFloatSlider scaleY;

    // GUI GROUP PANEL
    ofxGuiGroup globalGroup;
    ofxFloatSlider Scale;
    ofxFloatSlider Rotate;
    ofxFloatSlider Background;
    
    //Ajust the geometric primitive's drawing parameters
    ofxGuiGroup primGroup; // declares the new group of controls
    ofxFloatSlider shiftY, rotate; // two float sliders
    ofxVec2Slider size; // 2D slider's size parameter
    ofxColorSlider color; // color seletor
    ofxToggle filled, type; // declares two checkboxes
    
    // Hiding the GUI panel
    bool showGui;
    
    // Matrix pattern
    ofxIntSlider countY;
    ofxFloatSlider stepY, twistY, pinchY;
    
    float posX, posY;
		
};
