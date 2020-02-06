#include "stdafx.h"
#include "Monster.h"

//====================================================================
//==					R E C T			C R E A T E					==
//====================================================================
void Monster::init_ground()
{
	_stage = new stage;
	_stage->init();
}
void Monster::init_monster_size_rc()
{
	rndSpwan = RND->getFromIntTo(1, 8);
	_size_monster_rc = RectMake(0+ rndSpwan * 100, _stage->getGroud().top - _size_monster_height, _size_monster_width, _size_monster_height);
}
void Monster::init_chk_distance_player_rc()
{
	_distance_chk_player_rc = RectMakeCenter((_size_monster_rc.left + _size_monster_rc.right) / 2,(_size_monster_rc.top + _size_monster_rc.bottom ) / 2,
		_distance_chk_player_width, _distance_chk_player_height);
}
void Monster::init_attack_distance_rc_left()
{
	_distance_attack_monster_rc_left = RectMake(_size_monster_rc.left - _distance_attack_monster_left_width + ((_size_monster_rc.right - _size_monster_rc.left) / 2), _size_monster_rc.bottom - _distance_attack_monster_left_height,
		_distance_attack_monster_left_width, _distance_attack_monster_left_height);
}
void Monster::init_attack_distance_rc_right()
{
	_distance_attack_monster_rc_right = RectMake(_size_monster_rc.right - ((_size_monster_rc.right-_size_monster_rc.left)/2), _size_monster_rc.bottom- _distance_attack_monster_left_height,
		_distance_attack_monster_right_width, _distance_attack_monster_right_height);
}
//====================================================================
//==				B A S I C	O P E R A T I O N	   				==
//====================================================================
void Monster::moveLeft()
{
	_size_monster_rc.left -= _speed_move;
	_size_monster_rc.right -= _speed_move;
	_distance_chk_player_rc.left -= _speed_move;
	_distance_chk_player_rc.right -= _speed_move;
	_distance_attack_monster_rc_left.left -= _speed_move;
	_distance_attack_monster_rc_left.right -= _speed_move;
	_distance_attack_monster_rc_right.left -= _speed_move;
	_distance_attack_monster_rc_right.right -= _speed_move;
	_bShow_left = true;
}
void Monster::moveRight()
{
	_size_monster_rc.left += _speed_move;
	_size_monster_rc.right += _speed_move;
	_distance_chk_player_rc.left += _speed_move;
	_distance_chk_player_rc.right += _speed_move;
	_distance_attack_monster_rc_left.left += _speed_move;
	_distance_attack_monster_rc_left.right += _speed_move;
	_distance_attack_monster_rc_right.left += _speed_move;
	_distance_attack_monster_rc_right.right += _speed_move;
	_bShow_left = false;
}
void Monster::jump_up()
{
	if (_bJump_monster == true)
	{
		if (_counter_monsterJump <= 30)
		{
			OffsetRect(&_size_monster_rc, 0, -(_speed_move + 2));
			OffsetRect(&_distance_chk_player_rc, 0, -(_speed_move + 2));
			OffsetRect(&_distance_attack_monster_rc_right, 0, -(_speed_move + 2));
			OffsetRect(&_distance_attack_monster_rc_left, 0, -(_speed_move + 2));
			_counter_monsterJump++;
		}
		if (_counter_monsterJump >= 30)
		{
			OffsetRect(&_size_monster_rc, 0, _speed_move + 3);
			OffsetRect(&_distance_chk_player_rc, 0, _speed_move + 3);
			OffsetRect(&_distance_attack_monster_rc_right, 0, _speed_move + 3);
			OffsetRect(&_distance_attack_monster_rc_left, 0, _speed_move + 3);
			_counter_monsterJump++;
		}

		if (_size_monster_rc.bottom >= _stage->getGroud().top + 1)
		{
			_size_monster_rc.bottom = _stage->getGroud().top + 1;
			_distance_chk_player_rc.bottom = ((_size_monster_rc.bottom + _size_monster_rc.top)/2) + (_distance_chk_player_height / 2);
			_distance_attack_monster_rc_right.bottom = _size_monster_rc.bottom;
			_distance_attack_monster_rc_left.bottom = _size_monster_rc.bottom;

			_size_monster_rc.top = _size_monster_rc.bottom - _size_monster_height;
			_distance_chk_player_rc.top = ((_size_monster_rc.bottom + _size_monster_rc.top) / 2) - (_distance_chk_player_height / 2);
			_distance_attack_monster_rc_right.top = _distance_attack_monster_rc_right.bottom - _distance_attack_monster_right_height;
			_distance_attack_monster_rc_left.top = _distance_attack_monster_rc_left.bottom - _distance_attack_monster_left_height;
			_counter_monsterJump = 0;
			_bJump_monster = false;
		}
	}
}
void Monster::jump_down()
{
	_size_monster_rc.top += _speed_move;
	_size_monster_rc.bottom += _speed_move;
	_distance_chk_player_rc.top += _speed_move;
	_distance_chk_player_rc.bottom += _speed_move;
}

//=====================================================================
//== 							A	I								 ==
//=====================================================================
void Monster::idle()
{
	if (_bChk_player == false)
	{
		if (_cooldown_idle_Act == 0)
		{
			_rnd_idleAct = RND->getFromIntTo(0, 2);
			_cooldown_idle_Act = 100;
		}
		if (_cooldown_idle_Act != 0)
		{
			_cooldown_idle_Act -= 1;
			switch (_rnd_idleAct)
			{
			case 0:

				break;
			case 1:
				moveLeft();
				break;
			case 2:
				moveRight();
				break;
			}
		}
	}
}
void Monster::findPlayer()
{
	RECT temp;
	RECT tempPlayer = PLAYER->get_playerRC();
	if (IntersectRect(&temp, &_distance_chk_player_rc, &tempPlayer))
	{
		_bChk_player = true;
	}
}
void Monster::chasePlayer()
{
	RECT destPlayer = PLAYER->get_playerRC();
	if (_bChk_player == true && _bSwing_sword == false)
	{
		if (_cooldown_attack != 0)
		{
			_cooldown_attack -= 1;
		}
		if (destPlayer.right < ((_size_monster_rc.left + _size_monster_rc.right) / 2) +1)
		{
			moveLeft();
		}
		else if (destPlayer.left > ((_size_monster_rc.left + _size_monster_rc.right) / 2) -1)
		{
			moveRight();
		}

		if (destPlayer.top < _size_monster_rc.top)
		{
			_bJump_monster = true;
		}
	}
}
void Monster::compareAttack()
{
	RECT sourPlayer = PLAYER->get_playerRC();
	if (sourPlayer.bottom == _size_monster_rc.bottom)
	{
		if (sourPlayer.right >= _size_monster_rc.left-20 && sourPlayer.right <= _size_monster_rc.left )
		{
			_bAttackable_monster = true;

			if (_cooldown_attack == 0 && _bAttackable_monster == true)
			{
				_bSwing_sword = true;
			}
		}
		if (sourPlayer.left <= _size_monster_rc.right+20 && sourPlayer.left >= _size_monster_rc.left)
		{
			_bAttackable_monster = true;

			if (_cooldown_attack == 0 && _bAttackable_monster == true)
			{
				_bSwing_sword = true;
			}
		}
	}
}
void Monster::attack()
{
	if (_bSwing_sword == true)
	{
		if (_speed_swing_sword != 0)
		{
			_speed_swing_sword -= 1;
		}
		if (_speed_swing_sword == 0)
		{

			if (_bShow_left == true)
			{
				RECT temp;
				RECT sourPlayer = PLAYER->get_playerRC();
				int playerhp = PLAYER->get_playerHP();
				if (IntersectRect(&temp, &_distance_attack_monster_rc_left, &sourPlayer))
				{
					playerhp -= 10;
					PLAYER->set_playerHP(playerhp);
				}
			}
			if (_bShow_left == false)
			{
				RECT temp;
				RECT sourPlayer = PLAYER->get_playerRC();
				int playerhp = PLAYER->get_playerHP();
				if (IntersectRect(&temp, &_distance_attack_monster_rc_right, &sourPlayer))
				{
					playerhp -= 10;
					PLAYER->set_playerHP(playerhp);
				}
			}
			_bSwing_sword = false;
			_speed_swing_sword = 30;
			_cooldown_attack = _speed_attack;
		}
	}
}
//================================================
//##				디버그 : F1					##
//================================================
void Monster::show_rc()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		if (_bShow_left == false)
		{
			Rectangle(getMemDC(), _distance_attack_monster_rc_right.left, _distance_attack_monster_rc_right.top,
				_distance_attack_monster_rc_right.right, _distance_attack_monster_rc_right.bottom);
		}
		if (_bShow_left == true)
		{
			Rectangle(getMemDC(), _distance_attack_monster_rc_left.left, _distance_attack_monster_rc_left.top,
				_distance_attack_monster_rc_left.right, _distance_attack_monster_rc_left.bottom);
		}
		Rectangle(getMemDC(), _size_monster_rc.left, _size_monster_rc.top, _size_monster_rc.right, _size_monster_rc.bottom);
		
		FrameRect(getMemDC(), &_distance_chk_player_rc, CreateSolidBrush(RGB(255, 0, 0)));
		
		char str[128];
		wsprintf(str, "| 공격개시 : %d |공격대기시간 : %d", _speed_swing_sword, _cooldown_attack);
		TextOut(getMemDC(), WINSIZEX / 2 - 300, 150, str, strlen(str));
	}
}
//================================================================
//==				D E F A U L T   B A S E						==
//================================================================
Monster::Monster()
{
}
Monster::~Monster()
{
}
HRESULT Monster::init()
{	
	return S_OK;
}
void Monster::release()
{
}
void Monster::update()
{
	
}
void Monster::render()
{
}
