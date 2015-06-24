
#ifndef __PLUGIN_FLURRY_ANALYTICS_JS_HELPER_H__
#define __PLUGIN_FLURRY_ANALYTICS_JS_HELPER_H__

#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
void register_PluginFlurryAnalyticsJs_helper(JSContext* cx, JS::HandleObject global);
#else
void register_PluginFlurryAnalyticsJs_helper(JSContext* cx, JSObject* global);
#endif

#endif


