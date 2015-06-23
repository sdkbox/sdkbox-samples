
#include "PluginFlurryAnalyticsLuaHelper.h"
#include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include <sstream>

class FlurryAnalyticsListenerLua : public sdkbox::FlurryAnalyticsListener {
public:
	FlurryAnalyticsListenerLua(): mLuaHandler(0) {

	}
	~FlurryAnalyticsListenerLua() {
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

	void flurrySessionDidCreateWithInfo(std::map<std::string, std::string>& info) {

		std::string jsonStr = map2JsonString(info);
		LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushString(jsonStr.c_str());
        stack->executeFunctionByHandler(mLuaHandler, 1);
	}

private:
	std::string map2JsonString(std::map<std::string, std::string>& map) {
	    std::ostringstream strStream;
	    bool bFirstItem = true;
	    strStream << "{";
        for (std::map<std::string, std::string>::iterator it = map.begin()
             ; it != map.end()
             ; it++)
        {
            if (!bFirstItem) {
                strStream << ",";
            }
            strStream << "\"";
            strStream << it->first;
            strStream << "\":\"";
            strStream << it->second;
            strStream << "\"";
            bFirstItem = false;
        }
        strStream << "}";
	}

private:
	int mLuaHandler;
};

int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:logEvent");
            if (!ok) { break; }
            int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    } while (0);

    ok  = true;
    do
    {
        if (argc == 2)
        {
        	if (lua_isboolean(tolua_S, 3)) {
        		std::string arg0;
	            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:logEvent");
	            if (!ok) { break; }
	            bool arg1;
	            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:logEvent");
	            if (!ok) { break; }
	            int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0, arg1);
	            tolua_pushnumber(tolua_S,(lua_Number)ret);
	            return 1;
        	} else {
	            std::string arg0;
	            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:logEvent");
	            if (!ok) { break; }
	            std::string arg1;
	            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:logEvent");
	            if (!ok) { break; }
	            int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0, arg1);
	            tolua_pushnumber(tolua_S,(lua_Number)ret);
	            return 1;
	        }
        }
    } while (0);

    ok  = true;
    do
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:logEvent");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:logEvent");
            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "sdkbox.PluginFlurryAnalytics:logEvent");
            if (!ok) { break; }
            int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0, arg1, arg2);
            tolua_pushnumber(tolua_S,(lua_Number)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginFlurryAnalytics:logEvent",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logEvent'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_addOrigin(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:addOrigin");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:addOrigin");
            if (!ok) { break; }
            sdkbox::PluginFlurryAnalytics::addOrigin(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:addOrigin");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:addOrigin");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "sdkbox.PluginFlurryAnalytics:addOrigin");
            if (!ok) { break; }
            sdkbox::PluginFlurryAnalytics::addOrigin(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginFlurryAnalytics:addOrigin",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_addOrigin'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endTimedEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFlurryAnalytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:endTimedEvent");
            if (!ok) { break; }
            sdkbox::PluginFlurryAnalytics::endTimedEvent(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFlurryAnalytics:endTimedEvent");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFlurryAnalytics:endTimedEvent");
            if (!ok) { break; }
            sdkbox::PluginFlurryAnalytics::endTimedEvent(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginFlurryAnalytics:endTimedEvent",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endTimedEvent'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setListener(lua_State* tolua_S) {
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
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        FlurryAnalyticsListenerLua* lis = static_cast<FlurryAnalyticsListenerLua*> (sdkbox::PluginFlurryAnalytics::getListener());
        if (nullptr == lis) {
        	lis = new FlurryAnalyticsListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginFlurryAnalytics::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFlurryAnalytics::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setListener'.",&tolua_err);
#endif
    return 0;
}

int extern_PluginFlurryAnalytics(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginFlurryAnalytics");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "logEvent", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_logEvent);
        tolua_function(L,"addOrigin", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_addOrigin);
        tolua_function(L,"endTimedEvent", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_endTimedEvent);
        tolua_function(L,"setListener", lua_PluginFlurryAnalyticsLua_PluginFlurryAnalytics_setListener);
    }
    lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_PluginFlurryAnalyticsLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginFlurryAnalytics(L);

	tolua_endmodule(L);
	return 1;
}


