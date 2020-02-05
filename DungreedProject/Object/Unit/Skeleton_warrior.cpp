#include "stdafx.h"
#include "Skeleton_warrior.h"

Skeleton_warrior::Skeleton_warrior()
{
}

Skeleton_warrior::~Skeleton_warrior()
{
}

HRESULT Skeleton_warrior::init()
{
	//===================
	//=		렉트 크기	=
	//===================
	monster_size_width = 50;
	monster_size_height = 50;
	_chk_distance_player_width = 300;
	_chk_distance_player_height = 50;

	//===================
	//=		능력치		=
	//===================
	_hp = 50;
	_attack_damage = 10;
	_speed_attack = 300;
	_speed_move = 1.0f;
	//===================
	//=		A I			=
	//===================
	_bChk_player = false;
	_cooldown_idle_Act = 200;
	//===================
	//=		이미지		=
	//===================
	//_img = IMAGEMANAGER->addImage(_type, "images/Skeleton_warrior.bmp", _width, _height, true, RGB(255, 0, 255));
	_bDebug = false;

	return S_OK;
}

void Skeleton_warrior::release()
{
	//_img = nullptr;
}

void Skeleton_warrior::update()
{
	idle();
	findPlayer();
	chasePlayer();	
}

void Skeleton_warrior::render()
{
	//_img->render(getMemDC(), _rc.left, _rc.top);
}
