#pragma once
#include "gameNode.h"
#include "CharactorSelect.h"
#include "TownScene.h"
class GameScene: public gameNode
{
public:
	GameScene();
	~GameScene();
	HRESULT init();
	void release();
	void update();
	void render();
};

