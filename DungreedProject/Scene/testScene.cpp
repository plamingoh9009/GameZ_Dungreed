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
	IMAGEMANAGER->addImage("배경", "resource/image/배경/동원이여친.bmp", 1024 * 2, 900, true, RGB(255, 0, 255));
	_backGroudimg = IMAGEMANAGER->findImage("배경");



	return S_OK;
}

void testScene::release()
{
	_stage->release();
	_stage = nullptr;

	

	_monsterControl->release();
	_monsterControl = nullptr;
}

void testScene::update()
{
	_stage->update();

	_monsterControl->update();
	PLAYER->setBackGround(_backGroud);
	PLAYER->update();

}

void testScene::render()
{
	_backGroudimg->render(getMemDC(), PLAYER->getPlayercameraX(), PLAYER->getPlayercameraY());
	_stage->render();

	_monsterControl->render();

	PLAYER->render();
}
