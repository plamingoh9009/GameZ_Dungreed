#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
}
GameScene::~GameScene()
{
}
HRESULT GameScene::init()
{
	SCENEMANAGER->addScene("CharactorSelect", new CharactorSelect);
	SCENEMANAGER->addScene("TownScene", new TownScene);
	SCENEMANAGER->changeScene("CharactorSelect");
	return S_OK;
}
void GameScene::release()
{
	SCENEMANAGER->release();
}
void GameScene::update()
{
	SCENEMANAGER->update();
}
void GameScene::render()
{
	SCENEMANAGER->render();
}
