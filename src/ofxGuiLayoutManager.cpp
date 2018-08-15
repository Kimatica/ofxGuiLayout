
#include "ofxGuiLayoutManager.h"


ofxGuiLayoutManager::ofxGuiLayoutManager(){
}


void ofxGuiLayoutManager::addPanel(ofxPanel* panel){
    panels.push_back(panel);
}


void ofxGuiLayoutManager::addPanel(GuiPresets* panel){
    panelsPreset.push_back(panel);
}


void ofxGuiLayoutManager::loadLayout(string path){
    ofXml xml;
    xml.load(path);
    
    // iterate the regular panels
    for(int i=0; i<panels.size(); i++){
        ofxPanel* panel = panels[i];
        
        xml.setTo("//"); // = xml.reset()
        
        // if exists on the xml
        if(xml.exists("//[@name='" + panel->getName() + "']")){
            xml.setTo("//[@name='" + panel->getName() + "']");
            
            float x = xml.getValue<float>("x");
            float y = xml.getValue<float>("y");
            
            // setup the panel with the stored position
            //panel->setup(name, name+"-settings.xml", x, y);
            panel->setPosition(x, y);
        }else{
            // not saved position for this panel
        }
    }
    
    // iterate the preset panels
//    for(int i=0; i<panelsPreset.size(); i++){
//        GuiPresets* panel = panelsPreset[i];
//
//        xml.setTo("//"); // = xml.reset()
//
//        // if exists on the xml
//        if(xml.exists("//[@name='" + panel->getName() + "']")){
//            xml.setTo("//[@name='" + panel->getName() + "']");
//
//            float x = xml.getValue<float>("x");
//            float y = xml.getValue<float>("y");
//
//            // setup the panel with the stored position
//            panel->setPosition(ofPoint(x,y));
//        }else{
//            // not saved position for this panel
//        }
//    }
}


void ofxGuiLayoutManager::saveLayout(string path){
    int num_panels = 0;
    
    ofXml xml;
    xml.addChild("layout");
    
    for(int i=0; i<panels.size(); i++){
        ofxPanel* panel = panels[i];
        
        xml.setTo("//layout");
        xml.addChild("panel");
        xml.setTo("panel[" + ofToString(num_panels) + "]");
        xml.setAttribute("name", panel->getName());
        xml.addValue("x", panel->getPosition().x);
        xml.addValue("y", panel->getPosition().y);
        
        num_panels++;
    }
    
//    for(int i=0; i<panelsPreset.size(); i++){
//        GuiPresets* panel = panelsPreset[i];
//
//        xml.setTo("//layout");
//        xml.addChild("panel");
//        xml.setTo("panel[" + ofToString(num_panels) + "]");
//        xml.setAttribute("name", panel->getName());
//        xml.addValue("x", panel->getPosition().x);
//        xml.addValue("y", panel->getPosition().y);
//
//        num_panels++;
//    }
    
    xml.save(path);
}