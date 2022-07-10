#ifndef BUTTON_H
#define BUTTON_H

#include "Sprite.h"
#include "EventDispatcher.h"

class Button;
class ButtonListener
{
public:
	virtual void onUIButtonClickBegin( Button* aButton ) {};
	virtual void onUIButtonClickEnd( Button* aButton ) {};
	virtual void onUIButtonClickCancel( Button* aButton ) {};
};


class Button
	: public Node
	, public EventDispatcherListener
{
	ButtonListener* mButtonListener;

	Node* mNormal;
	Node* mClicked;
	Node* mDisabled;

	bool mIsButtonClicked;

	bool initWithFile( const std::string& aFileNameNormal, const std::string& aFileNameClicked, const std::string& aFileNameDisabled );

protected:

	// EventDispatcher callback
	virtual bool onLeftButtonClickDown( const sPoint& aCursorPosition ) override;
	virtual void onLeftButtonClickUp( const sPoint& aCursorPosition ) override;

	virtual void onCursorMoved( const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition ) override;

public:

	Button();
	virtual ~Button();

	static Button* create( const std::string& aFileNameNormal, const std::string& aFileNameClicked = "", const std::string& aFileNameDisabled = "" );

	Node* createInnerElement( const std::string& aFileName );

	void setListener( ButtonListener* aListener );

	void setAnchorPoint( const sPoint& aPoint ) = delete;
};


#endif
