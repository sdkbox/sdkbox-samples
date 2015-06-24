#ifndef __PluginGoogleAnalyticsJS_h__
#define __PluginGoogleAnalyticsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginGoogleAnalytics_class;
extern JSObject *jsb_sdkbox_PluginGoogleAnalytics_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JS::HandleObject global);
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JSObject* global);
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_PluginGoogleAnalytics(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_PluginGoogleAnalytics(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

