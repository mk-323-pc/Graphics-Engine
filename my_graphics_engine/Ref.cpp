#include "Ref.h"
#include "AutoreleasePool.h"


Ref::Ref()
	: mRefCounter( 0 )
{
}

Ref::~Ref()
{
}

void Ref::retain()
{
	++mRefCounter;
}

void Ref::release()
{
	--mRefCounter;
}

int Ref::getRefCounter()
{
	return mRefCounter;
}

void Ref::autorelease()
{
	AutoreleasePool::getInstance()->addObject( this );
}

void Ref::clear()
{
	AutoreleasePool::getInstance()->delObject( this );

	delete this;
}