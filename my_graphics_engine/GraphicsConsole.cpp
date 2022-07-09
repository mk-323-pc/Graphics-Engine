#include "GraphicsConsole.h"
#include <Windows.h>
#include <float.h>


GraphicsConsole::GraphicsConsole()
	: mWindow( nullptr )
	, mDefaultDeltaTime( 0.04f )
{
}

GraphicsConsole::~GraphicsConsole()
{
}

GraphicsConsole* GraphicsConsole::getInstance()
{
	static GraphicsConsole instance;

	return &instance;
}

bool GraphicsConsole::initGLFW()
{
	auto result = true;

	if ( !glfwInit() )
	{
		glfwTerminate();
		result = false;
	}

	return result;
}

bool GraphicsConsole::createWindowAndMakeContext( int aWidth, int aHeight, std::string aTitle )
{
	auto result = true;

	mWindow = glfwCreateWindow( aWidth, aHeight, aTitle.c_str(), nullptr, nullptr );

	if ( mWindow )
	{
		glfwMakeContextCurrent( mWindow );
	}
	else
	{
		glfwTerminate();
		result = false;
	}

	return result;
}

void GraphicsConsole::initStartState()
{
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_TEXTURE_2D );
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	glLoadIdentity();
	glOrtho( -1.0, 1.0, -1.0, 1.0, -1.0, 1.0 );
	glTranslatef( -1.0f, -1.0f, 0.0f );

	Director::getInstance()->setWindow( mWindow );
}

void GraphicsConsole::run()
{
	auto previouseTime = glfwGetTime();

	while ( !glfwWindowShouldClose( mWindow ) )
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		auto currentTime = glfwGetTime();
		auto deltaTime = currentTime - previouseTime;

		if ( deltaTime < FLT_EPSILON || deltaTime > mDefaultDeltaTime )
		{
			deltaTime = mDefaultDeltaTime;
		}
		previouseTime = currentTime;

		// Main Loop
		Director::getInstance()->update( deltaTime );
		//

		glfwSwapBuffers( mWindow );
		glfwPollEvents();

		Sleep( 1 );
	}

	glfwTerminate();
}