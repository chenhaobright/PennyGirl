#ifndef __DATA_LAYER_H__
#define __DATA_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class DataLayer : public LayerColor
{
public:
	DataLayer();
	~DataLayer();

	static DataLayer* createWithColor(const Color4B& color, GLfloat width, GLfloat height);

	bool initWithColor(const Color4B& color, GLfloat width, GLfloat height);
	bool loadLabel();

	void setTotalMoney(int totalMoney);
	void setNextMoney(int nextMoney);
	void setTopScore(int topScore);

public:
	Label* _totalMoneyLabel;
	Label* _nextMoneyLabel;
	Label* _topScoreLabel;
};

#endif	//__DATA_LAYER_H__