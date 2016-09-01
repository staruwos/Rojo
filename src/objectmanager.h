#include "object.h"

class ObjectsManager
{
public:
	ObjectsManager();
	~ObjectsManager();

	void Draw(SDL_Renderer* Renderer);
	void Update();
	void DeleteObject(int ID);
	const GameObject& GetObject(int ID);

	void AddObject(GameObject* object);

private:
	GameObject* gameObjectList;

	int last_Index;
};