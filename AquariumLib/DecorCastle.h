/**
 * @file DecorCastle.h
 * @author shash
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
#define AQUARIUM_AQUARIUMLIB_DECORCASTLE_H

#include "Item.h"

/**
 * Class DecorCastle
 * Class used to implement a Castle in the aquarium
 */
class DecorCastle : public Item
{
private:

public:
    /// Default constructor (disabled)
    DecorCastle() = delete;

    /// Copy constructor (disabled)
    DecorCastle(const DecorCastle &) = delete;
    DecorCastle(Aquarium* aquarium);
      /**
* Save the Castle attributes to an XML node.
*
* This function is responsible for saving the attributes of Castle
* instance to an XML node.
*
* @param node The XML node to which the attributes will be saved.
* @return The XML node with saved attributes.
*/
    wxXmlNode *XmlSave(wxXmlNode *node) override;

};

#endif //AQUARIUM_AQUARIUMLIB_DECORCASTLE_H
