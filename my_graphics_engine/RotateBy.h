#ifndef ROTATE_BY_H
#define ROTATE_BY_H

#include "Action.h"


class RotateBy
	: public Action
{
	float mDeltaRotation;
	float mFinalRotation;

	bool mIsFinalRotationInited;

	void initFinalRotation();

public:
	RotateBy();
	virtual ~RotateBy();

	static RotateBy* create( float aDuration, float aDeltaRotation );

	bool init( float aDuration, float aDeltaRotation );

	virtual void update( float aDeltaTime ) override;
	virtual void reset() override;

};


#endif
