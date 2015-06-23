
#include "PluginVungleLuaHelper.h"
#include "PluginVungle/PluginVungle.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class VungleListenerLua : public sdkbox::VungleListener {
public:
	VungleListenerLua(): mLuaHandler(0) {

	}
	~VungleListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (mLuaHandler == luaHandler) {
			return;
		}
		resetHandler();
		mLuaHandler = luaHandler;
	}

	void resetHandler() {
		if (0 == mLuaHandler) {
			return;
		}

        LUAENGINE->removeScriptHandler(mLuaHandler);
		mLuaHandler = 0;
	}

    void onVungleCacheAvailable() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onVungleCacheAvailable");
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVungleStarted() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onVungleStarted");
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVungleFinished() {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onVungleFinished");
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onVungleAdViewed(bool isComplete) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString("onVungleAdViewed");
        stack->pushBoolean(isComplete);
        stack->executeFunctionByHandler(mLuaHandler, 2);
    }

private:
	int mLuaHandler;
};

int lua_PluginVungelLua_PluginVungel_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginVungle",0,&tolua_err)) goto tolua_lerror;
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
        VungleListenerLua* lis = static_cast<VungleListenerLua*> (sdkbox::PluginVungle::getListener());
        if (nullptr == lis) {
        	lis = new VungleListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginVungle::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginVungle::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginVungleLua_PluginVungle_setListener'.",&tolua_err);
#endif
    return 0;
}



int extern_PluginVungel(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginVungle");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginVungelLua_PluginVungel_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_PluginVungelLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginVungel(L);

	tolua_endmodule(L);
	return 1;
}


