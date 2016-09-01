#include "system.h"
#include "object.h"
#include "text.h"

System::System()
{

}

System::~System()
{

}

bool System::InitSystem()
{
	//Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    else
    {
        //Create window
        window = SDL_CreateWindow( "Rojo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );

            return false;
        }

        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
            if( renderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                return false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    return false;
                }
            }
        }

    }

    return true;
}

void System::Render(GameObject* objectList, RText* text)
{


    //Clear screen
    SDL_RenderClear( renderer );

    objectList->Draw(renderer);


    if(text)
        text->Draw(renderer);
    //Update screen
    SDL_RenderPresent( renderer );
    

}

void System::EndSystem()
{
    SDL_DestroyRenderer( renderer );
    renderer = NULL;
	//Destroy window
    SDL_DestroyWindow( window );
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}