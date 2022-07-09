#include "Director.h"


Director::Director()
	: mWindow( nullptr )
	, mCurrentScene( nullptr )
{
}

Director::~Director()
{
}

Director* Director::getInstance()
{
	static Director instance;

	return &instance;
}

void Director::setWindow( GLFWwindow* aWindow )
{
	mWindow = aWindow;
}

GLFWwindow* Director::getWindow()
{
	return mWindow;
}

void Director::setScene( Scene* aScene )
{
	if ( aScene )
	{
		mCurrentScene = aScene;
		mCurrentScene->retain();
	}
}

Scene* Director::getCurrentScene()
{
	return mCurrentScene;
}

sSize Director::getVisibleSize()
{
	sSize size;

	if ( mWindow )
	{
		int width;
		int height;

		glfwGetWindowSize( mWindow, &width, &height );

		size.width = width;
		size.height = height;
	}

	return std::move( size );
}

void Director::update( float aDeltaTime )
{
	if ( mCurrentScene )
	{
		mCurrentScene->drawScene( aDeltaTime );
	}
}