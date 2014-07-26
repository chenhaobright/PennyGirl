#ifndef __DEFINE_H__
#define __DEFINE_H__


#define PISTOL1_MP3			("sound/pistol1.mp3")
#define PISTOL2_MP3			("sound/pistol2.mp3")
#define ROLL_MP3			("sound/roll.mp3")
#define SHOT_EMPTY_MP3		("sound/shot_empty.mp3")

#define WINSIZE				(Director::getInstance()->getWinSize())

#define GET_TOP_SCORE		(UserDefault::getInstance()->getIntegerForKey("TOP_SCORE"))
#define SET_TOP_SCORE(score)(UserDefault::getInstance()->setIntegerForKey("TOP_SCORE", score))

#define GET_DEAD_NUM		(UserDefault::getInstance()->getIntegerForKey("DEAD_NUM"))
#define SET_DEAD_NUM(num)	(UserDefault::getInstance()->setIntegerForKey("DEAD_NUM", num))

#endif	//__DEFINE_H__