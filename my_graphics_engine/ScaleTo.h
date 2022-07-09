#ifndef SCALE_TO_H
#define SCALE_TO_H

#include "Action.h"


class ScaleTo
	: public Action
{
	float mFinalScale;

public:
	ScaleTo();
	virtual ~ScaleTo();

	static ScaleTo* create( float aDuration, float aScale );

	bool init( float aDuration, float aScale );

	virtual void update( float aDeltaTime ) override;

};


#endif
