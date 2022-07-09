#ifndef MY_TEST_SCENE_H
#define MY_TEST_SCENE_H

#include "..\my_graphics_engine\GraphicsEngine.h"

class MyTestScene
	: public Scene
{
	enum class eActionTag
	{
		DEFAULT = 101
	};

	Node* mNode;

public:
	MyTestScene();
	~MyTestScene();

	static MyTestScene* create();

	void init();

protected:

	virtual void update( float aDeltaTime ) override;

	virtual bool onLeftButtonClickDown( GLFWwindow* aWindow, const sPoint& aCursorPosition ) override;
	virtual void onLeftButtonClickUp( GLFWwindow* aWindow, const sPoint& aCursorPosition ) override;

};

#endif

