#include "Node.h"
#include <Windows.h>
#include "Director.h"

Node::Node()
	: mIsVisible( true )
	, mRotation( 0.0f )
	, mLocalZOrder( 0 )
	, mZOrderCoef( 0.001f )
	, mAnchorPoint( 0.5f, 0.5f )
	, mScale( 1.0f )
	, mColor( sColor3f::WHITE )
	, mOpacity( 255.0f )
	, mParent( nullptr )
{
}

Node::~Node()
{
}

Node* Node::create()
{
	Node* result = new Node;

	if ( result )
	{
		result->autorelease();
	}

	return result;
}

void Node::update( float aDeltaTime )
{
	if ( mIsVisible )
	{
		for ( auto child : mChildren )
		{
			if ( child )
			{
				child->update( aDeltaTime );
			}
		}
	}

	updateActions( aDeltaTime );
	render();
}

void Node::updateActions( float aDeltaTime )
{
	std::vector< Action* > actions( mActions );

	for ( auto action : actions )
	{
		if ( action )
		{
			action->update( aDeltaTime );

			if ( action->isActionComplited() )
			{
				auto iter = std::find( mActions.begin(), mActions.end(), action );
				if ( iter != mActions.end() )
				{
					action->release();
					mActions.erase( iter );
				}
			}
		}
	}
}

void Node::render()
{
	if ( mIsVisible )
	{
		glPushMatrix();

		auto visibleSize = Director::getInstance()->getVisibleSize();

		glColor4f( mColor.red / 255.0f, mColor.green / 255.0f, mColor.blue / 255.0f, mOpacity / 255.0f );

		if ( mParent )
		{
			auto convertedPosition = mParent->convertToWorldSpace( mPosition );

			glTranslatef(
				convertedPosition.x / ( 0.5f * visibleSize.width ),
				convertedPosition.y / ( 0.5f * visibleSize.height ), 0.0f );

			glScalef(
				mSize.width * getSummaryScale() / ( 0.5f * visibleSize.width ),
				mSize.height * getSummaryScale() / ( 0.5f * visibleSize.height ), 1.0f );
		}

		glRotatef( -mRotation, 0.0f, 0.0f, 1.0f );


		glBegin( GL_TRIANGLE_FAN );
		glVertex3f( 0.0f - mAnchorPoint.x, 0.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef );
		glVertex3f( 1.0f - mAnchorPoint.x, 0.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef );
		glVertex3f( 1.0f - mAnchorPoint.x, 1.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef );
		glVertex3f( 0.0f - mAnchorPoint.x, 1.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef );
		glEnd();

		glPopMatrix();
	}
}

void Node::setVisible( bool aIsVisible )
{
	mIsVisible = aIsVisible;
}

bool Node::isVisible()
{
	return mIsVisible;
}

void Node::setAnchorPoint( const sPoint& aAnchorPoint )
{
	mAnchorPoint = aAnchorPoint;
}

const sPoint& Node::getAnchorPoint()
{
	return mAnchorPoint;
}

void Node::setSize( const sSize& aSize )
{
	mSize.height = aSize.height;
	mSize.width = aSize.width;
}

const sSize& Node::getSize()
{
	return mSize;
}

void Node::setScale( float aScale )
{
	mScale = aScale;
}

float Node::getScale()
{
	return mScale;
}

float Node::getSummaryScale()
{
	auto result = 1.0f;

	if ( mParent )
	{
		result = mParent->getSummaryScale();
	}

	result *= mScale;

	return result;
}

void Node::setPosition( const sPoint& aPosition )
{
	mPosition = aPosition;
}

const sPoint& Node::getPosition()
{
	return mPosition;
}

void Node::setRotation( float aRotation )
{
	mRotation = aRotation;
}

float Node::getRotation()
{
	return mRotation;
}

void Node::setColor( const sColor3f& aColor )
{
	mColor = aColor;
}

const sColor3f& Node::getColor()
{
	return mColor;
}

void Node::setOpacity( float aOpacity )
{
	mOpacity = aOpacity;
}

float Node::getOpacity()
{
	return mOpacity;
}

void Node::setLocalZOrder( int aLocalZOrderZOrder )
{
	mLocalZOrder = aLocalZOrderZOrder;
}

int Node::getLocalZOrder()
{
	return mLocalZOrder;
}

void Node::setName( const std::string& aName )
{
	mName = aName;
}

const std::string& Node::getName()
{
	return mName;
}

void Node::setCustomID( const std::string& aCustomID )
{
	mCustomID = aCustomID;
}

const std::string& Node::getCustomID()
{
	return mCustomID;
}

void Node::setParent( Node* aParent )
{
	mParent = aParent;
}

Node* Node::getParent()
{
	return mParent;
}

void Node::removeFromParent()
{
	if ( mParent )
	{
		mParent->removeChild( this );
	}
}

void Node::addChild( Node* aNode )
{
	auto iter = find( mChildren.begin(), mChildren.end(), aNode );
	if ( iter == mChildren.end() )
	{
		mChildren.push_back( aNode );
		aNode->setParent( this );
		aNode->retain();
	}
}

void Node::removeChild( Node* aNode )
{
	auto iter = find( mChildren.begin(), mChildren.end(), aNode );
	if ( iter != mChildren.end() )
	{
		mChildren.erase( iter );

		aNode->setParent( nullptr );
		aNode->release();
	}
}

const std::vector< Node* >& Node::getChildren()
{
	return mChildren;
}

Rect Node::getBoundingBox()
{
	float x = mPosition.x - mAnchorPoint.x * mSize.width * mScale;
	float y = mPosition.y - mAnchorPoint.y * mSize.height * mScale;

	float width = mSize.width * mScale;
	float height = mSize.height * mScale;

	Rect bBox( x, y, width, height );

	return std::move( bBox );
}

sPoint Node::convertToNodeSpace( const sPoint& aWorldPosition )
{
	sPoint nodeWorldPosition;

	if ( mParent )
	{
		nodeWorldPosition = mParent->convertToWorldSpace( mPosition );
	}

	return ( aWorldPosition - nodeWorldPosition ) / getSummaryScale();
}

sPoint Node::convertToWorldSpace( const sPoint& aLocalPosition )
{
	sPoint nodeWorldPosition;
	float parentScale = 1.0f;

	if ( mParent )
	{
		nodeWorldPosition = mParent->convertToWorldSpace( mPosition );
	}

	return  nodeWorldPosition + aLocalPosition * getSummaryScale();
}

void Node::runAction( Action* aAction )
{
	if ( aAction )
	{
		aAction->retain();
		aAction->setTargetNode( this );

		mActions.push_back( aAction );
	}
}

void Node::stopAllActions()
{
	for ( auto action : mActions )
	{
		if ( action )
		{
			action->stop();
		}
	}
}

void Node::stopAction( Action* aAction )
{
	auto iter = std::find( mActions.begin(), mActions.end(), aAction );
	if ( iter != mActions.end() )
	{
		aAction->stop();
	}
}

void Node::stopActionByTag( int aTag )
{
	for ( auto action : mActions )
	{
		if ( action )
		{
			if ( action->getTag() == aTag )
			{
				action->stop();
			}
		}
	}
}

