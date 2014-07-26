#include "PennyScene.h"

#include "SimpleAudioEngine.h"

#include "Define.h"

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

		CC_BREAK_IF(!this->preloadSound());
		CC_BREAK_IF(!this->preloadRes());

		this->addStartLayer();

		bRet = true;
	} while (0);

	return bRet;
}

bool PennyScene::preloadSound()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(PISTOL1_MP3);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(PISTOL2_MP3);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(ROLL_MP3);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(SHOT_EMPTY_MP3);

	return true;
}

bool PennyScene::preloadRes()
{
	return true;
}


void PennyScene::addStartLayer()
{
	_startLayer = StartLayer::create();
	this->addChild(_startLayer);
}

void PennyScene::addGameLayer()
{
	_gameLayer = GameLayer::create();
	this->addChild(_gameLayer);
}

