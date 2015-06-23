
#include "PluginChartboostLuaHelper.h"
#include "PluginChartboost/PluginChartboost.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class ChartboostListenerLuaHelper : public sdkbox::ChartboostListener {
public:
	ChartboostListenerLuaHelper(): mLuaHandler(0) {
	}
	~ChartboostListenerLuaHelper() {
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
    
    void onChartboostCached(const std::string& name) {
        invokeLuaHandler("onChartboostCached", name.c_str());
    }
    bool onChartboostShouldDisplay(const std::string& name) {
        invokeLuaHandler("onChartboostShouldDisplay", name.c_str());
        return true;
    }
    void onChartboostDisplay(const std::string& name) {
        invokeLuaHandler("onChartboostDisplay", name.c_str());
    }
    void onChartboostDismiss(const std::string& name) {
        invokeLuaHandler("onChartboostDismiss", name.c_str());
    }
    void onChartboostClose(const std::string& name) {
        invokeLuaHandler("onChartboostClose", name.c_str());
    }
    void onChartboostClick(const std::string& name) {
        invokeLuaHandler("onChartboostClick", name.c_str());
    }
    void onChartboostReward(const std::string& name, int reward) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("func", LuaValue::stringValue("onChartboostReward")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("reward", LuaValue::intValue(reward)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("func", LuaValue::stringValue("onChartboostFailedToLoad")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("e", LuaValue::intValue(e)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("func", LuaValue::stringValue("onChartboostFailToRecordClick")));
        dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        dict.insert(std::make_pair("e", LuaValue::intValue(e)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    
    //Miscellaneous callbacks
    void onChartboostConfirmation() {
        invokeLuaHandler("onChartboostConfirmation", nullptr);
    }
    void onChartboostCompleteStore() {
        invokeLuaHandler("onChartboostCompleteStore", nullptr);
    }


private:
    void invokeLuaHandler(const char* func, const char* name) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("func", LuaValue::stringValue(func)));
        if (nullptr != name) {
            dict.insert(std::make_pair("name", LuaValue::stringValue(name)));
        }
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
	int mLuaHandler;
};

int lua_PluginChartboostLua_PluginChartboost_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginChartboost",0,&tolua_err)) goto tolua_lerror;
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
        ChartboostListenerLuaHelper* lis = static_cast<ChartboostListenerLuaHelper*> (sdkbox::PluginChartboost::getListener());
        if (nullptr == lis) {
        	lis = new ChartboostListenerLuaHelper();
        }
        lis->setHandler(handler);
        sdkbox::PluginChartboost::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginChartboost::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginChartboostLua_PluginChartboost_setListener'.",&tolua_err);
#endif
    return 0;
}



int extern_PluginChartboost(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginChartboost");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginChartboostLua_PluginChartboost_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_PluginChartboostlLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginChartboost(L);

	tolua_endmodule(L);
	return 1;
}


