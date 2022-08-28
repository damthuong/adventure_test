#pragma once 
#include <SFML/Graphics.hpp> 
#include<Windows.h> 

#include "Singleton.h"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 793 
#define TITLE_GAME "Adventure_Game"
#define WALL_WIDTH 50 
#define WALL_HEIGHT 50 
#define MAX_Y_NINJA 750 
#define CREEP_WIDTH 50 
#define CREEP_HEIGHT 50 
#define SIZE_BACKGROUD 5568

#define WConnect WindowConnector::GetInstance()

class WindowConnector :public CSingleton<WindowConnector> {
public:
	WindowConnector();
	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
private:
	sf::RenderWindow* m_Window;
};


void CursorGotoXY(int x, int y);
int GetRandomValue(int vlMin, int vlMax);