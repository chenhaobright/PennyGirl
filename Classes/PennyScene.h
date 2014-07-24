#ifndef __PENNY_SCENE_H__
#define __PENNY_SCENE_H__

#include "cocos2d.h"
#include "GameLayer.h"
#include "StartLayer.h"

USING_NS_CC;

class PennyScene : public Scene
{
public:
	PennyScene();
	~PennyScene();

	virtual bool init();
	CREATE_FUNC(PennyScene);

private:
	bool preloadSound();
	bool preloadRes();

public:
	CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
	CC_SYNTHESIZE(StartLayer*, _startLayer, StartLayer);
	
};

#endif