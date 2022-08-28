#pragma once
#include <SFML/Graphics.hpp> 
#include"Animation.h"

class Application {
public:
	void Run();
	~Application();
private:
	void Init();
	void Update(float deltaTime);
	void Render();
private:
	sf::RenderWindow* _window;

};