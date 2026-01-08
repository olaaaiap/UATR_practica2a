#pragma once
#define GLAD_BIN
#include "mapi/common.h"
#include "IObject.h"
#include "IRender.h"


typedef struct
{
	//id de array de buffers
	unsigned int arrayBufferId;
	//id de vertex array buffer
	unsigned int vertexArrayId;
	//id de vertex index buffer
	unsigned int vertexIdxArrayId;
}bo_t; //datos de buffer object

class GL1Render : public IRender
{
	GLFWwindow* window; //Puntero a una ventana GLFW.
	
	//Variables para la funcion draw de GL1Render
	std::vector<IObject*> objectList; 
	std::map<int, bo_t>  bufferObjectList; 


public:
    GL1Render(double width, double height);
	void init();
	void setupObject(IObject* obj);
	void removeObject(IObject* obj);
	void drawObjects(std::vector<IObject*>* objs);
};

