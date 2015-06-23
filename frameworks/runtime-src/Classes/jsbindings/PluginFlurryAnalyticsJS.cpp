#include "PluginFlurryAnalyticsJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"
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
JSClass  *jsb_sdkbox_PluginFlurryAnalytics_class;
JSObject *jsb_sdkbox_PluginFlurryAnalytics_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setReportLocation(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setReportLocation(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setUserID(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setUserID(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::endSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::endSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setBackgroundSessionEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setBackgroundSessionEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::startSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::startSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::clearLocation();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::clearLocation();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnPauseEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnPauseEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginFlurryAnalytics::getSessionID();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginFlurryAnalytics::getSessionID();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginFlurryAnalytics::activeSessionExists();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginFlurryAnalytics::activeSessionExists();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        ok &= sdkbox::js_to_number(cx, args.get(0), &arg0);
        ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
        ok &= sdkbox::js_to_number(cx, args.get(2), &arg2);
        ok &= sdkbox::js_to_number(cx, args.get(3), &arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setLatitude(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 4) {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        ok &= sdkbox::js_to_number(cx, argv[0], &arg0);
        ok &= sdkbox::js_to_number(cx, argv[1], &arg1);
        ok &= sdkbox::js_to_number(cx, argv[2], &arg2);
        ok &= sdkbox::js_to_number(cx, argv[3], &arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setLatitude(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp)
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
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::logError(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError(JSContext *cx, uint32_t argc, jsval *vp)
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
        sdkbox::PluginFlurryAnalytics::logError(arg0, arg1, arg2);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setDebugLogEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setDebugLogEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setEventLoggingEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setEventLoggingEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::FA_FlurryLogLevel arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setLogLevel(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::FA_FlurryLogLevel arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setLogLevel(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setCrashReportingEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setCrashReportingEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginFlurryAnalytics::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginFlurryAnalytics::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::pauseBackgroundSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::pauseBackgroundSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setGender(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setGender(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::logPageView();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFlurryAnalytics::logPageView();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setAppVersion(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setAppVersion(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setAge(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setAge(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setPulseEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setPulseEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginFlurryAnalytics::getFlurryAgentVersion();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginFlurryAnalytics::getFlurryAgentVersion();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnCloseEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnCloseEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setShowErrorInLogEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setShowErrorInLogEnabled(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        double arg0;
        ok &= sdkbox::js_to_number(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds : Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setSessionContinueSeconds(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        double arg0;
        ok &= sdkbox::js_to_number(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFlurryAnalytics::setSessionContinueSeconds(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginFlurryAnalytics)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginFlurryAnalytics *nobj = static_cast<sdkbox::PluginFlurryAnalytics *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginFlurryAnalytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginFlurryAnalytics_class->name = "PluginFlurryAnalytics";
    jsb_sdkbox_PluginFlurryAnalytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->finalize = js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_finalize;
    jsb_sdkbox_PluginFlurryAnalytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setReportLocation", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserID", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("endSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBackgroundSessionEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clearLocation", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionReportsOnPauseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSessionID", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("activeSessionExists", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLatitude", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logError", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugLogEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEventLoggingEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLogLevel", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCrashReportingEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("pauseBackgroundSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logPageView", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppVersion", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPulseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getFlurryAgentVersion", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionReportsOnCloseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShowErrorInLogEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionContinueSeconds", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginFlurryAnalytics_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginFlurryAnalytics_class,
        dummy_constructor<sdkbox::PluginFlurryAnalytics>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginFlurryAnalytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginFlurryAnalytics> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginFlurryAnalytics_class;
        p->proto = jsb_sdkbox_PluginFlurryAnalytics_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginFlurryAnalytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginFlurryAnalytics_class->name = "PluginFlurryAnalytics";
    jsb_sdkbox_PluginFlurryAnalytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->finalize = js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_finalize;
    jsb_sdkbox_PluginFlurryAnalytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setReportLocation", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserID", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("endSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBackgroundSessionEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clearLocation", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionReportsOnPauseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSessionID", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("activeSessionExists", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLatitude", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logError", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugLogEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEventLoggingEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLogLevel", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCrashReportingEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("pauseBackgroundSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logPageView", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppVersion", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPulseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getFlurryAgentVersion", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionReportsOnCloseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShowErrorInLogEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionContinueSeconds", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginFlurryAnalytics_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginFlurryAnalytics_class,
        dummy_constructor<sdkbox::PluginFlurryAnalytics>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginFlurryAnalytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginFlurryAnalytics> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginFlurryAnalytics_class;
        p->proto = jsb_sdkbox_PluginFlurryAnalytics_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginFlurryAnalytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginFlurryAnalytics_class->name = "PluginFlurryAnalytics";
    jsb_sdkbox_PluginFlurryAnalytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginFlurryAnalytics_class->finalize = js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_finalize;
    jsb_sdkbox_PluginFlurryAnalytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setReportLocation", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setReportLocation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserID", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setUserID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("endSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setBackgroundSessionEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setBackgroundSessionEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_startSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clearLocation", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_clearLocation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionReportsOnPauseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnPauseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSessionID", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getSessionID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("activeSessionExists", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_activeSessionExists, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLatitude", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLatitude, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logError", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logError, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugLogEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setDebugLogEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEventLoggingEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setEventLoggingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLogLevel", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setLogLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCrashReportingEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setCrashReportingEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("pauseBackgroundSession", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_pauseBackgroundSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logPageView", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logPageView, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppVersion", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAppVersion, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPulseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setPulseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getFlurryAgentVersion", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_getFlurryAgentVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionReportsOnCloseEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionReportsOnCloseEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShowErrorInLogEnabled", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setShowErrorInLogEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSessionContinueSeconds", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setSessionContinueSeconds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginFlurryAnalytics_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginFlurryAnalytics_class,
        dummy_constructor<sdkbox::PluginFlurryAnalytics>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginFlurryAnalytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginFlurryAnalytics> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginFlurryAnalytics_class;
        p->proto = jsb_sdkbox_PluginFlurryAnalytics_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(cx, ns);
}
#else
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(cx, obj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginFlurryAnalyticsJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginFlurryAnalyticsJS_PluginFlurryAnalytics(cx, obj);
}
#endif