#include"Unity.h" 
#include<time.h> 
#include<ctime> 
using namespace std;

void CursorGotoXY(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

//random Y_Wall and random time creep 
//int x = WINDOW_WIDTH - WALL_WIDTH; 

int GetRandomValue(int vlMin, int vlMax) {
	int temp;
	temp = (rand() * ((unsigned int)clock()) % vlMax);
	return ((temp % (vlMax - vlMin)) + vlMin);
}