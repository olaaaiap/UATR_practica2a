#pragma once
#include "mapi/common.h"

typedef struct {
	double xPos;
	double yPos;
	std::map<int, bool> buttonState;
} mouseStats_t;


class InputManager
{
public:
	static inline GLFWwindow* window;
	static inline std::map<int, bool>keyboardState; //Mapa de carácteres para poder consultar si una tecla está apretada o no
	static inline mouseStats_t mouseState; //Mouse state


	static void init(GLFWwindow* window); //Initialize key manager
	static void windowKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods); //Keyboard event
	static void mousePosEvent(GLFWwindow* window, double xpos, double ypos); //Mouse position event
	static void mouseButtonEvent(GLFWwindow* window, int button, int action, int mods); //Mouse button event

	bool isPressed(char key);
};

