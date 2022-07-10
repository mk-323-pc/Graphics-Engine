#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <GLFW/glfw3.h>
#include "Types.h"
#include <vector>



class EventDispatcherListener
{
public:

	virtual bool onLeftButtonClickDown( const sPoint& aCursorPosition ) { return false; };
	virtual void onLeftButtonClickUp( const sPoint& aCursorPosition ) {};

	virtual bool onRightButtonClickDown( const sPoint& aCursorPosition ) { return false; };
	virtual void onRightButtonClickUp( const sPoint& aCursorPosition ) {};

	virtual void onCursorMoved( const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition ) {};
};


class EventDispatcher
{
	GLFWwindow* mWindow;

	static std::vector< EventDispatcherListener* > mEventDispatcherListeners;
	static std::vector< EventDispatcherListener* > mEventDispatcherActiveListeners;

	sPoint mPreviousCursorPosition;

	EventDispatcher();
	virtual ~EventDispatcher();

	static sPoint getCursorPosition( GLFWwindow* aWindow );

public:
	static EventDispatcher* getInstance();

	void initWindowCallBack( GLFWwindow* aWindow );

	void addEventDispatcherListener( EventDispatcherListener* aListener, bool aIsItPriorityListener = false );
	void delEventDispatcherListener( EventDispatcherListener* aListener );

	static void onMouseButtonCallBack( GLFWwindow* aWindow, int aButton, int aAction, int aMods );

	void update();
};


#endif