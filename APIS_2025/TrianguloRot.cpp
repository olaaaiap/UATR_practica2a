#include "TrianguloRot.h"
#include "GLFWInputManager.h"
#include "System.h"

TrianguloRot::TrianguloRot(){
    Mesh3D* mesh = new Mesh3D();
    this->objectId = objectCounter++;
    this->vertexList = {
        {{ 0.0f,  0.5f, 0.0f, 1.0f }},
        {{-0.5f, -0.5f, 0.0f, 1.0f }},
        {{ 0.5f, -0.5f, 0.0f, 1.0f }}
    };
    this->vertexIndexList = { 0, 1, 2 };
    
    for(auto v : this->vertexList){
        mesh->addVertex(v);
    }

    this->setPosicion({ 0.0f,0.0f,0.0f,1.0f });
    this->setRotacion({ 0.0f,0.0f,0.0f,1.0f });
    this->setEscala({ 1.0f,1.0f,1.0f,1.0f });
}

void TrianguloRot::step(double deltaTime){
    float velRot = 90.0f;
    glm::vec4 rot = this->GetRotacion();
    
    if (GLFWInputManager::keyboardState[GLFW_KEY_R])
        rot.y += static_cast<float>(velRot * deltaTime);

    if (GLFWInputManager::keyboardState[GLFW_KEY_T])
        rot.y -= static_cast<float>(velRot * deltaTime);

    this->setRotacion(rot);
    
    if (GLFWInputManager::keyboardState[GLFW_KEY_E]){
        System::exit();
    }
}
