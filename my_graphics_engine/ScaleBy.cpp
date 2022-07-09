#include "ScaleBy.h"
#include "Node.h"


ScaleBy::ScaleBy()
	: mDeltaScale( 0.0f )
	, mFinalScale( 0.0f )
	, mIsFinalScaleInited( false )
{
}

ScaleBy::~ScaleBy()
{
}

ScaleBy* ScaleBy::create( float aDuration, float aDeltaScale )
{
	ScaleBy* result = new ScaleBy;

	if ( result && result->init( aDuration, aDeltaScale ) )
	{
		result->autorelease();
	}

	return result;
}

bool ScaleBy::init( float aDuration, float aDeltaScale )
{
	mDuration = aDuration;
	mDeltaScale = aDeltaScale;

	return true;
}

void ScaleBy::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
		initFinalScale();

		if ( mDuration - mElapsed > FLT_EPSILON )
		{
			auto coef = ( mDuration - mElapsed ) / aDeltaTime;

			auto scale = mTargetNode->getScale();

			auto deltaScale = ( mFinalScale - scale ) / coef;

			mTargetNode->setScale( scale + deltaScale );

			mElapsed += aDeltaTime;
		}
		else
		{
			mTargetNode->setScale( mFinalScale );
			mIsActionComplited = true;
		}
	}
}

void ScaleBy::initFinalScale()
{
	if ( !mIsFinalScaleInited )
	{
		if ( mTargetNode )
		{
			mFinalScale = mTargetNode->getScale() + mDeltaScale;
		}

		mIsFinalScaleInited = true;
	}
}

void ScaleBy::reset()
{
	mElapsed = 0.0f;
	mIsActionComplited = false;
	mIsFinalScaleInited = false;
}

