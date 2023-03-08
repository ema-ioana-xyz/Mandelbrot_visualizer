#include <complex>
#include <iostream>

#include "drawing.hxx"
#include "fractalMath.hxx"
#include "color.hxx"

double escript::Painter::getStartingVerticalPosition() {
    double position = -1.0 * complexHalfHeight;
    position *= getZoomFactor();
    position += verticalOffset;
    return position;
}

double escript::Painter::getStartingHorizontalPosition() {
    double position = -1.0 * complexHalfWidth;
    position *= getZoomFactor();
    position += horizontalOffset;
    return position;
}

double escript::Painter::getZoomFactor() {
    return 1.0 / zoomLevel;
}

escript::Painter::Painter(escript::Window& targetWindow) : targetWindow(targetWindow){
    complexHalfHeight = 1.1;
    zoomLevel = 1.0;
    panValue = 0.25;
    horizontalOffset = 0;
    verticalOffset = 0;
    complexHalfWidth = complexHalfHeight * targetWindow.getDrawingWidth() / targetWindow.getDrawingHeight();
}

std::vector<std::vector<escript::Color>> escript::Painter::getMandelbrotSetPixels() {
    const auto rowCount = targetWindow.getDrawingHeight();
    const auto columnCount = targetWindow.getDrawingWidth();
    const double zoomFactor = 1.0 / zoomLevel;
    const double horizontalStep = 2.0 * complexHalfWidth * zoomFactor / columnCount;
    const double verticalStep = 2.0 * complexHalfHeight * zoomFactor / rowCount;
    double horizontalPosition = getStartingHorizontalPosition();
    double verticalPosition = getStartingVerticalPosition();

    const Color catppuccinPink(0xf5, 0xbd, 0xe6);
    const Color catppuccinBase(0x1e, 0x20, 0x30);

    // std::cout << horizontalPosition << " " << verticalPosition << 
    // " " << horizontalStep << " " << verticalStep << std::endl;

    using rowT = std::vector<Color>;

    std::vector<rowT> pixels(rowCount, rowT(columnCount, Color(0x00, 0x00, 0x00)));
 
    for(rowT& row : pixels) {
        for(Color& pixel : row) {
            auto currentNumber = std::complex<double>(horizontalPosition, verticalPosition);
            int maxIter = 50;
            int escapeTime = Mandelbrot::iterationsUntilEscape(currentNumber, maxIter);
            // double value = -1.0 * std::exp(-escapeTime / maxIter) * 0xFF;
            double value = 1.0 * escapeTime / maxIter;
            pixel = Color::interpolate(catppuccinBase, catppuccinPink, value);
            //pixel = Color(0xFF, 0xAA, value);
            
            horizontalPosition += horizontalStep;
        }
        horizontalPosition = getStartingHorizontalPosition();
        verticalPosition += verticalStep;
    }
    return pixels;
}

void escript::Painter::drawPixels(std::vector<std::vector<escript::Color>> pixels) {
    const auto pink = Color(0x55, 0x55, 0x55);
    const auto height = targetWindow.getDrawingHeight();
    const auto width = targetWindow.getDrawingWidth();
    targetWindow.clearScreen(pink);
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            Color color = pixels[i][j];
            targetWindow.drawPixel(color, j, height - i);
        }
    }
    targetWindow.presentBuffer();
}

void escript::Painter::zoomIn() {
    zoomLevel += 1;
}

void escript::Painter::zoomOut() {
    if(zoomLevel >= 2){
        zoomLevel -= 1;
    }
}

void escript::Painter::panRight() {
    double change = complexHalfWidth * panValue * (1/zoomLevel);
    horizontalOffset += change;
}

void escript::Painter::panLeft() {
    double change = complexHalfWidth * panValue * (1/zoomLevel);
    horizontalOffset -= change;
}

void escript::Painter::panUp() {
    double change = complexHalfHeight * panValue * (1/zoomLevel);
    verticalOffset += change;
}

void escript::Painter::panDown() {
    double change = complexHalfHeight * panValue * (1/zoomLevel);
    verticalOffset -= change;
}