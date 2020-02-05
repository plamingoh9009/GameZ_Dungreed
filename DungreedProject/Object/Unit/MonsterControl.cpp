#include "stdafx.h"
#include "MonsterControl.h"


//생성
void MonsterControl::init_monsters(MONSTER_TYPE type)
{
	Monster * monster = nullptr;

	if (type == SKELETON_WORRIOR)
	{
		monster = new Skeleton_warrior;
	}
	
	monster->init();
	monster->init_monster_size_rc(WINSIZEX/2 + rndSpwan * 100, WINSIZEY - (WINSIZEY / 4) - 50);
	monster->init_chk_distance_player_rc();
	_monsters.push_back(monster);
	monster = nullptr;
}
//제거
void MonsterControl::delete_monsters()
{
	_monstersIter = _monsters.begin();
	for (; _monstersIter != _monsters.end();)
	{
		if ((*_monstersIter)->get_hp() == 0)//hp가 0이면 제거해라
		{
			_monstersIter = _monsters.erase(_monstersIter);
		}
		else { _monstersIter++; }
	}
}
//업데이트
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
//그리기
void MonsterControl::draw_monsters()
{
	_monstersIter = _monsters.begin();
	for (; _monstersIter != _monsters.end(); _monstersIter++)
	{
		(*_monstersIter)->render();
		(*_monstersIter)->show_rc();
	}
}
//릴리즈
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
void MonsterControl::spawn_monsters()
{
	rndSpwan = RND->getFromIntTo(1, 4);
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		init_monsters(SKELETON_WORRIOR);
	}
	//if (KEYMANAGER->isOnceKeyDown('2'))
	//{
	//	init_monsters(SKELETON_ARCHER);
	//}
	//if (KEYMANAGER->isOnceKeyDown('3'))
	//{
	//	init_monsters(TYPE_EMPTY);
	//}


	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		//delete_monsters(MONSTER_TYPE type);
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		if (show_rc == false)
		{
			show_rc = true;
		}
		else if (show_rc == true)
		{
			show_rc = false;
		}
	}	
}

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
	void init_monsters(MONSTER_TYPE type);
	spawn_monsters();
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
