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
			break;
		case Move:
			_playerimg = IMAGEMANAGER->findImage("LEFT_MOVE");
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
			break;
		case Move:
			_playerimg = IMAGEMANAGER->findImage("RIGHT_MOVE");

			break;
		case Jump:
			_playerimg = IMAGEMANAGER->findImage("RIGHT_JUMP");
			break;

		}
	}
}

void Player::player_Jump()
{

	if (_playerJumpCount <= 30)
	{
		OffsetRect(&_playerRC, 0, -(_playerSpeed+2));
		_playerJumpCount++;
	}
	if (_playerJumpCount >= 30)
	{
		OffsetRect(&_playerRC, 0, _playerSpeed + 3);
		_playerJumpCount++;
	}

	if (_playerRC.bottom < _stage->getGroud().top)
	{
		_playerMove = Jump;
	}
	else
	{
		//_playerMove = Idle;
		_playerRC.bottom = _stage->getGroud().top+1;
		_playerRC.top = _playerRC.bottom - 42;
		_playerJumpCount = 0;
		b_isJump = false;
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
	IMAGEMANAGER->addFrameImage("LEFT_IDLE", "resource/image/플레이어/왼쪽아이들.bmp", 68 * 2, 21 * 2, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RIGHT_IDLE", "resource/image/플레이어/오른쪽아이들.bmp", 68 * 2, 21 * 2, 4, 1, true, RGB(255, 0, 255));
	//이동
	IMAGEMANAGER->addFrameImage("LEFT_MOVE", "resource/image/플레이어/왼쪽이동.bmp", 238 * 2, 21 * 2, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("RIGHT_MOVE", "resource/image/플레이어/오른쪽이동.bmp", 238 * 2, 21 * 2, 14, 1, true, RGB(255, 0, 255));
	//점프
	IMAGEMANAGER->addImage("LEFT_JUMP", "resource/image/플레이어/왼쪽점프.bmp", 17 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("RIGHT_JUMP", "resource/image/플레이어/오른쪽점프.bmp", 17 * 2, 21 * 2, true, RGB(255, 0, 255));


	_stage = new stage;
	_stage -> init();


	_playerWay = Left;
	_playerMove = Idle;
	_playerimg = IMAGEMANAGER->findImage("LEFT_IDLE");
	_playerRC = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 17 * 2, 21 * 2);
	_playerSpeed = 3;
	_playerMoveCount = 0;//움직일떄 플레이어 점프 
	_playerJumpCount = 0;//점프에만 사용할 카운트
	_playerRC.bottom = _stage->getGroud().top;
	_playerRC.top = _playerRC.bottom-42;
	_playerHP = 80;




	b_isJump = false;



	b_Debug = false;
	return S_OK;
}

void Player::release()
{
	SAFE_DELETE(_playerimg);
}
//================================================
//##					업데이트					##
//================================================
void Player::update()
{
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
		_playerMoveCount++;
		_playerMove = Move;
		OffsetRect(&_playerRC, -_playerSpeed, 0);
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			b_isJump = true;
		}

	}
	else if (KEYMANAGER->isStayKeyDown('D'))//right_rc
	{
		_playerMoveCount++;
		_playerMove = Move;
		OffsetRect(&_playerRC, _playerSpeed, 0);
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			b_isJump = true;
		}
	}
	else
	{
		_playerMoveCount++;
		_playerMove = Idle;
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			b_isJump = true;
		}
	}
	if (b_isJump)
	{
		player_Jump();
	}
	if (_playerMoveCount > 280)
	{
		_playerMoveCount = 0;
	}
	player_Move();



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
		wsprintf(str, "|플레이어 무브 카운트 : %d | 플레이어 점프 카운트 : %d | 플레이어 무브 : %d |플레이어 HP : %d", _playerMoveCount, _playerJumpCount, _playerMove,_playerHP);
		TextOut(getMemDC(), WINSIZEX / 2 - 300, 0, str, strlen(str));

		Rectangle(getMemDC(), _stage->getGroud().left, _stage->getGroud().top, _stage->getGroud().right, _stage->getGroud().bottom);
		Rectangle(getMemDC(), _playerRC.left, _playerRC.top, _playerRC.right, _playerRC.bottom);
	}

	if (_playerMove == Move)
	{
		_playerimg->frameRender(getMemDC(), _playerRC.left, _playerRC.top, (_playerMoveCount / 15) % 14, 0);
	}
	else if (_playerMove == Idle)
	{
		_playerimg->frameRender(getMemDC(), _playerRC.left, _playerRC.top, (_playerMoveCount / 15) % 4, 0);
	}
	else if (_playerMove == Jump)
	{
		_playerimg->render(getMemDC(), _playerRC.left, _playerRC.top);
	}
}
