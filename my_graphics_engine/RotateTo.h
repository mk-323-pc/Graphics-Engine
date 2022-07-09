#ifndef ROTATE_TO_H
#define ROTATE_TO_H

#include "Action.h"


class RotateTo
	: public Action
{
	float mFinalRotation;

public:
	RotateTo();
	virtual ~RotateTo();

	static RotateTo* create( float aDuration, float aRotation );

	bool init( float aDuration, float aRotation );

	virtual void update( float aDeltaTime ) override;

};


#endif
