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

	_curBulletNum = 1;

	_shotIndex = rand() % MAX_BULLET_COUNT + 1;

	_totalMoney = 0;
	_nextMoney = _curBulletNum * _curBulletNum * 10;

	_bDead = false;
}

void RussionRoulette::reset()
{
	this->init();
}

//开枪
void RussionRoulette::shot()
{
	_shotSum++;
	
	if (_curBulletNum >= _shotIndex)
	{
		this->dead();
	}
	else
	{
		_curBulletNum++;
		_totalMoney += _nextMoney;
		_nextMoney = _curBulletNum * _curBulletNum * 10;
	}
}

//上膛
void RussionRoulette::roll()
{
	_rollCount++;
	_curBulletNum = 1;
	_shotIndex = rand() % MAX_BULLET_COUNT + 1;
	_nextMoney = _curBulletNum * _curBulletNum * 10;

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
