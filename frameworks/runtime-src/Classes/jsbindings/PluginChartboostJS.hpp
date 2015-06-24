#ifndef __PluginChartboostJS_h__
#define __PluginChartboostJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginChartboost_class;
extern JSObject *jsb_sdkbox_PluginChartboost_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JS::HandleObject global);
void register_all_PluginChartboostJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JSObject* global);
void register_all_PluginChartboostJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginChartboostJS_PluginChartboost_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginChartboostJS_PluginChartboost_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_handleOpenURL(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_handleOpenURL(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_isAnyViewVisible(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_isAnyViewVisible(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_getCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_getCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_show(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_show(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_cache(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_cache(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_didPassAgeGate(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_didPassAgeGate(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_getAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_getAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_closeImpression(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_closeImpression(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_isAvailable(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_isAvailable(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

