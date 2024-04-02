/**
 * @file Fish.h
 * @author shash
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISH_H
#define AQUARIUM_AQUARIUMLIB_FISH_H

#include "Item.h"
#include <wx/dcbuffer.h>
/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:

    /// Fish speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY;
    /// Oscillates the fish  in the Y direction
    /// in pixels per second
    double mOscillation = 0.0;

protected:

    /**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
   Fish(Aquarium *aquarium, const std::wstring &filename) ;



public:
    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;

    /// Assignment operator
    void operator=(const Fish &) = delete;


    void Update(double elapsed);
    /**
* Save the Fish attributes to an XML node.
*
* This function is responsible for saving the attributes of Fish
* instance to an XML node.
*
* @param node The XML node to which the attributes will be saved.
* @return The XML node with saved attributes.
*/
    wxXmlNode* XmlSave(wxXmlNode* node) ;
    /**
* Loads the Fish attributes  XML node.
*
* This function is responsible for loading the attributes of Fish
* instance from an XML node
*
* @param node The XML node to which the attributes will be saved.
*
*/

    void XmlLoad(wxXmlNode* node);

};

#endif //AQUARIUM_AQUARIUMLIB_FISH_H
