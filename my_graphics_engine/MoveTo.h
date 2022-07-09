#ifndef MOVE_TO_H
#define MOVE_TO_H

#include "Action.h"


class MoveTo
	: public Action
{
	sPoint mFinalPosition;

public:
	MoveTo();
	virtual ~MoveTo();

	static MoveTo* create( float aDuration, const sPoint& aPosition );

	bool init( float aDuration, const sPoint& aPosition );

	virtual void update( float aDeltaTime ) override;

};


#endif
