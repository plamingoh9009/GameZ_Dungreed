#pragma once
#include "base/gameNode.h"
#include "Object/Unit/Player.h"

enum MONSTER_TYPE
{
	TYPE_EMPTY,
	SKELETON_WORRIOR,
	SKELETON_ARCHER
};

class Monster : public gameNode
{
protected:
	image * _img;					//이미지	
	RECT _monster_size_rc;			//몬스터의 렉트
	RECT _chk_distance_player_rc;	//몬스터의 플레이어 인식 범위 렉트
	//=========================================================
	//===					 렉트 변수들						===
	//=========================================================
	int monster_size_width;			//몬스터 렉트 부피
	int monster_size_height;		//몬스터 렉트 높이
	int _chk_distance_player_width;	//몬스터의 플레이어 인식 범위 렉트 부피
	int _chk_distance_player_height;//몬스터의 플레이어 인식 범위 렉트 높이
	bool _bDebug;
	//=========================================================
	//===					능력치 변수						===
	//=========================================================
	int _hp;						//체력
	int _attack_damage;				//공격력
	int _speed_attack;				//공격속도
	float _speed_move;				//이동속도
	int _colldown_attack;			//공격 대기시간


	//=========================================================
	//===						A I	변수						===
	//=========================================================
	bool _bChk_player;				//인식범위 안에 플레이어가 들어 왔다
	bool _bChase_player;			//플레이어를 쫓는 중이다
	bool _bAttackable_player;		//공격범위 안에 플레이어가 들어 왔다
	int _rnd_idleAct;				//대기상태에서 할 행동 랜덤 변수
	int _cooldown_idle_Act;			//idle 상태 행동 카운트
	int _cooldown_idle_Stand;		//idle 상태 멍때리기 카운트
	int _cooldown_chase;			//추적 카운트





	//=========================================================
	//===						함	수						===
	//=========================================================
	//void masterAi();			//인공지능 총괄 함수
	void findPlayer();			//플레이어를 찾아라!
	void moveLeft();			//왼쪽으로 이동
	void moveRight();			//오른쪽으로 이동
	void jump_up();				//위로 점프
	void jump_down();				//아래로 점프

	void chasePlayer();			//플레이어 추격
	void compareAttack();		//공격사거리 내에 있는지 확인
	void attack();				//공격

	void idle();				//대기상태

public:
	//void set_rc(RECT rc) { _monster_size_rc = rc; }
	//RECT get_rc() { return _monster_size_rc; }
	void show_rc();										//렉트 보이기 ( 토글 )	
	void init_monster_size_rc(int x, int y);			//몬스터 생성
	void init_chk_distance_player_rc();					//몬스터의 플레이어 인식 범위 생성
	void set_hp(int x) { _hp = x; }						//HP 설정하기
	int get_hp() { return _hp; }						//HP 받아오기
		
public:
	Monster();
	~Monster();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

};


