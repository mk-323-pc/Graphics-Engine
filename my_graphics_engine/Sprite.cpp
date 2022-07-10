#include "Sprite.h"
#include "TextureLoader.h"
#include "Director.h"


Sprite::Sprite()
	: mTextureIndex( 0u )
{
}

Sprite::~Sprite()
{
}

Sprite* Sprite::create( const std::string& aFileName )
{
	Sprite* result = new Sprite;

	if ( result )
	{
		if ( result->initWithFile( aFileName ) )
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

bool Sprite::initWithFile( const std::string& aFileName )
{
	auto result = false;

	if ( !aFileName.empty() )
	{
		auto textureInfoPair = TextureLoader::getInstance()->loadTexture( aFileName );
		
		if ( textureInfoPair.first )
		{
			mTextureIndex = textureInfoPair.first;

			setSize( textureInfoPair.second );
			setColor( sColor3f::WHITE );
			setOpacity( 255.0f );

			result = true;
		}
	}

	return result;
}

void Sprite::render()
{
	//Debug info
	auto name = getName();
	//

	if ( mIsVisible )
	{
		/*for ( auto child : mChildren )
		{
			if ( child )
			{
				child->render();
			}
		}*/

		float texCoord[] = { 0.0f, 1.0f,	1.0f, 1.0f,		1.0f, 0.0f,		0.0f, 0.0f };
		float vertex[] =
		{
			0.0f - mAnchorPoint.x, 0.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef,
			1.0f - mAnchorPoint.x, 0.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef,
			1.0f - mAnchorPoint.x, 1.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef,
			0.0f - mAnchorPoint.x, 1.0f - mAnchorPoint.y, mLocalZOrder * mZOrderCoef
		};

		glPushMatrix();

		glColor4f( mColor.red / 255.0f, mColor.green / 255.0f, mColor.blue / 255.0f, mOpacity / 255.0f );

		if ( mParent )
		{
			auto visibleSize = Director::getInstance()->getVisibleSize();
			auto convertedPosition = mParent->convertToWorldSpace( mPosition );

			glTranslatef(
				convertedPosition.x / ( 0.5f * visibleSize.width ),
				convertedPosition.y / ( 0.5f * visibleSize.height ), 0.0f );

			glScalef(
				mSize.width * getSummaryScale() / ( 0.5f * visibleSize.width ),
				mSize.height * getSummaryScale() / ( 0.5f * visibleSize.height ), 1.0f );
		}

		glRotatef( -mRotation, 0.0f, 0.0f, 1.0f );

		glBindTexture( GL_TEXTURE_2D, mTextureIndex );

		glEnableClientState( GL_VERTEX_ARRAY );
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );

		glVertexPointer( 3, GL_FLOAT, 0, vertex );
		glTexCoordPointer( 2, GL_FLOAT, 0, texCoord );
		glDrawArrays( GL_TRIANGLE_FAN, 0, 4 );

		glDisableClientState( GL_VERTEX_ARRAY );
		glDisableClientState( GL_TEXTURE_COORD_ARRAY );

		glBindTexture( GL_TEXTURE_2D, 0u );

		glPopMatrix();
	}
}