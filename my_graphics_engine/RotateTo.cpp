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
	RotateTo* result = new RotateTo;

	if ( result && result->init( aDuration, aRotation ) )
	{
		result->autorelease();
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
