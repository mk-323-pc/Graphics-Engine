#include "CallFunc.h"


CallFunc::CallFunc()
{
}

CallFunc::~CallFunc()
{
}

CallFunc* CallFunc::create( std::function< void() > aCallBack )
{
	CallFunc* result = new CallFunc;

	if ( result && result->init( aCallBack ) )
	{
		result->autorelease();
	}

	return result;
}

bool CallFunc::init( std::function< void() > aCallBack )
{
	mCallBack = aCallBack;

	return true;
}

void CallFunc::update( float aDeltaTime )
{
	if ( !mIsActionComplited )
	{
		mCallBack();
		mIsActionComplited = true;
	}
}