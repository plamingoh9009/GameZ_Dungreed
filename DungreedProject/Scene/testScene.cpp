#include "stdafx.h"
#include "testScene.h"

testScene::testScene()
{
}

testScene::~testScene()
{
}

HRESULT testScene::init()
{
	gameNode::init(true);
	_stage  = new stage;
	_stage->init();
	PLAYER->init();
	_monsterControl = new MonsterControl;
	_monsterControl->init();


	return S_OK;
}

void testScene::release()
{
	_stage->release();
	_stage = nullptr;

	PLAYER->release();

	_monsterControl->release();
	_monsterControl = nullptr;
}

void testScene::update()
{
	_stage->update();

	_monsterControl->update();
	PLAYER->update();

}

void testScene::render()
{
	_stage->render();

	_monsterControl->render();

	PLAYER->render();
}
