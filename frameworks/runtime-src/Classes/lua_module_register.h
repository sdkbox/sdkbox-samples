#ifndef __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__
#define __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__

#include "cocosdenshion/lua_cocos2dx_cocosdenshion_manual.h"
#include "network/lua_cocos2dx_network_manual.h"
#include "cocosbuilder/lua_cocos2dx_cocosbuilder_manual.h"
#include "cocostudio/lua_cocos2dx_coco_studio_manual.hpp"
#include "extension/lua_cocos2dx_extension_manual.h"
#include "ui/lua_cocos2dx_ui_manual.hpp"
#include "spine/lua_cocos2dx_spine_manual.hpp"
#include "3d/lua_cocos2dx_3d_manual.h"
#include "audioengine/lua_cocos2dx_audioengine_manual.h"

// AdColonuy
#include "luabindings/PluginAdColonyLua.hpp"
#include "luabindings/PluginAdcolonyLuaHelper.h"

// charboost
#include "luabindings/PluginChartboostLua.hpp"
#include "luabindings/PluginChartboostLuaHelper.h"

// flurry analytics
#include "luabindings/PluginFlurryAnalyticsLua.hpp"
#include "luabindings/PluginFlurryAnalyticsLuaHelper.h"

// google analytics
#include "luabindings/PluginGoogleAnalyticsLua.hpp"

// iap
#include "luabindings/PluginIAPLua.hpp"
#include "luabindings/PluginIAPLuaHelper.hpp"

// kochava
#include "luabindings/PluginKochavaLua.hpp"

// tune
#include "luabindings/PluginTuneLua.hpp"
#include "luabindings/PluginTuneLuaHelper.h"

// vungle
#include "luabindings/PluginVungleLua.hpp"
#include "luabindings/PluginVungleLuaHelper.h"

static int lua_module_register(lua_State* L)
{
    //Dont' change the module register order unless you know what your are doing
    register_cocosdenshion_module(L);
    register_network_module(L);
    register_cocosbuilder_module(L);
    register_cocostudio_module(L);
    register_ui_moudle(L);
    register_extension_module(L);
    register_spine_module(L);
    register_cocos3d_module(L);
    register_audioengine_module(L);

    // adcolony
    register_all_PluginAdColonyLua(L);
    register_PluginAdcolonyLua_helper(L);

    // chartboost
    register_all_PluginChartboostLua(L);
    register_PluginChartboostLua_helper(L);

    // flurry analytics
    register_all_PluginFlurryAnalyticsLua(L);
    register_PluginFlurryAnalyticsLua_helper(L);

    // google analytics
    register_all_PluginGoogleAnalyticsLua(L);

    // iap
    register_all_PluginIAPLua(L);
    register_PluginIAPLua_helper(L);

    // kochava
    register_all_PluginKochavaLua(L);

    // tune
    register_all_PluginTuneLua(L);
    register_PluginTuneLua_helper(L);

    // vungle
    register_all_PluginVungleLua(L);
    register_PluginVungelLua_helper(L);

    return 1;
}

#endif  // __LUA_TEMPLATE_RUNTIME_FRAMEWORKS_RUNTIME_SRC_CLASSES_LUA_MODULE_REGISTER_H__

