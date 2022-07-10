#ifndef SPRITE_H
#define SPRITE_H

#include "Node.h"

class Sprite
	: public Node
{
	unsigned int mTextureIndex;

	bool initWithFile( const std::string& aFileName );

protected:

	virtual void render() override;

public:

	Sprite();
	virtual ~Sprite();

	static Sprite* create( const std::string& aFilePath );
};

#endif
