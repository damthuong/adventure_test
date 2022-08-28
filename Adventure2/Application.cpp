#include <SFML/Graphics.hpp>
#include "Application.h"
#include<Windows.h> 
#include "Wall.h" 
#include "Unity.h" 
#include "Point2D.h" 
#include "Animation.h" 
#include <list>
#include <thread>



Application::~Application()
{
	if (_window != nullptr) delete _window;
}

void Application::Init()
{
	_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE_GAME, sf::Style::Close);
	_window->setFramerateLimit(60);
	_window->setVerticalSyncEnabled(false);
}

void Application::Run()
{
	Init();
	sf::Clock clock;
	float deltaTime = 0.f;
	while (_window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		//y_C = MAX_Y_NINJA - 100;
		//ani.Init(tAni_current, sf::Vector2i(6, 1), 0.1f);
		//ani.setTexture(tAni_current);

		//deltaTime = clock.restart().asSeconds();
		////	deltaTime += 2;

		sf::Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window->close();
		}
		Update(deltaTime);
		Render();
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		//	ani.Init(tAni_runRight, sf::Vector2i(6, 1), 0.1f);
		//	ani.setTexture(tAni_runRight);
		//	if (x < SIZE_BACKGROUD - WINDOW_WIDTH) {
		//		if (x_C == WINDOW_WIDTH / 2) {
		//			x++;
		//			if (xW > -WALL_WIDTH) {
		//				xW--;
		//			}
		//			else if (xW == -WALL_WIDTH) {
		//				xW = wall.GetX() + WALL_WIDTH;
		//			}
		//		}
		//		else {
		//			x_C++;
		//		}
		//	}

		//	else if (x == SIZE_BACKGROUD - WINDOW_WIDTH) {
		//		if (x_C <= WINDOW_WIDTH - 100)
		//			x_C++;
		//	}
		//}

		//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		//	ani.Init(tAni_runLeft, sf::Vector2i(6, 1), 0.1f);
		//	ani.setTexture(tAni_runLeft);
		//	//	if(x<=SIZE_BACKGROUD-WINDOW_WIDTH+1){ 

		//	if (x_C >= 0) {
		//		x_C--;
		//	}
		//}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		//	y_C = MAX_Y_NINJA - 70;
		//	ani.Init(tAni_runDown, sf::Vector2i(6, 1), 0.1f);
		//	ani.setTexture(tAni_runDown);
		//	if (x < SIZE_BACKGROUD - WINDOW_WIDTH) {
		//		if (x_C == WINDOW_WIDTH / 2) {
		//			x++;
		//			if (xW > -WALL_WIDTH) {
		//				xW--;
		//			}
		//			else if (xW == -WALL_WIDTH) {
		//				xW = wall.GetX() + WALL_WIDTH;
		//			}
		//		}
		//		else {
		//			x_C++;
		//		}
		//	}

		//	else if (x == SIZE_BACKGROUD - WINDOW_WIDTH) {
		//		if (x_C <= WINDOW_WIDTH - 100)
		//			x_C++;
		//	}
		//}

		//if (x == SIZE_BACKGROUD - WINDOW_WIDTH) {

		//	//boss.Init(tBoss_moveRight, sf::Vector2i(6, 1), 0.1f);

		//}


		//if (x >= SIZE_BACKGROUD - WINDOW_WIDTH - 1) {
		//	boss.Update(deltaTime);

		//	if (x_Boss < WINDOW_WIDTH - 200 && derection == 0) {
		//		boss.Init(tBoss_moveRight, sf::Vector2i(6, 1), 0.1f);
		//		boss.setTexture(tBoss_moveRight);
		//		x_Boss++;
		//	}
		//	else if (x_Boss > 0 && derection == 1) {
		//		boss.Init(tBoss_moveLeft, sf::Vector2i(6, 1), 0.1f);
		//		boss.setTexture(tBoss_moveLeft);
		//		x_Boss--;
		//	}
		//	if (x_Boss == WINDOW_WIDTH - 200) {
		//		derection = 1;
		//	}
		//	else if (x_Boss == 0) {
		//		derection = 0;
		//	}
		//	//Sleep(10);
		//	boss.setPosition(x_Boss, MAX_Y_NINJA - 200);
		//}


		//hien animation 

		//ani.Update(deltaTime);
		//ani.setPosition(x_C, y_C);

		////gan anh vao noi chua 
		//spriteBg.setTexture(tBackGround);
		//spriteBg.setTextureRect(sf::IntRect(x, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

		////vi tri va kich thuong tuong 
		//spriteWall.setTexture(tWall);
		//spriteWall.setPosition(sf::Vector2f(xW + WALL_WIDTH, wall.GetY()));
		//spriteWall.setScale(sf::Vector2f(1.f, 1.f));

		//ve 


		//dieu kien chay cua tuong 
		//Sleep(10); 
	}
}

void Application::Update(float deltaTime)
{
	//Code
}

void Application::Render()
{
	_window->clear();

	//draw
	/*window.draw(spriteBg);
	window.draw(spriteWall);
	window.draw(ani);
	window.draw(boss);*/
	_window->display();
}
