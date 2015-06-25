
#ifndef __PLUGIN_VUNGLE_LUA_HELPER_H__
#define __PLUGIN_VUNGLE_LUA_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int register_PluginVungelLua_helper(lua_State* L);

#endif
