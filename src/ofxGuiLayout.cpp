#include "ofxGuiLayout.h"

void ofxGuiLayout::addPanel(ofxPanel* panel)
{
    panels.push_back(panel);
}

void ofxGuiLayout::loadLayout(string path)
{
    ofXml xml;
    bool bLoaded = xml.load(path);
    if (!bLoaded) return;
    
    auto layout = xml.getChild("layout");
    if (!layout) return;
    
    for (auto& panel : panels) {
        auto xmlPanel = layout.findFirst("panel[@name='" + panel->getName() + "']");
        if (xmlPanel) {
            panel->setPosition(
                xmlPanel.getChild("x").getFloatValue(),
                xmlPanel.getChild("y").getFloatValue()
            );
        }
    }
}

void ofxGuiLayout::saveLayout(string path)
{
    ofXml xml;
    auto layout = xml.appendChild("layout");
    
    for (auto& panel : panels) {
        auto xmlPanel = layout.appendChild("panel");
        xmlPanel.setAttribute("name", panel->getName());
        xmlPanel.appendChild("x").set(panel->getPosition().x);
        xmlPanel.appendChild("y").set(panel->getPosition().y);
    }
    xml.save(path);
}
