#pragma once
#include "base/gameNode.h"
#include "Object/Unit/Player.h"
#include "Object/Unit/stage.h"

enum MONSTER_TYPE
{
	TYPE_EMPTY,
	SKELETON_WORRIOR,
	SKELETON_ARCHER
};

class Monster : public gameNode
{
protected:
	image * _img;						//�̹���	
	stage* _stage;						//��������
	RECT _size_monster_rc;					//������ ��Ʈ
	RECT _distance_chk_player_rc;			//������ �÷��̾� �ν� ���� ��Ʈ
	RECT _distance_attack_monster_rc_left;	//������ ���� ���� ���� ��Ʈ
	RECT _distance_attack_monster_rc_right;	//������ ���� ���� ���� ��Ʈ
	//=========================================================
	//===					 ��Ʈ ������						===
	//=========================================================
	int _size_monster_width;				//���� ��Ʈ ����
	int _size_monster_height;				//���� ��Ʈ ����
	int _distance_chk_player_width;			//������ �÷��̾� �ν� ���� ��Ʈ ����
	int _distance_chk_player_height;		//������ �÷��̾� �ν� ���� ��Ʈ ����
	int _distance_attack_monster_left_width;	//������ ���� ���� ���� ����
	int _distance_attack_monster_left_height;	//������ ���� ���� ���� ����
	int _distance_attack_monster_right_width;	//������ ������ ���� ���� ����
	int _distance_attack_monster_right_height;	//������ ������ ���� ���� ����
	
	int rndSpwan;//�׽�Ʈ�� ������ġ ��ȯ
	bool _bDebug;
	//=========================================================
	//===					�ɷ�ġ ����						===
	//=========================================================
	int _hp;						//ü��
	int _attack_damage;				//���ݷ�
	int _speed_attack;				//���ݼӵ�
	int _speed_swing_sword;			//�ֵθ��� �ӵ�	(Į�� ġ�ѵ���ٰ� ������ �ӵ���, Į�� �������� �������� �Դ´�)
	float _speed_move;				//�̵��ӵ�
	int _cooldown_attack;			//���� ���ð�


	//=========================================================
	//===						A I	����						===
	//=========================================================
	bool _bShow_left;				//���� ������
	bool _bChk_player;				//�νĹ��� �ȿ� �÷��̾ ��� �Դ�
	bool _bChase_player;			//�÷��̾ �Ѵ� ���̴�
	bool _bJump_monster;			//������ �ߴ°�
	bool _bAttackable_monster;		//���ݹ��� �ȿ� �÷��̾ ��� �Դ�
	bool _bSwing_sword;				//���� �ֵθ������ΰ�

	int _counter_monsterJump;		//���� ���� �Ѱ踦 �����ش�
	int _rnd_idleAct;				//�����¿��� �� �ൿ ���� ����
	int _cooldown_idle_Act;			//idle ���� �ൿ ī��Ʈ
	int _cooldown_idle_Stand;		//idle ���� �۶����� ī��Ʈ

	//=========================================================
	//===						��	��						===
	//=========================================================
	void findPlayer();			//�÷��̾ ã�ƶ�!
	void moveLeft();			//�������� �̵�
	void moveRight();			//���������� �̵�
	void jump_up();				//���� ����
	void jump_down();			//�Ʒ��� ����

	void chasePlayer();			//�÷��̾� �߰�
	void compareAttack();		//���ݻ�Ÿ� ���� �ִ��� Ȯ��
	void attack();				//����

	void idle();				//������

public:
	void show_rc();										//��Ʈ ���̱� ( ��� )	
	void init_ground();									//�׶��� �� �޾ƿ���
	void init_monster_size_rc();						//���� ����
	void init_chk_distance_player_rc();					//������ �÷��̾� �ν� ���� ����
	void init_attack_distance_rc_left();				//������ ���� ���� ���� ����
	void init_attack_distance_rc_right();				//������ ������ ���� ���� ����


	void set_hp(int x) { _hp = x; }						//HP �����ϱ�	(������ ^^)
	int get_hp() { return _hp; }						//HP �޾ƿ���
	//void set_rc(RECT rc) { _monster_size_rc = rc; }
	//RECT get_rc() { return _monster_size_rc; }
public:
	Monster();
	~Monster();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

};


