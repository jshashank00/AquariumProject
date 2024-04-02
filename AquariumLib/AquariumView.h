/**
 * @file AquariumView.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H

#include "Aquarium.h"

/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow
{
private:
    void OnPaint(wxPaintEvent& event);
    /// An object that describes our aquarium
    Aquarium  mAquarium;
    void OnAddFishBetaFish(wxCommandEvent& event);
    void OnAddFishBubbleFish(wxCommandEvent& event);
    void OnAddDory(wxCommandEvent& event);
    void OnAddCastle(wxCommandEvent& event);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;
    ///does the timer functionality
    /// @param event
    void OnTimer(wxTimerEvent& event);




    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

public:
    void Initialize(wxFrame* parent);

    void OnFileSaveAs(wxCommandEvent &event);
    void OnFileOpen(wxCommandEvent &event);
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
