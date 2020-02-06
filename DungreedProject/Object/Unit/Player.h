#pragma once
#include "base/gameNode.h"
#include "base/singletonBase.h"
#include "Object/Unit/stage.h"

enum player_WAY
{
	Left=0,
	Right
};

enum player_MOVE
{
	Idle=0,
	Move,
	Jump
};
class Player : public gameNode  ,public singletonBase<Player>
{
private:


	stage* _stage;

	player_WAY _playerWay;
	player_MOVE _playerMove;
	RECT _playerRC;
	image* _playerimg;
	animation* _playerani;
	int _playerFocusX;
	int _playerSpeed;
	int _playerJumpCount;
	float _playerJumpPower;
	float _playerJumpGravity;
	float _playerframeSpeed;
	int _playerHP;

	//���߿� �սô�.
	//int _playerAtk;
	//int _playerDef;
	//bool b_playerFight;

	/////////ī�޶�///////////

	int _focousplayerX; //�÷��̾� RC ����
	int _focousplayerY; //�÷��̾� RC ����
	int _cameraX, _cameraY;

	RECT _playerbackGround;
	

	
	bool b_isJump;
	bool b_isMAXJump;

	void player_Move();
	void player_Jump();


	bool b_Debug;
public:
	

	Player();
	~Player();

	RECT get_playerRC() { return _playerRC; }
	void setBackGround(RECT rc) {	_playerbackGround = rc;	}

	int get_playerHP() { return _playerHP; }
	void set_playerHP(int x) { _playerHP = x; }


	int getPlayercameraX() {return _cameraX;}
	int getPlayercameraY() {return _cameraY;}

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);


	


};

#define PLAYER	Player::getSingleton()
