
#include "PluginFlurryAnalyticsJSHelper.h"
#include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"
#include <sstream>
#include "js_manual_conversions.h"
#include "ScriptingCore.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginFlurryAnalytics_prototype;

static JSContext* s_cx = nullptr;

class FlurryAnalyticsListenerJs : public sdkbox::FlurryAnalyticsListener {
public:
    FlurryAnalyticsListenerJs(): mJsHandler(nullptr) {
    }
    ~FlurryAnalyticsListenerJs() {
    }

    void setHandler(JSObject* jsHandler) {
        if (mJsHandler == jsHandler) {
            return;
        }
        mJsHandler = jsHandler;
    }

    void flurrySessionDidCreateWithInfo(std::map<std::string, std::string>& info) {
        if (!s_cx)
        {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "flurrySessionDidCreateWithInfo";

        JS::RootedObject obj(cx, mJsHandler);
        JSAutoCompartment ac(cx, obj);
        
#if MOZJS_MAJOR_VERSION >= 31
        bool hasAction;
        JS::RootedValue retval(cx);
        JS::RootedValue func_handle(cx);
#else
        JSBool hasAction;
        jsval retval;
        jsval func_handle;
#endif
        std::string jsonStr = map2JsonString(info);

        jsval dataVal[1];
        dataVal[0] = std_string_to_jsval(cx, jsonStr);

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }
            
#if MOZJS_MAJOR_VERSION >= 31
            JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(sizeof(dataVal)/sizeof(*dataVal), dataVal), &retval);
#else
            JS_CallFunctionName(cx, obj, func_name, sizeof(dataVal)/sizeof(*dataVal), dataVal, &retval);
#endif
        }
    }

private:
    std::string map2JsonString(std::map<std::string, std::string>& map) {
        std::ostringstream strStream;
        bool bFirstItem = true;
        strStream << "{";
        for (std::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++) {
            if (!bFirstItem) {
                strStream << ",";
            }
            strStream << "\"";
            strStream << it->first;
            strStream << "\":\"";
            strStream << it->second;
            strStream << "\"";
            bFirstItem = false;
        }
        strStream << "}";
        
        return strStream.str();
    }

private:
    JSObject* mJsHandler;
};

#if MOZJS_MAJOR_VERSION >= 31
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    s_cx = cx;
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    if (argc == 1) {
        
        if (!args.get(0).isObject())
        {
            ok = false;
        }
        JSObject *tmpObj = args.get(0).toObjectOrNull();
        
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setListener : Error processing arguments");
        FlurryAnalyticsListenerJs* wrapper = new FlurryAnalyticsListenerJs();
        wrapper->setHandler(tmpObj);
        sdkbox::PluginFlurryAnalytics::setListener(wrapper);
        
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setListener : wrong number of arguments");
    return false;
}

#if MOZJS_MAJOR_VERSION >= 31
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0);
            jsval jsret = JSVAL_NULL;
            jsret = int32_to_jsval(cx, ret);
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 2) {
            if (args.get(1).isString()) {
                std::string arg0;
                ok &= jsval_to_std_string(cx, args.get(0), &arg0);
                if (!ok) { ok = true; break; }
                std::string arg1;
                ok &= jsval_to_std_string(cx, args.get(1), &arg1);
                if (!ok) { ok = true; break; }
                int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0, arg1);
                jsval jsret = JSVAL_NULL;
                jsret = int32_to_jsval(cx, ret);
                args.rval().set(jsret);
                return true;
            } else if (args.get(1).isBoolean()) {
                std::string arg0;
                ok &= jsval_to_std_string(cx, args.get(0), &arg0);
                if (!ok) { ok = true; break; }
                bool arg1;
                arg1 = JS::ToBoolean(args.get(1));
                if (!ok) { ok = true; break; }
                int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0, arg1);
                jsval jsret = JSVAL_NULL;
                jsret = int32_to_jsval(cx, ret);
                args.rval().set(jsret);
                return true;
            }
        }
    } while (0);
    
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            arg2 = JS::ToBoolean(args.get(2));
            if (!ok) { ok = true; break; }
            int ret = sdkbox::PluginFlurryAnalytics::logEvent(arg0, arg1, arg2);
            jsval jsret = JSVAL_NULL;
            jsret = int32_to_jsval(cx, ret);
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logEvent : wrong number of arguments");
    return false;
}

#if MOZJS_MAJOR_VERSION >= 31
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_addOrigin(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_addOrigin(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFlurryAnalytics::addOrigin(arg0, arg1);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 3) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            std::string arg2;
            ok &= jsval_to_std_string(cx, args.get(2), &arg2);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFlurryAnalytics::addOrigin(arg0, arg1, arg2);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_addOrigin : wrong number of arguments");
    return false;
}

#if MOZJS_MAJOR_VERSION >= 31
bool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endTimedEvent(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endTimedEvent(JSContext *cx, uint32_t argc, jsval *vp)
#endif
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    
    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFlurryAnalytics::endTimedEvent(arg0);
            return true;
        }
    } while (0);
    
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFlurryAnalytics::endTimedEvent(arg0, arg1);
            return true;
        }
    } while (0);
    JS_ReportError(cx, "js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endTimedEvent : wrong number of arguments");
    return false;
}

#if MOZJS_MAJOR_VERSION >= 31
void register_PluginFlurryAnalyticsJs_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginFlurryAnalytics", &pluginObj);
    
    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "logEvent", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logEvent, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "addOrigin", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_addOrigin, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "endTimedEvent", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endTimedEvent, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_PluginFlurryAnalyticsJs_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginFlurryAnalytics", &pluginObj);
    
    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "logEvent", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_logEvent, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "addOrigin", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_addOrigin, 1, JSPROP_READONLY | JSPROP_PERMANENT);
    JS_DefineFunction(cx, pluginObj, "endTimedEvent", js_PluginFlurryAnalyticsJS_PluginFlurryAnalytics_endTimedEvent, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif

