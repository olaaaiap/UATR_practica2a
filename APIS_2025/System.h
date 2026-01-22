#pragma once
#include "IRender.h"
#include "InputManager.h"
#include "World.h"


class System
{
	static inline IRender* render; //Puntero a una clase IRender que implemente esa interfaz.
	static inline InputManager* inputManager; //Puntero a una clase InputManager que la implemente.
	static inline bool end; //Variable para indicar si se debe acabar la ejecución.
	static inline World* world; //Variable que apunta a un objeto de tipo "mundo" que representa el escenario activo en este momento.

public:
	static void initSystem(); //Inicializa el sistema.
	static void addObject(Object3D* obj); //Añadirá un nuevo objeto a la lista "objects"
	static void exit(); //Método para acabar la ejecución del sistema.
};

