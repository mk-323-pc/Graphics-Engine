#include "TintTo.h"
#include "Node.h"

TintTo::TintTo()
{
}

TintTo::~TintTo()
{
}

bool TintTo::init( float aDuration, sColor3f aColor )
{
	mDuration = aDuration;
	mFinalColor = aColor;

	return true;
}

TintTo* TintTo::create( float aDuration, sColor3f aColor )
{
	TintTo* result = new TintTo;

	if ( result && result->init( aDuration, aColor ) )
	{
		result->autorelease();
	}

	return result;
}

void TintTo::update( float aDeltaTime )
{
	if ( mTargetNode && !mIsActionComplited )
	{
		if ( mDuration - mElapsed > FLT_EPSILON )
		{
			auto coef = ( mDuration - mElapsed ) / aDeltaTime;

			auto color = mTargetNode->getColor();

			auto deltaColor = ( mFinalColor - color ) / coef;

			mTargetNode->setColor( color + deltaColor );

			mElapsed += aDeltaTime;
		}
		else
		{
			mTargetNode->setColor( mFinalColor );
			mIsActionComplited = true;
		}
	}
}