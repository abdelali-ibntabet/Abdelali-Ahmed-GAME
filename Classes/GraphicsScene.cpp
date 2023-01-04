#include "GraphicsScene.h"

USING_NS_CC;

Scene* GraphicsScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicsScene::create();
    scene->addChild(layer);

    return scene;
}

bool GraphicsScene::init()
{
    if (!Layer::init())
    {
        return false;
    }


    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getVisibleSize();

    auto background = DrawNode::create();
    background->drawSolidRect(origin, winSize, Color4F(1, 1, 0.9, 1.0));
    this->addChild(background);

    auto player = Sprite::create("player1.png");
    player->setScale(0.4);
    player->setAnchorPoint(Vec2(0, 0));
    player->setPosition(Vec2(200, 50));

    auto ground = Sprite::create("ground.png");
    ground->setScale(1.0);
    ground->setAnchorPoint(Vec2(0, 0));
    ground->setPosition(Vec2(0, 0));



    this->addChild(player, 0);
    this->addChild(ground, 0);


    auto eventListener = EventListenerKeyboard::create();



    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {

        Vec2 loc = event->getCurrentTarget()->getPosition();
        switch (keyCode) {

        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->setPosition(loc.x=loc.x-10, loc.y);
            break;


        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->setPosition(loc.x = loc.x + 10, loc.y);
            break;


            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                auto jumpAction = JumpBy::create(0.5, Point(0, 0), 50, 1);
                event->getCurrentTarget()->runAction(jumpAction);
               /* DelayTime* pause = DelayTime::create(0.5);
                event->getCurrentTarget()->runAction(Sequence::create(pause));*/
                break;
                

            //    event->getCurrentTarget()->setPosition(loc.x, ++loc.y);
            //    break;


            //case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            //case EventKeyboard::KeyCode::KEY_S:
            //    event->getCurrentTarget()->setPosition(loc.x, --loc.y);
            //    break;
            }
        };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, player);

 

 












    return true;
}

