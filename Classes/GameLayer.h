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
	void shotLogic();	//��ǹ�߼�
	void rollLogic();	//�����߼�
	void restart();		//���¿�ʼ
	void gameover();	//��Ϸ�����˳�

	void reset();		//��Ϸ��ԭ
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
