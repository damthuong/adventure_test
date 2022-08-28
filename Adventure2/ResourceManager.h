#pragma once
#include <SFML/Graphics.hpp> 
#include "Singleton.h"
#include <string>
#include <map>


class ResourceManager :public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();

	void AddTexture(std::string name);
	void RemoveTexture(std::string name);
	sf::Texture* GetTexture(std::string name);

	void AddFonts(std::string name);
	void RemoveFonts(std::string name);
	sf::Font* GetFonts(std::string name);

private:
	std::map<std::string, sf::Texture*> _MapTexture;
	std::map<std::string, sf::Font*> _MapFont;

	std::string _Path;
	std::string _TexturePath;
	std::string _FontPath;
};
