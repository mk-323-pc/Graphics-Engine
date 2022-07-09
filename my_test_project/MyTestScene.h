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

	virtual void update( float aDeltaTime ) override;
};

#endif

