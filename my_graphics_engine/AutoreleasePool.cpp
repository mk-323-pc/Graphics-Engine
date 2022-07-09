#include "AutoreleasePool.h"

AutoreleasePool::AutoreleasePool()
{
}

AutoreleasePool::~AutoreleasePool()
{
}

AutoreleasePool* AutoreleasePool::getInstance()
{
	static AutoreleasePool instance;

	return &instance;
}

void AutoreleasePool::addObject( Ref* aRef )
{
	auto iter = std::find( mObjectsPool.begin(), mObjectsPool.end(), aRef );
	if ( iter == mObjectsPool.end() )
	{
		mObjectsPool.push_back( aRef );
	}
}

void AutoreleasePool::delObject( Ref* aRef )
{
	auto iter = std::find( mObjectsPool.begin(), mObjectsPool.end(), aRef );
	if ( iter != mObjectsPool.end() )
	{
		mObjectsPool.erase( iter );
	}
}

void AutoreleasePool::checkPoolAndFreeMemory()
{
	std::vector< Ref* > objectsPool( mObjectsPool );

	for ( auto object : objectsPool )
	{
		if ( object )
		{
			if ( object->getRefCounter() < 1 )
			{
				object->clear();
			}
		}
	}
}
