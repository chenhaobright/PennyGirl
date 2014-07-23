#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class StartLayer : public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;

	CREATE_FUNC(StartLayer);
private:
	
};

#endif	//__START_SCENE_H__