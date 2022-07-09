#ifndef CALL_FUNC_H
#define CALL_FUNC_H

#include "Action.h"
#include <functional>


class CallFunc
	: public Action
{
	std::function< void() > mCallBack;

public:
	CallFunc();
	virtual ~CallFunc();

	static CallFunc* create( std::function< void() > aCallBack );

	bool init( std::function< void() > aCallBack );

	virtual void update( float aDeltaTime ) override;

};

#endif
