#include <SFML/Graphics.hpp> 
#include "Wall.h" 
#include "Unity.h" 



// 



Wall::Wall() {

	_position = Point2D(WINDOW_WIDTH - WALL_WIDTH, GetRandomValue(MAX_Y_NINJA - WALL_HEIGHT - 300, MAX_Y_NINJA - WALL_HEIGHT), '0');

}

Wall::~Wall() {}

int Wall::GetX() {

	return _position.GetX();

}

int Wall::GetY() {

	return _position.GetY();

}



void Wall::DisplayWall() {

	_position.Display();

}



void Wall::UpdateWall() {

	_position.SetY(GetRandomValue(MAX_Y_NINJA - WALL_HEIGHT - 300, MAX_Y_NINJA - WALL_HEIGHT));

}