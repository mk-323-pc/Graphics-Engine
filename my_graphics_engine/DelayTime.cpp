#include "DelayTime.h"
#include "Node.h"

DelayTime::DelayTime()
{
}

DelayTime::~DelayTime()
{
}

DelayTime* DelayTime::create( float aDuration )
{
	DelayTime* result = new ( std::nothrow ) DelayTime();

	if ( result )
	{
		if ( result->init( aDuration ) )
		{
			result->autorelease();
		}
		else
		{
			delete result;
			result = nullptr;
		}
	}

	return result;
}

bool DelayTime::init( float aDuration )
{
	mDuration = aDuration;
	return true;
}

void DelayTime::update( float aDeltaTime )
{
	if ( !mIsActionComplited )
	{
		mElapsed += aDeltaTime;

		if ( mElapsed - mDuration > FLT_EPSILON )
		{
			mIsActionComplited = true;
		}
	}
}
