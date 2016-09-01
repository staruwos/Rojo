#include "player_rojo.h"

Rojo::Rojo()
{
	m_Texture = new RTexture();
}

Rojo::~Rojo()
{

}

void Rojo::Draw(SDL_Renderer* gRenderer)
{
	m_Texture->render(gRenderer, 0, 0);
}

void Rojo::LoadAssets(SDL_Renderer* gRenderer)
{
	m_Texture->loadFromFile(gRenderer, "data/graphics/Rojo.png");
}