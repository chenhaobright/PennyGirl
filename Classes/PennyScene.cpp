#include "PennyScene.h"

PennyScene::PennyScene(void)
{
	_gameLayer = NULL;
	_startLayer = NULL;
}

PennyScene::~PennyScene(void)
{
}

bool PennyScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		_startLayer = StartLayer::create();
		this->addChild(_startLayer, 0);

		_gameLayer = GameLayer::create();
		_gameLayer->setVisible(false);
		this->addChild(_gameLayer, 1);

		bRet = true;
	} while (0);

	return bRet;
}