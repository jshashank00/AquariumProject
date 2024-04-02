/**
 * @file Fish.cpp
 * @author shash
 */
#include "pch.h"
#include "Fish.h"
#include <random>
#include "Aquarium.h"
#include "Item.h"

/// Maximum speed of Beta
/// in pixels per second
const double MaxSpeedBeta = 35;

/// Minimum speed of Beta
/// pixels per second
const double MinSpeedBeta = 30;


/// Maximum speed of Dory
/// in pixels per second
const double MaxSpeedDory = 85;
/// Maximum speed of BubbleFish
/// in pixels per second
const double MaxSpeedBubble = 10;
/// Minimum speed of Dory
/// pixels per second
const double MinSpeedDory = 70;
/// Minimum speed of Bubble
/// pixels per second
const double MinSpeedBubble = 5;

Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
    Item(aquarium, filename)
{
    if (filename == L"images/dory.png")
    {
        std::uniform_real_distribution<> distribution(MinSpeedDory, MaxSpeedDory);
        mSpeedX = distribution(aquarium->GetRandom());
        mSpeedY = distribution(aquarium->GetRandom());
    }
    if (filename == L"images/bubbles.png")
    {
        std::uniform_real_distribution<> distribution(MinSpeedBubble, MaxSpeedBubble);
        mSpeedX = distribution(aquarium->GetRandom());
        mSpeedY = distribution(aquarium->GetRandom());
    }
    if (filename == L"images/beta.png")
    {
        std::uniform_real_distribution<> distribution(MinSpeedBeta, MaxSpeedBeta);
        mSpeedX = distribution(aquarium->GetRandom());
        mSpeedY = distribution(aquarium->GetRandom());
    }

}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */

void Fish::Update(double elapsed)
{
    // Update Oscillation for vertical movement
    mOscillation += elapsed;

    // Compute new position
    double newX = GetX() + mSpeedX * elapsed;
    double oscY = 30.0 * sin(mOscillation) * elapsed;
    double newY = GetY() + oscY;

    // Horizontal boundary checks
    double maxAllowedX = GetAquarium()->GetWidth() - 10 - FishWid() / 2;
    if (newX >= maxAllowedX)
    {
        mSpeedX = -mSpeedX;
        SetMirror(true);
        newX = maxAllowedX;
    }
    else if (newX <= 10 + FishWid() / 2)
    {
        mSpeedX = -mSpeedX;
        SetMirror(false);
        newX = 10 + FishWid() / 2;
    }



    if (newY <= FishHeight() / 2)
    {
        newY = FishHeight() / 2 + 1;
    }
    else if (newY >= GetAquarium()->GetHeight() - FishHeight() / 2)
    {
        newY =GetAquarium()->GetHeight() - FishHeight() / 2 - 1;
    }

    // Set the new position
    SetLocation(newX, newY);
}


wxXmlNode* Fish::XmlSave(wxXmlNode* node) {
    auto itemNode = Item::XmlSave(node);


    itemNode->AddAttribute(L"speedX", wxString::FromDouble(mSpeedX));
    itemNode->AddAttribute(L"speedY", wxString::FromDouble(mSpeedY));

    return itemNode;
}

void Fish::XmlLoad(wxXmlNode* node) {
    Item::XmlLoad(node);

    wxString speedX, speedY;
    if (node->GetAttribute(L"speedX", &speedX) && node->GetAttribute(L"speedY", &speedY)) {
        speedX.ToDouble(&mSpeedX);
        speedY.ToDouble(&mSpeedY);
    }
}