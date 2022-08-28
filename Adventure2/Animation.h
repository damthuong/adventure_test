#pragma once 

#include <SFML/Graphics.hpp> 
#include <time.h> 
#include<Windows.h> 

class Animation :public sf::Sprite {
private:
	//	int frame; 
	//int m_direction; 
	float _frameTime;
	float _currentTime;
	//int m_animation_timer; 
	sf::Vector2i _frameNum;
	sf::Vector2i _currentFrame;
	sf::Vector2i _rectUV;
	sf::Vector2i _rectSize;
	sf::IntRect _rect;
public:
	Animation();
	void Init(sf::Texture& texture, sf::Vector2i frameNum, float FrameTime);
	~Animation();
	void Update(float deltaTime);
	void CaculatorRectSize();
	void CaculatorRectUV();
	void ApplyRect();
	void Reset();
};
