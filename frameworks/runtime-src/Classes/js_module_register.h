#ifndef __JS_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_JS_MODULE_HELPER_H__
#define __JS_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_JS_MODULE_HELPER_H__

#include "scripting/js-bindings/manual/ScriptingCore.h"
#include "jsb_cocos2dx_auto.hpp"
#include "jsb_cocos2dx_ui_auto.hpp"
#include "jsb_cocos2dx_studio_auto.hpp"
#include "jsb_cocos2dx_builder_auto.hpp"
#include "jsb_cocos2dx_spine_auto.hpp"
#include "jsb_cocos2dx_extension_auto.hpp"
#include "ui/jsb_cocos2dx_ui_manual.h"
#include "cocostudio/jsb_cocos2dx_studio_manual.h"
#include "cocosbuilder/js_bindings_ccbreader.h"
#include "spine/jsb_cocos2dx_spine_manual.h"
#include "extension/jsb_cocos2dx_extension_manual.h"
#include "localstorage/js_bindings_system_registration.h"
#include "chipmunk/js_bindings_chipmunk_registration.h"
#include "jsb_opengl_registration.h"
#include "network/XMLHTTPRequest.h"
#include "network/jsb_websocket.h"
#include "network/jsb_socketio.h"
#include "cocos2d_specifics.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/CCJavascriptJavaBridge.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "platform/ios/JavaScriptObjCBridge.h"
#endif

// AdColonuy
#include "jsbindings/PluginAdColonyJS.hpp"
#include "jsbindings/PluginAdcolonyJSHelper.hpp"

// charboost
#include "jsbindings/PluginChartboostJS.hpp"
#include "jsbindings/PluginChartboostJSHelper.h"

// flurry analytics
#include "jsbindings/PluginFlurryAnalyticsJS.hpp"
#include "jsbindings/PluginFlurryAnalyticsJSHelper.h"

// google analytics
#include "jsbindings/PluginGoogleAnalyticsJS.hpp"

// iap
#include "jsbindings/PluginIAPJS.hpp"
#include "jsbindings/PluginIAPJSHelper.hpp"

// kochava
#include "jsbindings/PluginKochavaJS.hpp"

// tune
#include "jsbindings/PluginTuneJS.hpp"
#include "jsbindings/PluginTuneJSHelper.h"

// vungle
#include "jsbindings/PluginVungleJS.hpp"
#include "jsbindings/PluginVungleJSHelper.h"

//// facebook
//#include "jsbindings/PluginFacebookJS.hpp"
//#include "jsbindings/PluginFacebookJSHelper.h"
//
//// agecheq
//#include "jsbindings/PluginAgeCheqJS.hpp"
//#include "jsbindings/PluginAgeCheqJSHelper.hpp"

USING_NS_CC;
int js_module_register()
{
    ScriptingCore* sc = ScriptingCore::getInstance();
    sc->addRegisterCallback(register_all_cocos2dx);
    sc->addRegisterCallback(register_cocos2dx_js_core);
    //sc->addRegisterCallback(register_cocos2dx_js_extensions);
    sc->addRegisterCallback(jsb_register_system);

    // extension can be commented out to reduce the package
    sc->addRegisterCallback(register_all_cocos2dx_extension);
    sc->addRegisterCallback(register_all_cocos2dx_extension_manual);

    // chipmunk can be commented out to reduce the package
    sc->addRegisterCallback(jsb_register_chipmunk);
    // opengl can be commented out to reduce the package
    sc->addRegisterCallback(JSB_register_opengl);

    // builder can be commented out to reduce the package
    sc->addRegisterCallback(register_all_cocos2dx_builder);
    sc->addRegisterCallback(register_CCBuilderReader);

    // ui can be commented out to reduce the package, attension studio need ui module
    sc->addRegisterCallback(register_all_cocos2dx_ui);
    sc->addRegisterCallback(register_all_cocos2dx_ui_manual);

    // studio can be commented out to reduce the package,
    sc->addRegisterCallback(register_all_cocos2dx_studio);
    sc->addRegisterCallback(register_all_cocos2dx_studio_manual);

    // spine can be commented out to reduce the package
    sc->addRegisterCallback(register_all_cocos2dx_spine);
    sc->addRegisterCallback(register_all_cocos2dx_spine_manual);

    // XmlHttpRequest can be commented out to reduce the package
    sc->addRegisterCallback(MinXmlHttpRequest::_js_register);
    // websocket can be commented out to reduce the package
    sc->addRegisterCallback(register_jsb_websocket);
    // sokcet io can be commented out to reduce the package
    sc->addRegisterCallback(register_jsb_socketio);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    sc->addRegisterCallback(JavascriptJavaBridge::_js_register);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS|| CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    sc->addRegisterCallback(JavaScriptObjCBridge::_js_register);
#endif

    // adcolony
    sc->addRegisterCallback(register_all_PluginAdColonyJS);
    sc->addRegisterCallback(register_all_PluginAdColonyJS_helper);

    // chartboost
    sc->addRegisterCallback(register_all_PluginChartboostJS);
    sc->addRegisterCallback(register_PluginChartboostJs_helper);

    // flurry analytics
    sc->addRegisterCallback(register_all_PluginFlurryAnalyticsJS);
    sc->addRegisterCallback(register_PluginFlurryAnalyticsJs_helper);

    // google analytics
    sc->addRegisterCallback(register_all_PluginGoogleAnalyticsJS);

    // iap
    sc->addRegisterCallback(register_all_PluginIAPJS);
    sc->addRegisterCallback(register_all_PluginIAPJS_helper);

    // kochava
    sc->addRegisterCallback(register_all_PluginKochavaJS);

    // tune
    sc->addRegisterCallback(register_all_PluginTuneJS);
    sc->addRegisterCallback(register_PluginTuneJs_helper);

    // vungle
    sc->addRegisterCallback(register_all_PluginVungleJS);
    sc->addRegisterCallback(register_PluginVungleJs_helper);

//    // facebook
//    sc->addRegisterCallback(register_all_PluginFacebookJS);
//    sc->addRegisterCallback(register_PluginFacebookJs_helper);
//    
//    // agecheq
//    sc->addRegisterCallback(register_all_PluginAgeCheqJS);
//    sc->addRegisterCallback(register_all_PluginAgeCheqJS_helper);
    return 1;
}

#endif  // __JS_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_JS_MODULE_HELPER_H__

