#include "Program.h"



void Program::callback_error(int error, const char * description){ }

void Program::callback_keyboard(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	//EXIT ON ESC
	if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS){
		glfwSetWindowShouldClose(window, GL_TRUE);   }

	//if (key == GLFW_KEY_C && action == GLFW_PRESS)
}



Program::~Program(){}

Program::Program()
{
	srand(time(0));

	//Callback - Error
	glfwSetErrorCallback(callback_error);

	//GLFW - Init
	if(!glfwInit()){   exit(EXIT_FAILURE);   }


	//WindowMain - Init
	window = glfwCreateWindow(windowWidth, windowHeight, "Window Title", NULL, NULL);
	if(!window){
		glfwTerminate();
		exit(EXIT_FAILURE);   }
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	//Callback - Keyboard
	glfwSetKeyCallback(window, callback_keyboard);
}

void Program::end()
{
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Program::run()
{
	while(!glfwWindowShouldClose(window)){

		loopBegin();



		//Draw
		//...
		glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glVertex2f(10, 10);
			glVertex2f(10, 50);
			glVertex2f(50, 50);
			glVertex2f(50, 10);
		glEnd();



		loopEnd();
	}
}

void Program::loopBegin()
{
	//Window - Properties
	float windowRatio;
	int windowWidth;
	int windowHeight;

	glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
	windowRatio = windowWidth / (float)windowHeight;


	//Viewport
	glViewport(0, 0, windowWidth, windowHeight);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-windowRatio, windowRatio, -1.f, 1.f, 1.f, -1.f);
	glOrtho(0, 100.0f, 0, 100.0f, 0, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Program::loopEnd()
{
	//Window - Draw
	glfwSwapBuffers(window);
	//Call Events
	glfwPollEvents();
}
