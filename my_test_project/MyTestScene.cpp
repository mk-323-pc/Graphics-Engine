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
		node->setSize( sSize( 300.0f, 100.0f ) );
		node->setPosition( sPoint( 640.0f, 360.0f ) );
	}
}