#include "stdafx.h"
#include "UI/UI.h"

UI::UI()
{
}

UI::~UI()
{
}

HRESULT UI::init()
{
	_inventory = new Inventory;
	_inventory->init();
	return S_OK;
}

void UI::release()
{
	_inventory->release();
}

void UI::update()
{
	_inventory->update();
}

void UI::render()
{
	_inventory->render();
}
