#include "MoveBy.h"
#include "Node.h"

MoveBy::MoveBy()
{
}

MoveBy::~MoveBy()
{
}

MoveBy* MoveBy::create( float aDuration, const sPoint& aDeltaPosition )
{
	MoveBy* result = new MoveBy;

	if ( result && result->init( aDuration, aDeltaPosition ) )
	{
		result->autorelease();
	}

	return result;
}

bool MoveBy::init( float aDuration, const sPoint& aDeltaPosition )
{
	mDuration = aDuration;
	mDeltaPosition = aDeltaPosition;

	return true;
}

void MoveBy::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
		initFinalPosition();

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

void MoveBy::initFinalPosition()
{
	if ( !mIsFinalPositionInited )
	{
		if ( mTargetNode )
		{
			mFinalPosition = mTargetNode->getPosition() + mDeltaPosition;
		}

		mIsFinalPositionInited = true;
	}
}

void MoveBy::reset()
{
	mElapsed = 0.0f;
	mIsActionComplited = false;
	mIsFinalPositionInited = false;
}
