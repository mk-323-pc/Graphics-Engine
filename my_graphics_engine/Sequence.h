#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Action.h"
#include <vector>

class Sequence
	: public Action
{

	std::vector< Action* > mActions;

public:
	Sequence();
	virtual ~Sequence();

	static Sequence* createWithTwoActions( Action* aFirstAction, Action* aSecondAction );
	bool initWithTwoActions( Action* aFirstAction, Action* aSecondAction );

	static Sequence* create( Action* aAction, ... );
	bool init( const std::vector< Action* >& aActions );

	virtual void setTargetNode( Node* aNode ) override;
	virtual void update( float aDeltaTime ) override;
	virtual void reset() override;
	
};


#endif
