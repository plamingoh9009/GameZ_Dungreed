#include "stdafx.h"
#include "UI/Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}
 
HRESULT Inventory::init()
{
	_inventory = new image;
	_inventory = IMAGEMANAGER->addImage("Inventory", "resource/image/inventory/Inventory.bmp",_rcInventory.left,_rcInventory.top,123*2 , 188*2 ,true, RGB(255, 0, 255));
	_rcInventory = RectMakeCenter(WINSIZEX /2 +200, 0 + 300,200,200/*inventory->getFrameWidth(),inventory->getFrameHeight()*/);

	return S_OK;
}

void Inventory::release()
{
	_inventory = nullptr;
}

void Inventory::update()
{

}

void Inventory::render()
{

	if (KEYMANAGER->isToggleKey('V'))
	{
	IMAGEMANAGER->render("Inventory", getMemDC());
	Rectangle(getMemDC(), _rcInventory.left,_rcInventory.top, _rcInventory.right, _rcInventory.bottom);
	}
	//if (KEYMANAGER->isStayKeyDown(VK_F1))
	//{
	//	Rectangle(getMemDC(), _rcInventory.left, _rcInventory.top, _rcInventory.right, _rcInventory.bottom);
	//}
	


}
