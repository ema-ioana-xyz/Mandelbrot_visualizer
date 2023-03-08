#pragma once
#include <cstdint>
#include <SDL2/SDL.h>
#include "color.hxx"

namespace escript {
    class WindowConfig {
    private:
        int width;
        int height;
    public:
        WindowConfig(int windowWidth, int windowHeight);
        int getWindowWidth();
        int getWindowHeight();
        void setWindowWidth(int width);
        void setWindowHeight(int height);
};

class Window {
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;

        WindowConfig config;
        const int drawingWidth;
        const int drawingHeight;

    public:
        Window(WindowConfig config);
        ~Window();
        void clearScreen(Color color);
        void drawPixel(Color color, int xPosition, int yPosition);
        void presentBuffer();
        WindowConfig& getConfig();
        int getDrawingHeight();
        int getDrawingWidth();
};
};
