#include "RepeatForever.h"


RepeatForever::RepeatForever()
	: mAction( nullptr )
{
}

RepeatForever::~RepeatForever()
{
	if ( mAction )
	{
		mAction->release();
	}
}

RepeatForever* RepeatForever::create( Action* aAction )
{
	RepeatForever* result = new RepeatForever;

	if ( result && result->init( aAction ) )
	{
		result->autorelease();
	}

	return result;
}

bool RepeatForever::init( Action* aAction )
{
	if ( aAction )
	{
		aAction->retain();
		mAction = aAction;
	}

	return true;
}

void RepeatForever::setTargetNode( Node* aNode )
{
	if ( mAction )
	{
		mAction->setTargetNode( aNode );
	}

	mTargetNode = aNode;
}

void RepeatForever::update( float aDeltaTime )
{
	if ( !mIsActionComplited )
	{
		if ( mAction )
		{
			mAction->update( aDeltaTime );

			if ( mAction->isActionComplited() )
			{
				mAction->reset();
			}
		}
	}
}
