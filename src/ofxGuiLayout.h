
#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxXmlPoco.h"
#include "ofxPresets.h"


class ofxGuiLayout {
    
public:
    
    ofxGuiLayout();
    
    void addPanel(ofxPanel* panel);
    void addPanel(ofxPresets* panel);
    void saveLayout(string path);
    void loadLayout(string path);
    
private:
    
    vector<ofxPanel*> panels;
    // at the moment need another map for this class
    // TODO: make ofxPresets inherit from ofxPanel
    vector<ofxPresets*> panelsPreset;
};
