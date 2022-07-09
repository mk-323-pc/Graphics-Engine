#ifndef NODE_H
#define NODE_H

#include "Action.h"
#include <vector>

class Node
	: public Ref
{
	friend class Sprite;

	bool mIsVisible;

	int mLocalZOrder;
	float mZOrderCoef;
	float mRotation;
	float mScale;
	float mOpacity;

	sPoint mPosition;
	sPoint mAnchorPoint;
	sSize mSize;
	sColor3f mColor;

	std::string mName;
	std::string mCustomID;

	Node* mParent;

	std::vector< Node* > mChildren;
	std::vector< Action* > mActions;

	void updateActions( float aDeltaTime );

public:

	Node();
	virtual ~Node();

	static Node* create();

	virtual void update( float aDeltaTime );

	virtual void render();

	void setVisible( bool aIsVisible );
	bool isVisible();

	void setAnchorPoint( const sPoint& aAnchorPoint );
	const sPoint& getAnchorPoint();

	void setSize( const sSize& aSize );
	const sSize& getSize();

	void setScale( float aScale );
	float getScale();
	float getSummaryScale();

	void setPosition( const sPoint& aPosition );
	const sPoint& getPosition();

	void setRotation( float aRotation );
	float getRotation();

	void setColor( const sColor3f& aColor );
	const sColor3f& getColor();

	void setOpacity( float aOpacity );
	float getOpacity();

	void setLocalZOrder( int aLocalZOrder );
	int getLocalZOrder();

	void setName( const std::string& aName );
	const std::string& getName();

	void setCustomID( const std::string& aCustomID );
	const std::string& getCustomID();

	void setParent( Node* aParent );
	Node* getParent();
	void removeFromParent();

	void addChild( Node* aNode );
	void removeChild( Node* aNode );

	const std::vector< Node* >& getChildren();

	Rect getBoundingBox();

	sPoint convertToNodeSpace( const sPoint& aWorldPosition );
	sPoint convertToWorldSpace( const sPoint& aLocalPosition );

	void runAction( Action* aAction );

	void stopAllActions();
	void stopAction( Action* aAction );
	void stopActionByTag( int aTag );


};


#endif
