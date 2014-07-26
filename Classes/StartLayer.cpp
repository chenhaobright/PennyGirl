#include "StartLayer.h"
#include "GameLayer.h"
#include "PennyScene.h"
#include "Define.h"

StartLayer::StartLayer()
{
	_topScoreLabel = NULL;
	_deadNumLabel = NULL;
}

StartLayer::~StartLayer()
{

}

bool StartLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Layer::init());
		CC_BREAK_IF(!this->loadRes());
		CC_BREAK_IF(!this->loadUserDefault());

		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->onTouchBegan = CC_CALLBACK_2(StartLayer::onTouchBegan, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

		bRet = true;
	} while (0);

	return bRet;
}

bool StartLayer::loadRes()
{
	bool bRet = false;
	
	do
	{
		auto startSprite = Sprite::create("girl/preface.jpg");
		startSprite->setPosition(Point(WINSIZE.width / 2, WINSIZE.height / 2));
		this->addChild(startSprite);

		int foneSize = 30;

		//¼ÓÔØtopScoreLable
		auto dataLable = Label::createWithSystemFont("SCORE", "fonts/youyuan.ttf", foneSize, Size::ZERO, TextHAlignment::LEFT);
		dataLable->setPosition(Point(WINSIZE.width * 0.1, WINSIZE.height * 0.9));
		dataLable->setColor(Color3B::WHITE);
		this->addChild(dataLable, 100);

		_topScoreLabel = Label::createWithSystemFont(Value(GET_TOP_SCORE).asString(), "fonts/youyuan.ttf", foneSize, Size::ZERO, TextHAlignment::LEFT);
		_topScoreLabel->setPosition(Point(WINSIZE.width * 0.2, WINSIZE.height * 0.9));
		_topScoreLabel->setColor(Color3B::WHITE);
		this->addChild(_topScoreLabel, 100);


		//¼ÓÔØdeadNumLable
		dataLable = Label::createWithSystemFont("DEAD", "fonts/youyuan.ttf", foneSize, Size::ZERO, TextHAlignment::LEFT);
		dataLable->setPosition(Point(WINSIZE.width * 0.1, WINSIZE.height * 0.8));
		dataLable->setColor(Color3B::WHITE);
		this->addChild(dataLable, 100);

		_deadNumLabel = Label::createWithSystemFont(Value(GET_DEAD_NUM).asString(), "fonts/youyuan.ttf", foneSize, Size::ZERO, TextHAlignment::LEFT);
		_deadNumLabel->setPosition(Point(WINSIZE.width * 0.2, WINSIZE.height * 0.8));
		_deadNumLabel->setColor(Color3B::WHITE);
		this->addChild(_deadNumLabel, 100);

		bRet = true;
	} while (0);
	
	return bRet;
}

bool StartLayer::loadUserDefault()
{
	bool bRet = false;
	
	do
	{

		bRet = true;
	} while (0);
	
	return bRet;

}

bool StartLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	auto* scene = static_cast<PennyScene*>(Director::getInstance()->getRunningScene());
	scene->addGameLayer();

	this->removeFromParentAndCleanup(true);
	
	return true;
}
