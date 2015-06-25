#include "PluginGoogleAnalyticsJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"
#include "SDKBoxJSHelper.h"

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;    
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginGoogleAnalytics_class;
JSObject *jsb_sdkbox_PluginGoogleAnalytics_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        std::string arg0;
        int arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logTiming(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 4) {
        std::string arg0;
        int arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_int32(cx, argv[1], (int32_t *)&arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logTiming(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::stopPeriodicalDispatch();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::stopPeriodicalDispatch();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::setDryRun(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::setDryRun(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        int arg3;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logEvent(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        int arg3;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_int32(cx, argv[3], (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logEvent(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::dispatchPeriodically(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::dispatchPeriodically(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logScreen(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logScreen(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::startSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::startSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logException(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        arg1 = JS::ToBoolean(argv[1]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logException(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::stopSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::stopSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logSocial(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::logSocial(arg0, arg1, arg2);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableAdvertisingTracking(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableAdvertisingTracking(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::dispatchHits();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginGoogleAnalytics::dispatchHits();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableTracker(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::enableTracker(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker : Error processing arguments");
        sdkbox::PluginGoogleAnalytics::createTracker(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginGoogleAnalytics::createTracker(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
bool js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    sdkbox::PluginGoogleAnalytics* cobj = new (std::nothrow) sdkbox::PluginGoogleAnalytics();
    TypeTest<sdkbox::PluginGoogleAnalytics> t;
    js_type_class_t *typeClass = nullptr;
    std::string typeName = t.s_name();
    auto typeMapIter = _js_global_type_map.find(typeName);
    CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
    typeClass = typeMapIter->second;
    CCASSERT(typeClass, "The value is null.");
    // JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
    JS::RootedObject proto(cx, typeClass->proto.get());
    JS::RootedObject parent(cx, typeClass->parentProto.get());
    JS::RootedObject obj(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
    args.rval().set(OBJECT_TO_JSVAL(obj));
    // link the native object with the javascript object
    js_proxy_t* p = jsb_new_proxy(cobj, obj);
    if (JS_HasProperty(cx, obj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(obj), "_ctor", args);
    return true;
}



void js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginGoogleAnalytics)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginGoogleAnalytics *nobj = static_cast<sdkbox::PluginGoogleAnalytics *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginGoogleAnalytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginGoogleAnalytics_class->name = "PluginGoogleAnalytics";
    jsb_sdkbox_PluginGoogleAnalytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->finalize = js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_finalize;
    jsb_sdkbox_PluginGoogleAnalytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("logTiming", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stopPeriodicalDispatch", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDryRun", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispatchPeriodically", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logScreen", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logException", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stopSession", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logSocial", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableAdvertisingTracking", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispatchHits", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableTracker", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("createTracker", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginGoogleAnalytics_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginGoogleAnalytics_class,
        js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginGoogleAnalytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginGoogleAnalytics> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginGoogleAnalytics_class;
        p->proto = jsb_sdkbox_PluginGoogleAnalytics_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginGoogleAnalytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginGoogleAnalytics_class->name = "PluginGoogleAnalytics";
    jsb_sdkbox_PluginGoogleAnalytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->finalize = js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_finalize;
    jsb_sdkbox_PluginGoogleAnalytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("logTiming", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stopPeriodicalDispatch", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDryRun", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispatchPeriodically", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logScreen", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logException", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stopSession", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logSocial", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableAdvertisingTracking", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispatchHits", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableTracker", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("createTracker", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginGoogleAnalytics_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginGoogleAnalytics_class,
        js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginGoogleAnalytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginGoogleAnalytics> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginGoogleAnalytics_class;
        p->proto = jsb_sdkbox_PluginGoogleAnalytics_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginGoogleAnalytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginGoogleAnalytics_class->name = "PluginGoogleAnalytics";
    jsb_sdkbox_PluginGoogleAnalytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginGoogleAnalytics_class->finalize = js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_finalize;
    jsb_sdkbox_PluginGoogleAnalytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("logTiming", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logTiming, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stopPeriodicalDispatch", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopPeriodicalDispatch, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDryRun", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_setDryRun, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logEvent, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispatchPeriodically", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchPeriodically, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logScreen", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logScreen, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_startSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logException", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logException, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stopSession", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_stopSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logSocial", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_logSocial, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableAdvertisingTracking", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableAdvertisingTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispatchHits", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_dispatchHits, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableTracker", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_enableTracker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("createTracker", js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_createTracker, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginGoogleAnalytics_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginGoogleAnalytics_class,
        js_PluginGoogleAnalyticsJS_PluginGoogleAnalytics_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginGoogleAnalytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginGoogleAnalytics> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginGoogleAnalytics_class;
        p->proto = jsb_sdkbox_PluginGoogleAnalytics_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(cx, ns);
}
#else
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(cx, obj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginGoogleAnalyticsJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginGoogleAnalyticsJS_PluginGoogleAnalytics(cx, obj);
}
#endif