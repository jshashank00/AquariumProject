/**
 * @file MainFrame.h
 * @author Shashank Jayaram
 *
 * The top-level (main) frame of the application
 */

#ifndef AQUARIUM_MAINFRAME_H
#define AQUARIUM_MAINFRAME_H
#include <wx/wx.h>

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:
    /**
     * Exit menu option handlers
     * @param event
     */
    void OnExit(wxCommandEvent& event);
    /**
    * About menu option handlers
    * @param event
    */
    void OnAbout(wxCommandEvent& event);
public:
    void Initialize();

};

#endif //AQUARIUM_MAINFRAME_H