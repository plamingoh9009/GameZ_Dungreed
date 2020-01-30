#include "stdafx.h"
#include "CharactorSelect.h"
//============================================
//##			캐릭터 선택씬					##
//============================================
void CharactorSelect::check_chooseCharactor()
{
	auto iter = _cards.begin();
	for (;iter != _cards.end();iter++)
	{
		if ((*iter)->is_chooseCharactor() == true)
		{
//============================================
//##			씬 체인지						##
//============================================
			PLAYER->set_type((*iter)->get_type());
			SCENEMANAGER->changeScene("TownScene");
			break;
		}// 캐릭터를 골랐다면
	}
}
void CharactorSelect::check_clickCard()
{
	make_mouseRect();
	auto iter = _cards.begin();
	for (;iter != _cards.end();iter++)
	{
		if (IntersectRect(&RECT(), &_mouseRect, &(*iter)->get_rect()))
		{
			(*iter)->set_fClickCard(true);
		}// 만약 카드를 클릭하면
	}
}
void CharactorSelect::check_mouseOnCard()
{
	make_mouseRect();
	auto iter = _cards.begin();
	for (;iter != _cards.end();iter++)
	{
		if (IntersectRect(&RECT(), &_mouseRect, &(*iter)->get_rect()))
		{
			(*iter)->set_fMouseOnCard(true);
		}// 만약 카드에 마우스를 대면
	}
}
RECT CharactorSelect::make_mouseRect()
{
	_mouseRect = RectMakeCenter(m_ptMouse.x, m_ptMouse.y, 5, 5);
	return _mouseRect;
}
void CharactorSelect::init_cards()
{
	Card * card;
	card = new Card;
	card->init();
	card->init_card("Gobugi");
	_cards.push_back(card);
	card = nullptr;
	card = new Card;
	card->init();
	card->init_card("Pikachu");
	_cards.push_back(card);
	card = nullptr;
	card = new Card;
	card->init();
	card->init_card("Hanuts");
	_cards.push_back(card);
	card = nullptr;
}
void CharactorSelect::delete_cardsAll()
{
	auto iter = _cards.begin();
	for (;iter != _cards.end();)
	{
		(*iter)->release();
		iter = _cards.erase(iter);
	}
	swap(_cards, vCards());
}
void CharactorSelect::update_cards()
{
	auto iter = _cards.begin();
	for (;iter != _cards.end();iter++)
	{
		(*iter)->update();
	}
}
void CharactorSelect::draw_cards()
{
	auto iter = _cards.begin();
	for (;iter != _cards.end();iter++)
	{
		(*iter)->render();
	}
}
CharactorSelect::CharactorSelect()
{
}
CharactorSelect::~CharactorSelect()
{
}
HRESULT CharactorSelect::init()
{
	_width = 1024;
	_height = 694;
	_backGround = IMAGEMANAGER->addImage("BackGround",
		"images/CharactorSelect/BackGround.bmp", _width, _height, false, RGB(255, 0, 255));
	init_cards();
	return S_OK;
}
void CharactorSelect::release()
{
	// 사용한 카드를 지운다.
	delete_cardsAll();
	// 배경을 날린다.
	IMAGEMANAGER->deleteImage("BackGround");
	_backGround = nullptr;
}
void CharactorSelect::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		check_clickCard();
	}
	else
	{
		check_mouseOnCard();
	}
	// 캐릭터를 골랐다면 씬을 바꾼다.
	check_chooseCharactor();
	// 카드 업데이트
	update_cards();
}
void CharactorSelect::render()
{
	_backGround->render(getMemDC(), 0, (int)((WINSIZEY - _height)*0.5));
	draw_cards();
}
//============================================
//##		카드를 정의하는 클래스				##
//============================================
void Card::blink_card()
{
	_blinkCounter++;
	_blinkTimer--;
	if (_blinkCounter >= _blinkDelay)
	{
//============================================
//##			카드 깜빡이기					##
//============================================
		if (_fBlink == false) { _alpha = 180; }
		else { _alpha = 255; } // _fBlink가 false면 _alpha는 255
		_fBlink = !_fBlink;
		_blinkCounter = 0;
	}
}
void Card::init_forBlink()
{
	_fClickCard = false;
	_fBlink = false;
	_blinkCounter = 0;
	_blinkDelay = 10;
	_blinkTimer = 90;
}
void Card::init_card(string type)
{
	// 타입과 기준좌표, 얼마나 띄어서 출력할지 정한다.
	_type = type;
	_rect = RectMakeCenter((int)(WINSIZEX*0.5), (int)(WINSIZEY*0.5),
		_width, _height);
	double blank = (WINSIZEX - _width * 3) * 0.25;
	// front 이미지의 좌표를 잡아서 RECT에 대입한다.
	RECT frontRect;
	if (type.compare("Gobugi") == 0)
	{
		_rect.left -= (int)(blank + _width);
		_rect.right -= (int)(blank + _width);
		_frontImg = IMAGEMANAGER->addImage(type,
			"images/CharactorSelect/Gobugi.bmp", 183, 183, true, RGB(255, 0, 255));
		// 앞에 출력할 이미지 위치 초기화
		frontRect = RectMakeCenter((int)(_rect.left + _width * 0.5),
			(int)(_rect.top + _height * 0.5), 183, 183);
		_frontImg->setX((float)(frontRect.left));
		_frontImg->setY((float)(frontRect.top));
	}
	else if (type.compare("Pikachu") == 0)
	{
		_frontImg = IMAGEMANAGER->addImage(type,
			"images/CharactorSelect/Pikachu.bmp", 183, 271, true, RGB(255, 0, 255));
		// 앞에 출력할 이미지 위치 초기화
		frontRect = RectMakeCenter((int)(_rect.left + _width * 0.5),
			(int)(_rect.top + _height * 0.5), 183, 271);
		_frontImg->setX((float)(frontRect.left));
		_frontImg->setY((float)(frontRect.top));
	}
	else if (type.compare("Hanuts") == 0)
	{
		_rect.left += (int)(blank + _width);
		_rect.right += (int)(blank + _width);
		_frontImg = IMAGEMANAGER->addImage(type,
			"images/CharactorSelect/Hanuts.bmp", 183, 183, true, RGB(255, 0, 255));
		// 앞에 출력할 이미지 위치 초기화
		frontRect = RectMakeCenter((int)(_rect.left + _width * 0.5),
			(int)(_rect.top + _height * 0.5), 183, 183);
		_frontImg->setX((float)(frontRect.left));
		_frontImg->setY((float)(frontRect.top));
	}
}
Card::Card()
{
}
Card::~Card()
{
}
HRESULT Card::init()
{
	_width = 280;
	_height = 374;
	_backImg = IMAGEMANAGER->addImage("CardBack",
		"images/CharactorSelect/CardBack.bmp", _width, _height, false, RGB(255, 0, 255));
	// 마우스를 카드에 올렸을 때
	_fMouseOnCard = false;
	_alpha = 255;
	init_forBlink();
	// 씬 체인지를 위한 변수
	_fChooseCharactor = false;
	return S_OK;
}

void Card::release()
{
	_backImg = nullptr;
}

void Card::update()
{
	if (_fClickCard == true)
	{
		blink_card();
	}
	else {}

	// 깜빡이는거 보여 준 다음에 씬을 바꾼다.
	if (_blinkTimer <= 0)
	{
		_fClickCard = false;
		_fChooseCharactor = true;
	}
}

void Card::render()
{
	if (_fMouseOnCard == true && _fClickCard == false) { _alpha = 180; }
	else if(_fMouseOnCard == false && _fClickCard == false) { _alpha = 255; }

	_backImg->alphaRender(getMemDC(), _rect.left, _rect.top, _alpha);
	_frontImg->alphaRender(getMemDC(),
		(int)(_frontImg->getX()), (int)(_frontImg->getY()), _alpha);
	_fMouseOnCard = false;
}
