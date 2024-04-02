/**
 * @file Dory.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_DORY_H
#define AQUARIUM_AQUARIUMLIB_DORY_H

#include "Item.h"
#include "Fish.h"

/**
 * Class Dory
 * Class used to implement a Dory Fish (from Finding Nemo) in the aquarium
 */

class Dory : public Fish {
private:


public:
    /// Default constructor (disabled)
    Dory() = delete;

    /// Copy constructor (disabled)
    Dory(const Dory &) = delete;

    /// Assignment operator
    void operator=(const Dory &) = delete;

    Dory(Aquarium* aquarium);
    wxXmlNode* XmlSave(wxXmlNode* node) override;



};

#endif //AQUARIUM_AQUARIUMLIB_DORY_H
