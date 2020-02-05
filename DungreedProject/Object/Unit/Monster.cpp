#include "stdafx.h"
#include "Monster.h"

//====================================================================
//==				M O N S T E R   C R E A T E						==
//====================================================================
void Monster::show_rc()
{
	FrameRect(getMemDC(), &_chk_distance_player_rc,CreateSolidBrush(RGB(255,0,0)));
	Rectangle(getMemDC(), _monster_size_rc.left, _monster_size_rc.top, _monster_size_rc.right, _monster_size_rc.bottom);
}

void Monster::init_monster_size_rc(int x, int y)
{
	_monster_size_rc = RectMake(x, y, monster_size_width, monster_size_height);	
}

void Monster::init_chk_distance_player_rc()
{
	_chk_distance_player_rc = RectMakeCenter((_monster_size_rc.left + _monster_size_rc.right) / 2,(_monster_size_rc.top + _monster_size_rc.bottom ) / 2,
		_chk_distance_player_width, _chk_distance_player_height);
}
//====================================================================
//==				B A S I C	O P E R A T I O N	   				==
//====================================================================
void Monster::moveLeft()
{
	_monster_size_rc.left -= _speed_move;
	_monster_size_rc.right -= _speed_move;
	_chk_distance_player_rc.left -= _speed_move;
	_chk_distance_player_rc.right -= _speed_move;
}
void Monster::moveRight()
{
	_monster_size_rc.left += _speed_move;
	_monster_size_rc.right += _speed_move;
	_chk_distance_player_rc.left += _speed_move;
	_chk_distance_player_rc.right += _speed_move;
}

void Monster::jump_up()
{
	_monster_size_rc.top -= _speed_move;
	_monster_size_rc.bottom -= _speed_move;
	_chk_distance_player_rc.top -= _speed_move;
	_chk_distance_player_rc.bottom -= _speed_move;
}

void Monster::jump_down()
{
	_monster_size_rc.top += _speed_move;
	_monster_size_rc.bottom += _speed_move;
	_chk_distance_player_rc.top += _speed_move;
	_chk_distance_player_rc.bottom += _speed_move;
}



//=====================================================================
//== 							A	I								 ==
//=====================================================================
/*void Monster::masterAi()
{

}*/
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
	RECT tempPlayer = PLAYER->get_player();
	if (IntersectRect(&temp, &_chk_distance_player_rc, &tempPlayer))
	{
		_bChk_player = true;
		_cooldown_chase = 200;
	}
}
void Monster::chasePlayer()
{
	RECT destPlayer = PLAYER->get_player();
	if (_bChk_player == true)
	{
		_cooldown_chase -= 1;
		if (destPlayer.right < _monster_size_rc.left)
		{
			moveLeft();
		}
		else if (destPlayer.left > _monster_size_rc.right)
		{
			moveRight();
		}





		if (_cooldown_chase == 0)
		{
			_bChk_player = false;
		}
	}
}

void Monster::compareAttack()
{

}

void Monster::attack()
{

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
