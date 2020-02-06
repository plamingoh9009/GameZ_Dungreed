#include "stdafx.h"
#include "MonsterControl.h"

//����
void MonsterControl::init_monsters(MONSTER_TYPE type)
{
	Monster * monster = nullptr;

	if (type == SKELETON_WORRIOR)
	{
		monster = new Skeleton_warrior;
	}
	
	monster->init();
	monster->init_monster_size_rc();
	monster->init_chk_distance_player_rc();
	monster->init_attack_distance_rc_left();
	monster->init_attack_distance_rc_right();
	_monsters.push_back(monster);
	monster = nullptr;
}
//����
void MonsterControl::delete_monsters()
{
	_monstersIter = _monsters.begin();
	for (; _monstersIter != _monsters.end();)
	{
		if ((*_monstersIter)->get_hp() == 0)//hp�� 0�̸� �����ض�
		{
			_monstersIter = _monsters.erase(_monstersIter);
		}
		else { _monstersIter++; }
	}
}
//������Ʈ
void MonsterControl::update_monsters()
{
	_monstersIter = _monsters.begin();
	for (; _monstersIter != _monsters.end(); _monstersIter++)
	{
		(*_monstersIter)->update();
	}
}
//============================================================
//==					R E N D E R							==
//============================================================
//�׸���
void MonsterControl::draw_monsters()
{
	_monstersIter = _monsters.begin();
	for (; _monstersIter != _monsters.end(); _monstersIter++)
	{
		(*_monstersIter)->render();
		(*_monstersIter)->show_rc();
	}
}
//������
void MonsterControl::release_monsters()
{
	_monstersIter = _monsters.begin();
	for (; _monstersIter != _monsters.end();)
	{
		(*_monstersIter)->release();
		_monstersIter = _monsters.erase(_monstersIter);
	}
	swap(_monsters, vMonster());
}

//============================================================
//==						T E S T							==
//============================================================
void MonsterControl::kill_monsters()
{
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		_monstersIter = _monsters.begin();
		for (; _monstersIter != _monsters.end();)
		{			
			(*_monstersIter)->set_hp(0);
			_monstersIter++;
		}
	}
}

//============================================================
//==				D E F A U L T   B A S E					==
//============================================================
MonsterControl::MonsterControl()
{
}
MonsterControl::~MonsterControl()
{
}
HRESULT MonsterControl::init()
{
	
	return S_OK;
}

void MonsterControl::release()
{
	release_monsters();
}

void MonsterControl::update()
{
	if (KEYMANAGER->isOnceKeyUp('1'))
	{
		init_monsters(SKELETON_WORRIOR);
	}

	kill_monsters();
	delete_monsters();
	update_monsters();
	
}

void MonsterControl::render()
{
	if (show_rc == true)
	{
		draw_monsters();
	}
}
