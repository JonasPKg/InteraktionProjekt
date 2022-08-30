#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	camera.setDeviceID(0);
	camera.setup(40, 30);
	curFlow = &fb;

	//ab hier für Sender
	sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update() {
	camera.update();

	if (camera.isFrameNew()) {
		curFlow->calcOpticalFlow(camera);
		temp = (fb.getAverageFlow() * 40);
		vektorenWert = vektorenWert + temp;
	}

	//ab hier für Sender
	ofxOscMessage m;
	m.setAddress("/ball/position");
	m.addFloatArg(ofMap(positionX, 0, ofGetWidth(), 0.f, 1.f, true));
	m.addFloatArg(ofMap(positionY, 0, ofGetHeight(), 0.f, 1.f, true));
	sender.sendMessage(m, false);
}

//--------------------------------------------------------------
void ofApp::draw() {
	curFlow->draw(640, 0, -640, 480);
	ofDrawBitmapStringHighlight(ofToString(vektorenWert), 10, 30);
	ofDrawBitmapStringHighlight(ofToString(temp), 10, 10);
	if (vektorenWert.x <= 0 && vektorenWert.y >= 0) {
		if (vektorenWert.x < -640) {
			vektorenWert = vektorenWert - temp;
			//ofDrawCircle(-640, vektorenWert.y, BALL_SIZE);
			positionX = -640;
			positionY = vektorenWert.y;
		}
		else if (vektorenWert.y > 480) {
			vektorenWert = vektorenWert - temp;
			//ofDrawCircle(vektorenWert.x, 480, BALL_SIZE);
			positionX = vektorenWert.x;
			positionY = 480;
		}
		//ofDrawCircle((vektorenWert.x)*(-1), (vektorenWert.y), BALL_SIZE);
		positionX = vektorenWert.x * (-1);
		positionY = vektorenWert.y;
	}
	else if (vektorenWert.x > 0 && vektorenWert.y > 0) {
		vektorenWert = vektorenWert - temp;
		//ofDrawCircle(0, vektorenWert.y, BALL_SIZE);
		positionX = 0;
		positionY = vektorenWert.y;
	}
	else if (vektorenWert.x < 0 && vektorenWert.y < 0) {
		vektorenWert = vektorenWert - temp;
		//ofDrawCircle(vektorenWert.x * (-1), 0, BALL_SIZE);
		positionX = vektorenWert.x * (-1);
		positionY = 0;
	}
	else {
		vektorenWert = vektorenWert - temp;
		//ofDrawCircle(vektorenWert.x, vektorenWert.y, BALL_SIZE);
		positionX = vektorenWert.x;
		positionY = vektorenWert.y;
	}

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
