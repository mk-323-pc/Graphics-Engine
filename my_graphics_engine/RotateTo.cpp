#include "RotateTo.h"
#include "Node.h"

RotateTo::RotateTo()
	: mFinalRotation( 0.0f )
{
}

RotateTo::~RotateTo()
{
}

RotateTo* RotateTo::create( float aDuration, float aRotation )
{
	RotateTo* result = new ( std::nothrow ) RotateTo();

	if ( result )
	{
		if ( result->init( aDuration, aRotation ) )
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

bool RotateTo::init( float aDuration, float aRotation )
{
	mDuration = aDuration;
	mFinalRotation = aRotation;

	return true;
}

void RotateTo::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
		if ( mDuration - mElapsed > FLT_EPSILON )
		{
			auto coef = ( mDuration - mElapsed ) / aDeltaTime;

			auto rotation = mTargetNode->getRotation();

			auto deltaRotation = ( mFinalRotation - rotation ) / coef;

			mTargetNode->setRotation( rotation + deltaRotation );

			mElapsed += aDeltaTime;
		}
		else
		{
			mTargetNode->setRotation( mFinalRotation );
			mIsActionComplited = true;
		}
	}
}
