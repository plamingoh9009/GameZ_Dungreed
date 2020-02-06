#pragma once
#include "base/gameNode.h"
class startscene : public gameNode
{
protected:
	image * _imgfront;
	image * _imgmiddle;
	image * _imgLogo;

	image * _imgstart;
	image * _imgset;
	image * _imgexit;

	RECT exitrc;
	RECT setrc;
	RECT startrc;
	RECT background;
	RECT _LogoRC;

	bool bcheck_button;
	int _loopX;
	int _frontloopX;

	int _runframe;
	int _startframe;
public:
	startscene();
	~startscene();

	HRESULT init();
	void release();
	void update();
	void render();
};

