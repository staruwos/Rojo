#ifndef TEXT_H
#define TEXT_H

#include "system.h"
#include "texture.h"

class RText {
	
public:
	RText();
	~RText();

	void TextInit();
	void PrintText(std::string text, int x, int y, SDL_Renderer* gRenderer);
	void Draw(SDL_Renderer* gRenderer);

	

private:
	TTF_Font* textFont;
	RTexture* textTexture;


};

#endif