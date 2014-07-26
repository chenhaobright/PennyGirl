#include "GameLayer.h"
#include "PennyScene.h"

#include "Define.h"

using namespace CocosDenshion;

GameLayer::GameLayer()
{
	_dataLayer = NULL;
	_girlSpriteAlive = nullptr;
	_girlSpriteRoll = nullptr;
	_girlSpriteDead = nullptr;
}

GameLayer::~GameLayer()
{
}

GameLayer* GameLayer::createWithColor(const Color4B& color, GLfloat width, GLfloat height)
{
	GameLayer* pRet = new GameLayer();
	if (pRet && pRet->initWithColor(color, width, height))
	{
		pRet->autorelease();
	}
	else
	{
		delete pRet;
		pRet = NULL;
	}

	return pRet;
}

bool GameLayer::initWithColor(const Color4B& color, GLfloat width, GLfloat height)
{
	bool bRet = false;

	do 
	{
		CC_BREAK_IF(!LayerColor::initWithColor(color, width, height));

		CC_BREAK_IF(!this->loadResource());
		CC_BREAK_IF(!this->loadDataLayer());

		//增加单点触摸
		auto touchListener = EventListenerTouchOneByOne::create();
		touchListener->setSwallowTouches(true);
		touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

		bRet = true;
	} while (0);

	return bRet;
}

bool GameLayer::loadResource()
{
	bool bRet = false;
	do 
	{
		std::string girlName;
		_randomIndex = this->getRandom(1, 3);
		
		//读取alive状态女孩
		girlName = this->getGirlName(_randomIndex, "alive");
		_girlSpriteAlive = Sprite::create(girlName.c_str());
		if (_girlSpriteAlive == NULL) return false;	
		_girlSpriteAlive->setPosition(Point(WINSIZE.width / 2, WINSIZE.height / 2));
		_girlSpriteAlive->setVisible(true);
		_girlSpriteAlive->setScale(2.0f);
		this->addChild(_girlSpriteAlive);

		//读取roll状态女孩
		girlName = this->getGirlName(_randomIndex, "roll");
		_girlSpriteRoll = Sprite::create(girlName.c_str());
		if (_girlSpriteRoll == NULL) return false;
		_girlSpriteRoll->setPosition(Point(WINSIZE.width / 2, WINSIZE.height / 2));
		_girlSpriteRoll->setVisible(false);
		_girlSpriteRoll->setScale(2.0f);
		this->addChild(_girlSpriteRoll);

		//读取dead状态女孩
		girlName = this->getGirlName(_randomIndex, "die");
		_girlSpriteDead = Sprite::create(girlName.c_str());
		if (_girlSpriteDead == NULL) return false;
		_girlSpriteDead->setPosition(Point(WINSIZE.width / 2, WINSIZE.height / 2));
		_girlSpriteDead->setVisible(false);
		_girlSpriteDead->setScale(2.0f);
		this->addChild(_girlSpriteDead);

		bRet = true;
	} while (0);

	return bRet;
}

bool GameLayer::loadDataLayer()
{
	bool bRet = false;
	
	do
	{
		_dataLayer = DataLayer::createWithColor(Color4B(200, 200, 200, 50), WINSIZE.width, WINSIZE.height / 5);
		this->addChild(_dataLayer, 100);

		bRet = true;
	} while (0);
	
	return bRet;
}

bool GameLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	Point pt = touch->getLocation();

	if (_rr.getIsDead())		//如果女孩已经死亡
	{
		if (pt.y < WINSIZE.height / 2)		
		{
			this->restart();
		}
		else						
		{
			this->gameover();
		}
	}
	else						//女孩活着
	{
		if (pt.y < WINSIZE.height / 2)		
		{
			this->shotLogic();
		}
		else							
		{
			this->rollLogic();
		}
	}

	return true;
}

void GameLayer::shotLogic()
{
	SET_DEAD_NUM(GET_DEAD_NUM + 1);
	
	_rr.shot();

	if (_rr.getIsDead())
	{
		static int i = 0;
		if (i++ % 2 == 0)
		{
			SimpleAudioEngine::getInstance()->playEffect(PISTOL2_MP3);
		}
		else
		{
			SimpleAudioEngine::getInstance()->playEffect(PISTOL1_MP3);
		}
		
		_girlSpriteAlive->setVisible(false);
		_girlSpriteDead->setVisible(true);
	}
	else
	{
		SimpleAudioEngine::getInstance()->playEffect(SHOT_EMPTY_MP3);
		int totalMoney = _rr.getTotalMoney();

		_dataLayer->setTotalMoney(totalMoney);
		_dataLayer->setNextMoney(_rr.getNextMoney());

		if (totalMoney > GET_TOP_SCORE)
		{
			SET_TOP_SCORE(totalMoney);
			_dataLayer->setTopScore(totalMoney);
		}
	}
}

void GameLayer::rollLogic()
{
	SimpleAudioEngine::getInstance()->playEffect(ROLL_MP3);
	_rr.roll();

	_dataLayer->setNextMoney(_rr.getNextMoney());
}

void GameLayer::restart()
{
	this->reset();

	this->loadResource();
	this->loadDataLayer();
}

void GameLayer::gameover()
{
	this->reset();

	auto scene = dynamic_cast<PennyScene*>(Director::getInstance()->getRunningScene());
	if (scene != nullptr)
	{
		scene->addStartLayer();
		this->removeFromParentAndCleanup(true);
	}
}

void GameLayer::reset()
{
	_rr.reset();
	this->removeAllChildren();
}

std::string GameLayer::getGirlName(int index, const std::string& state)
{
	std::string girlName;
	if (_randomIndex != -1)
	{
		if (_randomIndex < 10)
			girlName = "girl/girl0" + Value(_randomIndex).asString() + "_" + state + ".png";
		else
			girlName = "girl/girl"  + Value(_randomIndex).asString() + "_" + state + ".png";
		
	}

	return girlName;
}

int GameLayer::getRandom(int start, int end)
{
	if (start < 1 || end < 1 || start >= end)
	{
		return -1;
	}

	return  (end - start + 1) * CCRANDOM_0_1() + start;
}