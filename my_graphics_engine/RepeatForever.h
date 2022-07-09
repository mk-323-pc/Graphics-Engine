#ifndef REPEAT_FOREVER_H
#define REPEAT_FOREVER_H

#include "Action.h"

class RepeatForever
	: public Action
{
	Action* mAction;

public:
	RepeatForever();
	virtual ~RepeatForever();

	static RepeatForever* create( Action* aAction );

	bool init( Action* aAction );

	virtual void setTargetNode( Node* aNode ) override;
	virtual void update( float aDeltaTime ) override;
};


#endif
