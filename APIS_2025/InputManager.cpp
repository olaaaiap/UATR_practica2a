#include "InputManager.h"


void InputManager::init(GLFWwindow* window)
{
	glfwSetKeyCallback(window, InputManager::windowKeyboardEvent);
	glfwSetMouseButtonCallback(window, InputManager::mouseButtonEvent);
	glfwSetCursorPosCallback(window, InputManager::mousePosEvent);
	InputManager::window = window;


	glfwSetCursorPos(window, 0, 0);
}


void InputManager::windowKeyboardEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
	{
		keyboardState[key] = true;

	}break;

	case GLFW_RELEASE:
	{
		keyboardState[key] = false;

	}break;

	}

}
void InputManager::mousePosEvent(GLFWwindow* window, double xpos, double ypos)
{
	mouseState.xPos = xpos;
	mouseState.yPos = ypos;
}

void InputManager::mouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
{
	switch (action)
	{
	case GLFW_PRESS:
	{
		mouseState.buttonState[button] = true;
	}break;

	case GLFW_RELEASE:
	{
		mouseState.buttonState[button] = false;
	}break;
	}
}

bool InputManager::isPressed(char key)
{
	if (keyboardState[key])
	{
		return true;
	}
	return false;
}
