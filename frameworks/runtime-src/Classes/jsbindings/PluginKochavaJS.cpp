#include "PluginKochavaJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginKochava/PluginKochava.h"
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
JSClass  *jsb_sdkbox_PluginKochava_class;
JSObject *jsb_sdkbox_PluginKochava_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_sendDeepLink(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_PluginKochavaJS_PluginKochava_sendDeepLink : Error processing arguments");
        sdkbox::PluginKochava::sendDeepLink(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_sendDeepLink : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_sendDeepLink(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginKochava::sendDeepLink(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_spatialEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        const char* arg0;
        double arg1;
        double arg2;
        double arg3;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
        ok &= sdkbox::js_to_number(cx, args.get(2), &arg2);
        ok &= sdkbox::js_to_number(cx, args.get(3), &arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginKochavaJS_PluginKochava_spatialEvent : Error processing arguments");
        sdkbox::PluginKochava::spatialEvent(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_spatialEvent : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_spatialEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 4) {
        const char* arg0;
        double arg1;
        double arg2;
        double arg3;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= sdkbox::js_to_number(cx, argv[1], &arg1);
        ok &= sdkbox::js_to_number(cx, argv[2], &arg2);
        ok &= sdkbox::js_to_number(cx, argv[3], &arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginKochava::spatialEvent(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_setLimitAdTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginKochavaJS_PluginKochava_setLimitAdTracking : Error processing arguments");
        sdkbox::PluginKochava::setLimitAdTracking(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_setLimitAdTracking : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_setLimitAdTracking(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginKochava::setLimitAdTracking(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_enableLogging(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_PluginKochavaJS_PluginKochava_enableLogging : Error processing arguments");
        sdkbox::PluginKochava::enableLogging(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_enableLogging : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_enableLogging(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(argv[0]);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginKochava::enableLogging(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_trackEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, args.get(1), &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_PluginKochavaJS_PluginKochava_trackEvent : Error processing arguments");
        sdkbox::PluginKochava::trackEvent(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_trackEvent : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_trackEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        const char* arg0;
        const char* arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, argv[0], &arg0_tmp); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= jsval_to_std_string(cx, argv[1], &arg1_tmp); arg1 = arg1_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginKochava::trackEvent(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_retrieveAttribution(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        const std::map<std::string, std::string>* ret = sdkbox::PluginKochava::retrieveAttribution();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char>, std::basic_string<char> > > >>(cx, (std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char>, std::basic_string<char> > > >*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_retrieveAttribution : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_retrieveAttribution(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        const std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, std::basic_string<char> > > >* ret = sdkbox::PluginKochava::retrieveAttribution();
        jsval jsret;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char>, std::basic_string<char> > > >>(cx, (std::map<std::basic_string<char>, std::basic_string<char>, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char>, std::basic_string<char> > > >*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginKochava::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginKochava::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginKochavaJS_PluginKochava_shutdown(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginKochava::shutdown();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginKochavaJS_PluginKochava_shutdown : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginKochavaJS_PluginKochava_shutdown(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginKochava::shutdown();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginKochavaJS_PluginKochava_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginKochava)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginKochava *nobj = static_cast<sdkbox::PluginKochava *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginKochavaJS_PluginKochava(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginKochava_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginKochava_class->name = "PluginKochava";
    jsb_sdkbox_PluginKochava_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginKochava_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginKochava_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginKochava_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginKochava_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginKochava_class->finalize = js_PluginKochavaJS_PluginKochava_finalize;
    jsb_sdkbox_PluginKochava_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("sendDeepLink", js_PluginKochavaJS_PluginKochava_sendDeepLink, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("spatialEvent", js_PluginKochavaJS_PluginKochava_spatialEvent, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLimitAdTracking", js_PluginKochavaJS_PluginKochava_setLimitAdTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableLogging", js_PluginKochavaJS_PluginKochava_enableLogging, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("trackEvent", js_PluginKochavaJS_PluginKochava_trackEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("retrieveAttribution", js_PluginKochavaJS_PluginKochava_retrieveAttribution, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginKochavaJS_PluginKochava_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("shutdown", js_PluginKochavaJS_PluginKochava_shutdown, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginKochava_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginKochava_class,
        dummy_constructor<sdkbox::PluginKochava>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginKochava", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginKochava> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginKochava_class;
        p->proto = jsb_sdkbox_PluginKochava_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginKochavaJS_PluginKochava(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginKochava_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginKochava_class->name = "PluginKochava";
    jsb_sdkbox_PluginKochava_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginKochava_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginKochava_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginKochava_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginKochava_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginKochava_class->finalize = js_PluginKochavaJS_PluginKochava_finalize;
    jsb_sdkbox_PluginKochava_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("sendDeepLink", js_PluginKochavaJS_PluginKochava_sendDeepLink, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("spatialEvent", js_PluginKochavaJS_PluginKochava_spatialEvent, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLimitAdTracking", js_PluginKochavaJS_PluginKochava_setLimitAdTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableLogging", js_PluginKochavaJS_PluginKochava_enableLogging, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("trackEvent", js_PluginKochavaJS_PluginKochava_trackEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("retrieveAttribution", js_PluginKochavaJS_PluginKochava_retrieveAttribution, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginKochavaJS_PluginKochava_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("shutdown", js_PluginKochavaJS_PluginKochava_shutdown, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginKochava_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginKochava_class,
        dummy_constructor<sdkbox::PluginKochava>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginKochava", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginKochava> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginKochava_class;
        p->proto = jsb_sdkbox_PluginKochava_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginKochavaJS_PluginKochava(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginKochava_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginKochava_class->name = "PluginKochava";
    jsb_sdkbox_PluginKochava_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginKochava_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginKochava_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginKochava_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginKochava_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginKochava_class->finalize = js_PluginKochavaJS_PluginKochava_finalize;
    jsb_sdkbox_PluginKochava_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("sendDeepLink", js_PluginKochavaJS_PluginKochava_sendDeepLink, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("spatialEvent", js_PluginKochavaJS_PluginKochava_spatialEvent, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLimitAdTracking", js_PluginKochavaJS_PluginKochava_setLimitAdTracking, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("enableLogging", js_PluginKochavaJS_PluginKochava_enableLogging, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("trackEvent", js_PluginKochavaJS_PluginKochava_trackEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("retrieveAttribution", js_PluginKochavaJS_PluginKochava_retrieveAttribution, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginKochavaJS_PluginKochava_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("shutdown", js_PluginKochavaJS_PluginKochava_shutdown, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginKochava_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginKochava_class,
        dummy_constructor<sdkbox::PluginKochava>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginKochava", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginKochava> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginKochava_class;
        p->proto = jsb_sdkbox_PluginKochava_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginKochavaJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginKochavaJS_PluginKochava(cx, ns);

    sdkbox::Sdkbox::setProjectType("js");
}
#else
void register_all_PluginKochavaJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginKochavaJS_PluginKochava(cx, obj);

    sdkbox::Sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginKochavaJS(JSContext* cx, JSObject* obj) {
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

    js_register_PluginKochavaJS_PluginKochava(cx, obj);

    sdkbox::Sdkbox::setProjectType("js");
}
#endif