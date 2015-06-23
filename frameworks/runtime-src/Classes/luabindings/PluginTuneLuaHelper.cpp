
#include "PluginTuneLuaHelper.h"
#include "PluginTune/PluginTune.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include <sstream>

class TuneListenerLua : public sdkbox::TuneListener {
public:
	TuneListenerLua(): m_luaHandler(0) {

	}
	~TuneListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (m_luaHandler == luaHandler) {
			return;
		}
		resetHandler();
		m_luaHandler = luaHandler;
	}

	void resetHandler() {
		if (m_luaHandler == 0) {
			return;
		}

        LUAENGINE->removeScriptHandler(m_luaHandler);
		m_luaHandler = 0;
	}

    virtual void onMobileAppTrackerEnqueuedActionWithReferenceId(const std::string &referenceId)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onEnqueuedAction");
        stack->pushString(referenceId.c_str());
        stack->executeFunctionByHandler(m_luaHandler, 2);
    }
    virtual void onMobileAppTrackerDidSucceedWithData(const std::string &data)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onSucceed");
        stack->pushString(data.c_str());
        stack->executeFunctionByHandler(m_luaHandler, 2);
    }
    virtual void onMobileAppTrackerDidFailWithError(const std::string &errorString)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onFailed");
        stack->pushString(errorString.c_str());
        stack->executeFunctionByHandler(m_luaHandler, 2);
    }
    virtual void onMobileAppTrackerDidReceiveDeeplink(const std::string &deeplink)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onReceiveDeeplink");
        stack->pushString(deeplink.c_str());
        stack->executeFunctionByHandler(m_luaHandler, 2);
    }

private:
    int m_luaHandler;
};

int lua_PluginTuneLua_PluginTune_setListener(lua_State* tolua_S) {
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
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        TuneListenerLua* lis = static_cast<TuneListenerLua*> (sdkbox::PluginTune::getListener());
        if (nullptr == lis) {
        	lis = new TuneListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginTune::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setListener'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginTuneLua_PluginTune_measureEvent(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:measureEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_measureEvent'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::measureEventForScript(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:measureEvent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_measureEvent'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginTuneLua_PluginTune_setPreloadData(lua_State* tolua_S)
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
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginTune:setPreloadData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginTuneLua_PluginTune_setPreloadData'", nullptr);
            return 0;
        }
        sdkbox::PluginTune::setPreloadDataForScript(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginTune:setPreloadData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginTuneLua_PluginTune_setPreloadData'.",&tolua_err);
#endif
    return 0;
}

int extern_PluginTune(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginTune");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginTuneLua_PluginTune_setListener);
        tolua_function(L,"measureEvent", lua_PluginTuneLua_PluginTune_measureEvent);
        tolua_function(L,"setPreloadData", lua_PluginTuneLua_PluginTune_setPreloadData);
    }
    lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_PluginTuneLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginTune(L);

	tolua_endmodule(L);
	return 1;
}


