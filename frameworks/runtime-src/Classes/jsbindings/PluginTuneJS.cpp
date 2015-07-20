#include "PluginTuneJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginTune/PluginTune.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/sdkbox.h"


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
JSClass  *jsb_sdkbox_PluginTune_class;
JSObject *jsb_sdkbox_PluginTune_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUserName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setUserName : Error processing arguments");
        sdkbox::PluginTune::setUserName(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setUserName : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUserName(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setUserName(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setGoogleUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setGoogleUserId : Error processing arguments");
        sdkbox::PluginTune::setGoogleUserId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setGoogleUserId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setGoogleUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setGoogleUserId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setFacebookEventLogging(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        bool arg0;
        bool arg1;
        arg0 = JS::ToBoolean(args.get(0));
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setFacebookEventLogging : Error processing arguments");
        sdkbox::PluginTune::setFacebookEventLogging(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setFacebookEventLogging : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setFacebookEventLogging(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        bool arg0;
        bool arg1;
        arg0 = JS::ToBoolean(argv[0]);
        arg1 = JS::ToBoolean(argv[1]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setFacebookEventLogging(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginTune::measureSession();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_measureSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginTune::measureSession();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAppAdTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setAppAdTracking : Error processing arguments");
        sdkbox::PluginTune::setAppAdTracking(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setAppAdTracking : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAppAdTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setAppAdTracking(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier : Error processing arguments");
        sdkbox::PluginTune::setAppleAdvertisingIdentifier(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        arg1 = JS::ToBoolean(argv[1]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setAppleAdvertisingIdentifier(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPackageName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setPackageName : Error processing arguments");
        sdkbox::PluginTune::setPackageName(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setPackageName : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPackageName(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setPackageName(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setTRUSTeId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setTRUSTeId : Error processing arguments");
        sdkbox::PluginTune::setTRUSTeId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setTRUSTeId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setTRUSTeId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setTRUSTeId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_automateIapEventMeasurement(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_automateIapEventMeasurement : Error processing arguments");
        sdkbox::PluginTune::automateIapEventMeasurement(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_automateIapEventMeasurement : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_automateIapEventMeasurement(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::automateIapEventMeasurement(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUseCookieTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setUseCookieTracking : Error processing arguments");
        sdkbox::PluginTune::setUseCookieTracking(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setUseCookieTracking : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUseCookieTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setUseCookieTracking(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_openLogId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginTune::openLogId();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_openLogId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_openLogId(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginTune::openLogId();
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
bool js_PluginTuneJS_PluginTune_setAllowDuplicateRequests(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setAllowDuplicateRequests : Error processing arguments");
        sdkbox::PluginTune::setAllowDuplicateRequests(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setAllowDuplicateRequests : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAllowDuplicateRequests(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setAllowDuplicateRequests(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setUserId : Error processing arguments");
        sdkbox::PluginTune::setUserId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setUserId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setUserId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_applicationDidOpenURL(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_applicationDidOpenURL : Error processing arguments");
        sdkbox::PluginTune::applicationDidOpenURL(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_applicationDidOpenURL : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_applicationDidOpenURL(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::applicationDidOpenURL(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setExistingUser(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setExistingUser : Error processing arguments");
        sdkbox::PluginTune::setExistingUser(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setExistingUser : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setExistingUser(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setExistingUser(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken : Error processing arguments");
        sdkbox::PluginTune::setShouldAutoDetectJailbroken(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setShouldAutoDetectJailbroken(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginTune::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginTune::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setAppleVendorIdentifier : Error processing arguments");
        sdkbox::PluginTune::setAppleVendorIdentifier(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setAppleVendorIdentifier : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setAppleVendorIdentifier(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginTune::Gender arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setGender : Error processing arguments");
        sdkbox::PluginTune::setGender(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setGender : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setGender(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginTune::Gender arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setGender(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setCurrencyCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setCurrencyCode : Error processing arguments");
        sdkbox::PluginTune::setCurrencyCode(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setCurrencyCode : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setCurrencyCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setCurrencyCode(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setJailbroken(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setJailbroken : Error processing arguments");
        sdkbox::PluginTune::setJailbroken(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setJailbroken : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setJailbroken(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setJailbroken(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_startAppToAppTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        arg4 = JS::ToBoolean(args.get(4));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_startAppToAppTracking : Error processing arguments");
        sdkbox::PluginTune::startAppToAppTracking(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_startAppToAppTracking : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_startAppToAppTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        arg4 = JS::ToBoolean(argv[4]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::startAppToAppTracking(arg0, arg1, arg2, arg3, arg4);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setAge : Error processing arguments");
        sdkbox::PluginTune::setAge(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setAge : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setAge(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setAge(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPhoneNumber(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setPhoneNumber : Error processing arguments");
        sdkbox::PluginTune::setPhoneNumber(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setPhoneNumber : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPhoneNumber(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setPhoneNumber(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        double arg0;
        ok &= sdkbox::js_to_number(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout : Error processing arguments");
        sdkbox::PluginTune::checkForDeferredDeeplinkWithTimeout(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        double arg0;
        ok &= sdkbox::js_to_number(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::checkForDeferredDeeplinkWithTimeout(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureEventForScript(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_measureEventForScript : Error processing arguments");
        sdkbox::PluginTune::measureEventForScript(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_measureEventForScript : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureEventForScript(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::measureEventForScript(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureEventName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_measureEventName : Error processing arguments");
        sdkbox::PluginTune::measureEventName(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_measureEventName : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureEventName(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::measureEventName(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setRedirectUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setRedirectUrl : Error processing arguments");
        sdkbox::PluginTune::setRedirectUrl(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setRedirectUrl : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setRedirectUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setRedirectUrl(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier : Error processing arguments");
        sdkbox::PluginTune::setShouldAutoGenerateAppleVendorIdentifier(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setShouldAutoGenerateAppleVendorIdentifier(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_isPayingUser(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginTune::isPayingUser();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_isPayingUser : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_isPayingUser(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginTune::isPayingUser();
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
bool js_PluginTuneJS_PluginTune_setPreloadDataForScript(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setPreloadDataForScript : Error processing arguments");
        sdkbox::PluginTune::setPreloadDataForScript(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setPreloadDataForScript : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPreloadDataForScript(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setPreloadDataForScript(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setUserEmail : Error processing arguments");
        sdkbox::PluginTune::setUserEmail(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setUserEmail : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setUserEmail(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setUserEmail(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setFacebookUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setFacebookUserId : Error processing arguments");
        sdkbox::PluginTune::setFacebookUserId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setFacebookUserId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setFacebookUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setFacebookUserId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_matId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginTune::matId();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_matId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_matId(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginTune::matId();
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
bool js_PluginTuneJS_PluginTune_setTwitterUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setTwitterUserId : Error processing arguments");
        sdkbox::PluginTune::setTwitterUserId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setTwitterUserId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setTwitterUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setTwitterUserId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_measureEventId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_measureEventId : Error processing arguments");
        sdkbox::PluginTune::measureEventId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_measureEventId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_measureEventId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::measureEventId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setPayingUser(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setPayingUser : Error processing arguments");
        sdkbox::PluginTune::setPayingUser(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setPayingUser : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setPayingUser(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setPayingUser(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setSiteId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setSiteId : Error processing arguments");
        sdkbox::PluginTune::setSiteId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setSiteId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setSiteId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setSiteId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginTuneJS_PluginTune_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginTuneJS_PluginTune_setDebugMode : Error processing arguments");
        sdkbox::PluginTune::setDebugMode(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginTuneJS_PluginTune_setDebugMode : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginTuneJS_PluginTune_setDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginTune::setDebugMode(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginTuneJS_PluginTune_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginTune)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginTune *nobj = static_cast<sdkbox::PluginTune *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginTuneJS_PluginTune(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginTune_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginTune_class->name = "PluginTune";
    jsb_sdkbox_PluginTune_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginTune_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginTune_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginTune_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginTune_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginTune_class->finalize = js_PluginTuneJS_PluginTune_finalize;
    jsb_sdkbox_PluginTune_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setUserName", js_PluginTuneJS_PluginTune_setUserName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGoogleUserId", js_PluginTuneJS_PluginTune_setGoogleUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFacebookEventLogging", js_PluginTuneJS_PluginTune_setFacebookEventLogging, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureSession", js_PluginTuneJS_PluginTune_measureSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppAdTracking", js_PluginTuneJS_PluginTune_setAppAdTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppleAdvertisingIdentifier", js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPackageName", js_PluginTuneJS_PluginTune_setPackageName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTRUSTeId", js_PluginTuneJS_PluginTune_setTRUSTeId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("automateIapEventMeasurement", js_PluginTuneJS_PluginTune_automateIapEventMeasurement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUseCookieTracking", js_PluginTuneJS_PluginTune_setUseCookieTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openLogId", js_PluginTuneJS_PluginTune_openLogId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAllowDuplicateRequests", js_PluginTuneJS_PluginTune_setAllowDuplicateRequests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserId", js_PluginTuneJS_PluginTune_setUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("applicationDidOpenURL", js_PluginTuneJS_PluginTune_applicationDidOpenURL, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setExistingUser", js_PluginTuneJS_PluginTune_setExistingUser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldAutoDetectJailbroken", js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginTuneJS_PluginTune_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppleVendorIdentifier", js_PluginTuneJS_PluginTune_setAppleVendorIdentifier, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginTuneJS_PluginTune_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCurrencyCode", js_PluginTuneJS_PluginTune_setCurrencyCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setJailbroken", js_PluginTuneJS_PluginTune_setJailbroken, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startAppToAppTracking", js_PluginTuneJS_PluginTune_startAppToAppTracking, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginTuneJS_PluginTune_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPhoneNumber", js_PluginTuneJS_PluginTune_setPhoneNumber, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("checkForDeferredDeeplinkWithTimeout", js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventForScript", js_PluginTuneJS_PluginTune_measureEventForScript, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventName", js_PluginTuneJS_PluginTune_measureEventName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRedirectUrl", js_PluginTuneJS_PluginTune_setRedirectUrl, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldAutoGenerateAppleVendorIdentifier", js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isPayingUser", js_PluginTuneJS_PluginTune_isPayingUser, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPreloadDataForScript", js_PluginTuneJS_PluginTune_setPreloadDataForScript, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserEmail", js_PluginTuneJS_PluginTune_setUserEmail, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFacebookUserId", js_PluginTuneJS_PluginTune_setFacebookUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("matId", js_PluginTuneJS_PluginTune_matId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTwitterUserId", js_PluginTuneJS_PluginTune_setTwitterUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventId", js_PluginTuneJS_PluginTune_measureEventId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPayingUser", js_PluginTuneJS_PluginTune_setPayingUser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSiteId", js_PluginTuneJS_PluginTune_setSiteId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugMode", js_PluginTuneJS_PluginTune_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginTune_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginTune_class,
        dummy_constructor<sdkbox::PluginTune>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginTune", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginTune> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginTune_class;
        p->proto = jsb_sdkbox_PluginTune_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginTuneJS_PluginTune(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginTune_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginTune_class->name = "PluginTune";
    jsb_sdkbox_PluginTune_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginTune_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginTune_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginTune_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginTune_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginTune_class->finalize = js_PluginTuneJS_PluginTune_finalize;
    jsb_sdkbox_PluginTune_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setUserName", js_PluginTuneJS_PluginTune_setUserName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGoogleUserId", js_PluginTuneJS_PluginTune_setGoogleUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFacebookEventLogging", js_PluginTuneJS_PluginTune_setFacebookEventLogging, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureSession", js_PluginTuneJS_PluginTune_measureSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppAdTracking", js_PluginTuneJS_PluginTune_setAppAdTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppleAdvertisingIdentifier", js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPackageName", js_PluginTuneJS_PluginTune_setPackageName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTRUSTeId", js_PluginTuneJS_PluginTune_setTRUSTeId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("automateIapEventMeasurement", js_PluginTuneJS_PluginTune_automateIapEventMeasurement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUseCookieTracking", js_PluginTuneJS_PluginTune_setUseCookieTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openLogId", js_PluginTuneJS_PluginTune_openLogId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAllowDuplicateRequests", js_PluginTuneJS_PluginTune_setAllowDuplicateRequests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserId", js_PluginTuneJS_PluginTune_setUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("applicationDidOpenURL", js_PluginTuneJS_PluginTune_applicationDidOpenURL, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setExistingUser", js_PluginTuneJS_PluginTune_setExistingUser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldAutoDetectJailbroken", js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginTuneJS_PluginTune_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppleVendorIdentifier", js_PluginTuneJS_PluginTune_setAppleVendorIdentifier, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginTuneJS_PluginTune_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCurrencyCode", js_PluginTuneJS_PluginTune_setCurrencyCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setJailbroken", js_PluginTuneJS_PluginTune_setJailbroken, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startAppToAppTracking", js_PluginTuneJS_PluginTune_startAppToAppTracking, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginTuneJS_PluginTune_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPhoneNumber", js_PluginTuneJS_PluginTune_setPhoneNumber, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("checkForDeferredDeeplinkWithTimeout", js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventForScript", js_PluginTuneJS_PluginTune_measureEventForScript, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventName", js_PluginTuneJS_PluginTune_measureEventName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRedirectUrl", js_PluginTuneJS_PluginTune_setRedirectUrl, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldAutoGenerateAppleVendorIdentifier", js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isPayingUser", js_PluginTuneJS_PluginTune_isPayingUser, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPreloadDataForScript", js_PluginTuneJS_PluginTune_setPreloadDataForScript, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserEmail", js_PluginTuneJS_PluginTune_setUserEmail, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFacebookUserId", js_PluginTuneJS_PluginTune_setFacebookUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("matId", js_PluginTuneJS_PluginTune_matId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTwitterUserId", js_PluginTuneJS_PluginTune_setTwitterUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventId", js_PluginTuneJS_PluginTune_measureEventId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPayingUser", js_PluginTuneJS_PluginTune_setPayingUser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSiteId", js_PluginTuneJS_PluginTune_setSiteId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugMode", js_PluginTuneJS_PluginTune_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginTune_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginTune_class,
        dummy_constructor<sdkbox::PluginTune>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginTune", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginTune> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginTune_class;
        p->proto = jsb_sdkbox_PluginTune_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginTuneJS_PluginTune(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginTune_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginTune_class->name = "PluginTune";
    jsb_sdkbox_PluginTune_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginTune_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginTune_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginTune_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginTune_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginTune_class->finalize = js_PluginTuneJS_PluginTune_finalize;
    jsb_sdkbox_PluginTune_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setUserName", js_PluginTuneJS_PluginTune_setUserName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGoogleUserId", js_PluginTuneJS_PluginTune_setGoogleUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFacebookEventLogging", js_PluginTuneJS_PluginTune_setFacebookEventLogging, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureSession", js_PluginTuneJS_PluginTune_measureSession, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppAdTracking", js_PluginTuneJS_PluginTune_setAppAdTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppleAdvertisingIdentifier", js_PluginTuneJS_PluginTune_setAppleAdvertisingIdentifier, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPackageName", js_PluginTuneJS_PluginTune_setPackageName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTRUSTeId", js_PluginTuneJS_PluginTune_setTRUSTeId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("automateIapEventMeasurement", js_PluginTuneJS_PluginTune_automateIapEventMeasurement, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUseCookieTracking", js_PluginTuneJS_PluginTune_setUseCookieTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openLogId", js_PluginTuneJS_PluginTune_openLogId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAllowDuplicateRequests", js_PluginTuneJS_PluginTune_setAllowDuplicateRequests, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserId", js_PluginTuneJS_PluginTune_setUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("applicationDidOpenURL", js_PluginTuneJS_PluginTune_applicationDidOpenURL, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setExistingUser", js_PluginTuneJS_PluginTune_setExistingUser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldAutoDetectJailbroken", js_PluginTuneJS_PluginTune_setShouldAutoDetectJailbroken, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginTuneJS_PluginTune_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppleVendorIdentifier", js_PluginTuneJS_PluginTune_setAppleVendorIdentifier, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGender", js_PluginTuneJS_PluginTune_setGender, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCurrencyCode", js_PluginTuneJS_PluginTune_setCurrencyCode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setJailbroken", js_PluginTuneJS_PluginTune_setJailbroken, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("startAppToAppTracking", js_PluginTuneJS_PluginTune_startAppToAppTracking, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAge", js_PluginTuneJS_PluginTune_setAge, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPhoneNumber", js_PluginTuneJS_PluginTune_setPhoneNumber, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("checkForDeferredDeeplinkWithTimeout", js_PluginTuneJS_PluginTune_checkForDeferredDeeplinkWithTimeout, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventForScript", js_PluginTuneJS_PluginTune_measureEventForScript, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventName", js_PluginTuneJS_PluginTune_measureEventName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRedirectUrl", js_PluginTuneJS_PluginTune_setRedirectUrl, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldAutoGenerateAppleVendorIdentifier", js_PluginTuneJS_PluginTune_setShouldAutoGenerateAppleVendorIdentifier, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isPayingUser", js_PluginTuneJS_PluginTune_isPayingUser, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPreloadDataForScript", js_PluginTuneJS_PluginTune_setPreloadDataForScript, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserEmail", js_PluginTuneJS_PluginTune_setUserEmail, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setFacebookUserId", js_PluginTuneJS_PluginTune_setFacebookUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("matId", js_PluginTuneJS_PluginTune_matId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTwitterUserId", js_PluginTuneJS_PluginTune_setTwitterUserId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("measureEventId", js_PluginTuneJS_PluginTune_measureEventId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPayingUser", js_PluginTuneJS_PluginTune_setPayingUser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setSiteId", js_PluginTuneJS_PluginTune_setSiteId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDebugMode", js_PluginTuneJS_PluginTune_setDebugMode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginTune_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginTune_class,
        dummy_constructor<sdkbox::PluginTune>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginTune", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginTune> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginTune_class;
        p->proto = jsb_sdkbox_PluginTune_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginTuneJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginTuneJS_PluginTune(cx, ns);

    sdkbox::Sdkbox::setProjectType("js");
}
#else
void register_all_PluginTuneJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginTuneJS_PluginTune(cx, obj);

    sdkbox::Sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginTuneJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginTuneJS_PluginTune(cx, obj);

    sdkbox::Sdkbox::setProjectType("js");
}
#endif