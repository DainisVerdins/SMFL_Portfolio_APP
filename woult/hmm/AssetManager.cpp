#include "AssetManager.h"
#include<cassert>
#include<iostream>
AssetManager* AssetManager::sInstance = nullptr;
AssetManager::AssetManager()
{
	//Only one AssetManager to exist
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(const std::string& filename)
{
	auto& texMap = sInstance->m_Texture;

	//see if the texture is already loaded
	auto pairFound = texMap.find(filename);
	//if yes , return the texture
	if (pairFound!=texMap.end())
	{
		return pairFound->second;
	}
	else {//load texture and return it 
		//create element in the texture map
		auto& texture = texMap[filename];
		if (!texture.loadFromFile(filename)) {
			std::cout << "cannot load " << filename << "\n";
		}
		return texture;
	}
}
