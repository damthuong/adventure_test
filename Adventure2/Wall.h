#pragma once
#include <SFML/Graphics.hpp> 
#include "Point2D.h" 
#include "Unity.h" 

class Wall {
private:
	Point2D _position;
public:
	Wall();
	~Wall();
	int GetX();
	int GetY();
	void DisplayWall();
	void UpdateWall();
};