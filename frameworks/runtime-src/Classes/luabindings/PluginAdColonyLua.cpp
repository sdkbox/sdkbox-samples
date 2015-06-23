#include "PluginAdColonyLua.hpp"
#include "PluginAdColony/PluginAdColony.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"



int lua_PluginAdColonyLua_PluginAdColony_getVideosPerReward(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:getVideosPerReward");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getVideosPerReward'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginAdColony::getVideosPerReward(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getVideosPerReward",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getVideosPerReward'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_getCustomID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getCustomID'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginAdColony::getCustomID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getCustomID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getCustomID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_zoneStatusForZone(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:zoneStatusForZone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_zoneStatusForZone'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginAdColony::zoneStatusForZone(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:zoneStatusForZone",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_zoneStatusForZone'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_show(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:show");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_show'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::show(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:show",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_show'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_getStatus(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:getStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getStatus'", nullptr);
            return 0;
        }
        int ret = (int)sdkbox::PluginAdColony::getStatus(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getStatus",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getStatus'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_videoAdCurrentlyRunning(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_videoAdCurrentlyRunning'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginAdColony::videoAdCurrentlyRunning();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:videoAdCurrentlyRunning",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_videoAdCurrentlyRunning'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_turnAllAdsOff(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_turnAllAdsOff'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::turnAllAdsOff();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:turnAllAdsOff",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_turnAllAdsOff'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_getVendorIdentifier(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getVendorIdentifier'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginAdColony::getVendorIdentifier();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getVendorIdentifier",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getVendorIdentifier'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_setUserMetadata(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:setUserMetadata");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginAdColony:setUserMetadata");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_setUserMetadata'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::setUserMetadata(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:setUserMetadata",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_setUserMetadata'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_init'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_getUniqueDeviceID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getUniqueDeviceID'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginAdColony::getUniqueDeviceID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getUniqueDeviceID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getUniqueDeviceID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_getAdvertisingIdentifier(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getAdvertisingIdentifier'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginAdColony::getAdvertisingIdentifier();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getAdvertisingIdentifier",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getAdvertisingIdentifier'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_userInterestedIn(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:userInterestedIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_userInterestedIn'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::userInterestedIn(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:userInterestedIn",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_userInterestedIn'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_setCustomID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:setCustomID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_setCustomID'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::setCustomID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:setCustomID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_setCustomID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_notifyIAPComplete(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::string arg0;
        std::string arg1;
        int arg2;
        double arg3;
        std::string arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:notifyIAPComplete");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginAdColony:notifyIAPComplete");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "sdkbox.PluginAdColony:notifyIAPComplete");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "sdkbox.PluginAdColony:notifyIAPComplete");
        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "sdkbox.PluginAdColony:notifyIAPComplete");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_notifyIAPComplete'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::notifyIAPComplete(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:notifyIAPComplete",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_notifyIAPComplete'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_getVideoCreditBalance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAdColony:getVideoCreditBalance");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_getVideoCreditBalance'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginAdColony::getVideoCreditBalance(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:getVideoCreditBalance",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_getVideoCreditBalance'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAdColonyLua_PluginAdColony_cancelAd(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAdColonyLua_PluginAdColony_cancelAd'", nullptr);
            return 0;
        }
        sdkbox::PluginAdColony::cancelAd();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony:cancelAd",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_cancelAd'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginAdColonyLua_PluginAdColony_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginAdColony)");
    return 0;
}

int lua_register_PluginAdColonyLua_PluginAdColony(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginAdColony");
    tolua_cclass(tolua_S,"PluginAdColony","sdkbox.PluginAdColony","",nullptr);

    tolua_beginmodule(tolua_S,"PluginAdColony");
        tolua_function(tolua_S,"getVideosPerReward", lua_PluginAdColonyLua_PluginAdColony_getVideosPerReward);
        tolua_function(tolua_S,"getCustomID", lua_PluginAdColonyLua_PluginAdColony_getCustomID);
        tolua_function(tolua_S,"zoneStatusForZone", lua_PluginAdColonyLua_PluginAdColony_zoneStatusForZone);
        tolua_function(tolua_S,"show", lua_PluginAdColonyLua_PluginAdColony_show);
        tolua_function(tolua_S,"getStatus", lua_PluginAdColonyLua_PluginAdColony_getStatus);
        tolua_function(tolua_S,"videoAdCurrentlyRunning", lua_PluginAdColonyLua_PluginAdColony_videoAdCurrentlyRunning);
        tolua_function(tolua_S,"turnAllAdsOff", lua_PluginAdColonyLua_PluginAdColony_turnAllAdsOff);
        tolua_function(tolua_S,"getVendorIdentifier", lua_PluginAdColonyLua_PluginAdColony_getVendorIdentifier);
        tolua_function(tolua_S,"setUserMetadata", lua_PluginAdColonyLua_PluginAdColony_setUserMetadata);
        tolua_function(tolua_S,"init", lua_PluginAdColonyLua_PluginAdColony_init);
        tolua_function(tolua_S,"getUniqueDeviceID", lua_PluginAdColonyLua_PluginAdColony_getUniqueDeviceID);
        tolua_function(tolua_S,"getAdvertisingIdentifier", lua_PluginAdColonyLua_PluginAdColony_getAdvertisingIdentifier);
        tolua_function(tolua_S,"userInterestedIn", lua_PluginAdColonyLua_PluginAdColony_userInterestedIn);
        tolua_function(tolua_S,"setCustomID", lua_PluginAdColonyLua_PluginAdColony_setCustomID);
        tolua_function(tolua_S,"notifyIAPComplete", lua_PluginAdColonyLua_PluginAdColony_notifyIAPComplete);
        tolua_function(tolua_S,"getVideoCreditBalance", lua_PluginAdColonyLua_PluginAdColony_getVideoCreditBalance);
        tolua_function(tolua_S,"cancelAd", lua_PluginAdColonyLua_PluginAdColony_cancelAd);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginAdColony).name();
    g_luaType[typeName] = "sdkbox.PluginAdColony";
    g_typeCast["PluginAdColony"] = "sdkbox.PluginAdColony";
    return 1;
}
TOLUA_API int register_all_PluginAdColonyLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginAdColonyLua_PluginAdColony(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

