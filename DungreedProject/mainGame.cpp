#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);
	SCENEMANAGER->addScene("startscene", new startscene);
	SCENEMANAGER->addScene("testScene", new testScene);
	SCENEMANAGER->changeScene("startscene");
	_ui = new UI;
	_ui->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	_ui->release();
}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	_ui->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=====================================================


	SCENEMANAGER->render();
	TIMEMANAGER->render(getMemDC());
	_ui->render(); 
	//=====================================================
	//������� ������ HDC�� �׸���.(��������!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}









