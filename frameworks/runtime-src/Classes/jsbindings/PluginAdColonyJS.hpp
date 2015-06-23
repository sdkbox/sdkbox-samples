#ifndef __PluginAdColonyJS_h__
#define __PluginAdColonyJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginAdColony_class;
extern JSObject *jsb_sdkbox_PluginAdColony_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JS::HandleObject global);
void register_all_PluginAdColonyJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JSObject* global);
void register_all_PluginAdColonyJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginAdColonyJS_PluginAdColony_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginAdColonyJS_PluginAdColony_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getVideosPerReward(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getVideosPerReward(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_show(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_show(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getStatus(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getStatus(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_setUserMetadata(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_setUserMetadata(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_userInterestedIn(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_userInterestedIn(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_setCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_setCustomID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_cancelAd(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_cancelAd(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

