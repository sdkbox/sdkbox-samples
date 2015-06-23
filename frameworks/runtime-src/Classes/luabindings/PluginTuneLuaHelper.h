
#ifndef __PLUGIN_TUNE_LUA_HELPER_H__
#define __PLUGIN_TUNE_LUA_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int register_PluginTuneLua_helper(lua_State* L);

#endif //  __PLUGIN_TUNE_LUA_HELPER_H__


