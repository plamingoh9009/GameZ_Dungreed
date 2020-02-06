#pragma once
#include "Object/Unit/Skeleton_warrior.h"

class MonsterControl : public gameNode
{
private:
	typedef vector<Monster *> vMonster;
private:
	vMonster _monsters;
	vMonster::iterator _monstersIter;
protected:
	void init_monsters(MONSTER_TYPE type);		//몬스터 생성
	void delete_monsters();						//몬스터 체력 0으로
	void draw_monsters();						//그리기
	void release_monsters();					//릴리즈

	void update_monsters();						

//테스트용┐
public:
	bool show_rc = true;
	
	void kill_monsters();	//몬스터 HP 0 으로 만들기
//테스트용┘

public:
	MonsterControl();
	~MonsterControl();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳
};





