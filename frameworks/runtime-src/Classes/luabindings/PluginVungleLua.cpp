#include "PluginVungleLua.hpp"
#include "PluginVungle/PluginVungle.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"



int lua_PluginVungleLua_PluginVungle_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginVungle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginVungle:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginVungleLua_PluginVungle_setUserID'", nullptr);
            return 0;
        }
        sdkbox::PluginVungle::setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginVungle:setUserID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginVungleLua_PluginVungle_setUserID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginVungleLua_PluginVungle_show(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginVungle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginVungle:show");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginVungleLua_PluginVungle_show'", nullptr);
            return 0;
        }
        sdkbox::PluginVungle::show(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginVungle:show",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginVungleLua_PluginVungle_show'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginVungleLua_PluginVungle_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginVungle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginVungleLua_PluginVungle_init'", nullptr);
            return 0;
        }
        sdkbox::PluginVungle::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginVungle:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginVungleLua_PluginVungle_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginVungleLua_PluginVungle_setDebug(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginVungle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginVungle:setDebug");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginVungleLua_PluginVungle_setDebug'", nullptr);
            return 0;
        }
        sdkbox::PluginVungle::setDebug(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginVungle:setDebug",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginVungleLua_PluginVungle_setDebug'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginVungleLua_PluginVungle_isCacheAvailable(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginVungle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginVungleLua_PluginVungle_isCacheAvailable'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginVungle::isCacheAvailable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginVungle:isCacheAvailable",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginVungleLua_PluginVungle_isCacheAvailable'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginVungleLua_PluginVungle_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginVungle)");
    return 0;
}

int lua_register_PluginVungleLua_PluginVungle(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginVungle");
    tolua_cclass(tolua_S,"PluginVungle","sdkbox.PluginVungle","",nullptr);

    tolua_beginmodule(tolua_S,"PluginVungle");
        tolua_function(tolua_S,"setUserID", lua_PluginVungleLua_PluginVungle_setUserID);
        tolua_function(tolua_S,"show", lua_PluginVungleLua_PluginVungle_show);
        tolua_function(tolua_S,"init", lua_PluginVungleLua_PluginVungle_init);
        tolua_function(tolua_S,"setDebug", lua_PluginVungleLua_PluginVungle_setDebug);
        tolua_function(tolua_S,"isCacheAvailable", lua_PluginVungleLua_PluginVungle_isCacheAvailable);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginVungle).name();
    g_luaType[typeName] = "sdkbox.PluginVungle";
    g_typeCast["PluginVungle"] = "sdkbox.PluginVungle";
    return 1;
}
TOLUA_API int register_all_PluginVungleLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginVungleLua_PluginVungle(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

