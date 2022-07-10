#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Button.h"

class Scene
	: public Node
	, public EventDispatcherListener
	, public ButtonListener
{

public:

	Scene();
	virtual ~Scene();

	void drawScene( float aDeltaTime );

	virtual void update( float aDeltaTime ) {};
};


#endif