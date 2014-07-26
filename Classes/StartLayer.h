#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class StartLayer : public Layer
{
public:
	StartLayer();
	~StartLayer();

	virtual bool init();
	bool loadRes();
	bool loadUserDefault();

	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;

	CREATE_FUNC(StartLayer);
private:
	Label* _topScoreLabel;
	Label* _deadNumLabel;
};

#endif	//__START_SCENE_H__