#pragma once
#include "Player.h"
class TownScene: public gameNode
{
private:
	image * _mapImg;
	
public:
	TownScene();
	~TownScene();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

