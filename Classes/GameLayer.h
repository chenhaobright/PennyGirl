#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__

#include "cocos2d.h"

#include "RussionRoulette.h"

USING_NS_CC;

class GameLayer : public Layer
{
public:
	GameLayer();
	~GameLayer();

	virtual bool init();
	CREATE_FUNC(GameLayer);

private:
	RussionRoulette _rr;
};

#endif	//__GAME_LAYER_H__
