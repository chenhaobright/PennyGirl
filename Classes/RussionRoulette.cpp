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

//��ǹ
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

//����
void RussionRoulette::roll()
{
	_rollCount++;
	_curBulletNum = 1;
	_shotIndex = rand() % MAX_BULLET_COUNT + 1;
	_nextMoney = _curBulletNum * _curBulletNum * 10;

}

//��ͷ
void RussionRoulette::dead()
{
	_bDead = true;
}

//���¿�ʼ
void RussionRoulette::tryAgain()
{
	this->reset();
}

//�����˳���������
void RussionRoulette::end()
{

}
