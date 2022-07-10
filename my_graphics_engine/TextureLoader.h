#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <GLFW/glfw3.h>
#include "Types.h"
#include <map>


class TextureLoader
{
	std::map< std::string, std::pair< unsigned int, sSize > > mLoadedTexture;

	TextureLoader();
	~TextureLoader();

public:
	static TextureLoader* getInstance();

	std::pair< unsigned int, sSize > loadTexture( const std::string& aFileName );

};

#endif