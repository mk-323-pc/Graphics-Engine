#include "Scene.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::drawScene( float aDeltaTime )
{
	if ( isVisible() )
	{
		for ( auto child : getChildren() )
		{
			if ( child )
			{
				child->update( aDeltaTime );
			}
		}
	}
}