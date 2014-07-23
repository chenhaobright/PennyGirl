#ifndef __RUSSION_ROULETTE_H__
#define __RUSSION_ROULETTE_H__

#include <time.h>
#include <stdlib.h>

const int MAX_BULLET_COUNT = 6;

class RussionRoulette
{
public:
	RussionRoulette();
	virtual ~RussionRoulette();

public:
	void init();
	void reset();

	void shot();
	void roll();
	void dead();
	void tryAgain();
	void end();

public:
	int getNextShotMoney();

private:
	int _shotSum;			//开枪次数
	int _rollCount;			//上膛次数
	int _shotIndex;			//第几枪死亡
	int _curBulletNum;		//当前roll的第N枪

private:
	int _sumMoney;			//获得总金钱
	int _nextShotMoney;		//下一枪金钱

	bool _bDead;			//是否死亡

};

#endif	//__RUSSION_ROULETTE_H__