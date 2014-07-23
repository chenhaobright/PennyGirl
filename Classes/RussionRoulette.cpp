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

//����
void RussionRoulette::shot()
{
	_shotSum++;
	_curBulletNum++;
	if (_curBulletNum >= _shotIndex)
	{
		this->dead();
	}
}

//����
void RussionRoulette::roll()
{
	_rollCount++;
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

//������ǹ��Ǯ
int RussionRoulette::getNextShotMoney()
{
	return 0;
}