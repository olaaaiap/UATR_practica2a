#define GLAD_BIN

#include "mapi/common.h"
#include "FactoryEngine.h"
#include "GL1Render.h"
#include "System.h"
#include "TrianguloRot.h"

int main(int argc, char** argv){
	IRender* render = FactoryEngine::getNewRender();
	InputManager* inputManager = FactoryEngine::getNewInputManager();

	System system;
	system.initSystem();
	
	TrianguloRot* triangulo = new TrianguloRot();
	System::addObject(triangulo);
	World* world = new World();
	world->addObject(triangulo); //Añadir triangulo al mundo
	System::SetWorld(world);
	system.mainLoop();

	return 0;
}
