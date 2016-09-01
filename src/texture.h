#ifndef TEXTURE_H
#define TEXTURE_H

#include "system.h"

class RTexture
{
    public:
        //Initializes variables
        RTexture();

        //Deallocates memory
        ~RTexture();

        //Loads image at specified path
        bool loadFromFile(SDL_Renderer* gRenderer, std::string path );

        bool loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont  );

        //Deallocates RTexture
        void free();

        //Renders RTexture at given point
        void render( SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip = NULL );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware RTexture
        SDL_Texture* mRTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

#endif