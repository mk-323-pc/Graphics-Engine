#include "CallFunc.h"


CallFunc::CallFunc()
{
}

CallFunc::~CallFunc()
{
}

CallFunc* CallFunc::create( std::function< void() > aCallBack )
{
	CallFunc* result = new ( std::nothrow ) CallFunc();

	if ( result )
	{
		if ( result->init( aCallBack ) )
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