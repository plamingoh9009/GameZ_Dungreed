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
	init_ground();
	//===================
	//=		렉트 크기	=
	//===================
	_size_monster_width = 50;
	_size_monster_height = 50;
	_distance_chk_player_width = 500;
	_distance_chk_player_height = 200;
	_distance_attack_monster_left_width = 70;
	_distance_attack_monster_left_height = 70;
	_distance_attack_monster_right_width = 70;
	_distance_attack_monster_right_height = 70;


	_bJump_monster = false;


	//===================
	//=		능력치		=
	//===================
	_hp = 50;
	_attack_damage = 10;
	_speed_attack = 300;
	_speed_move = 1.0f;
	_speed_swing_sword = 30;
	//===================
	//=		A I			=
	//===================
	_bChk_player = false;
	_cooldown_idle_Act = 200;
	_cooldown_attack = 0;
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
	jump_up();

	compareAttack();
	attack();


}

void Skeleton_warrior::render()
{
	//_img->render(getMemDC(), _rc.left, _rc.top);
}
