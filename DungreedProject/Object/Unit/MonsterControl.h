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
	void init_monsters(MONSTER_TYPE type);		//���� ����
	void delete_monsters();						//���� ü�� 0����
	void draw_monsters();						//�׸���
	void release_monsters();					//������

	void update_monsters();						

//�׽�Ʈ�릤
public:
	bool show_rc = true;
	
	void kill_monsters();	//���� HP 0 ���� �����
//�׽�Ʈ�릥

public:
	MonsterControl();
	~MonsterControl();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
};





