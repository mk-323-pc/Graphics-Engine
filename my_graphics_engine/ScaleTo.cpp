#include "ScaleTo.h"
#include "Node.h"

ScaleTo::ScaleTo()
	: mFinalScale( 0.0f )
{
}

ScaleTo::~ScaleTo()
{
}

bool ScaleTo::init( float aDuration, float aScale )
{
	mDuration = aDuration;
	mFinalScale = aScale;

	return true;
}

ScaleTo* ScaleTo::create( float aDuration, float aScale )
{
	ScaleTo* result = new ( std::nothrow ) ScaleTo();

	if ( result )
	{
		if ( result->init( aDuration, aScale ) )
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

void ScaleTo::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
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