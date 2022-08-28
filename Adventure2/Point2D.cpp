#include "Point2D.h" 

#include "Unity.h" 

#include<iostream> 

using namespace std;



Point2D::Point2D() {}

Point2D::Point2D(int x, int y, char c) {
	_x = x;
	_y = y;
	_c = c;
}

Point2D::~Point2D() {}

int Point2D::GetX() {
	return _x;
}



int Point2D::GetY() {
	return _y;
}



void Point2D::SetX(int x) {
	_x = x;
}



void Point2D::SetY(int y) {
	_y = y;
}



char Point2D::GetC() {
	return _c;
}



void Point2D::MoveLeft() {
	_x--;
}

void Point2D::MoveRight() {
	_x++;
}

void Point2D::MoveJump() {

}



void Point2D::Display() {

	CursorGotoXY(_x, _y);

	std::cout << _c;

}

void Point2D::Clean() {

	CursorGotoXY(_x, _y);

	std::cout << ' ';

}