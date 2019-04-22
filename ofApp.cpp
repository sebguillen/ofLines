#include "ofApp.h"

//--------------------------------------------------------------

// Similar implementation than ofFractals

void ofApp::setup(){
    
// SetCanvas
    ofSetWindowTitle ("Video synth");
    ofSetWindowShape (1280, 720);
    ofSetFrameRate (120); // 60 Hertz

//Set Graphic User Interface
    gui.setup ("Parameters", "settings.xml");
    gui.add (countX.setup ("countX", 50, 0, 200));
    gui.add (stepX.setup ("stepX", 20, 0, 200));
    gui.add (twistX.setup ("twistX", 5, -45, 45));
    gui.add (scaleX.setup ("scaleX", 0.5, 0, 20));
    gui.add (scaleY.setup ("scaleY", 0.2, 0, 20));

// Matrix pattern
    gui.add (countY.setup ("countY", 0, 0, 50));
    gui.add (stepY.setup ("stepY", 20, 0, 200));
    gui.add (twistY.setup ("twistY", 0, -30, 30));
    gui.add (pinchY.setup ("pinchY", 0, 0, 1));

// Set GUI Group
    globalGroup.setup ("Global");
    globalGroup.add (Scale.setup ("Scale", 1, 0.0, 1));
    globalGroup.add (Rotate.setup ("Rotate", 0, -180, 180));
    globalGroup.add (Background.setup ("Background", 255, 0, 255));
    gui.add (&globalGroup);
    
// primGroup
    primGroup.setup ("Primitive");
    primGroup.add (shiftY.setup ("shiftY", 0.0, -1000.0, 1000.0));
    primGroup.add (rotate.setup ("rotate", 0.0, -180.0, 180.0));

    primGroup.add (color.setup ("color",
                                ofColor::black,
                                ofColor (0, 0, 0, 0),
                                ofColor::white));
    primGroup.add (filled.setup ("filled", false));
    primGroup.add (type.setup ("type", false));
    gui.add (&primGroup);
    
 
    showGui = true;
    gui.loadFromFile ("settings.xml");
  
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float timer = ofGetElapsedTimef();
    float phase = sin (timer);

    
    shiftY = ofMap (ofNoise(timer), 0, 1, -500, 500);
    pinchY = ofMap (phase, -1, 1, 0, 1);

}


//--------------------------------------------------------------
void ofApp::stripePattern(){
    
    ofSetColor (color);
    ofSetLineWidth (1);
    if (filled) ofFill(); else ofNoFill();
    
    for (int i=-countX; i<countX; i++){
        ofPushMatrix();
        ofTranslate (i*stepX, 0);
        ofRotate (i * twistX);
        
        ofTranslate (0, shiftY);
        ofRotate (rotate);
        ofScale (scaleX, scaleY);
        
        if (type) ofDrawRectangle (-50, -50, 100, 100);
        else ofDrawTriangle(0, 0, -50, 100, 50, 100);
        ofPopMatrix();
    }
    }


void ofApp::matrixPattern(){
    
    for (int y =- countY; y <= countY; y++){
        ofPushMatrix();
        if (countY > 0){
            float scl = ofMap (y, -countY, countY, 1-pinchY, 1);
            ofScale (scl, scl);
        }
        ofTranslate (0, y * stepY);
        ofRotate (y * twistY);
        stripePattern();
        ofPopMatrix();
        }
    }


void ofApp::draw(){
    
    ofBackground (Background);
    float Scl = pow (Scale, 4.0f);

    // 1st shape
    ofPushMatrix();
    ofTranslate ( ofGetWidth() / 2, ofGetHeight() * 1/3);
    ofScale (Scl, Scl);
    ofRotate (Rotate);
    matrixPattern();
    ofPopMatrix();
    
    // 2nd shape
    ofPushMatrix();
    ofTranslate ( ofGetWidth() / 2, ofGetHeight() * 2/3 );
    ofScale (Scl, Scl);
    ofRotate (Rotate + 180);
    matrixPattern();
    ofPopMatrix();
    
    // 3rd shape
    ofPushMatrix();
    ofTranslate ( ofGetWidth() * 1/3, ofGetHeight() / 2 );
    ofScale (Scl, Scl);
    ofRotate (Rotate + 90);
    matrixPattern();
    ofPopMatrix();
    
    // 4th shape
    ofPushMatrix();
    ofTranslate ( ofGetWidth() * 2/3, ofGetHeight() / 2 );
    ofScale (Scl, Scl);
    ofRotate (Rotate - 90);
    matrixPattern();
    ofPopMatrix();
    
    // Gui
    if (showGui) gui.draw();

}

// To save presets
void ofApp::exit(){
    gui.saveToFile ("settings.xml");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
// Showcase the GUI panel
    if (key == 'z') showGui = !showGui;
// Save a screenshot in data folder
    if (key == OF_KEY_RETURN) ofSaveScreen ("screenshot.png");
// System save dialog to save presets
    if (key == 's'){
        ofFileDialogResult res;
        res = ofSystemSaveDialog("preset.xml", "Saving Preset");
        if (res.bSuccess) gui.saveToFile (res.filePath);
    }
// Loading a preset
    if (key == 'l'){
        ofFileDialogResult res;
        res = ofSystemLoadDialog ("Loading Preset");
        if (res.bSuccess) gui.loadFromFile (res.filePath);
    }

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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


