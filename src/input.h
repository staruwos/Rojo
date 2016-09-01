#ifndef INPUT_H
#define INPUT_H

#include "system.h"

typedef struct _InputConfig InputConfig;

class Input {

public:
	Input();
	~Input();

	void ProcessInput(SDL_Event eventKey);
	void LoadInputConfig();

private:
	InputConfig* m_InputConfig;
};	

#endif