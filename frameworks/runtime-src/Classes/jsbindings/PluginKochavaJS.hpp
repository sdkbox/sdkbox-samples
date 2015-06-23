#ifndef __PluginKochavaJS_h__
#define __PluginKochavaJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginKochava_class;
extern JSObject *jsb_sdkbox_PluginKochava_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginKochavaJS_PluginKochava(JSContext *cx, JS::HandleObject global);
void register_all_PluginKochavaJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginKochavaJS_PluginKochava(JSContext *cx, JSObject* global);
void register_all_PluginKochavaJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginKochavaJS_PluginKochava_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginKochavaJS_PluginKochava_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_sendDeepLink(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_sendDeepLink(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_spatialEvent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_spatialEvent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_setLimitAdTracking(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_setLimitAdTracking(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_enableLogging(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_enableLogging(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_trackEvent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_trackEvent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_retrieveAttribution(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_retrieveAttribution(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_shutdown(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_shutdown(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

