#include "Action.h"

Action::Action()
	: mDuration( 0.0f )
	, mElapsed( 0.0f )
	, mTag( 0 )
	, mIsActionComplited( false )
	, mTargetNode( nullptr )
{
}

Action::~Action()
{
}

void Action::setTargetNode( Node* aNode )
{
	mTargetNode = aNode;
}

void Action::reset()
{
	mElapsed = 0.0f;
	mIsActionComplited = false;
}

void Action::setTag( int aTag )
{
	mTag = aTag;
}

int Action::getTag()
{
	return mTag;
}

float Action::getDuration()
{
	return mDuration;
}

float Action::getElapsed()
{
	return mElapsed;
}

bool Action::isActionComplited()
{
	return mIsActionComplited;
}

void Action::stop()
{
	mIsActionComplited = true;
}

