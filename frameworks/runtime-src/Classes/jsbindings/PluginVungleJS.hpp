#ifndef __PluginVungleJS_h__
#define __PluginVungleJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginVungle_class;
extern JSObject *jsb_sdkbox_PluginVungle_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginVungleJS_PluginVungle(JSContext *cx, JS::HandleObject global);
void register_all_PluginVungleJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginVungleJS_PluginVungle(JSContext *cx, JSObject* global);
void register_all_PluginVungleJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginVungleJS_PluginVungle_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginVungleJS_PluginVungle_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginVungleJS_PluginVungle_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginVungleJS_PluginVungle_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginVungleJS_PluginVungle_show(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginVungleJS_PluginVungle_show(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginVungleJS_PluginVungle_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginVungleJS_PluginVungle_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginVungleJS_PluginVungle_setDebug(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginVungleJS_PluginVungle_setDebug(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginVungleJS_PluginVungle_isCacheAvailable(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginVungleJS_PluginVungle_isCacheAvailable(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

