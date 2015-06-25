
#ifndef __PLUGIN_FLURRY_ANALYTICS_LUA_HELPER_H__
#define __PLUGIN_FLURRY_ANALYTICS_LUA_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int register_PluginFlurryAnalyticsLua_helper(lua_State* L);

#endif


