#include "GameLayer.h"



GameLayer::GameLayer()
{

}

GameLayer::~GameLayer()
{

}

bool GameLayer::init()
{
	bool bRet = false;

	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		CC_BREAK_IF(!loadResource());

		bRet = true;
	} while (0);

	return bRet;
}

bool GameLayer::loadResource()
{
	bool bRet = false;
	do 
	{
		Size winSize = Director::getInstance()->getWinSize();
		std::string girlName = getRandomGirlName();
		auto *pSprite = Sprite::create(girlName.c_str());
		if (pSprite == NULL) return false;

		pSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));

		this->addChild(pSprite);

		bRet = true;
	} while (0);

	return bRet;
}

std::string GameLayer::getRandomGirlName()
{
	int randomIndex = getRandom(1, 3);
	std::string girlName;
	if (randomIndex != -1)
	{
		if (randomIndex < 10)
			girlName = "girl/girl0" + Value(randomIndex).asString() + ".png";
		else
			girlName = "girl/girl" + Value(randomIndex).asString() + ".png";
		
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