#include "stdafx.h"
#include "TownScene.h"


TownScene::TownScene()
{
}
TownScene::~TownScene()
{
}

HRESULT TownScene::init()
{
	PLAYER->init();
	return S_OK;
}

void TownScene::release()
{
}

void TownScene::update()
{
	PLAYER->update();
}

void TownScene::render()
{
	TextOut(getMemDC(), 50, 50, "Â¥ÀÜ", strlen("Â¥ÀÜ"));
	PLAYER->render();
}
