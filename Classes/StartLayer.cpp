#include "StartLayer.h"
#include "PennyScene.h"

Scene* StartLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = StartLayer::create();
	scene->addChild(layer);

	return scene;
}

bool StartLayer::init()
{
	bool bRet = false;
	do 
	{
		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->onTouchBegan = CC_CALLBACK_2(StartLayer::onTouchBegan, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

		CC_BREAK_IF(!Layer::init());

		Size visibleSize = Director::getInstance()->getVisibleSize();

		auto *startSprite = Sprite::create("girl/preface.jpg");
		startSprite->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(startSprite);

		bRet = true;
	} while (0);

	return bRet;
}

bool StartLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	PennyScene* runningScene = static_cast<PennyScene*>(Director::getInstance()->getRunningScene());
	runningScene->getStartLayer()->setVisible(false);
	runningScene->getGameLayer()->setVisible(true);
	
	return true;
}
