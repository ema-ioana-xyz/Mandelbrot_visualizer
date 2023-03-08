#include <SDL2/SDL.h>
#include <cmath>
#include "color.hxx"

#include "window.hxx"

escript::WindowConfig::WindowConfig(int windowWidth, int windowHeight) : 
width(windowWidth), height(windowHeight) 
{}

int escript::WindowConfig::getWindowWidth() {
    return width;
}
int escript::WindowConfig::getWindowHeight() {
    return height;
}
void escript::WindowConfig::setWindowWidth(int windowWidth) {
    width = windowWidth;
}
void escript::WindowConfig::setWindowHeight(int windowHeight) {
    height = windowHeight;
}

escript::Window::Window(WindowConfig config) : config(config), drawingWidth(1900), drawingHeight(1350) {
    window = SDL_CreateWindow(
        "Mandelbrot Set Visualizer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config.getWindowWidth(),
        config.getWindowHeight(),
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RaiseWindow(window);
}

escript::Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void escript::Window::clearScreen(Color color) {
    SDL_SetRenderDrawColor(renderer, color.red(), color.green(), color.blue(), color.alpha());
    SDL_RenderClear(renderer);
}

void escript::Window::drawPixel(Color color, int xPosition, int yPosition) {
    SDL_SetRenderDrawColor(renderer, color.red(), color.green(), color.blue(), color.alpha());
    double drawingX = static_cast<double>(xPosition) / drawingWidth * config.getWindowWidth();
    drawingX = std::round(drawingX);
    double drawingY = static_cast<double>(yPosition) / drawingHeight * config.getWindowHeight();
    drawingY = std::round(drawingY);
    SDL_RenderDrawPoint(renderer, static_cast<int>(drawingX), static_cast<int>(drawingY));
}

void escript::Window::presentBuffer() {
    SDL_RenderPresent(renderer);
}

escript::WindowConfig& escript::Window::getConfig() {
    return this->config;
}

int escript::Window::getDrawingHeight() {
    return this->drawingHeight;
}

int escript::Window::getDrawingWidth() {
    return this->drawingWidth;
}