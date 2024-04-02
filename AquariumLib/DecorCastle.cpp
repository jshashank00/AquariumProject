/**
 * @file DecorCastle.cpp
 * @author shash
 */
#include "pch.h"
#include "DecorCastle.h"
#include "Aquarium.h"
#include "Item.h"

using namespace std;

/// Fish filename
const wstring DecorCastleImageName = L"images/castle.png";

/**
 * Constructor
 * @param aquarium Aquarium this decor is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorCastleImageName)
{

}

wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"type", L"castle");

    return itemNode;



}