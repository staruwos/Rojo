#include <stdio.h>
#include "texture.h"


RTexture::RTexture()
{
	//Initialize
	mRTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

RTexture::~RTexture()
{
	//Deallocate
	free();
}

bool RTexture::loadFromFile(SDL_Renderer* gRenderer, std::string path )
{
	//Get rid of preexisting RTexture
	free();

	//The final RTexture
	SDL_Texture* newRTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create RTexture from surface pixels
        newRTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newRTexture == NULL )
		{
			printf( "Unable to create RTexture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mRTexture = newRTexture;
	return mRTexture != NULL;
}

bool RTexture::loadFromRenderedText( std::string textureText, SDL_Color textColor, SDL_Renderer* gRenderer, TTF_Font* gFont )
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mRTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mRTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return mRTexture != NULL;
}

void RTexture::free()
{
	//Free RTexture if it exists
	if( mRTexture != NULL )
	{
		SDL_DestroyTexture( mRTexture );
		mRTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void RTexture::render( SDL_Renderer* gRenderer, int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( gRenderer, mRTexture, clip, &renderQuad );
}

int RTexture::getWidth()
{
	return mWidth;
}

int RTexture::getHeight()
{
	return mHeight;
}