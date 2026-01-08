#include "GL1Render.h"

GL1Render::GL1Render(double width, double height)
{
	this->SetWidth(static_cast<int>(width));
	this->SetHeight(static_cast<int>(height));
}

void GL1Render::init()
{
	//Inicialización de GLFW
	if (glfwInit() != GLFW_TRUE) {
		std::cout << "ERROR iniciando glfw\n";
	}
	else {
		//iniciar opengl
		#ifdef __APPLE__
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		#endif


		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		this->window = glfwCreateWindow(640, 480, "Practica 2 APIS3D", nullptr, nullptr); //nullptr->para que coja los valores por defecto
		
		glfwMakeContextCurrent(this->window);

		gladLoadGL(glfwGetProcAddress); // cargar funciones OpenGL
		
	}

}

void GL1Render::setupObject(IObject* obj)
{
}

void GL1Render::removeObject(IObject* obj)
{
}

//void GL1Render::drawObjects(std::vector<IObject*>* objs)
//{
//	//MODO NUEVO: CON BUFFERS ESTE ES EL METODO DRAW DE LA PRACTICA 2!!!!
//	for (auto& obj : objs)
//	{
//		//calcular matriz modelo
//		auto model = obj->getModelMatrix();
//		//Los vertices ya estan en la gpu entonces no hay pasarle por cada vertice.
//		//copiar matrices a gpu
//		glPushMatrix(); //añadir una matriz a gpu
//		glLoadIdentity();//cargar identidad
//		glMultMatrixf(&model[0][0]);//multiplicar por modelo
//		//activar buffers de datos
//		auto bo = bufferObjectList[obj->objectId];
//		glBindVertexArray(bo.arrayBufferId);
//		glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);//activar lista de vertices
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);//activar lista de indices de vertices
//
//		//describir buffers
//		glEnableClientState(GL_VERTEX_ARRAY); //voy a describir listas de vertices
//		glVertexPointer(4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition));//4 floats al inicio de la estructura
//
//		glEnableClientState(GL_COLOR_ARRAY); //voy a describir listas de colores
//		glColorPointer(4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, vColor));//4 floats despues de 4 floats (posicion)
//
//
//		//ordenar a dibujar
//		glDrawElements(GL_TRIANGLES, obj->vertexIndexList.size(), GL_UNSIGNED_INT, nullptr);
//
//		//borrar matriz cargada
//		glPopMatrix;
//
//		glDisableClientState(GL_VERTEX_ARRAY); //dejar de describir listas de vertices
//		glDisableClientState(GL_COLOR_ARRAY); //dejar de describir listas de colores
//	}
//}

void GL1Render::drawObjects(std::vector<IObject*>* objs)
{
    // Recorrer todos los objetos
    for (auto& obj : *objs)
    {
        // Calcular matriz modelo
        auto model = obj->computeModelMatrix();

        // Guardar la matriz actual en la pila
        glPushMatrix();
        glLoadIdentity(); // Cargar matriz identidad
        glMultMatrixf(&model[0][0]); // Multiplicar por la matriz modelo del objeto

        // Activar buffers de datos
        auto bo = bufferObjectList[obj->objectId];
        glBindVertexArray(bo.arrayBufferId);
        glBindBuffer(GL_ARRAY_BUFFER, bo.vertexArrayId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo.vertexIdxArrayId);

        // Describir los buffers
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(4, GL_FLOAT, sizeof(vertex_t), (void*)offsetof(vertex_t, vPosition));
        
        // Dibujar los elementos
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(obj->vertexIndexList.size()), GL_UNSIGNED_INT, nullptr);

        // Restaurar la matriz anterior
        glPopMatrix();

        // Deshabilitar los estados de cliente
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
    }
}
