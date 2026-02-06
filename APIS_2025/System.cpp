#include "System.h"
#include "FactoryEngine.h"

#include <GLFW/glfw3.h>
#include <vector>

void System::SetRender(IRender* r) {
	render = r;
}

IRender* System::GetRender() {
	return render;
}

void System::SetInputManager(InputManager* im) {
	inputManager = im;
}

InputManager* System::GetInputManager() {
	return inputManager;
}

void System::SetWorld(World* w) {
	world = w;
}

World* System::GetWorld() {
	return world;
}

void System::initSystem() {
	world = new World();
	render = FactoryEngine::getNewRender();
	inputManager = FactoryEngine::getNewInputManager();
	render->init();
	inputManager->init(glfwGetCurrentContext());
}

void System::addObject(Object3D* obj) {
	world->addObject(obj);
}

void System::exit() {
	end = true;
}

void System::mainLoop() {
	auto& objList = world->getObjects();

	for (auto* obj : objList) {
		render->setupObject(obj);
	}

	float newTime = static_cast<float>(glfwGetTime());
	float deltaTime = 0;
	float lastTime = newTime;

	std::vector<IObject*> objVec;
	objVec.reserve(objList.size());

	for (auto* obj : objList) {
		objVec.push_back(static_cast<IObject*>(obj));
	}

	while(!end) {
		newTime = static_cast<float>(glfwGetTime());
		deltaTime = newTime - lastTime;
		lastTime = newTime;
		
		world->update(deltaTime);
		
		render->drawObjects(&objVec);
	}
}
