#pragma once 

class Point2D {

private:

	int _x, _y;

	char _c;

public:

	Point2D();

	Point2D(int x, int y, char c);

	~Point2D();



	int GetX();

	int GetY();

	char GetC();

	void SetX(int x);

	void SetY(int y);



	void MoveLeft();

	void MoveRight();

	void MoveJump();



	void Display();

	void Clean();

};