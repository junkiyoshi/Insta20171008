#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();
	
	ofVec3f prev_point = ofVec3f();
	float z = 0;
	for (float deg = 0; deg < 360 * 5; deg += 1) {

		float x = 350 * cos(deg * DEG_TO_RAD);
		float y = 350 * sin(deg * DEG_TO_RAD);

		float noise_value = ofNoise((z + ofGetFrameNum()) * 0.25);

		if (noise_value > 0.5 && noise_value < 0.6) {
			x = 350 * ofMap(noise_value, 0.5, 0.6, 1.5, 0.5) * cos(deg * DEG_TO_RAD);
			y = 350 * ofMap(noise_value, 0.5, 0.6, 1.5, 0.5) * sin(deg * DEG_TO_RAD);
		}

		if (deg != 0) { 
			ofSetColor(255, 255 + z / (360 * 5) * 255);
			ofLine(ofVec3f(x, y, z), prev_point);
		}

		z -= 1;
		prev_point = ofVec3f(x, y, z);
	}

	this->cam.end();
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
