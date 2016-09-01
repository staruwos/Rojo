#include "objectmanager.h"

ObjectsManager::ObjectsManager()
{
	last_Index = 0;
}

ObjectsManager::~ObjectsManager()
{

}

void ObjectsManager::Draw(SDL_Renderer* Renderer)
{
	for (int i = 0; i < last_Index; i++)
	{
		gameObjectList[i].Draw(Renderer);
	}
}

void ObjectsManager::Update()
{
	
}

void ObjectsManager::DeleteObject(int ID)
{
	
}

void ObjectsManager::AddObject(GameObject* object)
{

}

const GameObject& GetObject(int ID)
{

}