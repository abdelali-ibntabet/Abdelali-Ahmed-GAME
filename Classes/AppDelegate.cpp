#include "AppDelegate.h"
#include "GraphicsScene.h"


USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}




bool AppDelegate::applicationDidFinishLaunching() {

    static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
    static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
    static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
    static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

    auto director = Director::getInstance();

    auto glview = director->getOpenGLView();
    if (!glview) {
        glview = GLViewImpl::create("NotPicoPark");
        glview->setFrameSize(900, 600);
        director->setOpenGLView(glview);
    }




    auto scene = GraphicsScene::createScene();
    director->runWithScene(scene);



    return true;
}




void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}