/**
 * @file Item.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_ITEM_H
#define AQUARIUM_AQUARIUMLIB_ITEM_H
class Aquarium;

/**
* Base class for items in the aquarium
*/
class Item {
private:
    /// The aquarium this item is contained in
    Aquarium   *mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item
    /// The underlying fish image

    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mItemBitmap;

    bool mMirror = false;   ///< True mirrors the item image




protected:
    Item(Aquarium* aquarium, const std::wstring &filename);

public:
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    ~Item();

    /**
     * The X location of the item
     * @returns X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @returns Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual void Draw(wxDC *dc);

    virtual bool HitTest(int x, int y);

    /**
     * Get the pointer to the Aquarium object
     * @return Pointer to Aquarium object
     */
    Aquarium *GetAquarium() { return mAquarium;  }
    /**
     * Get width of Fish
     * @return Width of Fish
     */
    int FishWid() {return( mItemBitmap -> GetWidth());};
    /**
    * Get height of Fish
    * @return Height of Fish
    */
    int FishHeight() {return( mItemBitmap -> GetHeight());};
    virtual wxXmlNode *XmlSave(wxXmlNode *node);
    virtual void XmlLoad(wxXmlNode *node);
    /**
  * Handle updates for animation
  * @param elapsed The time since the last update
  */
    virtual void Update(double elapsed) {}
    void SetMirror(bool m);
};

#endif //AQUARIUM_AQUARIUMLIB_ITEM_H
