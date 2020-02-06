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
	image * _img;						//이미지	
	stage* _stage;						//스테이지
	RECT _size_monster_rc;					//몬스터의 렉트
	RECT _distance_chk_player_rc;			//몬스터의 플레이어 인식 범위 렉트
	RECT _distance_attack_monster_rc_left;	//몬스터의 왼쪽 공격 범위 렉트
	RECT _distance_attack_monster_rc_right;	//몬스터의 왼쪽 공격 범위 렉트
	//=========================================================
	//===					 렉트 변수들						===
	//=========================================================
	int _size_monster_width;				//몬스터 렉트 부피
	int _size_monster_height;				//몬스터 렉트 높이
	int _distance_chk_player_width;			//몬스터의 플레이어 인식 범위 렉트 부피
	int _distance_chk_player_height;		//몬스터의 플레이어 인식 범위 렉트 높이
	int _distance_attack_monster_left_width;	//몬스터의 왼쪽 공격 범위 부피
	int _distance_attack_monster_left_height;	//몬스터의 왼쪽 공격 범위 높이
	int _distance_attack_monster_right_width;	//몬스터의 오른쪽 공격 범위 부피
	int _distance_attack_monster_right_height;	//몬스터의 오른쪽 공격 범위 높이
	
	int rndSpwan;//테스트용 랜덤위치 소환
	bool _bDebug;
	//=========================================================
	//===					능력치 변수						===
	//=========================================================
	int _hp;						//체력
	int _attack_damage;				//공격력
	int _speed_attack;				//공격속도
	int _speed_swing_sword;			//휘두르는 속도	(칼을 치켜들었다가 내리는 속도다, 칼이 내려오면 데미지를 입는다)
	float _speed_move;				//이동속도
	int _cooldown_attack;			//공격 대기시간


	//=========================================================
	//===						A I	변수						===
	//=========================================================
	bool _bShow_left;				//왼쪽 보는중
	bool _bChk_player;				//인식범위 안에 플레이어가 들어 왔다
	bool _bChase_player;			//플레이어를 쫓는 중이다
	bool _bJump_monster;			//점프를 했는가
	bool _bAttackable_monster;		//공격범위 안에 플레이어가 들어 왔다
	bool _bSwing_sword;				//검을 휘두르는중인가

	int _counter_monsterJump;		//점프 도달 한계를 세어준다
	int _rnd_idleAct;				//대기상태에서 할 행동 랜덤 변수
	int _cooldown_idle_Act;			//idle 상태 행동 카운트
	int _cooldown_idle_Stand;		//idle 상태 멍때리기 카운트

	//=========================================================
	//===						함	수						===
	//=========================================================
	void findPlayer();			//플레이어를 찾아라!
	void moveLeft();			//왼쪽으로 이동
	void moveRight();			//오른쪽으로 이동
	void jump_up();				//위로 점프
	void jump_down();			//아래로 점프

	void chasePlayer();			//플레이어 추격
	void compareAttack();		//공격사거리 내에 있는지 확인
	void attack();				//공격

	void idle();				//대기상태

public:
	void show_rc();										//렉트 보이기 ( 토글 )	
	void init_ground();									//그라운드 값 받아오기
	void init_monster_size_rc();						//몬스터 생성
	void init_chk_distance_player_rc();					//몬스터의 플레이어 인식 범위 생성
	void init_attack_distance_rc_left();				//몬스터의 왼쪽 공격 범위 생성
	void init_attack_distance_rc_right();				//몬스터의 오른쪽 공격 범위 생성


	void set_hp(int x) { _hp = x; }						//HP 설정하기	(쓰세용 ^^)
	int get_hp() { return _hp; }						//HP 받아오기
	//void set_rc(RECT rc) { _monster_size_rc = rc; }
	//RECT get_rc() { return _monster_size_rc; }
public:
	Monster();
	~Monster();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

};


