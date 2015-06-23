
#ifndef __PLUGIN_CHARTBOOST_JS_HELPER_H__
#define __PLUGIN_CHARTBOOST_JS_HELPER_H__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 31
void register_PluginChartboostJs_helper(JSContext* cx, JS::HandleObject global);
#else
void register_PluginChartboostJs_helper(JSContext* cx, JSObject* global);
#endif


#endif
