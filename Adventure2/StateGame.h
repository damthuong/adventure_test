#pragma once
#include "ResourceManager.h"

enum StateTypes
{
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	SETTING,
	ABOUT,
	HIGHSCORE,
	END,
};

class GameStateBase {
public:
	GameStateBase() {}
	virtual ~GameStateBase() {}

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

	static GameStateBase* CreateState(StateTypes st);
};
