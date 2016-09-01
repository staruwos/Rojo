#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "system.h"

//Loads individual image as texture
SDL_Texture* loadTexture( SDL_Renderer* Renderer, std::string path );

#endif