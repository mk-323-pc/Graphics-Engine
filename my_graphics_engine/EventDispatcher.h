#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <GLFW/glfw3.h>
#include "Types.h"
#include <vector>



class EventDispatcherListener
{
public:

	virtual bool onLeftButtonClickDown( GLFWwindow* aWindow, const sPoint& aCursorPosition ) { return false; };
	virtual void onLeftButtonClickUp( GLFWwindow* aWindow, const sPoint& aCursorPosition ) {};

	virtual bool onRightButtonClickDown( GLFWwindow* aWindow, const sPoint& aCursorPosition ) { return false; };
	virtual void onRightButtonClickUp( GLFWwindow* aWindow, const sPoint& aCursorPosition ) {};

	virtual void onCursorMoved( GLFWwindow* aWindow, const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition ) {};
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