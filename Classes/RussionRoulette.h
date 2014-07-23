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
	int _shotSum;			//��ǹ����
	int _rollCount;			//���Ŵ���
	int _shotIndex;			//�ڼ�ǹ����
	int _curBulletNum;		//��ǰroll�ĵ�Nǹ

private:
	int _sumMoney;			//����ܽ�Ǯ
	int _nextShotMoney;		//��һǹ��Ǯ

	bool _bDead;			//�Ƿ�����

};

#endif	//__RUSSION_ROULETTE_H__