#ifndef MOVE_BY_H
#define MOVE_BY_H

#include "Action.h"


class MoveBy
	: public Action
{
	sPoint mDeltaPosition;
	sPoint mFinalPosition;

	bool mIsFinalPositionInited;

	void initFinalPosition();

public:
	MoveBy();
	virtual ~MoveBy();

	static MoveBy* create( float aDuration, const sPoint& aDeltaPosition );

	bool init( float aDuration, const sPoint& aDeltaPosition );

	virtual void update( float aDeltaTime ) override;
	virtual void reset() override;

};


#endif
