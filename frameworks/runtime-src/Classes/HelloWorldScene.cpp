#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "MyPluginsMgr.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto winSize = Director::getInstance()->getWinSize();
    auto color1 = Color3B(255,255,0);
    auto color2 = Color3B(255,0,0);
    CCMenuItemFont::setFontSize(32);
    CCMenuItemFont::setFontName("arial");

    auto *bg = Sprite::create("HelloWorld.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    addChild(bg);

    int y = winSize.height;
   // AdColony
   {
       y -= 60;
       auto *name = MenuItemFont::create("AdColony :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("video", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventAdColony1);
       });
       auto *item1 = MenuItemFont::create("v4vc", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventAdColony2);
       });

       
       auto *menu = CCMenu::create(name, item, item1, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0, 0));
       menu->setPosition(200, y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color1);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // PluginChartboost
   {
       y -= 60;
       auto *name = MenuItemFont::create("Chartboost :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("default", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventChartboost1);
       });

       auto *item1 = MenuItemFont::create("Level-Complete", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventChartboost2);
       });

       
       auto *menu = CCMenu::create(name, item, item1, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color2);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // Flurry Analytics
   {
       y -= 60;
       auto *name = MenuItemFont::create("Flurry :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("test", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventFA1);
       });
       
       
       auto *menu = CCMenu::create(name, item, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color1);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // Google Analytics
   {
       y -= 60;
       auto *name = MenuItemFont::create("GA :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("test", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventGA1);
       });
       
       
       auto *menu = CCMenu::create(name, item, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color2);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // IAP test
   {
       y -= 60;
       auto *name = MenuItemFont::create("IAP :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("purchase", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventIAP1);
       });
       
       auto *menu = CCMenu::create(name, item, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color1);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // Kochava
   {
       y -= 60;
       auto *name = MenuItemFont::create("Kochava :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("test", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventKochava1);
       });
       
       
       auto *menu = CCMenu::create(name, item, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color2);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // Tune
   {
       y -= 60;
       auto *name = MenuItemFont::create("Tune :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("test", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventTune1);
       });
       
       
       auto *menu = CCMenu::create(name, item, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color1);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
   
   // Vungle
   {
       y -= 60;
       auto *name = MenuItemFont::create("Vungle :", nullptr);
       name->setAnchorPoint(cocos2d::Point(0,0.5));
       
       auto *item = MenuItemFont::create("ad1", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventVungle1);
       });

       auto *item1 = MenuItemFont::create("ad2", [](Ref*){
           Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(kMenuEventVungle2);
       });
       
       auto *menu = CCMenu::create(name, item, item1, nullptr);
       menu->setAnchorPoint(cocos2d::Point(0,0));
       menu->setPosition(200,y);
       
       int x = 0;
       int w = 50;
       for (auto *node : menu->getChildren())
       {
           node->setAnchorPoint(cocos2d::Point(0,0));
           node->setPosition(x, 0);
           node->setColor(color2);
           x += node->getContentSize().width + w;
       }
       addChild(menu);
   }
    return true;
}

void HelloWorld::onButton1Click(Ref *sender)
{
    getEventDispatcher()->dispatchCustomEvent(kMenuEvent1);
    
    CCLOG("Button1 Click");
}

void HelloWorld::onButton2Click(Ref *sender)
{
    getEventDispatcher()->dispatchCustomEvent(kMenuEvent2);
    CCLOG("Button2 Click");
}