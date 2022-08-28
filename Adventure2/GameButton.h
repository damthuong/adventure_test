#pragma once
//#include "WindowConnector.h"
#include "ResourceManager.h"

class GameButton :public sf::RectangleShape {
public:
	GameButton();
	~GameButton();

	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void HandleTouchEvent();
	bool isHandle();
private:
//	void (*m_btnClickFunc)();
	bool _isHandling;
};