#include "PluginGoogleAnalyticsLua.hpp"
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"



int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logTiming(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        std::string arg2;
        std::string arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:logTiming");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginGoogleAnalytics:logTiming");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginGoogleAnalytics:logTiming");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "sdkbox.PluginGoogleAnalytics:logTiming");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logTiming'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::logTiming(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:logTiming",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logTiming'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopPeriodicalDispatch(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopPeriodicalDispatch'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::stopPeriodicalDispatch();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:stopPeriodicalDispatch",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopPeriodicalDispatch'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_setDryRun(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:setDryRun");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_setDryRun'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::setDryRun(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:setDryRun",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_setDryRun'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        int arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:logEvent");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginGoogleAnalytics:logEvent");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginGoogleAnalytics:logEvent");
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "sdkbox.PluginGoogleAnalytics:logEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logEvent'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::logEvent(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:logEvent",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchPeriodically(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginGoogleAnalytics:dispatchPeriodically");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchPeriodically'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::dispatchPeriodically(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:dispatchPeriodically",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchPeriodically'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_init'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logScreen(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:logScreen");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logScreen'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::logScreen(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:logScreen",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logScreen'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_startSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_startSession'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::startSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:startSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_startSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logException(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:logException");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "sdkbox.PluginGoogleAnalytics:logException");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logException'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::logException(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:logException",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logException'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopSession'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::stopSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:stopSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logSocial(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:logSocial");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginGoogleAnalytics:logSocial");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginGoogleAnalytics:logSocial");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logSocial'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::logSocial(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:logSocial",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logSocial'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableAdvertisingTracking(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:enableAdvertisingTracking");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableAdvertisingTracking'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::enableAdvertisingTracking(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:enableAdvertisingTracking",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableAdvertisingTracking'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchHits(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchHits'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::dispatchHits();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:dispatchHits",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchHits'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableTracker(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:enableTracker");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableTracker'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::enableTracker(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:enableTracker",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableTracker'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_createTracker(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginGoogleAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginGoogleAnalytics:createTracker");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_createTracker'", nullptr);
            return 0;
        }
        sdkbox::PluginGoogleAnalytics::createTracker(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginGoogleAnalytics:createTracker",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_createTracker'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_constructor(lua_State* tolua_S)
{
    int argc = 0;
    sdkbox::PluginGoogleAnalytics* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_constructor'", nullptr);
            return 0;
        }
        cobj = new sdkbox::PluginGoogleAnalytics();
        tolua_pushusertype(tolua_S,(void*)cobj,"sdkbox.PluginGoogleAnalytics");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "sdkbox.PluginGoogleAnalytics:PluginGoogleAnalytics",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginGoogleAnalytics)");
    return 0;
}

int lua_register_PluginGoogleAnalyticsLua_PluginGoogleAnalytics(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginGoogleAnalytics");
    tolua_cclass(tolua_S,"PluginGoogleAnalytics","sdkbox.PluginGoogleAnalytics","",nullptr);

    tolua_beginmodule(tolua_S,"PluginGoogleAnalytics");
        tolua_function(tolua_S,"new",lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_constructor);
        tolua_function(tolua_S,"logTiming", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logTiming);
        tolua_function(tolua_S,"stopPeriodicalDispatch", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopPeriodicalDispatch);
        tolua_function(tolua_S,"setDryRun", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_setDryRun);
        tolua_function(tolua_S,"logEvent", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logEvent);
        tolua_function(tolua_S,"dispatchPeriodically", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchPeriodically);
        tolua_function(tolua_S,"init", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_init);
        tolua_function(tolua_S,"logScreen", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logScreen);
        tolua_function(tolua_S,"startSession", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_startSession);
        tolua_function(tolua_S,"logException", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logException);
        tolua_function(tolua_S,"stopSession", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_stopSession);
        tolua_function(tolua_S,"logSocial", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_logSocial);
        tolua_function(tolua_S,"enableAdvertisingTracking", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableAdvertisingTracking);
        tolua_function(tolua_S,"dispatchHits", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_dispatchHits);
        tolua_function(tolua_S,"enableTracker", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_enableTracker);
        tolua_function(tolua_S,"createTracker", lua_PluginGoogleAnalyticsLua_PluginGoogleAnalytics_createTracker);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginGoogleAnalytics).name();
    g_luaType[typeName] = "sdkbox.PluginGoogleAnalytics";
    g_typeCast["PluginGoogleAnalytics"] = "sdkbox.PluginGoogleAnalytics";
    return 1;
}
TOLUA_API int register_all_PluginGoogleAnalyticsLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginGoogleAnalyticsLua_PluginGoogleAnalytics(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

