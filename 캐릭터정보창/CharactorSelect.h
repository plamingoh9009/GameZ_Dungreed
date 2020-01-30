#pragma once
#include "Player.h"
class Card;
class CharactorSelect:public gameNode
{
private:
	typedef vector<Card *> vCards;
private:
	image * _backGround;
	int _width, _height;
	// 카드 정보 vector
	vCards _cards;
	// 내 마우스가 카드에 닿았는지 여부
	RECT _mouseRect;
protected:
	// 캐릭터를 골랐는지 확인한다.
	void check_chooseCharactor();
	// 마우스와 카드 충돌
	void check_clickCard();
	void check_mouseOnCard();
	RECT make_mouseRect();
	// 카드
	void init_cards();
	void delete_cardsAll();
	void update_cards();
	void draw_cards();
public:
	CharactorSelect();
	~CharactorSelect();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

class Card : public gameNode
{
private:
	image * _backImg;
	image * _frontImg;
	string _type;
	int _width, _height;
	RECT _rect;
	// 마우스를 카드에 댔을때
	int _alpha;
	bool _fMouseOnCard;
	// 카드가 깜빡거리기 위한 변수
	bool _fClickCard;
	bool _fBlink;
	int _blinkCounter;
	int _blinkDelay;
	int _blinkTimer;
	// 캐릭터를 골랐을때
	bool _fChooseCharactor;
protected:
	// 카드 깜빡이기
	void blink_card();
public:
	// 씬 바꿀때
	bool is_chooseCharactor() { return _fChooseCharactor; }
	// 마우스를 카드에 댔을때
	void init_forBlink();
	void set_fClickCard(bool fResult) { _fClickCard = fResult; }
	void set_fMouseOnCard(bool fResult) { _fMouseOnCard = fResult; }
	// 카드 위치를 RECT로 넘긴다.
	RECT get_rect() { return _rect; }
	// 타입을 받아서 카드를 만든다.
	void init_card(string type);
	string get_type() { return _type; }
public:
	Card();
	~Card();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};