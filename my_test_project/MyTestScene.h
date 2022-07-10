#ifndef MY_TEST_SCENE_H
#define MY_TEST_SCENE_H

#include "..\my_graphics_engine\GraphicsEngine.h"

class MyTestScene
	: public Scene
{
	enum class eActionTag
	{
		DEFAULT = 101
	};

	float mMoveStep;

	sPoint mTouchOffset;

	Node* mTouchedNode;
	Node* mTopLine;
	Node* mBottomNode;

	std::vector< Node* > mNodesVec;
	std::vector< Action* > mSavedActions;

	void init();

	void createUI();
	void createExampleNodes();

protected:

	virtual void update( float aDeltaTime ) override;

	// EventDispatcherListener 
	virtual bool onLeftButtonClickDown( const sPoint& aCursorPosition ) override;
	virtual void onLeftButtonClickUp( const sPoint& aCursorPosition ) override;
	virtual void onCursorMoved( const sPoint& aPreviousCursorPosition, const sPoint& aCurrentCursorPosition ) override;

	// ButtonListener
	virtual void onUIButtonClickEnd( Button* aButton ) override;

public:
	MyTestScene();
	~MyTestScene();

	static MyTestScene* create();

};

#endif

