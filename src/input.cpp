#include "input.h"


struct _InputConfig {
	std::string  Key_UP;
	std::string  Key_DOWN;
	std::string  Key_RIGHT;
	std::string  Key_LEFT;
};

Input::Input()
{
	
}

Input::~Input()
{

}

void Input::ProcessInput(SDL_Event eventKey)
{
	if(eventKey.type == SDL_KEYDOWN)
	{
		if(SDL_GetKeyName(eventKey.key.keysym.sym) == m_InputConfig->Key_UP)
			SDL_Quit();
	}
}

void Input::LoadInputConfig()
{
	m_InputConfig = new InputConfig();

	INIReader reader("config/input.ini");

    if (reader.ParseError() < 0) 
    {
        return ;
    }

    m_InputConfig->Key_UP 		= reader.Get("Keyboard", "UP", "UNKNOW");
    m_InputConfig->Key_DOWN 	= reader.Get("Keyboard", "DOWN", "UNKNOW");
    m_InputConfig->Key_RIGHT 	= reader.Get("Keyboard", "RIGHT", "UNKNOW");
    m_InputConfig->Key_LEFT		= reader.Get("Keyboard", "LEFT", "UNKNOW");
}