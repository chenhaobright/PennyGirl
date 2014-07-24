#include "AppDelegate.h"
#include "PennyScene.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) 
	{
        glview = GLView::create("PennyGirl");
		glview->setFrameSize(768, 1024);
		glview->setFrameZoomFactor(0.5f);

        director->setOpenGLView(glview);

		glview->setDesignResolutionSize(768, 1024, ResolutionPolicy::FIXED_WIDTH);
    }

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

	auto scene = PennyScene::create();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
