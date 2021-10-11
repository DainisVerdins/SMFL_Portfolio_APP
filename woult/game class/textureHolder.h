#pragma once
#include<memory>//unique ptr
#include<map>

#include <SFML/Graphics.hpp>

namespace Textures {
	enum class ID {Landscape,Airplane,Missile};
}

class TextureHolder
{

	void load(Textures::ID id, const std::string& filename);
	//get texture by id
	sf::Texture& get(Textures::ID id);
	const sf::Texture& get(Textures::ID id) const;
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

