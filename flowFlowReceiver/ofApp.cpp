#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update() {
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(m);

		if (m.getAddress() == "/ball/position") {

			ballXf = m.getArgAsFloat(0);
			ballYf = m.getArgAsFloat(1);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	glm::vec3 posIn(ballXf*ofGetWidth(), ballYf*ofGetHeight(), 0);
	ofDrawCircle(posIn, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
