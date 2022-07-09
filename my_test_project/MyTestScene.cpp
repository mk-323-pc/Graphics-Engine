#include "MyTestScene.h"


MyTestScene::MyTestScene()
{
}

MyTestScene::~MyTestScene()
{
}

MyTestScene* MyTestScene::create()
{
	MyTestScene* result = new MyTestScene;

	if ( result )
	{
		result->init();
		result->autorelease();
	}

	return result;
}

void MyTestScene::init()
{
	auto node = Node::create();
	if ( node )
	{
		addChild( node );

		node->setColor( sColor3f::GREEN );
		node->setSize( sSize( 300.0f, 10.0f ) );
		node->setPosition( sPoint( 0.0f, 50.0f ) );

		mNode = node;
	}
}

void MyTestScene::update( float aDeltaTime )
{
	if ( mNode )
	{
		mNode->setPosition( mNode->getPosition() + sPoint( 30.0f, 0.0f ) );

		if ( mNode->getPosition().x > Director::getInstance()->getVisibleSize().width + mNode->getSize().width / 2.0f )
		{
			mNode->setPosition( sPoint( 0.0f - mNode->getSize().width / 2.0f, mNode->getPosition().y ) );
		}
	}
}