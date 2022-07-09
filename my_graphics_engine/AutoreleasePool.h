#ifndef AUTORELEASE_POOL_H
#define AUTORELEASE_POOL_H

#include "Ref.h"
#include <vector>


class AutoreleasePool
{
	std::vector< Ref* > mObjectsPool;

	AutoreleasePool();
	~AutoreleasePool();

public:

	static AutoreleasePool* getInstance();

	void addObject( Ref* aRef );
	void delObject( Ref* aRef );

	void checkPoolAndFreeMemory();
};


#endif
