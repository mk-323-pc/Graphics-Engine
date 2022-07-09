#include "RotateBy.h"
#include "Node.h"

RotateBy::RotateBy()
	: mDeltaRotation( 0.0f )
	, mFinalRotation( 0.0f )
	, mIsFinalRotationInited( false )
{
}

RotateBy::~RotateBy()
{
}

RotateBy* RotateBy::create( float aDuration, float aDeltaRotation )
{
	RotateBy* result = new RotateBy;

	if ( result && result->init( aDuration, aDeltaRotation ) )
	{
		result->autorelease();
	}

	return result;
}

bool RotateBy::init( float aDuration, float aDeltaRotation )
{
	mDuration = aDuration;
	mDeltaRotation = aDeltaRotation;

	return true;
}

void RotateBy::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
		initFinalRotation();

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

void RotateBy::initFinalRotation()
{
	if ( !mIsFinalRotationInited )
	{
		if ( mTargetNode )
		{
			mFinalRotation = mTargetNode->getRotation() + mDeltaRotation;
		}

		mIsFinalRotationInited = true;
	}
}

void RotateBy::reset()
{
	mElapsed = 0.0f;
	mIsActionComplited = false;
	mIsFinalRotationInited = false;
}
