#include "MyTestScene.h"


MyTestScene::MyTestScene()
	: mMoveStep( 30.0f )
	, mTouchedNode( nullptr )
	, mTopLine( nullptr )
	, mBottomNode( nullptr )
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

void MyTestScene::createUI()
{
	auto stopBtn = Button::create( "../Resources/images/stop_normal.png", "../Resources/images/stop_clicked.png" );
	if ( stopBtn )
	{
		addChild( stopBtn );
		stopBtn->setListener( this );

		stopBtn->setName( "stop_btn" );
		stopBtn->setPosition( sPoint( 320.0f, 660.0f ) );
	}

	auto runBtn = Button::create( "../Resources/images/run_normal.png", "../Resources/images/run_clicked.png" );
	if ( runBtn )
	{
		addChild( runBtn );
		runBtn->setListener( this );

		runBtn->setName( "run_btn" );
		runBtn->setPosition( sPoint( 960.0f, 660.0f ) );
	}
}

void MyTestScene::init()
{
	EventDispatcher::getInstance()->addEventDispatcherListener( this );

	createUI();

	auto top = Node::create();
	if ( top )
	{
		addChild( top );

		top->setColor( sColor3f::GRAY );
		top->setSize( sSize( Director::getInstance()->getVisibleSize().width, 10.0f ) );
		top->setAnchorPoint( sPoint( 0.0f, 0.5f ) );
		top->setPosition( sPoint( 0.0f, 600.0f ) );

		mTopLine = top;
	}

	auto bottom = Node::create();
	if ( bottom )
	{
		addChild( bottom );

		bottom->setColor( sColor3f::GREEN );
		bottom->setSize( sSize( 300.0f, 10.0f ) );
		bottom->setPosition( sPoint( 0.0f, 50.0f ) );

		mBottomNode = bottom;
	}

	auto sprite1 = Sprite::create( "../Resources/images/scale.png" );
	if ( sprite1 )
	{
		addChild( sprite1 );
		mNodesVec.push_back( sprite1 );

		sprite1->setPosition( sPoint( 150.0f, 500.0f ) );
		
		auto scaleToMin = ScaleTo::create( 0.5f, 0.5f );
		auto scaleToMax = ScaleTo::create( 0.5f, 1.0f );
		auto delay = DelayTime::create( 0.5f );

		auto seq = Sequence::create( scaleToMin, scaleToMax, delay, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		sprite1->runAction( repeat );
	}

	auto sprite2 = Sprite::create( "../Resources/images/rotate_blue.png" );
	if ( sprite2 )
	{
		addChild( sprite2 );
		mNodesVec.push_back( sprite2 );

		sprite2->setPosition( sPoint( 150.0f, 300.0f ) );

		auto toRight = RotateBy::create( 0.5f, 90.0f );
		auto toLeft = RotateBy::create( 0.5f, -90.0f );
		auto delay = DelayTime::create( 1.0f );

		auto seq = Sequence::create( toRight, toLeft, delay, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		sprite2->runAction( repeat );
	}

	auto sprite3 = Sprite::create( "../Resources/images/rotate_yellow.png" );
	if ( sprite3 )
	{
		addChild( sprite3 );
		mNodesVec.push_back( sprite3 );

		sprite3->setPosition( sPoint( 550.0f, 300.0f ) );
		sprite3->setAnchorPoint( sPoint( 0.0f, 0.0f ) );

		auto toRight = RotateBy::create( 0.5f, 360.0f );
		auto toLeft = RotateBy::create( 0.5f, -360.0f );
		auto delay1 = DelayTime::create( 0.3f );
		auto delay2 = DelayTime::create( 0.3f );

		auto seq = Sequence::create( toRight, delay1, toLeft, delay2, nullptr );

		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		sprite3->runAction( repeat );
	}

	auto sprite4 = Sprite::create( "../Resources/images/move.png" );
	if ( sprite4 )
	{
		addChild( sprite4 );
		mNodesVec.push_back( sprite4 );

		sprite4->setPosition( sPoint( 900.0f, 500.0f ) );

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

		sprite4->runAction( repeat );
	}

	auto sprite5 = Sprite::create( "../Resources/images/callfunc.png" );
	if ( sprite5 )
	{
		addChild( sprite5 );
		mNodesVec.push_back( sprite5 );

		sprite5->setPosition( sPoint( 550.0f, 500.0f ) );

		auto call1 = CallFunc::create( [ this, sprite5 ] () { sprite5->setVisible( false ); } );
		auto call2 = CallFunc::create( [ this, sprite5 ] () { sprite5->setVisible( true ); } );
		auto delay1 = DelayTime::create( 0.1f );
		auto delay2 = DelayTime::create( 0.2f );

		auto seq = Sequence::create( call1, delay1, call2, delay2, nullptr );
		auto repeat = RepeatForever::create( seq );
		if ( repeat )
		{
			repeat->setTag( static_cast< int >( eActionTag::DEFAULT ) );
		}

		sprite5->runAction( repeat );
	}

	auto sprite6 = Sprite::create( "../Resources/images/tint.png" );
	if ( sprite6 )
	{
		addChild( sprite6 );
		mNodesVec.push_back( sprite6 );

		sprite6->setPosition( sPoint( 900.0f, 300.0f ) );

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

		sprite6->runAction( repeat );
	}
}

void MyTestScene::update( float aDeltaTime )
{
	if ( mBottomNode )
	{
		mBottomNode->setPosition( mBottomNode->getPosition() + sPoint( mMoveStep, 0.0f ) );

		if ( mBottomNode->getPosition().x > Director::getInstance()->getVisibleSize().width + mBottomNode->getSize().width / 2.0f )
		{
			mBottomNode->setPosition( sPoint( 0.0f - mBottomNode->getSize().width / 2.0f, mBottomNode->getPosition().y ) );
		}
	}
}

bool MyTestScene::onLeftButtonClickDown( const sPoint& aCursorPosition )
{
	auto result = false;

	for ( auto node : mNodesVec )
	{
		if ( node )
		{
			auto parent = node->getParent();
			if ( parent )
			{
				auto location = parent->convertToNodeSpace( aCursorPosition );
				
				if ( node->getBoundingBox().containsPoint( location ) )
				{
					mTouchedNode = node;

					mTouchedNode->stopActionByTag( static_cast< int >( eActionTag::DEFAULT ) );
					mTouchedNode->setVisible( true );
					mTouchedNode->setOpacity( 255.0f );
					
					mTouchOffset = mTouchedNode->getPosition() - location;

					result = true;
					break;
				}
			}
		}
	}

	return result;
}

void MyTestScene::onLeftButtonClickUp( const sPoint& aCursorPosition )
{
	if ( mTouchedNode )
	{
		mTouchedNode = nullptr;
		mTouchOffset = { 0.0f, 0.0f };
	}
}

void MyTestScene::onCursorMoved( const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition )
{
	if ( mTouchedNode )
	{
		auto parent = mTouchedNode->getParent();
		if ( parent )
		{
			mTouchedNode->setPosition( parent->convertToNodeSpace( aCurrentCursorPosition ) + mTouchOffset );

			if ( mTopLine )
			{
				if ( mTouchedNode->getBoundingBox().getMaxY() - mTopLine->getBoundingBox().getMinY() > FLT_EPSILON )
				{
					mTouchedNode->setPosition( sPoint(
						mTouchedNode->getPosition().x,
						mTopLine->getBoundingBox().getMinY() - mTouchedNode->getSize().height * ( 1.0f - mTouchedNode->getAnchorPoint().y ) ) );
				}
			}
		}
	}
}

void MyTestScene::onUIButtonClickEnd( Button* aButton )
{
	if ( aButton )
	{
		const auto& btnName = aButton->getName();

		if ( btnName == "stop_btn" )
		{
			for ( auto node : mNodesVec )
			{
				if ( node )
				{
					node->stopAllActions();
					node->setVisible( true );
					node->setOpacity( 255.0f );
				}
			}
		}
		else if ( btnName == "run_btn" )
		{

		}
	}
}