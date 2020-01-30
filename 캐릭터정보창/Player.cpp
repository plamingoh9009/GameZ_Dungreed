#include "stdafx.h"
#include "Player.h"

void Player::init_gobugi()
{
}
void Player::init_pikachu()
{
}
void Player::init_hanuts()
{
}
void Player::delete_img()
{
	_img = nullptr;
}
Player::Player()
{
}
Player::~Player()
{
}
HRESULT Player::init()
{
	if (_type.compare("Gobugi") == 0) { init_gobugi(); }
	else if (_type.compare("Pikachu") == 0) { init_pikachu(); }
	else if (_type.compare("Hanuts") == 0) { init_hanuts(); }
	return S_OK;
}
void Player::release()
{
	delete_img();
}
void Player::update()
{
}
void Player::render()
{
}
