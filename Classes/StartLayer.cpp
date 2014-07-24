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
		CC_BREAK_IF(!Layer::init());

		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->onTouchBegan = CC_CALLBACK_2(StartLayer::onTouchBegan, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

		Size winSize = Director::getInstance()->getVisibleSize();

		auto *startSprite = Sprite::create("girl/preface.jpg");
		startSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
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
