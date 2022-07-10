#ifndef TINT_TO_H
#define TINT_TO_H

#include "Action.h"


class TintTo
	: public Action
{
	sColor3f mFinalColor;

public:
	TintTo();
	virtual ~TintTo();

	static TintTo* create( float aDuration, sColor3f aColor );

	bool init( float aDuration, sColor3f aColor );

	virtual void update( float aDeltaTime ) override;

};


#endif
