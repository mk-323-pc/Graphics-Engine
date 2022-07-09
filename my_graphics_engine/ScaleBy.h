#ifndef SCALE_BY_H
#define SCALE_BY_H

#include "Action.h"


class ScaleBy
	: public Action
{
	float mDeltaScale;
	float mFinalScale;

	bool mIsFinalScaleInited;

	void initFinalScale();

public:
	ScaleBy();
	virtual ~ScaleBy();

	static ScaleBy* create( float aDuration, float aDeltaScale );

	bool init( float aDuration, float aDeltaScale );

	virtual void update( float aDeltaTime ) override;
	virtual void reset() override;

};

#endif
