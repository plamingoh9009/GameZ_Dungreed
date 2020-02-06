#include "stdafx.h"
#include "stage.h"

stage::stage()
{
}

stage::~stage()
{
}

HRESULT stage::init()
{
	gameNode::init(true);

	//ground = RectMake(0, WINSIZEY - (WINSIZEY / 4) , WINSIZEX, WINSIZEY / 4);


	//////////////////////////////////////////////////////////////////////////////////////////////
	ground = RectMake(0, WINSIZEY - (WINSIZEY / 4), WINSIZEX, WINSIZEY / 4);//나중에 지워 가상의 땅이야
	/////////////////////////////////////////////////////////////////////////////////////////////

	return S_OK;
}

void stage::release()
{
}

void stage::update()
{
}

void stage::render()
{
	//Rectangle(getMemDC(), ground.left, ground.top, ground.right, ground.bottom);
}
