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

	RECT _backGroud;
	image* _backGroudimg;


public:
	testScene();
	~testScene();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�5
	virtual void render(/*HDC hdc*/);//�׸��°�


	RECT getbackGroud() {return _backGroud;}

};

