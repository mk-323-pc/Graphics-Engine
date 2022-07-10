#include "MyTestScene.h"


MyTestScene::MyTestScene()
	: mMoveStep( 30.0f )
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
	EventDispatcher::getInstance()->addEventDispatcherListener( this );

	auto node = Node::create();
	if ( node )
	{
		addChild( node );

		node->setColor( sColor3f::GREEN );
		node->setSize( sSize( 300.0f, 10.0f ) );
		node->setPosition( sPoint( 0.0f, 50.0f ) );

		mNode = node;
	}

	auto node1 = Node::create();
	if ( node1 )
	{
		addChild( node1 );

		node1->setColor( sColor3f::RED );
		node1->setSize( sSize( 100.0f, 100.0f ) );
		node1->setPosition( sPoint( 150.0f, 600.0f ) );
		
		auto scaleToMin = ScaleTo::create( 0.5f, 0.5f );
		auto scaleToMax = ScaleTo::create( 0.5f, 1.0f );
		auto delay = DelayTime::create( 0.5f );

		auto seq = Sequence::create( scaleToMin, scaleToMax, delay, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		node1->runAction( repeat );
	}

	auto node2 = Node::create();
	if ( node2 )
	{
		addChild( node2 );

		node2->setColor( sColor3f::BLUE );
		node2->setSize( sSize( 100.0f, 100.0f ) );
		node2->setPosition( sPoint( 150.0f, 400.0f ) );

		auto toRight = RotateBy::create( 0.5f, 90.0f );
		auto toLeft = RotateBy::create( 0.5f, -90.0f );
		auto delay = DelayTime::create( 1.0f );

		auto seq = Sequence::create( toRight, toLeft, delay, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		node2->runAction( repeat );
	}

	auto node3 = Node::create();
	if ( node3 )
	{
		addChild( node3 );

		node3->setColor( sColor3f::YELLOW );
		node3->setSize( sSize( 100.0f, 100.0f ) );
		node3->setPosition( sPoint( 350.0f, 400.0f ) );

		auto toRight = RotateBy::create( 2.0f, 720.0f );
		auto toLeft = RotateBy::create( 2.0f, -720.0f );
		auto call1 = CallFunc::create( [ this, node3 ] () { node3->setVisible( false ); } );
		auto call2 = CallFunc::create( [ this, node3 ] () { node3->setVisible( true ); } );
		auto delay1 = DelayTime::create( 0.3f );
		auto delay2 = DelayTime::create( 0.3f );

		auto seq = Sequence::create( toRight, call1, delay1, call2, toLeft, delay2, nullptr );

		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		node3->runAction( repeat );
	}

	auto node4 = Node::create();
	if ( node4 )
	{
		addChild( node4 );

		node4->setColor( sColor3f::GREEN );
		node4->setSize( sSize( 100.0f, 50.0f ) );
		node4->setPosition( sPoint( 700.0f, 600.0f ) );

		auto toRight = MoveBy::create( 2.0f, sPoint( 200.0f, 0.0f ) );
		auto toLeft = MoveBy::create( 2.0f, sPoint( -200.0f, 0.0f ) );
		auto delay1 = DelayTime::create( 0.3f );
		auto delay2 = DelayTime::create( 0.3f );

		auto seq = Sequence::create( toRight, delay1, toLeft, delay2, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		node4->runAction( repeat );
	}

	auto node5 = Node::create();
	if ( node5 )
	{
		addChild( node5 );

		node5->setColor( sColor3f::PINK );
		node5->setSize( sSize( 100.0f, 50.0f ) );
		node5->setPosition( sPoint( 350.0f, 600.0f ) );

		auto call1 = CallFunc::create( [ this, node5 ] () {node5->setVisible( false ); } );
		auto call2 = CallFunc::create( [ this, node5 ] () {node5->setVisible( true ); } );
		auto delay1 = DelayTime::create( 0.1f );
		auto delay2 = DelayTime::create( 0.2f );

		auto seq = Sequence::create( call1, delay1, call2, delay2, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		node5->runAction( repeat );
	}

	auto node6 = Node::create();
	if ( node6 )
	{
		addChild( node6 );

		node6->setColor( sColor3f::BLACK );
		node6->setSize( sSize( 150.0f, 150.0f ) );
		node6->setPosition( sPoint( 700.0f, 400.0f ) );

		auto tint1 = TintTo::create( 1.0f, sColor3f::RED );
		auto tint2 = TintTo::create( 1.0f, sColor3f::GREEN );
		auto tint3 = TintTo::create( 1.0f, sColor3f::YELLOW );
		auto tint4 = TintTo::create( 1.0f, sColor3f::BLUE );

		auto seq = Sequence::create( tint1, tint2, tint3, tint4, nullptr );

		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		node6->runAction( repeat );
	}
}

void MyTestScene::update( float aDeltaTime )
{
	if ( mNode )
	{
		mNode->setPosition( mNode->getPosition() + sPoint( mMoveStep, 0.0f ) );

		if ( mNode->getPosition().x > Director::getInstance()->getVisibleSize().width + mNode->getSize().width / 2.0f )
		{
			mNode->setPosition( sPoint( 0.0f - mNode->getSize().width / 2.0f, mNode->getPosition().y ) );
		}
	}
}

bool MyTestScene::onLeftButtonClickDown( GLFWwindow* aWindow, const sPoint& aCursorPosition )
{
	return true;
}

void MyTestScene::onLeftButtonClickUp( GLFWwindow* aWindow, const sPoint& aCursorPosition )
{

}