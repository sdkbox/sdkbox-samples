
#include "PluginAdcolonyLuaHelper.h"
#include "PluginAdColony/PluginAdColony.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class AdColonyListenerLua : public sdkbox::AdColonyListener {
public:
	AdColonyListenerLua(): mLuaHandler(0) {

	}
	~AdColonyListenerLua() {
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

    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAdColonyChange")));
        dict.insert(std::make_pair("info", adInfo2LuaValue(info)));
        dict.insert(std::make_pair("available", LuaValue::booleanValue(available)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAdColonyReward")));
        dict.insert(std::make_pair("info", adInfo2LuaValue(info)));
        dict.insert(std::make_pair("currencyName", LuaValue::stringValue(currencyName)));
        dict.insert(std::make_pair("amount", LuaValue::intValue(amount)));
        dict.insert(std::make_pair("success", LuaValue::booleanValue(success)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAdColonyStarted")));
        dict.insert(std::make_pair("info", adInfo2LuaValue(info)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info) {
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAdColonyFinished")));
        dict.insert(std::make_pair("info", adInfo2LuaValue(info)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }


private:
    LuaValue adInfo2LuaValue(const sdkbox::AdColonyAdInfo& info) {
        LuaValueDict dicLua;
        dicLua.insert(std::make_pair("name", LuaValue::stringValue(info.name)));
        dicLua.insert(std::make_pair("show", LuaValue::booleanValue(info.shown)));
        dicLua.insert(std::make_pair("zoneID", LuaValue::stringValue(info.zoneID)));
        dicLua.insert(std::make_pair("iapEnabled", LuaValue::booleanValue(info.iapEnabled)));
        dicLua.insert(std::make_pair("iapProductID", LuaValue::stringValue(info.iapProductID)));
        dicLua.insert(std::make_pair("iapQuantity", LuaValue::intValue(info.iapQuantity)));
        dicLua.insert(std::make_pair("iapEngagementType", LuaValue::intValue(info.iapEngagementType)));
        
        return LuaValue::dictValue(dicLua);
    }

private:
	int mLuaHandler;
};

int lua_PluginAdColonyLua_PluginAdColony_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAdColony",0,&tolua_err)) goto tolua_lerror;
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
        AdColonyListenerLua* lis = static_cast<AdColonyListenerLua*> (sdkbox::PluginAdColony::getListener());
        if (nullptr == lis) {
        	lis = new AdColonyListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginAdColony::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAdColony::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAdColonyLua_PluginAdColony_setListener'.",&tolua_err);
#endif
    return 0;
}



int extern_PluginAdcolony(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginAdColony");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginAdColonyLua_PluginAdColony_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_PluginAdcolonyLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginAdcolony(L);

	tolua_endmodule(L);
	return 1;
}


