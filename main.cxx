#include <SDL2/SDL.h>
#include "window.hxx"
#include "drawing.hxx"

using namespace escript;

bool handleKeyDown(SDL_Event& event, Painter& painter) {
    switch(event.key.keysym.sym) {
        case SDLK_DOWN:
            painter.panDown();
            break;
        case SDLK_UP:
            painter.panUp();
            break;
        case SDLK_LEFT:
            painter.panLeft();
            break;
        case SDLK_RIGHT:
            painter.panRight();
            break;
        case SDLK_PLUS:
        case SDLK_KP_PLUS:
            painter.zoomIn();
            break;
        case SDLK_MINUS:
        case SDLK_KP_MINUS:
            painter.zoomOut();
            break;
        case SDLK_KP_MULTIPLY:
        case SDLK_KP_DIVIDE:
            break;
        default:
            return false;
    }
    return true;
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window window(WindowConfig(1900, 1350));
    window.clearScreen(Color(0xFF, 0xAA, 0xFF));
    window.presentBuffer();

    Painter painter(window);
    auto pixels = painter.getMandelbrotSetPixels();
    
    SDL_Event event;
    while(true) {
        painter.drawPixels(pixels);
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    SDL_Quit();
                    return 0;
                case SDL_KEYDOWN:
                    if(handleKeyDown(event, painter)){
                        window.clearScreen(Color(0xb7, 0xbd, 0xf8));
                        window.presentBuffer();
                        pixels = painter.getMandelbrotSetPixels();
                    }
            }
        }
        SDL_Delay(20);
    }
}