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

		pSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));

		this->addChild(pSprite);

		bRet = true;
	} while (0);

	return bRet;
}

std::string GameLayer::getRandomGirlName()
{
	int randomIndex = randomMToN(1, 3);
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

int GameLayer::randomMToN(int m, int n)
{
	if (m < 1 || n < 1 || m >= n)
	{
		return -1;
	}
	
	while (1)
	{
		int result = CCRANDOM_0_1() * n;
		if (result <= n && result >= m)
		{
			return result;
		}
	}

	return -1;
}