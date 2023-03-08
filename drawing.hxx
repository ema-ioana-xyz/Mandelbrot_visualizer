#pragma once
#include <vector>
#include "window.hxx"

namespace escript
{
    class Painter
    {
    public:
        Painter(escript::Window &targetWindow);
        std::vector<std::vector<escript::Color>> getMandelbrotSetPixels();
        void drawPixels(std::vector<std::vector<escript::Color>> pixels);
        void zoomIn();
        void zoomOut();
        void panRight();
        void panLeft();
        void panDown();
        void panUp();

    private:
        double zoomLevel = 1.0;
        double panValue = 0.25;
        Window &targetWindow;
        double complexHalfHeight;
        double complexHalfWidth;
        double horizontalOffset = 0;
        double verticalOffset = 0;

        double getStartingVerticalPosition();
        double getStartingHorizontalPosition();
        double getZoomFactor();
    };
};
