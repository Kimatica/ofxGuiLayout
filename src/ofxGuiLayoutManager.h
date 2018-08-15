
#pragma once

#include "ofMain.h"
#include "ofxGui.h"
//#include "GuiPresets.h"

class ofxGuiLayoutManager {
    
public:
    
    ofxGuiLayoutManager();
    
//    void addPanel(ofxPanel* panel, string key);
//    void addPanel(GuiPresets* panel, string key);
    void addPanel(ofxPanel* panel);
    void addPanel(GuiPresets* panel);
    void saveLayout(string path);
    void loadLayout(string path);
    
private:
    
    vector<ofxPanel*> panels;
    // at the moment need another map for this class
    // TODO: make GuiPresets inherit from ofxPanel
    //vector<GuiPresets*> panelsPreset;
};
