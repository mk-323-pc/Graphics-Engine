#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

int Application::run()
{
	auto console = GraphicsConsole::getInstance();
	if ( console )
	{
		if ( !console->initGLFW() )
		{
			return -1;
		}

		if ( !console->createWindowAndMakeContext( 1280, 720, "My Test Project" ) )
		{
			return -1;
		}

		console->initStartState();
		console->run();
	}

	return 0;
}