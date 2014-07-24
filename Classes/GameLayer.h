#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include <string>

#include "RussionRoulette.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
	GameLayer();
	~GameLayer();

	virtual bool init();
	CREATE_FUNC(GameLayer);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;

public:
	void shotLogic();	//¿ªÇ¹Âß¼­
	void rollLogic();	//ÉÏÌÅÂß¼­

private:
	bool loadResource();
	int getRandom(int start, int end);
	std::string getRandomGirlName();

private:
	RussionRoulette _rr;
};

#endif	//__GAME_LAYER_H__
