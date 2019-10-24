#ifndef ENV_LIB_DRAWINGAREA_H
#define ENV_LIB_DRAWINGAREA_H

#include "LASSIE.h"

class EnvelopeLibraryEntry;
class EnvLibEntrySeg;
class EnvLibEntryNode;
class EnvelopeLibraryWindow;
class EnvLibDrawingArea : public Gtk::DrawingArea {
public:
    explicit EnvLibDrawingArea(EnvelopeLibraryWindow* _envelopeLibraryWindow);

    ~EnvLibDrawingArea() override;
    void resetFields();
    void showGraph(EnvelopeLibraryEntry* _envelope);
    void clearGraph();
    bool mouseMoving(GdkEventMotion* event);
    void setActiveNodeCoordinate(const string& _x, const string& _y);
    void adjustBoundary(EnvelopeLibraryEntry* _envelope);

protected:
    // Override default signal handler:
    bool on_expose_event(GdkEventExpose* event) override;

    bool mouseButtonPressed(GdkEventButton* event);
    bool mouseButtonReleased(GdkEventButton* event);
    bool mouseLeftButtonPressedDown;

    double mouseY = 0.0;  // temp variables for exchanging values among methods;
    double mouseX = 0.0;

    void moveNode();
    void insertEnvelopeSegment();
    void removeNode();
    void setFlexible();
    void setFixed();
    void setLinear();
    void setExponential();
    void setSpline();
    double getAdjustedY(double y);  // scale coordinates in a larger window to a range of 0-1
    double mouseAdjustY(double y);  // scale mouse coordinates from 0-1 to the true height
private:
    EnvelopeLibraryWindow* envelopeLibraryWindow = nullptr;

    // these three are for setting up pop up menu
    Glib::RefPtr<Gtk::UIManager> m_refUIManager;
    Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
    Gtk::Menu* m_pMenuPopup = nullptr;

    EnvLibEntrySeg* activeSegment = nullptr;
    EnvLibEntryNode* activeNode = nullptr;

    double moveLeftBound = 0.0;
    double moveRightBound = 0.0;
    double upperY = 0.0;  // the max and min y values for envolope above 1 and below 0
    double lowerY = 0.0;
    EnvLibEntrySeg* head = nullptr;
    EnvLibEntryNode* tail = nullptr;
};

#endif
