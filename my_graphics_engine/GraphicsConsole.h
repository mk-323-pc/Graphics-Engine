#ifndef GRAPHICS_CONSOLE_H
#define GRAPHICS_CONSOLE_H

#include "Director.h"
#include <string>


class GraphicsConsole
{
	GLFWwindow* mWindow;

	float mDefaultDeltaTime;

protected:
	GraphicsConsole();
	~GraphicsConsole();

public:

	static GraphicsConsole* getInstance();

	bool initGLFW();
	bool createWindowAndMakeContext( int aWidth, int aHeight, std::string aTitle );
	void initStartState();

	void run();
};

#endif 

