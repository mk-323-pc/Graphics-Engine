#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Node.h"

class Scene
	: public Node
{

public:

	Scene();
	virtual ~Scene();

	void drawScene( float aDeltaTime );

	virtual void update( float aDeltaTime ) {};
};


#endif