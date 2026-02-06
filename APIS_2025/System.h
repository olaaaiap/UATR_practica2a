#pragma once

#include "IRender.h"
#include "InputManager.h"
#include "World.h"

class Object3D;

class System{
	static inline IRender* render;
	static inline InputManager* inputManager;
	static inline bool end = false;
	static inline World* world;

	public:
		static void SetRender(IRender* r);
		static IRender* GetRender();

		static void SetInputManager(InputManager* im);
		static InputManager* GetInputManager();

		static void SetWorld(World* w);
		static World* GetWorld();
	
		static void initSystem();
		static void addObject(Object3D* obj);
		static void exit();
		void mainLoop();
};
