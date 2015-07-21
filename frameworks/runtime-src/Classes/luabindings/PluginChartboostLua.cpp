#include "PluginChartboostLua.hpp"
#include "PluginChartboost/PluginChartboost.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/sdkbox.h"



int lua_PluginChartboostLua_PluginChartboost_handleOpenURL(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:handleOpenURL");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginChartboost:handleOpenURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_handleOpenURL'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginChartboost::handleOpenURL(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:handleOpenURL",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_handleOpenURL'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setAutoCacheAds(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:setAutoCacheAds");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setAutoCacheAds'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setAutoCacheAds(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setAutoCacheAds",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setAutoCacheAds'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setStatusBarBehavior(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::CB_StatusBarBehavior arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginChartboost:setStatusBarBehavior");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setStatusBarBehavior'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setStatusBarBehavior(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setStatusBarBehavior",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setStatusBarBehavior'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_isAnyViewVisible(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_isAnyViewVisible'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginChartboost::isAnyViewVisible();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:isAnyViewVisible",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_isAnyViewVisible'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_getCustomID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_getCustomID'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginChartboost::getCustomID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:getCustomID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_getCustomID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_show(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:show");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_show'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::show(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:show",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_show'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_cache(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:cache");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_cache'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::cache(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:cache",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_cache'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setShouldDisplayLoadingViewForMoreApps(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:setShouldDisplayLoadingViewForMoreApps");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setShouldDisplayLoadingViewForMoreApps'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setShouldDisplayLoadingViewForMoreApps(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setShouldDisplayLoadingViewForMoreApps",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setShouldDisplayLoadingViewForMoreApps'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setShouldRequestInterstitialsInFirstSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:setShouldRequestInterstitialsInFirstSession");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setShouldRequestInterstitialsInFirstSession'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setShouldRequestInterstitialsInFirstSession(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setShouldRequestInterstitialsInFirstSession",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setShouldRequestInterstitialsInFirstSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_didPassAgeGate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:didPassAgeGate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_didPassAgeGate'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::didPassAgeGate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:didPassAgeGate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_didPassAgeGate'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setShouldPrefetchVideoContent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:setShouldPrefetchVideoContent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setShouldPrefetchVideoContent'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setShouldPrefetchVideoContent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setShouldPrefetchVideoContent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setShouldPrefetchVideoContent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_init'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_getAutoCacheAds(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_getAutoCacheAds'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginChartboost::getAutoCacheAds();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:getAutoCacheAds",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_getAutoCacheAds'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_closeImpression(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_closeImpression'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::closeImpression();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:closeImpression",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_closeImpression'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setCustomID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:setCustomID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setCustomID'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setCustomID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setCustomID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setCustomID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_isAvailable(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:isAvailable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_isAvailable'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginChartboost::isAvailable(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:isAvailable",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_isAvailable'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginChartboostLua_PluginChartboost_setShouldPauseClickForConfirmation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginChartboost:setShouldPauseClickForConfirmation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginChartboostLua_PluginChartboost_setShouldPauseClickForConfirmation'", nullptr);
            return 0;
        }
        sdkbox::PluginChartboost::setShouldPauseClickForConfirmation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost:setShouldPauseClickForConfirmation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setShouldPauseClickForConfirmation'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginChartboostLua_PluginChartboost_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginChartboost)");
    return 0;
}

int lua_register_PluginChartboostLua_PluginChartboost(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginChartboost");
    tolua_cclass(tolua_S,"PluginChartboost","sdkbox.PluginChartboost","",nullptr);

    tolua_beginmodule(tolua_S,"PluginChartboost");
        tolua_function(tolua_S,"handleOpenURL", lua_PluginChartboostLua_PluginChartboost_handleOpenURL);
        tolua_function(tolua_S,"setAutoCacheAds", lua_PluginChartboostLua_PluginChartboost_setAutoCacheAds);
        tolua_function(tolua_S,"setStatusBarBehavior", lua_PluginChartboostLua_PluginChartboost_setStatusBarBehavior);
        tolua_function(tolua_S,"isAnyViewVisible", lua_PluginChartboostLua_PluginChartboost_isAnyViewVisible);
        tolua_function(tolua_S,"getCustomID", lua_PluginChartboostLua_PluginChartboost_getCustomID);
        tolua_function(tolua_S,"show", lua_PluginChartboostLua_PluginChartboost_show);
        tolua_function(tolua_S,"cache", lua_PluginChartboostLua_PluginChartboost_cache);
        tolua_function(tolua_S,"setShouldDisplayLoadingViewForMoreApps", lua_PluginChartboostLua_PluginChartboost_setShouldDisplayLoadingViewForMoreApps);
        tolua_function(tolua_S,"setShouldRequestInterstitialsInFirstSession", lua_PluginChartboostLua_PluginChartboost_setShouldRequestInterstitialsInFirstSession);
        tolua_function(tolua_S,"didPassAgeGate", lua_PluginChartboostLua_PluginChartboost_didPassAgeGate);
        tolua_function(tolua_S,"setShouldPrefetchVideoContent", lua_PluginChartboostLua_PluginChartboost_setShouldPrefetchVideoContent);
        tolua_function(tolua_S,"init", lua_PluginChartboostLua_PluginChartboost_init);
        tolua_function(tolua_S,"getAutoCacheAds", lua_PluginChartboostLua_PluginChartboost_getAutoCacheAds);
        tolua_function(tolua_S,"closeImpression", lua_PluginChartboostLua_PluginChartboost_closeImpression);
        tolua_function(tolua_S,"setCustomID", lua_PluginChartboostLua_PluginChartboost_setCustomID);
        tolua_function(tolua_S,"isAvailable", lua_PluginChartboostLua_PluginChartboost_isAvailable);
        tolua_function(tolua_S,"setShouldPauseClickForConfirmation", lua_PluginChartboostLua_PluginChartboost_setShouldPauseClickForConfirmation);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginChartboost).name();
    g_luaType[typeName] = "sdkbox.PluginChartboost";
    g_typeCast["PluginChartboost"] = "sdkbox.PluginChartboost";
    return 1;
}
TOLUA_API int register_all_PluginChartboostLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginChartboostLua_PluginChartboost(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::Sdkbox::setProjectType("lua");
	return 1;
}

