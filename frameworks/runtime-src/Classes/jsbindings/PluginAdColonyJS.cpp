#include "PluginAdColonyJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginAdColony/PluginAdColony.h"
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
JSClass  *jsb_sdkbox_PluginAdColony_class;
JSObject *jsb_sdkbox_PluginAdColony_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getVideosPerReward(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_getVideosPerReward : Error processing arguments");
        int ret = sdkbox::PluginAdColony::getVideosPerReward(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getVideosPerReward : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getVideosPerReward(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        int ret = sdkbox::PluginAdColony::getVideosPerReward(arg0);
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getCustomID();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getCustomID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getCustomID();
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
bool js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone : Error processing arguments");
        int ret = sdkbox::PluginAdColony::zoneStatusForZone(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        int ret = sdkbox::PluginAdColony::zoneStatusForZone(arg0);
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_show(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_show : Error processing arguments");
        sdkbox::PluginAdColony::show(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_show : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_show(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAdColony::show(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_getStatus : Error processing arguments");
        int ret = (int)sdkbox::PluginAdColony::getStatus(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getStatus : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getStatus(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::AdColonyAdStatus ret = sdkbox::PluginAdColony::getStatus(arg0);
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginAdColony::videoAdCurrentlyRunning();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginAdColony::videoAdCurrentlyRunning();
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
bool js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAdColony::turnAllAdsOff();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAdColony::turnAllAdsOff();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getVendorIdentifier();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getVendorIdentifier();
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
bool js_PluginAdColonyJS_PluginAdColony_setUserMetadata(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_setUserMetadata : Error processing arguments");
        sdkbox::PluginAdColony::setUserMetadata(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_setUserMetadata : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_setUserMetadata(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAdColony::setUserMetadata(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAdColony::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAdColony::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getUniqueDeviceID();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getUniqueDeviceID();
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
bool js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getAdvertisingIdentifier();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginAdColony::getAdvertisingIdentifier();
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
bool js_PluginAdColonyJS_PluginAdColony_userInterestedIn(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_userInterestedIn : Error processing arguments");
        sdkbox::PluginAdColony::userInterestedIn(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_userInterestedIn : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_userInterestedIn(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAdColony::userInterestedIn(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_setCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_setCustomID : Error processing arguments");
        sdkbox::PluginAdColony::setCustomID(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_setCustomID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_setCustomID(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAdColony::setCustomID(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        int arg2;
        double arg3;
        std::string arg4;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= sdkbox::js_to_number(cx, args.get(3), &arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete : Error processing arguments");
        sdkbox::PluginAdColony::notifyIAPComplete(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        int arg2;
        double arg3;
        std::string arg4;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_int32(cx, argv[2], (int32_t *)&arg2);
        ok &= sdkbox::js_to_number(cx, argv[3], &arg3);
        ok &= jsval_to_std_string(cx, argv[4], &arg4);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginAdColony::notifyIAPComplete(arg0, arg1, arg2, arg3, arg4);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance : Error processing arguments");
        int ret = sdkbox::PluginAdColony::getVideoCreditBalance(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        int ret = sdkbox::PluginAdColony::getVideoCreditBalance(arg0);
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAdColonyJS_PluginAdColony_cancelAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginAdColony::cancelAd();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_cancelAd : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginAdColonyJS_PluginAdColony_cancelAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginAdColony::cancelAd();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginAdColonyJS_PluginAdColony_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginAdColony)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginAdColony *nobj = static_cast<sdkbox::PluginAdColony *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginAdColony_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAdColony_class->name = "PluginAdColony";
    jsb_sdkbox_PluginAdColony_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginAdColony_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAdColony_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAdColony_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAdColony_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAdColony_class->finalize = js_PluginAdColonyJS_PluginAdColony_finalize;
    jsb_sdkbox_PluginAdColony_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getVideosPerReward", js_PluginAdColonyJS_PluginAdColony_getVideosPerReward, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCustomID", js_PluginAdColonyJS_PluginAdColony_getCustomID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("zoneStatusForZone", js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("show", js_PluginAdColonyJS_PluginAdColony_show, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getStatus", js_PluginAdColonyJS_PluginAdColony_getStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("videoAdCurrentlyRunning", js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("turnAllAdsOff", js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVendorIdentifier", js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserMetadata", js_PluginAdColonyJS_PluginAdColony_setUserMetadata, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAdColonyJS_PluginAdColony_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUniqueDeviceID", js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAdvertisingIdentifier", js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("userInterestedIn", js_PluginAdColonyJS_PluginAdColony_userInterestedIn, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCustomID", js_PluginAdColonyJS_PluginAdColony_setCustomID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("notifyIAPComplete", js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVideoCreditBalance", js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cancelAd", js_PluginAdColonyJS_PluginAdColony_cancelAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAdColony_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginAdColony_class,
        dummy_constructor<sdkbox::PluginAdColony>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginAdColony", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAdColony> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginAdColony_class;
        p->proto = jsb_sdkbox_PluginAdColony_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginAdColony_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAdColony_class->name = "PluginAdColony";
    jsb_sdkbox_PluginAdColony_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginAdColony_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAdColony_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAdColony_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAdColony_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAdColony_class->finalize = js_PluginAdColonyJS_PluginAdColony_finalize;
    jsb_sdkbox_PluginAdColony_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getVideosPerReward", js_PluginAdColonyJS_PluginAdColony_getVideosPerReward, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCustomID", js_PluginAdColonyJS_PluginAdColony_getCustomID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("zoneStatusForZone", js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("show", js_PluginAdColonyJS_PluginAdColony_show, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getStatus", js_PluginAdColonyJS_PluginAdColony_getStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("videoAdCurrentlyRunning", js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("turnAllAdsOff", js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVendorIdentifier", js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserMetadata", js_PluginAdColonyJS_PluginAdColony_setUserMetadata, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAdColonyJS_PluginAdColony_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUniqueDeviceID", js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAdvertisingIdentifier", js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("userInterestedIn", js_PluginAdColonyJS_PluginAdColony_userInterestedIn, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCustomID", js_PluginAdColonyJS_PluginAdColony_setCustomID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("notifyIAPComplete", js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVideoCreditBalance", js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cancelAd", js_PluginAdColonyJS_PluginAdColony_cancelAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAdColony_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginAdColony_class,
        dummy_constructor<sdkbox::PluginAdColony>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginAdColony", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAdColony> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginAdColony_class;
        p->proto = jsb_sdkbox_PluginAdColony_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginAdColonyJS_PluginAdColony(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginAdColony_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginAdColony_class->name = "PluginAdColony";
    jsb_sdkbox_PluginAdColony_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginAdColony_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginAdColony_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginAdColony_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginAdColony_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginAdColony_class->finalize = js_PluginAdColonyJS_PluginAdColony_finalize;
    jsb_sdkbox_PluginAdColony_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getVideosPerReward", js_PluginAdColonyJS_PluginAdColony_getVideosPerReward, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCustomID", js_PluginAdColonyJS_PluginAdColony_getCustomID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("zoneStatusForZone", js_PluginAdColonyJS_PluginAdColony_zoneStatusForZone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("show", js_PluginAdColonyJS_PluginAdColony_show, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getStatus", js_PluginAdColonyJS_PluginAdColony_getStatus, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("videoAdCurrentlyRunning", js_PluginAdColonyJS_PluginAdColony_videoAdCurrentlyRunning, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("turnAllAdsOff", js_PluginAdColonyJS_PluginAdColony_turnAllAdsOff, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVendorIdentifier", js_PluginAdColonyJS_PluginAdColony_getVendorIdentifier, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserMetadata", js_PluginAdColonyJS_PluginAdColony_setUserMetadata, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginAdColonyJS_PluginAdColony_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUniqueDeviceID", js_PluginAdColonyJS_PluginAdColony_getUniqueDeviceID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAdvertisingIdentifier", js_PluginAdColonyJS_PluginAdColony_getAdvertisingIdentifier, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("userInterestedIn", js_PluginAdColonyJS_PluginAdColony_userInterestedIn, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCustomID", js_PluginAdColonyJS_PluginAdColony_setCustomID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("notifyIAPComplete", js_PluginAdColonyJS_PluginAdColony_notifyIAPComplete, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVideoCreditBalance", js_PluginAdColonyJS_PluginAdColony_getVideoCreditBalance, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cancelAd", js_PluginAdColonyJS_PluginAdColony_cancelAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginAdColony_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginAdColony_class,
        dummy_constructor<sdkbox::PluginAdColony>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginAdColony", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginAdColony> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginAdColony_class;
        p->proto = jsb_sdkbox_PluginAdColony_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAdColonyJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginAdColonyJS_PluginAdColony(cx, ns);
}
#else
void register_all_PluginAdColonyJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginAdColonyJS_PluginAdColony(cx, obj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAdColonyJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginAdColonyJS_PluginAdColony(cx, obj);
}
#endif