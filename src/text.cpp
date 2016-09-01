#include "text.h"

RText::RText()
{
	textFont = 0;
	textTexture = new RTexture();
}

RText::~RText()
{

}

void RText::TextInit()
{
	// Initialize SDL_ttf library
   if (TTF_Init() != 0)
   {
      SDL_Quit();
      exit(1);
   }

   textFont = TTF_OpenFont("data/fonts/FreeSans.ttf", 24);
   if (textFont == NULL)
   {
      TTF_Quit();
      SDL_Quit();
      exit(1);
   }
}
void RText::PrintText(std::string text, int x, int y, SDL_Renderer* gRenderer)
{
	SDL_Color text_color = {120, 122, 120};
	textTexture->loadFromRenderedText( text, text_color, gRenderer, textFont);
}
    
void RText::Draw(SDL_Renderer* gRenderer)
{
	textTexture->render(gRenderer, 0, 0);
}