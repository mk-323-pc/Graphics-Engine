#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "EventDispatcher.h"
#include "Scene.h"


class Director
{
	GLFWwindow* mWindow;

	Scene* mCurrentScene;

	Director();
	~Director();

public:

	static Director* getInstance();

	void setWindow( GLFWwindow* aWindow );
	GLFWwindow* getWindow();

	void setScene( Scene* aScene );
	Scene* getCurrentScene();

	sSize getVisibleSize();

	void update( float aDeltaTime );

};


#endif