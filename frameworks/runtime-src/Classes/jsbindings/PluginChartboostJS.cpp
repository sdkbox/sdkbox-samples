#include "PluginChartboostJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginChartboost/PluginChartboost.h"
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
JSClass  *jsb_sdkbox_PluginChartboost_class;
JSObject *jsb_sdkbox_PluginChartboost_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_handleOpenURL(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_handleOpenURL : Error processing arguments");
        bool ret = sdkbox::PluginChartboost::handleOpenURL(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_handleOpenURL : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_handleOpenURL(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginChartboost::handleOpenURL(arg0, arg1);
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
bool js_PluginChartboostJS_PluginChartboost_setAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setAutoCacheAds : Error processing arguments");
        sdkbox::PluginChartboost::setAutoCacheAds(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setAutoCacheAds : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setAutoCacheAds(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::CB_StatusBarBehavior arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior : Error processing arguments");
        sdkbox::PluginChartboost::setStatusBarBehavior(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::CB_StatusBarBehavior arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setStatusBarBehavior(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_isAnyViewVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginChartboost::isAnyViewVisible();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_isAnyViewVisible : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_isAnyViewVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginChartboost::isAnyViewVisible();
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
bool js_PluginChartboostJS_PluginChartboost_getCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginChartboost::getCustomID();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_getCustomID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_getCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginChartboost::getCustomID();
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
bool js_PluginChartboostJS_PluginChartboost_show(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_show : Error processing arguments");
        sdkbox::PluginChartboost::show(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_show : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_show(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::show(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_cache(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_cache : Error processing arguments");
        sdkbox::PluginChartboost::cache(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_cache : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_cache(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::cache(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps : Error processing arguments");
        sdkbox::PluginChartboost::setShouldDisplayLoadingViewForMoreApps(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setShouldDisplayLoadingViewForMoreApps(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession : Error processing arguments");
        sdkbox::PluginChartboost::setShouldRequestInterstitialsInFirstSession(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setShouldRequestInterstitialsInFirstSession(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_didPassAgeGate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_didPassAgeGate : Error processing arguments");
        sdkbox::PluginChartboost::didPassAgeGate(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_didPassAgeGate : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_didPassAgeGate(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::didPassAgeGate(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent : Error processing arguments");
        sdkbox::PluginChartboost::setShouldPrefetchVideoContent(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setShouldPrefetchVideoContent(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginChartboost::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginChartboost::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_getAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginChartboost::getAutoCacheAds();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_getAutoCacheAds : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_getAutoCacheAds(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginChartboost::getAutoCacheAds();
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
bool js_PluginChartboostJS_PluginChartboost_closeImpression(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginChartboost::closeImpression();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_closeImpression : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_closeImpression(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginChartboost::closeImpression();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_setCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setCustomID : Error processing arguments");
        sdkbox::PluginChartboost::setCustomID(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setCustomID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setCustomID(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginChartboostJS_PluginChartboost_isAvailable(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_isAvailable : Error processing arguments");
        bool ret = sdkbox::PluginChartboost::isAvailable(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_isAvailable : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_isAvailable(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        bool ret = sdkbox::PluginChartboost::isAvailable(arg0);
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
bool js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation : Error processing arguments");
        sdkbox::PluginChartboost::setShouldPauseClickForConfirmation(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginChartboost::setShouldPauseClickForConfirmation(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginChartboostJS_PluginChartboost_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginChartboost)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginChartboost *nobj = static_cast<sdkbox::PluginChartboost *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginChartboost_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginChartboost_class->name = "PluginChartboost";
    jsb_sdkbox_PluginChartboost_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginChartboost_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginChartboost_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginChartboost_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginChartboost_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginChartboost_class->finalize = js_PluginChartboostJS_PluginChartboost_finalize;
    jsb_sdkbox_PluginChartboost_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("handleOpenURL", js_PluginChartboostJS_PluginChartboost_handleOpenURL, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAutoCacheAds", js_PluginChartboostJS_PluginChartboost_setAutoCacheAds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setStatusBarBehavior", js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAnyViewVisible", js_PluginChartboostJS_PluginChartboost_isAnyViewVisible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCustomID", js_PluginChartboostJS_PluginChartboost_getCustomID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("show", js_PluginChartboostJS_PluginChartboost_show, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cache", js_PluginChartboostJS_PluginChartboost_cache, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldDisplayLoadingViewForMoreApps", js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldRequestInterstitialsInFirstSession", js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("didPassAgeGate", js_PluginChartboostJS_PluginChartboost_didPassAgeGate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldPrefetchVideoContent", js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginChartboostJS_PluginChartboost_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAutoCacheAds", js_PluginChartboostJS_PluginChartboost_getAutoCacheAds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("closeImpression", js_PluginChartboostJS_PluginChartboost_closeImpression, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCustomID", js_PluginChartboostJS_PluginChartboost_setCustomID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAvailable", js_PluginChartboostJS_PluginChartboost_isAvailable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldPauseClickForConfirmation", js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginChartboost_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginChartboost_class,
        dummy_constructor<sdkbox::PluginChartboost>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginChartboost", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginChartboost> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginChartboost_class;
        p->proto = jsb_sdkbox_PluginChartboost_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginChartboost_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginChartboost_class->name = "PluginChartboost";
    jsb_sdkbox_PluginChartboost_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginChartboost_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginChartboost_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginChartboost_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginChartboost_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginChartboost_class->finalize = js_PluginChartboostJS_PluginChartboost_finalize;
    jsb_sdkbox_PluginChartboost_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("handleOpenURL", js_PluginChartboostJS_PluginChartboost_handleOpenURL, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAutoCacheAds", js_PluginChartboostJS_PluginChartboost_setAutoCacheAds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setStatusBarBehavior", js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAnyViewVisible", js_PluginChartboostJS_PluginChartboost_isAnyViewVisible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCustomID", js_PluginChartboostJS_PluginChartboost_getCustomID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("show", js_PluginChartboostJS_PluginChartboost_show, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cache", js_PluginChartboostJS_PluginChartboost_cache, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldDisplayLoadingViewForMoreApps", js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldRequestInterstitialsInFirstSession", js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("didPassAgeGate", js_PluginChartboostJS_PluginChartboost_didPassAgeGate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldPrefetchVideoContent", js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginChartboostJS_PluginChartboost_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAutoCacheAds", js_PluginChartboostJS_PluginChartboost_getAutoCacheAds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("closeImpression", js_PluginChartboostJS_PluginChartboost_closeImpression, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCustomID", js_PluginChartboostJS_PluginChartboost_setCustomID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAvailable", js_PluginChartboostJS_PluginChartboost_isAvailable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldPauseClickForConfirmation", js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginChartboost_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginChartboost_class,
        dummy_constructor<sdkbox::PluginChartboost>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginChartboost", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginChartboost> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginChartboost_class;
        p->proto = jsb_sdkbox_PluginChartboost_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginChartboostJS_PluginChartboost(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginChartboost_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginChartboost_class->name = "PluginChartboost";
    jsb_sdkbox_PluginChartboost_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginChartboost_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginChartboost_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginChartboost_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginChartboost_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginChartboost_class->finalize = js_PluginChartboostJS_PluginChartboost_finalize;
    jsb_sdkbox_PluginChartboost_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("handleOpenURL", js_PluginChartboostJS_PluginChartboost_handleOpenURL, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAutoCacheAds", js_PluginChartboostJS_PluginChartboost_setAutoCacheAds, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setStatusBarBehavior", js_PluginChartboostJS_PluginChartboost_setStatusBarBehavior, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAnyViewVisible", js_PluginChartboostJS_PluginChartboost_isAnyViewVisible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCustomID", js_PluginChartboostJS_PluginChartboost_getCustomID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("show", js_PluginChartboostJS_PluginChartboost_show, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cache", js_PluginChartboostJS_PluginChartboost_cache, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldDisplayLoadingViewForMoreApps", js_PluginChartboostJS_PluginChartboost_setShouldDisplayLoadingViewForMoreApps, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldRequestInterstitialsInFirstSession", js_PluginChartboostJS_PluginChartboost_setShouldRequestInterstitialsInFirstSession, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("didPassAgeGate", js_PluginChartboostJS_PluginChartboost_didPassAgeGate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldPrefetchVideoContent", js_PluginChartboostJS_PluginChartboost_setShouldPrefetchVideoContent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginChartboostJS_PluginChartboost_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAutoCacheAds", js_PluginChartboostJS_PluginChartboost_getAutoCacheAds, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("closeImpression", js_PluginChartboostJS_PluginChartboost_closeImpression, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCustomID", js_PluginChartboostJS_PluginChartboost_setCustomID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isAvailable", js_PluginChartboostJS_PluginChartboost_isAvailable, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setShouldPauseClickForConfirmation", js_PluginChartboostJS_PluginChartboost_setShouldPauseClickForConfirmation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginChartboost_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginChartboost_class,
        dummy_constructor<sdkbox::PluginChartboost>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginChartboost", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginChartboost> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginChartboost_class;
        p->proto = jsb_sdkbox_PluginChartboost_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginChartboostJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginChartboostJS_PluginChartboost(cx, ns);
}
#else
void register_all_PluginChartboostJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginChartboostJS_PluginChartboost(cx, obj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginChartboostJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginChartboostJS_PluginChartboost(cx, obj);
}
#endif