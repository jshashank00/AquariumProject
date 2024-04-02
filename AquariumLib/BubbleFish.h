/**
 * @file BubbleFish.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_BUBBLEFISH_H
#define AQUARIUM_AQUARIUMLIB_BUBBLEFISH_H

#include "Item.h"
#include "Fish.h"
/**
 * Class BubbleFish
 * Class used to implement a Bubble Fish in the aquarium
 */
class BubbleFish : public Fish {
private:


public:
    /// Default constructor (disabled)
    BubbleFish() = delete;

    /// Copy constructor (disabled)
    BubbleFish(const BubbleFish &) = delete;

    /// Assignment operator
    void operator=(const BubbleFish &) = delete;

    BubbleFish(Aquarium* aquarium);

    /**
 * Save the BubbleFish attributes to an XML node.
 *
 * This function is responsible for saving the attributes of a BubbleFish
 * instance to an XML node.
 *
 * @param node The XML node to which the attributes will be saved.
 * @return The XML node with saved attributes.
 */
    wxXmlNode *XmlSave(wxXmlNode *node) override;
};

#endif //AQUARIUM_BUBBLEFISH_H
