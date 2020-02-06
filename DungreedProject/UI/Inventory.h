#pragma once
#include "base/gameNode.h"
class Inventory : public gameNode
{
private:
	image * _inventory;
	RECT _rcInventory;
	RECT _rcInventory_Slot[23];

public:
	Inventory();
	~Inventory();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();



};
 
