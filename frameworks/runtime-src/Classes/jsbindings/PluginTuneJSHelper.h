
#ifndef __PLUGIN_TUNE_JS_Helper_H__
#define __PLUGIN_TUNE_JS_Helper_H__

#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
void register_PluginTuneJs_helper(JSContext* cx, JS::HandleObject global);
#else
void register_PluginTuneJs_helper(JSContext* cx, JSObject* global);
#endif

#endif // __PLUGIN_TUNE_JS_MANUAL_H__


