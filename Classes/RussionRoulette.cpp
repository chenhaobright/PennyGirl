#include "RussionRoulette.h"

RussionRoulette::RussionRoulette()
{
	srand(unsigned int(time(NULL)));

	this->init();
}

RussionRoulette::~RussionRoulette()
{

}


void RussionRoulette::init()
{
	_rollCount = 0;
	_shotSum = 0;

	_curBulletNum = 0;

	_shotIndex = rand() % MAX_BULLET_COUNT + 1;

	_sumMoney = 0;
	_nextShotMoney = 10;

	_bDead = false;
}

void RussionRoulette::reset()
{
	this->init();
}

//开机
void RussionRoulette::shot()
{
	_shotSum++;
	_curBulletNum++;
	if (_curBulletNum >= _shotIndex)
	{
		this->dead();
	}
}

//上膛
void RussionRoulette::roll()
{
	_rollCount++;
}

//爆头
void RussionRoulette::dead()
{
	_bDead = true;
}

//重新开始
void RussionRoulette::tryAgain()
{
	this->reset();
}

//结束退出到主界面
void RussionRoulette::end()
{

}

//计算下枪金钱
int RussionRoulette::getNextShotMoney()
{
	return 0;
}