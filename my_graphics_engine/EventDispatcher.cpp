#include "EventDispatcher.h"


std::vector< EventDispatcherListener* > EventDispatcher::mEventDispatcherListeners = {};
std::vector< EventDispatcherListener* > EventDispatcher::mEventDispatcherActiveListeners = {};

EventDispatcher::EventDispatcher()
	: mWindow( nullptr )
{
}

EventDispatcher::~EventDispatcher()
{
}

EventDispatcher* EventDispatcher::getInstance()
{
	static EventDispatcher instance;

	return &instance;
}

void EventDispatcher::initWindowCallBack( GLFWwindow* aWindow )
{
	if ( aWindow )
	{
		mWindow = aWindow;

		mPreviousCursorPosition = getCursorPosition( aWindow );

		glfwSetMouseButtonCallback( aWindow, EventDispatcher::onMouseButtonCallBack );
	}
}

void EventDispatcher::addEventDispatcherListener( EventDispatcherListener* aListener, bool aIsItPriorityListener )
{
	auto iter = std::find( mEventDispatcherListeners.begin(), mEventDispatcherListeners.end(), aListener );
	if ( iter == mEventDispatcherListeners.end() )
	{
		if ( aIsItPriorityListener )
		{
			mEventDispatcherListeners.emplace( mEventDispatcherListeners.begin(), aListener );
		}
		else
		{
			mEventDispatcherListeners.push_back( aListener );
		}
	}
}

void EventDispatcher::delEventDispatcherListener( EventDispatcherListener* aListener )
{
	auto iter = std::find( mEventDispatcherListeners.begin(), mEventDispatcherListeners.end(), aListener );
	if ( iter != mEventDispatcherListeners.end() )
	{
		mEventDispatcherListeners.erase( iter );
	}
}

void EventDispatcher::onMouseButtonCallBack( GLFWwindow* aWindow, int aButton, int aAction, int aMods )
{
	if ( aWindow )
	{
		auto cursorPosition = getCursorPosition( aWindow );

		if ( aButton == 0 )
		{
			if ( aAction == 1 )
			{
				for ( auto listener : mEventDispatcherListeners )
				{
					if ( listener )
					{
						if ( listener->onLeftButtonClickDown( cursorPosition ) )
						{
							mEventDispatcherActiveListeners.push_back( listener );
						}
					}
				}
			}
			else if ( aAction == 0 )
			{
				for ( auto listener : mEventDispatcherActiveListeners )
				{
					if ( listener )
					{
						listener->onLeftButtonClickUp( cursorPosition );
					}
				}

				mEventDispatcherActiveListeners.clear();
			}
		}
		else if ( aButton == 1 )
		{
			if ( aAction == 1 )
			{
				for ( auto listener : mEventDispatcherListeners )
				{
					if ( listener )
					{
						if ( listener->onRightButtonClickDown( cursorPosition ) )
						{
							mEventDispatcherActiveListeners.push_back( listener );
						}
					}
				}
			}
			else if ( aAction == 0 )
			{
				for ( auto listener : mEventDispatcherActiveListeners )
				{
					if ( listener )
					{
						listener->onRightButtonClickUp( cursorPosition );
					}
				}

				mEventDispatcherActiveListeners.clear();
			}
		}
	}
}

sPoint EventDispatcher::getCursorPosition( GLFWwindow* aWindow )
{
	int width = 0;
	int height = 0;

	double x = 0.0;
	double y = 0.0;

	glfwGetCursorPos( aWindow, &x, &y );
	glfwGetWindowSize( aWindow, &width, &height );

	sPoint cursorPosition( ( float )x, ( float )height - ( float )y );

	return cursorPosition;
}

void EventDispatcher::update()
{
	if ( mWindow )
	{
		auto cursorPosition = getCursorPosition( mWindow );

		if ( fabs( mPreviousCursorPosition.x - cursorPosition.x ) > FLT_EPSILON
			|| fabs( mPreviousCursorPosition.y - cursorPosition.y ) > FLT_EPSILON )
		{
			for ( auto listener : mEventDispatcherActiveListeners )
			{
				if ( listener )
				{
					listener->onCursorMoved( mPreviousCursorPosition, cursorPosition );
				}
			}

			mPreviousCursorPosition = cursorPosition;
		}
	}
}

