#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Node.h"
#include "EventDispatcher.h"

class Scene
	: public Node
	, public EventDispatcherListener
{

public:

	Scene();
	virtual ~Scene();

	void drawScene( float aDeltaTime );

	virtual void update( float aDeltaTime ) {};
};


#endif