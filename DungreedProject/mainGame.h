#pragma once
#include "base/gameNode.h"
#include "Scene/testScene.h"
#include "Scene/startscene.h"
#include "UI/UI.h"
class mainGame : public gameNode
{
private:
	UI * _ui;
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
};

