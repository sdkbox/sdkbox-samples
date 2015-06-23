#include "AppDelegate.h"
#include "SimpleAudioEngine.h"

#include "HelloWorldScene.h"
#include "js_module_register.h"

#include "lua_module_register.h"
#include "CCLuaEngine.h"

#include "MyPluginsMgr.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
	SimpleAudioEngine::end();
    ScriptEngineManager::destroyInstance();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    //
    director->setDisplayStats(true);

    // init plugins
    MyPluginsMgr::getInstance()->init();
    
#if (SDKBOX_STARTER_KIT_TYPE == kSdkboxStarterKitTypeCpp)
    FileUtils::getInstance()->addSearchPath("res");
    director->runWithScene(HelloWorld::createScene());
    
#elif (SDKBOX_STARTER_KIT_TYPE == kSdkboxStarterKitTypeJs)
    
   js_module_register();
   ScriptingCore* sc = ScriptingCore::getInstance();
   sc->start();
   sc->runScript("script/jsb_boot.js");
   ScriptEngineProtocol *engine = ScriptingCore::getInstance();
   ScriptEngineManager::getInstance()->setScriptEngine(engine);
   ScriptingCore::getInstance()->runScript("main.js");
    
#elif (SDKBOX_STARTER_KIT_TYPE == kSdkboxStarterKitTypeLua)
    
    // register lua module
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);
    
    if (engine->executeScriptFile("src/main.lua"))
    {
        return false;
    }
#endif
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    auto director = Director::getInstance();
    director->stopAnimation();
    director->getEventDispatcher()->dispatchCustomEvent("game_on_hide");
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();    
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    auto director = Director::getInstance();
    director->startAnimation();
    director->getEventDispatcher()->dispatchCustomEvent("game_on_show");
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    
    MyPluginsMgr::getInstance()->applicationWillEnterForeground();
}
