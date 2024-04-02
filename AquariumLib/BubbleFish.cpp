/**
 * @file BubbleFish.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "BubbleFish.h"
#include "Aquarium.h"

using namespace std;

/// Fish filename
const wstring BubbleFishImageName = L"images/bubbles.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
BubbleFish::BubbleFish(Aquarium *aquarium) : Fish(aquarium, BubbleFishImageName)
{

}

wxXmlNode* BubbleFish::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"bubble");

    return itemNode;



}


