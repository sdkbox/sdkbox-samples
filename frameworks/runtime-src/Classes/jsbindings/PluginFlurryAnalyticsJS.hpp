#ifndef __PluginFlurryAnalyticsJS_h__
#define __PluginFlurryAnalyticsJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginFlurryAnalytics_class;
extern JSObject *jsb_sdkbox_PluginFlurryAnalytics_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JS::HandleObject global);
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JSObject* global);
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

