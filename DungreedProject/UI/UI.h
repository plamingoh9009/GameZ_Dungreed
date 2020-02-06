#pragma once
#include "UI/Inventory.h" 
class UI : public gameNode
{
public:
	Inventory * _inventory;
public:
	
	UI();
	~UI();

	Inventory * InfoInventory() { return _inventory; }
	HRESULT init();
	void release();
	void update();
	void render();
};

