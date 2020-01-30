#include "stdafx.h"
#include "camel.h"


camel::camel()
{
}


camel::~camel()
{
}

HRESULT camel::init()
{
	_camel = IMAGEMANAGER->addImage("camel", "images/camel.bmp", 
		300, 267, true, RGB(255, 0, 255));

	//처음 부터 끝까지 돌리자
	_ani1 = new animation;
	_ani1->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani1->setDefPlayFrame(false, true);
	_ani1->setFPS(1);
	//배열에 담아서 돌리자
	int arrAni[] = { 0,1,2,3,4,5,6,7,8,9 };
	_ani2 = new animation;
	_ani2->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani2->setPlayFrame(arrAni, 10, true);
	_ani2->setFPS(1);

	_ani3 = new animation;
	_ani3->init(_camel->getWidth(), _camel->getHeight(), 75, 89);
	_ani3->setPlayFrame(1, 10, false, true);
	_ani3->setFPS(1);


	return S_OK;
}

void camel::release()
{
	SAFE_DELETE(_ani1);
	SAFE_DELETE(_ani2);
	SAFE_DELETE(_ani3);
}

void camel::update()
{
	if(KEYMANAGER->isOnceKeyDown('1'))
	{
		_ani1->start();
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_ani2->start();
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_ani3->start();
	}
	_ani1->frameUpdate(0.4f);
	_ani2->frameUpdate(0.1f);
	_ani3->frameUpdate(1.0f);

}

void camel::render()
{
	_camel->aniRender(getMemDC(), WINSIZEX /2 -200, WINSIZEY / 2, _ani1);
	_camel->aniRender(getMemDC(), WINSIZEX /2 , WINSIZEY / 2, _ani2);
	_camel->aniRender(getMemDC(), WINSIZEX /2 +200, WINSIZEY / 2, _ani3);
}
