#ifndef OBJECT_H
#define OBJECT_H

#include "system.h"
#include "texture.h"
#include "math.h"

class GameObject
{

public:
	GameObject() {};
	~GameObject() {};
	virtual void Draw(SDL_Renderer* gRenderer){};
	virtual void Move(){};

	virtual void LoadAssets(SDL_Renderer* gRenderer){};

protected:
	int Scene_ID;
	Vector2D position;
	RTexture* m_Texture;



};

#endif