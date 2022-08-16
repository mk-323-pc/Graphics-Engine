#include "Button.h"


Button::Button()
	: mNormal( nullptr )
	, mClicked( nullptr )
	, mDisabled( nullptr )
	, mIsButtonClicked( false )
{
}

Button::~Button()
{
}

Button* Button::create( const std::string& aFileNameNormal, const std::string& aFileNameClicked, const std::string& aFileNameDisabled )
{
	Button* result = new ( std::nothrow ) Button();

	if ( result )
	{
		if ( result->initWithFile( aFileNameNormal, aFileNameClicked, aFileNameDisabled ) )
		{
			result->autorelease();
		}
		else
		{
			delete result;
			result = nullptr;
		}
	}

	return result;
}

bool Button::initWithFile( const std::string& aFileNameNormal, const std::string& aFileNameClicked, const std::string& aFileNameDisabled )
{
	auto result = false;

	mNormal = createInnerElement( aFileNameNormal );
	if ( mNormal )
	{
		result = true;

		mNormal->setVisible( true );
		
		setSize( mNormal->getSize() );

		mClicked = createInnerElement( aFileNameClicked );
		mDisabled = createInnerElement( aFileNameDisabled );
	}

	if ( result )
	{
		this->setOpacity( 0.0f );
		EventDispatcher::getInstance()->addEventDispatcherListener( this, true );
	}

	return result;
}

Node* Button::createInnerElement( const std::string& aFileName )
{
	Node* innerElement = nullptr;

	if ( !aFileName.empty() )
	{
		innerElement = Sprite::create( aFileName );

		if ( innerElement )
		{
			addChild( innerElement );

			innerElement->setVisible( false );
		}
	}

	return innerElement;
}

void Button::setListener( ButtonListener* aListener )
{
	mButtonListener = aListener;
}

bool Button::onLeftButtonClickDown( const sPoint& aCursorPosition )
{
	auto result = false;

	if ( mParent )
	{
		auto localPosition = mParent->convertToNodeSpace( aCursorPosition );

		if ( getBoundingBox().containsPoint( localPosition ) )
		{
			mIsButtonClicked = true;

			if ( mClicked && mNormal)
			{
				mNormal->setVisible( false );
				mClicked->setVisible( true );
			}

			if ( mButtonListener )
			{
				mButtonListener->onUIButtonClickBegin( this );
			}

			result = true;
		}
	}

	return result;
}

void Button::onLeftButtonClickUp( const sPoint& aCursorPosition )
{
	if ( mIsButtonClicked && mParent )
	{
		mIsButtonClicked = false;

		if ( mClicked && mNormal )
		{
			mNormal->setVisible( true );
			mClicked->setVisible( false );
		}

		auto localPosition = mParent->convertToNodeSpace( aCursorPosition );

		if ( getBoundingBox().containsPoint( localPosition ) )
		{
			if ( mButtonListener )
			{
				mButtonListener->onUIButtonClickEnd( this );
			}
		}
		else
		{
			if ( mButtonListener )
			{
				mButtonListener->onUIButtonClickCancel( this );
			}
		}
	}
}

void Button::onCursorMoved( const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition )
{
	if ( mIsButtonClicked && mParent )
	{
		auto localPosition = mParent->convertToNodeSpace( aCurrentCursorPosition );

		if ( getBoundingBox().containsPoint( localPosition ) )
		{
			if ( mClicked && mNormal )
			{
				mNormal->setVisible( false );
				mClicked->setVisible( true );
			}
		}
		else
		{
			if ( mClicked && mNormal )
			{
				mNormal->setVisible( true );
				mClicked->setVisible( false );
			}
		}
	}
}
