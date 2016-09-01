#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "math.h"


class Rojo : public GameObject {

public:
		Rojo();
		~Rojo();

		virtual void Draw(SDL_Renderer* gRenderer);
		virtual void LoadAssets(SDL_Renderer* gRenderer);
		
private:
	
};

#endif