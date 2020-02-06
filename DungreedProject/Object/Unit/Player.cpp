#include "stdafx.h"
#include "Player.h"


void Player::player_Move()
{
	if (_playerWay == Left)
	{
		switch (_playerMove)
		{
		case Idle:
			_playerimg = IMAGEMANAGER->findImage("LEFT_IDLE");
			_playerani = IMAGEMANAGER->findAnimation("LEFT_IDLE");
			_playerani->start();
			break;
		case Move:
			_playerimg = IMAGEMANAGER->findImage("LEFT_MOVE");
			_playerani = IMAGEMANAGER->findAnimation("LEFT_MOVE");
			_playerani->start();
			break;
		case Jump:
			_playerimg = IMAGEMANAGER->findImage("LEFT_JUMP");
			break;
		}
	}
	else if (_playerWay == Right)
	{
		switch (_playerMove)
		{

		case Idle:
			_playerimg = IMAGEMANAGER->findImage("RIGHT_IDLE");
			_playerani = IMAGEMANAGER->findAnimation("RIGHT_IDLE");
			_playerani->start();
			break;
		case Move:
			_playerimg = IMAGEMANAGER->findImage("RIGHT_MOVE");
			_playerani = IMAGEMANAGER->findAnimation("RIGHT_MOVE");
			_playerani->start();
			break;
		case Jump:
			_playerimg = IMAGEMANAGER->findImage("RIGHT_JUMP");
			break;

		}
	}
}

void Player::player_Jump()
{
	
	if (b_isJump)
	{
		_playerMove = Jump;
		_playerJumpGravity = 0.5f;
		_playerRC.top -= _playerJumpPower;
		_playerRC.bottom -= _playerJumpPower;
		_playerJumpPower -= _playerJumpGravity;
		if (_playerRC.top <200)
		{
			b_isMAXJump = true;
			b_isJump = false;
		}
		
	}
	
	if(!b_isJump|| b_isMAXJump)
	{
		//_playerMove = Jump;
		_playerJumpGravity = 10.0f;
		_playerRC.top += _playerJumpGravity;
		_playerRC.bottom += _playerJumpGravity;
	}
	RECT temp;
	if (IntersectRect(&temp, &_playerRC, &_stage->getGroud()))
	{
		b_isJump = false;
		b_isMAXJump = false;
		
		_playerRC.bottom = _stage->getGroud().top;
		_playerRC.top = _playerRC.bottom - 42;
	}
	else
	{
		_playerMove = Jump;
	}
}
////////////////////////////////////////////////////////
Player::Player()
{
}


Player::~Player()
{
}
////////////////////////////////////////////////////////
HRESULT Player::init()
{
	//아이들상태
	IMAGEMANAGER->addFrame("LEFT_IDLE", "resource/image/플레이어/왼쪽아이들.bmp", 68 * 2, 21 * 2, 4, 1, 1);
	IMAGEMANAGER->addFrame("RIGHT_IDLE", "resource/image/플레이어/오른쪽아이들.bmp", 68 * 2, 21 * 2, 4, 1, 1);
	//이동
	IMAGEMANAGER->addFrame("LEFT_MOVE", "resource/image/플레이어/왼쪽이동.bmp", 238 * 2, 21 * 2, 14, 1, 1);
	IMAGEMANAGER->addFrame("RIGHT_MOVE", "resource/image/플레이어/오른쪽이동.bmp", 238 * 2, 21 * 2, 14, 1, 1);
	//점프
	IMAGEMANAGER->addImage("LEFT_JUMP", "resource/image/플레이어/왼쪽점프.bmp", 17 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("RIGHT_JUMP", "resource/image/플레이어/오른쪽점프.bmp", 17 * 2, 21 * 2, true, RGB(255, 0, 255));


	_stage = new stage;
	_stage -> init();


	_playerWay = Left;
	_playerMove = Idle;
	_playerimg = IMAGEMANAGER->findImage("LEFT_IDLE");
	_playerani = IMAGEMANAGER->findAnimation("LEFT_IDLE");
	_playerani->start();
	_playerRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 17 * 2, 21 * 2);
	/////////////카메라//////////////
	_cameraX = 0;
	_cameraY = 0;
	///////////////////////////////
	_playerSpeed = 3;
	_playerJumpCount = 0;//점프에만 사용할 카운트
	_playerRC.bottom = _stage->getGroud().top;
	_playerRC.top = _playerRC.bottom-42;
	_playerHP = 80;




	b_isJump = false; 
	b_isMAXJump = false;



	b_Debug = false;
	return S_OK;
}

void Player::release()
{
	IMAGEMANAGER->deleteImage("LEFT_IDLE");
	IMAGEMANAGER->deleteImage("RIGHT_IDLE");
	IMAGEMANAGER->deleteImage("LEFT_MOVE");
	IMAGEMANAGER->deleteImage("RIGHT_MOVE");
	IMAGEMANAGER->deleteImage("LEFT_JUMP");
	IMAGEMANAGER->deleteImage("RIGHT_JUMP");
	//SAFE_DELETE(_playerimg);
	_stage->release();
	SAFE_DELETE(_stage);
}
//================================================
//##					업데이트					##
//================================================
void Player::update()
{
	
	_focousplayerX = _playerRC.right - (_playerRC.right - _playerRC.left) / 2;
	_focousplayerY = _playerRC.bottom - (_playerRC.bottom - _playerRC.top) / 2;

	_playerFocusX = _playerRC.right - (_playerRC.right - _playerRC.left) / 2;//플레이어 렉트 중점
	//플레이어 방향 지정
	if (m_ptMouse.x < _playerFocusX)
	{
		_playerWay = Left;
	}
	else
	{
		_playerWay = Right;
	}
	if (KEYMANAGER->isStayKeyDown('A'))//left_rc
	{
		_playerframeSpeed = 0.18;
		_playerMove = Move;
		//OffsetRect(&_playerRC, -_playerSpeed, 0);
		if (KEYMANAGER->isStayKeyDown(VK_SPACE) && !b_isMAXJump)
		{
			_playerJumpPower = 5.0f;
			b_isJump = true;
		}
		if (_focousplayerX >= WINSIZEX / 2)
		{
			OffsetRect(&_playerRC, -_playerSpeed, 0);
		}
		else if(_cameraX < 0)
		{
			_cameraX += _playerSpeed;
		}
		else
		{
			OffsetRect(&_playerRC, -_playerSpeed, 0);
		}
	}
	
	else if (KEYMANAGER->isStayKeyDown('D'))//right_rc
	{
		_playerMove = Move;
		_playerframeSpeed = 0.18;
		//OffsetRect(&_playerRC, _playerSpeed, 0);
		if (KEYMANAGER->isStayKeyDown(VK_SPACE) && !b_isMAXJump)
		{
			_playerJumpPower = 5.0f;
			b_isJump = true;
		}

		if (_focousplayerX <= WINSIZEX / 2)
		{
			OffsetRect(&_playerRC, _playerSpeed, 0);
		}
		else if (_cameraX > -WINSIZEX)
		{
			_cameraX -= _playerSpeed;
		}
		else
		{
			OffsetRect(&_playerRC, _playerSpeed, 0);
		}
		
	}
	else
	{
		_playerMove = Idle;
		_playerframeSpeed = 0.15;
		if (KEYMANAGER->isStayKeyDown(VK_SPACE) && !b_isMAXJump)
		{
			_playerJumpPower = 5.0f;
			b_isJump = true;
		}
	}
	_playerani->frameUpdate(_playerframeSpeed);

	player_Jump();
	player_Move();

	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		SCENEMANAGER->changeScene("startscene");
	}




	//================================================
	//##				디버그 : F1					##
	//================================================
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		b_Debug = !b_Debug;
	}
}

void Player::render()
{

	if (b_Debug)
	{
		char str[128];
		wsprintf(str, "| 플레이어 점프 카운트 : %d | 플레이어 무브 : %d |플레이어 HP : %d|플레이어카메라X : %d|플레이어카메라y : %d|", _playerJumpCount, _playerMove,_playerHP,_cameraX,_cameraY);
		TextOut(getMemDC(), WINSIZEX / 2 - 300, 0, str, strlen(str));

		Rectangle(getMemDC(), _stage->getGroud().left, _stage->getGroud().top, _stage->getGroud().right, _stage->getGroud().bottom);
		Rectangle(getMemDC(), _playerRC.left, _playerRC.top, _playerRC.right, _playerRC.bottom);
	}

	if (_playerMove == Move)
	{
		//_playerimg->frameRender(getMemDC(), _playerRC.left, _playerRC.top, (_playerMoveCount / 15) % 14, 0);
		_playerimg->aniRender(getMemDC(), _playerRC.left, _playerRC.top, _playerani);
	}
	else if (_playerMove == Idle)
	{
		//_playerimg->frameRender(getMemDC(), _playerRC.left, _playerRC.top, (_playerMoveCount / 15) % 4, 0);
		_playerimg->aniRender(getMemDC(), _playerRC.left, _playerRC.top, _playerani);
	}
	else if (_playerMove == Jump)
	{
		_playerimg->render(getMemDC(), _playerRC.left, _playerRC.top);
	}
}
