#include "Scene.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::drawScene( float aDeltaTime )
{
	if ( mIsVisible )
	{
		for ( auto child : mChildren )
		{
			if ( child )
			{
				child->update( aDeltaTime );
			}
		}
	}
}