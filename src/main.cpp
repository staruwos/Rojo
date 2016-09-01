#include "system.h"
#include "player_rojo.h"
#include "object.h"
#include "text.h"
#include "input.h"


int main()
{

	System* system = new System();

	Input* inputSystem = new Input();

	if(system->InitSystem())
	{
		Rojo* rojo = new Rojo();
		rojo->LoadAssets(system->GetRenderer());
		/* Main loop variable flag */
		bool loop = true;
		
		/* Event handler */
		SDL_Event event;

		while(loop)
		{
			// Handle envets on queue
			while(SDL_PollEvent( &event ) != 0)
			{
				//User requests quit
				if( event.type == SDL_QUIT )
				{
					loop = false;
				}

				else if(event.type == SDL_KEYDOWN)
					inputSystem->ProcessInput(event);
			}

			system->Render(rojo, NULL);

		
		}

		system->EndSystem();

	}


	return 0;
}