#include "PluginTuneLua.hpp"
#include "PluginTune/PluginTune.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/sdkbox.h"



int lua_PluginTuneLua_PluginTune_setUserName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setUserName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setUserName'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setUserName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setUserName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setUserName'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setGoogleUserId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setGoogleUserId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setGoogleUserId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setGoogleUserId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setGoogleUserId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setGoogleUserId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setFacebookEventLogging(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        bool arg0;
        bool arg1;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setFacebookEventLogging");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "sdkbox.PluginTune:setFacebookEventLogging");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setFacebookEventLogging'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setFacebookEventLogging(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setFacebookEventLogging",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setFacebookEventLogging'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_measureSession(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_measureSession'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::measureSession();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:measureSession",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_measureSession'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setAppAdTracking(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setAppAdTracking");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setAppAdTracking'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setAppAdTracking(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setAppAdTracking",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setAppAdTracking'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setAppleAdvertisingIdentifier(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setAppleAdvertisingIdentifier");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "sdkbox.PluginTune:setAppleAdvertisingIdentifier");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setAppleAdvertisingIdentifier'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setAppleAdvertisingIdentifier(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setAppleAdvertisingIdentifier",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setAppleAdvertisingIdentifier'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setPackageName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setPackageName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setPackageName'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setPackageName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setPackageName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setPackageName'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setTRUSTeId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setTRUSTeId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setTRUSTeId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setTRUSTeId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setTRUSTeId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setTRUSTeId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_automateIapEventMeasurement(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:automateIapEventMeasurement");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_automateIapEventMeasurement'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::automateIapEventMeasurement(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:automateIapEventMeasurement",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_automateIapEventMeasurement'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setUseCookieTracking(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setUseCookieTracking");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setUseCookieTracking'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setUseCookieTracking(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setUseCookieTracking",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setUseCookieTracking'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_openLogId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_openLogId'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginTune::openLogId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:openLogId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_openLogId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setLatitude(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginTune:setLatitude");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginTune:setLatitude");
            if (!ok) { break; }
            double arg2;
            ok &= luaval_to_number(tolua_S, 4,&arg2, "sdkbox.PluginTune:setLatitude");
            if (!ok) { break; }
            sdkbox::PluginTune::setLatitude(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginTune:setLatitude");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginTune:setLatitude");
            if (!ok) { break; }
            sdkbox::PluginTune::setLatitude(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginTune:setLatitude",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setLatitude'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setAllowDuplicateRequests(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setAllowDuplicateRequests");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setAllowDuplicateRequests'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setAllowDuplicateRequests(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setAllowDuplicateRequests",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setAllowDuplicateRequests'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setUserId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setUserId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setUserId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setUserId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setUserId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setUserId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_applicationDidOpenURL(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:applicationDidOpenURL");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginTune:applicationDidOpenURL");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_applicationDidOpenURL'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::applicationDidOpenURL(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:applicationDidOpenURL",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_applicationDidOpenURL'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setExistingUser(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setExistingUser");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setExistingUser'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setExistingUser(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setExistingUser",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setExistingUser'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setShouldAutoDetectJailbroken(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setShouldAutoDetectJailbroken");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setShouldAutoDetectJailbroken'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setShouldAutoDetectJailbroken(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setShouldAutoDetectJailbroken",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setShouldAutoDetectJailbroken'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_init'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setAppleVendorIdentifier(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setAppleVendorIdentifier");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setAppleVendorIdentifier'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setAppleVendorIdentifier(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setAppleVendorIdentifier",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setAppleVendorIdentifier'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setGender(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginTune::Gender arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginTune:setGender");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setGender'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setGender(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setGender",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setGender'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setCurrencyCode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setCurrencyCode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setCurrencyCode'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setCurrencyCode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setCurrencyCode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setCurrencyCode'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setJailbroken(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setJailbroken");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setJailbroken'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setJailbroken(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setJailbroken",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setJailbroken'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_startAppToAppTracking(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:startAppToAppTracking");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginTune:startAppToAppTracking");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginTune:startAppToAppTracking");
        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "sdkbox.PluginTune:startAppToAppTracking");
        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "sdkbox.PluginTune:startAppToAppTracking");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_startAppToAppTracking'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::startAppToAppTracking(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:startAppToAppTracking",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_startAppToAppTracking'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setAge(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginTune:setAge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setAge'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setAge(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setAge",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setAge'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setPhoneNumber(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setPhoneNumber");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setPhoneNumber'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setPhoneNumber(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setPhoneNumber",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setPhoneNumber'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_checkForDeferredDeeplinkWithTimeout(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "sdkbox.PluginTune:checkForDeferredDeeplinkWithTimeout");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_checkForDeferredDeeplinkWithTimeout'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::checkForDeferredDeeplinkWithTimeout(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:checkForDeferredDeeplinkWithTimeout",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_checkForDeferredDeeplinkWithTimeout'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_measureEventName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:measureEventName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_measureEventName'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::measureEventName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:measureEventName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_measureEventName'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setRedirectUrl(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setRedirectUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setRedirectUrl'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setRedirectUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setRedirectUrl",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setRedirectUrl'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setShouldAutoGenerateAppleVendorIdentifier(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setShouldAutoGenerateAppleVendorIdentifier");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setShouldAutoGenerateAppleVendorIdentifier'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setShouldAutoGenerateAppleVendorIdentifier(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setShouldAutoGenerateAppleVendorIdentifier",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setShouldAutoGenerateAppleVendorIdentifier'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_isPayingUser(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_isPayingUser'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginTune::isPayingUser();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:isPayingUser",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_isPayingUser'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setUserEmail(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setUserEmail");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setUserEmail'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setUserEmail(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setUserEmail",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setUserEmail'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setFacebookUserId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setFacebookUserId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setFacebookUserId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setFacebookUserId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setFacebookUserId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setFacebookUserId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_matId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_matId'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginTune::matId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:matId",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_matId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setTwitterUserId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setTwitterUserId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setTwitterUserId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setTwitterUserId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setTwitterUserId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setTwitterUserId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_measureEventId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginTune:measureEventId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_measureEventId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::measureEventId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:measureEventId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_measureEventId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setPayingUser(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setPayingUser");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setPayingUser'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setPayingUser(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setPayingUser",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setPayingUser'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setSiteId(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setSiteId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setSiteId'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setSiteId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setSiteId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setSiteId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginTuneLua_PluginTune_setDebugMode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginTune",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginTune:setDebugMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setDebugMode'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setDebugMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setDebugMode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setDebugMode'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginTuneLua_PluginTune_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginTune)");
    return 0;
}

int lua_register_PluginTuneLua_PluginTune(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginTune");
    tolua_cclass(tolua_S,"PluginTune","sdkbox.PluginTune","",nullptr);

    tolua_beginmodule(tolua_S,"PluginTune");
        tolua_function(tolua_S,"setUserName", lua_PluginTuneLua_PluginTune_setUserName);
        tolua_function(tolua_S,"setGoogleUserId", lua_PluginTuneLua_PluginTune_setGoogleUserId);
        tolua_function(tolua_S,"setFacebookEventLogging", lua_PluginTuneLua_PluginTune_setFacebookEventLogging);
        tolua_function(tolua_S,"measureSession", lua_PluginTuneLua_PluginTune_measureSession);
        tolua_function(tolua_S,"setAppAdTracking", lua_PluginTuneLua_PluginTune_setAppAdTracking);
        tolua_function(tolua_S,"setAppleAdvertisingIdentifier", lua_PluginTuneLua_PluginTune_setAppleAdvertisingIdentifier);
        tolua_function(tolua_S,"setPackageName", lua_PluginTuneLua_PluginTune_setPackageName);
        tolua_function(tolua_S,"setTRUSTeId", lua_PluginTuneLua_PluginTune_setTRUSTeId);
        tolua_function(tolua_S,"automateIapEventMeasurement", lua_PluginTuneLua_PluginTune_automateIapEventMeasurement);
        tolua_function(tolua_S,"setUseCookieTracking", lua_PluginTuneLua_PluginTune_setUseCookieTracking);
        tolua_function(tolua_S,"openLogId", lua_PluginTuneLua_PluginTune_openLogId);
        tolua_function(tolua_S,"setLatitude", lua_PluginTuneLua_PluginTune_setLatitude);
        tolua_function(tolua_S,"setAllowDuplicateRequests", lua_PluginTuneLua_PluginTune_setAllowDuplicateRequests);
        tolua_function(tolua_S,"setUserId", lua_PluginTuneLua_PluginTune_setUserId);
        tolua_function(tolua_S,"applicationDidOpenURL", lua_PluginTuneLua_PluginTune_applicationDidOpenURL);
        tolua_function(tolua_S,"setExistingUser", lua_PluginTuneLua_PluginTune_setExistingUser);
        tolua_function(tolua_S,"setShouldAutoDetectJailbroken", lua_PluginTuneLua_PluginTune_setShouldAutoDetectJailbroken);
        tolua_function(tolua_S,"init", lua_PluginTuneLua_PluginTune_init);
        tolua_function(tolua_S,"setAppleVendorIdentifier", lua_PluginTuneLua_PluginTune_setAppleVendorIdentifier);
        tolua_function(tolua_S,"setGender", lua_PluginTuneLua_PluginTune_setGender);
        tolua_function(tolua_S,"setCurrencyCode", lua_PluginTuneLua_PluginTune_setCurrencyCode);
        tolua_function(tolua_S,"setJailbroken", lua_PluginTuneLua_PluginTune_setJailbroken);
        tolua_function(tolua_S,"startAppToAppTracking", lua_PluginTuneLua_PluginTune_startAppToAppTracking);
        tolua_function(tolua_S,"setAge", lua_PluginTuneLua_PluginTune_setAge);
        tolua_function(tolua_S,"setPhoneNumber", lua_PluginTuneLua_PluginTune_setPhoneNumber);
        tolua_function(tolua_S,"checkForDeferredDeeplinkWithTimeout", lua_PluginTuneLua_PluginTune_checkForDeferredDeeplinkWithTimeout);
        tolua_function(tolua_S,"measureEventName", lua_PluginTuneLua_PluginTune_measureEventName);
        tolua_function(tolua_S,"setRedirectUrl", lua_PluginTuneLua_PluginTune_setRedirectUrl);
        tolua_function(tolua_S,"setShouldAutoGenerateAppleVendorIdentifier", lua_PluginTuneLua_PluginTune_setShouldAutoGenerateAppleVendorIdentifier);
        tolua_function(tolua_S,"isPayingUser", lua_PluginTuneLua_PluginTune_isPayingUser);
        tolua_function(tolua_S,"setUserEmail", lua_PluginTuneLua_PluginTune_setUserEmail);
        tolua_function(tolua_S,"setFacebookUserId", lua_PluginTuneLua_PluginTune_setFacebookUserId);
        tolua_function(tolua_S,"matId", lua_PluginTuneLua_PluginTune_matId);
        tolua_function(tolua_S,"setTwitterUserId", lua_PluginTuneLua_PluginTune_setTwitterUserId);
        tolua_function(tolua_S,"measureEventId", lua_PluginTuneLua_PluginTune_measureEventId);
        tolua_function(tolua_S,"setPayingUser", lua_PluginTuneLua_PluginTune_setPayingUser);
        tolua_function(tolua_S,"setSiteId", lua_PluginTuneLua_PluginTune_setSiteId);
        tolua_function(tolua_S,"setDebugMode", lua_PluginTuneLua_PluginTune_setDebugMode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginTune).name();
    g_luaType[typeName] = "sdkbox.PluginTune";
    g_typeCast["PluginTune"] = "sdkbox.PluginTune";
    return 1;
}
TOLUA_API int register_all_PluginTuneLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginTuneLua_PluginTune(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::Sdkbox::setProjectType("lua");
	return 1;
}

