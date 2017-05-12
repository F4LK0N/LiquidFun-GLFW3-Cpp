#ifndef FKN_PROGRAM
#define FKN_PROGRAM

#pragma once
#include <string>
#include <time.h>
#include "GLFW/glfw3.h"
#include <Box2D\Box2D.h>
using namespace std;



class Program
{
	private:
		string windowTitle = "Window Title";
		int windowWidth    = 640;
		int windowHeight   = 480;
		GLFWwindow *window = nullptr;
	
	public:
		static void callback_error(int error, const char* description);
		static void callback_keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);	
	
		~Program();
		Program();
		void end();
		void run();

	private:
		void loopBegin();
		void loopEnd();
};

#endif;