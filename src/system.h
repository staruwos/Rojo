#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "INIReader.h"


/* Screen dimensions constants */
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class System
{
	public:
		System();
		~System();

		bool InitSystem();

		void Render(class GameObject* objectList, class RText* text);

		void EndSystem();

		SDL_Window* GetWindow() { return window; };
		SDL_Renderer* GetRenderer() { return renderer; };

	private:
		SDL_Window *window;
		SDL_Renderer *renderer;

		SDL_Surface* screenSurface;

};

#endif