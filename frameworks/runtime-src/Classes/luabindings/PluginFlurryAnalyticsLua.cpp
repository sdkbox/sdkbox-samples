#include "PluginFlurryAnalyticsLua.hpp"
#include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/sdkbox.h"



int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setReportLocation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setReportLocation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setReportLocation'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setReportLocation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setReportLocation",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setReportLocation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setUserID'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setUserID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setUserID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endSession'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::endSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:endSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setBackgroundSessionEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setBackgroundSessionEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setBackgroundSessionEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setBackgroundSessionEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setBackgroundSessionEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setBackgroundSessionEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_startSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_startSession'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::startSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:startSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_startSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_clearLocation(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_clearLocation'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::clearLocation();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:clearLocation",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_clearLocation'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setSessionReportsOnPauseEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnPauseEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setSessionReportsOnPauseEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getSessionID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getSessionID'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginFlurryAnalytics::getSessionID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:getSessionID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getSessionID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_activeSessionExists(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_activeSessionExists'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginFlurryAnalytics::activeSessionExists();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:activeSessionExists",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_activeSessionExists'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLatitude(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setLatitude");
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:setLatitude");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "sdkbox.PluginFlurryAnalytics:setLatitude");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "sdkbox.PluginFlurryAnalytics:setLatitude");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLatitude'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setLatitude(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setLatitude",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLatitude'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logError(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:logError");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:logError");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginFlurryAnalytics:logError");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logError'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::logError(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:logError",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logError'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setDebugLogEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setDebugLogEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setDebugLogEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setDebugLogEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setDebugLogEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setDebugLogEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setEventLoggingEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setEventLoggingEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setEventLoggingEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setEventLoggingEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setEventLoggingEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setEventLoggingEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLogLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::FA_FlurryLogLevel arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFlurryAnalytics:setLogLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLogLevel'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setLogLevel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setLogLevel",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLogLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setCrashReportingEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setCrashReportingEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setCrashReportingEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setCrashReportingEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setCrashReportingEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setCrashReportingEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginFlurryAnalytics::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_pauseBackgroundSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_pauseBackgroundSession'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::pauseBackgroundSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:pauseBackgroundSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_pauseBackgroundSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setGender'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logPageView(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logPageView'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::logPageView();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:logPageView",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logPageView'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAppVersion(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setAppVersion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAppVersion'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setAppVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setAppVersion",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAppVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginFlurryAnalytics:setAge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAge'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setAge(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAge'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setPulseEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setPulseEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setPulseEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setPulseEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setPulseEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setPulseEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getFlurryAgentVersion(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getFlurryAgentVersion'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginFlurryAnalytics::getFlurryAgentVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:getFlurryAgentVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getFlurryAgentVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setSessionReportsOnCloseEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnCloseEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setSessionReportsOnCloseEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setShowErrorInLogEnabled(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setShowErrorInLogEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setShowErrorInLogEnabled'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setShowErrorInLogEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setShowErrorInLogEnabled",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setShowErrorInLogEnabled'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionContinueSeconds(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:setSessionContinueSeconds");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionContinueSeconds'", nullptr);
            return 0;
        }
        sdkbox::PluginFlurryAnalytics::setSessionContinueSeconds(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics:setSessionContinueSeconds",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionContinueSeconds'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginFlurryAnalytics)");
    return 0;
}

int lua_register_PluginFlurryAnalyticsLua_PluginFlurryAnalytics(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginFlurryAnalytics");
    tolua_cclass(tolua_S,"PluginFlurryAnalytics","sdkbox.PluginFlurryAnalytics","",nullptr);

    tolua_beginmodule(tolua_S,"PluginFlurryAnalytics");
        tolua_function(tolua_S,"setReportLocation", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setReportLocation);
        tolua_function(tolua_S,"setUserID", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setUserID);
        tolua_function(tolua_S,"endSession", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endSession);
        tolua_function(tolua_S,"setBackgroundSessionEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setBackgroundSessionEnabled);
        tolua_function(tolua_S,"startSession", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_startSession);
        tolua_function(tolua_S,"clearLocation", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_clearLocation);
        tolua_function(tolua_S,"setSessionReportsOnPauseEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled);
        tolua_function(tolua_S,"getSessionID", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getSessionID);
        tolua_function(tolua_S,"activeSessionExists", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_activeSessionExists);
        tolua_function(tolua_S,"setLatitude", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLatitude);
        tolua_function(tolua_S,"logError", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logError);
        tolua_function(tolua_S,"setDebugLogEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setDebugLogEnabled);
        tolua_function(tolua_S,"setEventLoggingEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setEventLoggingEnabled);
        tolua_function(tolua_S,"setLogLevel", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setLogLevel);
        tolua_function(tolua_S,"setCrashReportingEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setCrashReportingEnabled);
        tolua_function(tolua_S,"init", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_init);
        tolua_function(tolua_S,"pauseBackgroundSession", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_pauseBackgroundSession);
        tolua_function(tolua_S,"setGender", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setGender);
        tolua_function(tolua_S,"logPageView", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logPageView);
        tolua_function(tolua_S,"setAppVersion", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAppVersion);
        tolua_function(tolua_S,"setAge", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setAge);
        tolua_function(tolua_S,"setPulseEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setPulseEnabled);
        tolua_function(tolua_S,"getFlurryAgentVersion", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_getFlurryAgentVersion);
        tolua_function(tolua_S,"setSessionReportsOnCloseEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled);
        tolua_function(tolua_S,"setShowErrorInLogEnabled", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setShowErrorInLogEnabled);
        tolua_function(tolua_S,"setSessionContinueSeconds", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setSessionContinueSeconds);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginFlurryAnalytics).name();
    g_luaType[typeName] = "sdkbox.PluginFlurryAnalytics";
    g_typeCast["PluginFlurryAnalytics"] = "sdkbox.PluginFlurryAnalytics";
    return 1;
}
TOLUA_API int register_all_PluginFlurryAnalyticsLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginFlurryAnalyticsLua_PluginFlurryAnalytics(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::Sdkbox::setProjectType("lua");
	return 1;
}

