#pragma once
#include"base/gameNode.h"
#include"Object/Unit/stage.h"
#include"Object/Unit/MonsterControl.h"
//#include"Player.h"

class testScene : public gameNode
{
private :
	stage * _stage;
	MonsterControl * _monsterControl;


public:
	testScene();
	~testScene();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳5
	virtual void render(/*HDC hdc*/);//그리는곳

};

