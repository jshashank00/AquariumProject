/**
 * @file FishBeta.h
 * @author Shashank Jayaram
 */



#ifndef AQUARIUM_FISHBETA_H
#define AQUARIUM_FISHBETA_H

#include "Item.h"
#include "Fish.h"

/**
 * Class FishBeta
 * Class used to implement a Beta Fish in the aquarium
 */
class FishBeta : public Fish {
private:


public:
    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    /// Assignment operator
    void operator=(const FishBeta &) = delete;

    FishBeta(Aquarium *aquarium);

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISHBETA_H
