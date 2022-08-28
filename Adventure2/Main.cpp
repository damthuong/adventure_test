#include <SFML/Graphics.hpp> 
#include<Windows.h> 
#include "Wall.h" 
#include "Unity.h" 
#include "Point2D.h" 
#include "Animation.h" 
#include <list>
#include <thread>
using namespace std;

void fun(float* deltaTime){
		deltaTime += 10;
}

int main()
{
	//khoi tao anh va Animation cho charactor 
	//Character character; 
	sf::Texture tAni_current;
	tAni_current.loadFromFile("../Data/Texture/ninja_stand.png");
	sf::Texture tAni_runRight;
	tAni_runRight.loadFromFile("../Data/Texture/ninja_right.png");
	sf::Texture tAni_runLeft;
	tAni_runLeft.loadFromFile("../Data/Texture/ninja_left.png");
	sf::Texture tAni_runDown;
	tAni_runDown.loadFromFile("../Data/Texture/ninja_down.png");


	sf::Texture tBoss_moveRight;
	tBoss_moveRight.loadFromFile("../Data/Texture/boss_moveRight.png");
	sf::Texture tBoss_moveLeft;
	tBoss_moveLeft.loadFromFile("../Data/Texture/boss_moveLeft.png");

	Animation ani;
	ani.Init(tAni_current, sf::Vector2i(6, 1), 0.1f);

	Animation boss;
	//boss.Init(tBoss_moveRight, sf::Vector2i(6, 1), 0.1f);
	int x_Boss = WINDOW_WIDTH-200;
	//boss.setTexture(tBoss_moveRight);
	boss.setScale(1.5f, 1.5f);
	boss.setPosition(x_Boss, MAX_Y_NINJA - 200);
	boss.getScale();
	int derection = 1;

//	ani_Cur.Init(tAni_current, sf::Vector2i(4, 1), 0.1f);
	ani.setTexture(tAni_current);
	int x_C = WINDOW_WIDTH/2;
	int y_C = MAX_Y_NINJA - 100;
	ani.setScale(0.7f, 0.7f);
	ani.setPosition(x_C, y_C);
	ani.getScale();

	//character run 

	//lay thoi gian 
	sf::Clock clock;
	float deltaTime = 0.f;
	//khoi tao tuong 
	Wall wall;
	int xW = wall.GetX();
	int yW = wall.GetY();
	int x = 0;

	//khoi tao man hinh game 
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Adventure Game");
	window.setFramerateLimit(500);
	//khoi tao anh tuong va background 
	sf::Texture tBackGround, tWall;
	tBackGround.loadFromFile("../Data/Texture/Background.png");
	tWall.loadFromFile("../Data/Texture/wall.png");

	

	//khoi tao noi chua 
	sf::Sprite spriteBg;
	sf::Sprite spriteWall;

	//chay chuong trinh 
	while (window.isOpen())
	{
		y_C = MAX_Y_NINJA - 100;
		//ani.Reset();
		ani.Init(tAni_current, sf::Vector2i(6, 1), 0.1f);
		ani.setTexture(tAni_current);
		
		deltaTime = clock.restart().asSeconds();
		//	deltaTime += 2; 
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			ani.Init(tAni_runRight, sf::Vector2i(6, 1), 0.1f);
			ani.setTexture(tAni_runRight);
			if (x < SIZE_BACKGROUD - WINDOW_WIDTH) {
				if (x_C == WINDOW_WIDTH/2) {
					x++;
					if (xW > -WALL_WIDTH) {
						xW--;
					}
					else if (xW == -WALL_WIDTH) {
						xW = wall.GetX() + WALL_WIDTH;
					}
				}	
				else {
					x_C++;
				}
			}

			else if (x == SIZE_BACKGROUD - WINDOW_WIDTH) {
				if (x_C <= WINDOW_WIDTH - 100)
					x_C++;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			ani.Init(tAni_runLeft, sf::Vector2i(6, 1), 0.1f);
			ani.setTexture(tAni_runLeft);
			//	if(x<=SIZE_BACKGROUD-WINDOW_WIDTH+1){ 

			if (x_C >= 0) {
				x_C--;
			}
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			y_C = MAX_Y_NINJA - 70;
			ani.Init(tAni_runDown, sf::Vector2i(6, 1), 0.1f);
			ani.setTexture(tAni_runDown);
			if (x < SIZE_BACKGROUD - WINDOW_WIDTH) {
				if (x_C == WINDOW_WIDTH / 2) {
					x++;
					if (xW > -WALL_WIDTH) {
						xW--;
					}
					else if (xW == -WALL_WIDTH) {
						xW = wall.GetX() + WALL_WIDTH;
					}
				}
				else {
					x_C++;
				}
			}

			else if (x == SIZE_BACKGROUD - WINDOW_WIDTH) {
				if (x_C <= WINDOW_WIDTH - 100)
					x_C++;
			}
		}

		if (x == SIZE_BACKGROUD - WINDOW_WIDTH) {
			
			//boss.Init(tBoss_moveRight, sf::Vector2i(6, 1), 0.1f);
			
		}


		if (x >= SIZE_BACKGROUD - WINDOW_WIDTH - 1) {
			boss.Update(deltaTime);

			if (x_Boss < WINDOW_WIDTH-200 && derection == 0) {
				boss.Init(tBoss_moveRight, sf::Vector2i(6, 1), 0.1f);
				boss.setTexture(tBoss_moveRight);
				x_Boss++;
			}
			else if (x_Boss > 0 && derection == 1) {
				boss.Init(tBoss_moveLeft, sf::Vector2i(6, 1), 0.1f);
				boss.setTexture(tBoss_moveLeft);
				x_Boss--;
			}
			if (x_Boss == WINDOW_WIDTH-200) {
				derection = 1;
			}
			else if (x_Boss == 0) {
				derection = 0;
			}
			//Sleep(10);
			boss.setPosition(x_Boss, MAX_Y_NINJA - 200);
		}

		window.clear();
		//hien animation 
		ani.Update(deltaTime);
		ani.setPosition(x_C, y_C);

		//gan anh vao noi chua 
		spriteBg.setTexture(tBackGround);
		spriteBg.setTextureRect(sf::IntRect(x, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

		//vi tri va kich thuong tuong 
		spriteWall.setTexture(tWall);
		spriteWall.setPosition(sf::Vector2f(xW + WALL_WIDTH, wall.GetY()));
		spriteWall.setScale(sf::Vector2f(1.f, 1.f));

		//ve 
		window.draw(spriteBg);
		window.draw(spriteWall);
		window.draw(ani);
		window.draw(boss);
		window.display();

		//dieu kien chay cua tuong 
		//Sleep(10); 
	}
	return 0;
}