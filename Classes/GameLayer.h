#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include <string>

#include "RussionRoulette.h"
#include "DataLayer.h"

USING_NS_CC;

class GameLayer : public LayerColor
{
public:
	GameLayer();
	~GameLayer();

	static GameLayer* createWithColor(const Color4B& color, GLfloat width, GLfloat height);

	bool initWithColor(const Color4B& color, GLfloat width, GLfloat height);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;

public:
	void shotLogic();	//开枪逻辑
	void rollLogic();	//上膛逻辑
	void restart();		//重新开始
	void gameover();	//游戏结束退出

	void reset();		//游戏复原
private:
	bool loadResource();
	bool loadDataLayer();
	int getRandom(int start, int end);
	std::string getGirlName(int index, const std::string& state);

private:
	DataLayer* _dataLayer;

	RussionRoulette _rr;
	int _randomIndex;

	Sprite* _girlSpriteAlive;
	Sprite* _girlSpriteRoll;
	Sprite* _girlSpriteDead;
};

#endif	//__GAME_LAYER_H__
