/**
 * @file FishBeta.cpp
 * @author Shashank Jayaram
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"
#include "Item.h"

using namespace std;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";


/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"beta");

    return itemNode;



}



