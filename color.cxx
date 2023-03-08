#include <SDL2/SDL.h>
#include <cstdint>
#include "color.hxx"

escript::Color::Color(uint8_t red, uint8_t green, uint8_t blue) : 
redValue(red), greenValue(green), blueValue(blue), alphaValue(SDL_ALPHA_OPAQUE)
{}

escript::Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : 
redValue(red), greenValue(green), blueValue(blue), alphaValue(alpha)
{}

escript::Color escript::Color::interpolate(const Color& start, const Color& stop, double fraction) {
   double red = (stop.red() - start.red()) * fraction + start.red();
   double green = (stop.green() - start.green()) * fraction + start.green();
   double blue = (stop.blue() - start.blue()) * fraction + start.blue();

   return Color(static_cast<u_int8_t>(red), static_cast<u_int8_t>(green), static_cast<u_int8_t>(blue));
}

uint8_t escript::Color::red() const {return this->redValue;}
uint8_t escript::Color::green() const {return this->greenValue;}
uint8_t escript::Color::blue() const {return this->blueValue;}
uint8_t escript::Color::alpha() const {return this->alphaValue;}