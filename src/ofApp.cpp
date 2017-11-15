#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.loadImage("skyline.png");
    strength = 0;
    gather = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = fireworks.size()-1;i>=0;i--)
    {
        if(fireworks[i].isFinished())
            fireworks.erase(fireworks.begin()+i);
        else
            fireworks[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0,0,ofGetWidth(),ofGetHeight());
   
    for(int i = fireworks.size()-1;i>=0;i--)
    {
        fireworks[i].draw();
    }
    
    ofDrawRectangle(0, ofGetHeight(), 15, -(strength/1000.0)*ofGetHeight());
    if(gather)
    {
        strength += 15;
        printf("%d",strength);
    }
    if(strength >= 1000)
        strength = 0;
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
    gather = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    fireworks.push_back(Firework(mouseX,mouseY,strength));
    strength = 0;
    gather = false;
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
