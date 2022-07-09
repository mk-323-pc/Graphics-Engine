#ifndef ACTION_H
#define ACTION_H

#include "Ref.h"
#include "Types.h"

class Node;

class Action
	: public Ref
{

protected:

	float mDuration;
	float mElapsed;

	int mTag;

	bool mIsActionComplited;

	Node* mTargetNode;

	Action();
	virtual ~Action();

public:

	virtual void setTargetNode( Node* aNode );

	virtual void update( float DeltaTime ) {};
	virtual void reset();

	virtual Action* clone() { return nullptr; };

	virtual float getDuration();
	virtual float getElapsed();

	void setTag( int aTag );
	int getTag();

	bool isActionComplited();

	void stop();

};

#endif
