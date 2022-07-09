#ifndef MY_TEST_SCENE_H
#define MY_TEST_SCENE_H

#include "..\my_graphics_engine\GraphicsEngine.h"

class MyTestScene
	: public Scene
{
	Node* mNode;

public:
	MyTestScene();
	~MyTestScene();

	static MyTestScene* create();

	void init();

protected:

	virtual void update( float aDeltaTime ) override;

	virtual bool onLeftButtonClickDown( GLFWwindow* aWindow, const sPoint& aCursorPosition ) { return false; };
	virtual void onLeftButtonClickUp( GLFWwindow* aWindow, const sPoint& aCursorPosition ) {};

	virtual bool onRightButtonClickDown( GLFWwindow* aWindow, const sPoint& aCursorPosition ) { return false; };
	virtual void onRightButtonClickUp( GLFWwindow* aWindow, const sPoint& aCursorPosition ) {};

	virtual void onCursorMoved( GLFWwindow* aWindow, const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition ) {};
};

#endif

