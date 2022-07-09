#include "Sequence.h"


Sequence::Sequence()
{
}

Sequence::~Sequence()
{
	for ( auto action : mActions )
	{
		if ( action )
		{
			action->release();
		}
	}
}

Sequence* Sequence::createWithTwoActions( Action* aFirstAction, Action* aSecondAction )
{
	Sequence* result = new Sequence;

	if ( result && result->initWithTwoActions( aFirstAction, aSecondAction ) )
	{
		result->autorelease();
	}

	return result;
}

bool Sequence::initWithTwoActions( Action* aFirstAction, Action* aSecondAction )
{
	if ( aFirstAction )
	{
		aFirstAction->retain();
		mActions.push_back( aFirstAction );

		mDuration += aFirstAction->getDuration();
	}

	if ( aSecondAction )
	{
		aSecondAction->retain();
		mActions.push_back( aSecondAction );

		mDuration += aSecondAction->getDuration();
	}

	return true;
}

Sequence* Sequence::create( Action* aAction, ... )
{
	Sequence* result = new Sequence;

	if ( result )
	{
		result->autorelease();

		std::vector< Action* > actions;

		auto argument = &aAction;

		while ( argument && *argument )
		{
			actions.push_back( *argument );
			argument += 1;
		}

		result->init( actions );
	}

	return result;
}

bool Sequence::init( const std::vector< Action* >& aActions )
{
	mActions = aActions;

	for ( auto action : mActions )
	{
		if ( action )
		{
			action->retain();

			mDuration += action->getDuration();
		}
	}

	return true;
}

void Sequence::setTargetNode( Node* aNode )
{
	for ( auto action : mActions )
	{
		if ( action )
		{
			action->setTargetNode( aNode );
		}
	}

	mTargetNode = aNode;
}

void Sequence::update( float aDeltaTime )
{
	if ( !mIsActionComplited )
	{
		mElapsed += aDeltaTime;

		mIsActionComplited = true;

		for ( auto action : mActions )
		{
			if ( action && !action->isActionComplited() )
			{
				action->update( aDeltaTime );

				mIsActionComplited = false;

				break;
			}
		}
	}
}

void Sequence::reset()
{
	for ( auto action : mActions )
	{
		if ( action )
		{
			action->reset();
		}
	}

	mElapsed = 0.0f;
	mIsActionComplited = false;
}
