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
	void init_monsters(MONSTER_TYPE type);
	void delete_monsters();
	void draw_monsters();
	void release_monsters();

	void update_monsters();

//테스트용┐
public:
	bool show_rc = true;
	int rndSpwan;

	void spawn_monsters();	//소환하기
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





