#include "TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../STB_IMAGE/stb_image.h"


TextureLoader::TextureLoader()
{
}

TextureLoader::~TextureLoader()
{
}

TextureLoader* TextureLoader::getInstance()
{
	static TextureLoader instance;

	return &instance;
}

std::pair< unsigned int, sSize > TextureLoader::loadTexture( const std::string& aFileName )
{
	std::pair< unsigned int, sSize > result = std::make_pair( 0u, sSize( 0.0f, 0.0f ) );

	auto iter = mLoadedTexture.find( aFileName );
	if ( iter == mLoadedTexture.end() )
	{
		unsigned int textureIndex = 0u;

		int width, height, cnt;
		unsigned char *data = stbi_load( aFileName.c_str(), &width, &height, &cnt, 0 );

		if ( data )
		{
			glGenTextures( 1, &textureIndex );
			glBindTexture( GL_TEXTURE_2D, textureIndex );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
			glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data );
			glBindTexture( GL_TEXTURE_2D, 0 );
			stbi_image_free( data );

			result.first = textureIndex;
			result.second.width = ( float )width;
			result.second.height = ( float )height;

			mLoadedTexture[ aFileName ] = result;
		}
	}
	else
	{
		result = ( *iter ).second;
	}

	return result;
}