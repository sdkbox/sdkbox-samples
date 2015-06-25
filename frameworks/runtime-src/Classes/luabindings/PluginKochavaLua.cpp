#include "PluginKochavaLua.hpp"
#include "PluginKochava/PluginKochava.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"



int lua_PluginKochavaLua_PluginKochava_sendDeepLink(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginKochava:sendDeepLink"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "sdkbox.PluginKochava:sendDeepLink"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_sendDeepLink'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::sendDeepLink(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:sendDeepLink",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_sendDeepLink'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_spatialEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        const char* arg0;
        double arg1;
        double arg2;
        double arg3;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginKochava:spatialEvent"); arg0 = arg0_tmp.c_str();
        ok &= luaval_to_number(tolua_S, 3,&arg1, "sdkbox.PluginKochava:spatialEvent");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "sdkbox.PluginKochava:spatialEvent");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "sdkbox.PluginKochava:spatialEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_spatialEvent'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::spatialEvent(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:spatialEvent",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_spatialEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_setLimitAdTracking(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginKochava:setLimitAdTracking");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_setLimitAdTracking'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::setLimitAdTracking(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:setLimitAdTracking",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_setLimitAdTracking'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_enableLogging(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginKochava:enableLogging");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_enableLogging'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::enableLogging(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:enableLogging",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_enableLogging'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_trackEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "sdkbox.PluginKochava:trackEvent"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "sdkbox.PluginKochava:trackEvent"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_trackEvent'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::trackEvent(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:trackEvent",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_trackEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_retrieveAttribution(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_retrieveAttribution'", nullptr);
            return 0;
        }
        const std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, std::basic_string<char> > > >* ret = sdkbox::PluginKochava::retrieveAttribution();
        object_to_luaval<std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char>, std::basic_string<char> > > >>(tolua_S, "std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, std::basic_string<char> > > >*",(std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char>, std::basic_string<char> > > >*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:retrieveAttribution",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_retrieveAttribution'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_init'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginKochavaLua_PluginKochava_shutdown(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginKochava",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginKochavaLua_PluginKochava_shutdown'", nullptr);
            return 0;
        }
        sdkbox::PluginKochava::shutdown();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginKochava:shutdown",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginKochavaLua_PluginKochava_shutdown'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginKochavaLua_PluginKochava_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginKochava)");
    return 0;
}

int lua_register_PluginKochavaLua_PluginKochava(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginKochava");
    tolua_cclass(tolua_S,"PluginKochava","sdkbox.PluginKochava","",nullptr);

    tolua_beginmodule(tolua_S,"PluginKochava");
        tolua_function(tolua_S,"sendDeepLink", lua_PluginKochavaLua_PluginKochava_sendDeepLink);
        tolua_function(tolua_S,"spatialEvent", lua_PluginKochavaLua_PluginKochava_spatialEvent);
        tolua_function(tolua_S,"setLimitAdTracking", lua_PluginKochavaLua_PluginKochava_setLimitAdTracking);
        tolua_function(tolua_S,"enableLogging", lua_PluginKochavaLua_PluginKochava_enableLogging);
        tolua_function(tolua_S,"trackEvent", lua_PluginKochavaLua_PluginKochava_trackEvent);
        tolua_function(tolua_S,"retrieveAttribution", lua_PluginKochavaLua_PluginKochava_retrieveAttribution);
        tolua_function(tolua_S,"init", lua_PluginKochavaLua_PluginKochava_init);
        tolua_function(tolua_S,"shutdown", lua_PluginKochavaLua_PluginKochava_shutdown);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginKochava).name();
    g_luaType[typeName] = "sdkbox.PluginKochava";
    g_typeCast["PluginKochava"] = "sdkbox.PluginKochava";
    return 1;
}
TOLUA_API int register_all_PluginKochavaLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginKochavaLua_PluginKochava(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

