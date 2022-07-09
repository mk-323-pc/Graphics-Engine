#ifndef DELAY_TIME_H
#define DELAY_TIME_H

#include "Action.h"


class DelayTime
	: public Action
{
public:
	DelayTime();
	virtual ~DelayTime();

	static DelayTime* create( float aDuration );

	bool init( float aDuration );

	virtual void update( float aDeltaTime ) override;

};

#endif
