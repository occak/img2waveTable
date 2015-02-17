#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(55);

    
    image.loadImage("merzbow.png");
//    image.resize(image.getWidth()/2, image.getHeight()/2);
    int w = image.getWidth();
    int h = image.getHeight();
    wavetable.resize(w*h);
    
    
    ofSoundStreamSetup(1, 0, this, 44100, 1024, 4);
    phase = 0;
    
    
    
    for(int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
        
            ofColor c = image.getColor(i, j);
            float c_ = c.getBrightness();
            wavetable[j+(i*h)] = ofMap(c_,0,255,-1,1);
            waveShape.addVertex(ofMap(j+(i*h), 0, wavetable.size() - 1, ofGetWidth()/2-image.getWidth()/2, ofGetWidth()/2+image.getWidth()/2),                                ofMap(wavetable[j+(i*h)], -1, 1, image.getHeight(), ofGetHeight()));
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    image.draw(ofGetWidth()/2-image.getWidth()/2,0);
    
    waveShape.draw();
    

}

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

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    
    float sampleRate = 44100;
    float phaseStep = bufferSize/sampleRate;

    for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
        phase += phaseStep;
        int wavetableIndex = (int) (phase * wavetable.size()) % wavetable.size();
        output[i] = wavetable[wavetableIndex]*.8;
    }
    
}
