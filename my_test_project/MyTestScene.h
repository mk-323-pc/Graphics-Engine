#ifndef MY_TEST_SCENE_H
#define MY_TEST_SCENE_H

#include "..\my_graphics_engine\GraphicsEngine.h"

class MyTestScene
	: public Scene
{
public:
	MyTestScene();
	~MyTestScene();

	static MyTestScene* create();

	void init();
};

#endif

