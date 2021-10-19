#include "textureHolder.h"

#include<cassert>

// loads resource and stores it in mTextureMap
void TextureHolder::load(Textures::ID id, const std::string& filename)
{
	std::unique_ptr<sf::Texture>texture{ new sf::Texture{} };
	if (!texture->loadFromFile(filename)) {
		throw std::runtime_error("Texture::load - Failed to load " + filename);
	}

	//insert into map
	auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
	assert(inserted.second);
}

sf::Texture& TextureHolder::get(Textures::ID id)
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id) const
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	return *found->second;
}
