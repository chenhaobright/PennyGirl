#include "DataLayer.h"
#include "Define.h"

DataLayer::DataLayer()
{
	_totalMoneyLabel = nullptr;
	_nextMoneyLabel = nullptr;
	_topScoreLabel = nullptr;
}

DataLayer::~DataLayer()
{

}

DataLayer* DataLayer::createWithColor(const Color4B& color, GLfloat width, GLfloat height)
{
	DataLayer* pRet = new DataLayer();
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

bool DataLayer::initWithColor(const Color4B& color, GLfloat width, GLfloat height)
{
	bool bRet = false;
	
	do
	{
		CC_BREAK_IF(!LayerColor::initWithColor(color, width, height));
		CC_BREAK_IF(!this->loadLabel());

		bRet = true;
	} while (0);
	
	return bRet;
}

bool DataLayer::loadLabel()
{
	bool bRet = false;
	
	do
	{
		//¼ÓÔØTotalLabel
		int smallFontSize = 30;
		int bigFontSize = 40;

		auto dataLabel = Label::createWithSystemFont("Total", "Marker Felt", smallFontSize, Size::ZERO, TextHAlignment::LEFT);
		dataLabel->setPosition(Point(WINSIZE.width * 0.1, WINSIZE.height / 11));
		dataLabel->setColor(Color3B::RED);
		this->addChild(dataLabel);

		dataLabel = Label::createWithSystemFont("$", "Marker Felt", bigFontSize, Size::ZERO, TextHAlignment::LEFT);
		dataLabel->setPosition(Point(WINSIZE.width * 0.1 - 30, WINSIZE.height / 25));
		dataLabel->setColor(Color3B::RED);
		this->addChild(dataLabel);

		_totalMoneyLabel = Label::createWithSystemFont("0", "Marker Felt", smallFontSize, Size::ZERO, TextHAlignment::LEFT);
		_totalMoneyLabel->setPosition(Point(WINSIZE.width * 0.1 + 30, WINSIZE.height / 25));
		_totalMoneyLabel->setColor(Color3B::RED);
		this->addChild(_totalMoneyLabel);

		
		//¼ÓÔØnextMoneyLabel
		dataLabel = Label::createWithSystemFont("NEXT", "Marker Felt", smallFontSize, Size::ZERO, TextHAlignment::LEFT);
		dataLabel->setPosition(Point(WINSIZE.width * 0.5, WINSIZE.height / 11));
		dataLabel->setColor(Color3B::RED);
		this->addChild(dataLabel);

		dataLabel = Label::createWithSystemFont("$", "Marker Felt", bigFontSize, Size::ZERO, TextHAlignment::LEFT);
		dataLabel->setPosition(Point(WINSIZE.width * 0.5 - 30, WINSIZE.height / 25));
		dataLabel->setColor(Color3B::RED);
		this->addChild(dataLabel);

		_nextMoneyLabel = Label::createWithSystemFont("10", "Marker Felt", smallFontSize, Size::ZERO, TextHAlignment::LEFT);
		_nextMoneyLabel->setPosition(Point(WINSIZE.width * 0.5 + 30, WINSIZE.height / 25));
		_nextMoneyLabel->setColor(Color3B::RED);
		this->addChild(_nextMoneyLabel);


		//¼ÓÔØTopScoreLabel
		dataLabel = Label::createWithSystemFont("TOP", "Marker Felt", smallFontSize, Size::ZERO, TextHAlignment::LEFT);
		dataLabel->setPosition(Point(WINSIZE.width * 0.9, WINSIZE.height / 11));
		dataLabel->setColor(Color3B::RED);
		this->addChild(dataLabel);

		_topScoreLabel = Label::createWithSystemFont(Value(GET_TOP_SCORE).asString(), "Marker Felt", smallFontSize, Size::ZERO, TextHAlignment::LEFT);
		_topScoreLabel->setPosition(Point(WINSIZE.width * 0.9, WINSIZE.height / 25));
		_topScoreLabel->setColor(Color3B::RED);
		this->addChild(_topScoreLabel);

		bRet = true;
	} while (0);
	
	return bRet;
}

void DataLayer::setTotalMoney(int totalMoney)
{
	_totalMoneyLabel->setString(Value(totalMoney).asString());
}

void DataLayer::setNextMoney(int nextMoney)
{
	_nextMoneyLabel->setString(Value(nextMoney).asString());
}

void DataLayer::setTopScore(int topScore)
{
	_topScoreLabel->setString(Value(topScore).asString());
}
