#include "MoveTo.h"
#include "Node.h"

MoveTo::MoveTo()
{
}

MoveTo::~MoveTo()
{
}

MoveTo* MoveTo::create( float aDuration, const sPoint& aPosition )
{
	MoveTo* result = new ( std::nothrow ) MoveTo();

	if ( result )
	{
		if ( result->init( aDuration, aPosition ) )
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

bool MoveTo::init( float aDuration, const sPoint& aPosition )
{
	mDuration = aDuration;
	mFinalPosition = aPosition;

	return true;
}

void MoveTo::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
		if ( mDuration - mElapsed > FLT_EPSILON )
		{
			auto coef = ( mDuration - mElapsed ) / aDeltaTime;

			auto position = mTargetNode->getPosition();

			auto deltaPosition = ( mFinalPosition - position ) / coef;

			mTargetNode->setPosition( position + deltaPosition );

			mElapsed += aDeltaTime;
		}
		else
		{
			mTargetNode->setPosition( mFinalPosition );
			mIsActionComplited = true;
		}
	}
}
