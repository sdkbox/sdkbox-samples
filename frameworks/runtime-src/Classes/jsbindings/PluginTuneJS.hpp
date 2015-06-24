#ifndef __PluginTuneJS_h__
#define __PluginTuneJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginTune_class;
extern JSObject *jsb_sdkbox_PluginTune_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginTuneJS_PluginTune(JSContext *cx, JS::HandleObject global);
void register_all_PluginTuneJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginTuneJS_PluginTune(JSContext *cx, JSObject* global);
void register_all_PluginTuneJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginTuneJS_PluginTune_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginTuneJS_PluginTune_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUserName(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUserName(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setGoogleUserId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setGoogleUserId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setFacebookEventLogging(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setFacebookEventLogging(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAppAdTracking(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAppAdTracking(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPackageName(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPackageName(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setTRUSTeId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setTRUSTeId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_automateIapEventMeasurement(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_automateIapEventMeasurement(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUseCookieTracking(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUseCookieTracking(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_openLogId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_openLogId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAllowDuplicateRequests(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAllowDuplicateRequests(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUserId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUserId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_applicationDidOpenURL(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_applicationDidOpenURL(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setExistingUser(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setExistingUser(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setCurrencyCode(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setCurrencyCode(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setJailbroken(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setJailbroken(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_startAppToAppTracking(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_startAppToAppTracking(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAge(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAge(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPhoneNumber(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPhoneNumber(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureEventForScript(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureEventForScript(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureEventName(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureEventName(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setRedirectUrl(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setRedirectUrl(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_isPayingUser(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_isPayingUser(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPreloadDataForScript(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPreloadDataForScript(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setFacebookUserId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setFacebookUserId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_matId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_matId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setTwitterUserId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setTwitterUserId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureEventId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureEventId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPayingUser(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPayingUser(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setSiteId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setSiteId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

