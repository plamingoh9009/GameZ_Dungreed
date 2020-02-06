#pragma once
#include "base/gameNode.h"
#include "Scene/testScene.h"
<<<<<<< HEAD
#include "Scene/startscene.h"
#include "UI/UI.h"
class mainGame : public gameNode
{
private:
	UI * _ui;
=======
class mainGame : public gameNode
{
private:
	
>>>>>>> master
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
};

