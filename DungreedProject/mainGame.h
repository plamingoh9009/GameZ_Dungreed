#pragma once
#include "base/gameNode.h"
#include "Object/Unit/Player.h"
class mainGame : public gameNode
{
private:
	Player * _p;
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
};

