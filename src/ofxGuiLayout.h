#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class ofxGuiLayout {
    
public:
    
    void addPanel(ofxPanel* panel);
    void saveLayout(string path);
    void loadLayout(string path);
    
private:
    
    vector<ofxPanel*> panels;
};
