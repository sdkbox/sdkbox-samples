#include "PluginAdColonyJSHelper.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginAdColony/PluginAdColony.h"
#include "SDKBoxJSHelper.h"

extern JSObject* jsb_sdkbox_PluginAdColony_prototype;

static JSContext* s_cx = nullptr;

JSObject* adinfo_to_obj(JSContext* cx, const sdkbox::AdColonyAdInfo& info)
{
#if MOZJS_MAJOR_VERSION >= 31
    JS::RootedObject jsobj(cx, JS_NewObject(cx, NULL, JS::NullPtr(), JS::NullPtr()));
    JS::RootedValue name(cx);
    name = std_string_to_jsval(cx, info.name);
    
    JS_SetProperty(cx, jsobj, "name", name);

    JS::RootedValue zoneID(cx);
    zoneID = std_string_to_jsval(cx, info.zoneID);
    
    JS_SetProperty(cx, jsobj, "zoneID", zoneID);
    
    JS::RootedValue shown(cx);
    shown = BOOLEAN_TO_JSVAL(info.shown);
    
    JS_SetProperty(cx, jsobj, "shown", shown);
    
    JS::RootedValue iapEnabled(cx);
    iapEnabled = BOOLEAN_TO_JSVAL(info.iapEnabled);
    
    JS_SetProperty(cx, jsobj, "iapEnabled", iapEnabled);
    
    JS::RootedValue iapProductID(cx);
    iapProductID = std_string_to_jsval(cx, info.iapProductID);
    
    JS_SetProperty(cx, jsobj, "iapProductID", iapProductID);
    
    JS::RootedValue iapQuantity(cx);
    iapQuantity = INT_TO_JSVAL(info.iapQuantity);
    
    JS_SetProperty(cx, jsobj, "iapQuantity", iapQuantity);

    JS::RootedValue iapEngagementType(cx);
    iapEngagementType = INT_TO_JSVAL(info.iapEngagementType);
    
    JS_SetProperty(cx, jsobj, "iapEngagementType", iapEngagementType);
#else
    JSObject* jsobj = JS_NewObject(cx, NULL, NULL, NULL);
    jsval name;
    name = std_string_to_jsval(cx, info.name);
    
    JS_SetProperty(cx, jsobj, "name", &name);
    
    jsval zoneID;
    zoneID = std_string_to_jsval(cx, info.zoneID);
    
    JS_SetProperty(cx, jsobj, "zoneID", &zoneID);
    
    jsval shown;
    shown = BOOLEAN_TO_JSVAL(info.shown);
    
    JS_SetProperty(cx, jsobj, "shown", &shown);
    
    jsval iapEnabled;
    iapEnabled = BOOLEAN_TO_JSVAL(info.iapEnabled);
    
    JS_SetProperty(cx, jsobj, "iapEnabled", &iapEnabled);
    
    jsval iapProductID;
    iapProductID = std_string_to_jsval(cx, info.iapProductID);
    
    JS_SetProperty(cx, jsobj, "iapProductID", &iapProductID);
    
    jsval iapQuantity;
    iapQuantity = INT_TO_JSVAL(info.iapQuantity);
    
    JS_SetProperty(cx, jsobj, "iapQuantity", &iapQuantity);
    
    jsval iapEngagementType;
    iapEngagementType = INT_TO_JSVAL(info.iapEngagementType);
    
    JS_SetProperty(cx, jsobj, "iapEngagementType", &iapEngagementType);
#endif
    
    return jsobj;
}

class AdColonyListenerWrapper : public sdkbox::AdColonyListener
{
private:
    JSObject* _JSDelegate;
public:
    void setJSDelegate(JSObject* delegate)
    {
        _JSDelegate = delegate;
    }
    
    JSObject* getJSDelegate()
    {
        return _JSDelegate;
    }
    
    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available)
    {
        if (!s_cx)
        {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyChange";
        
        JS::RootedObject obj(cx, _JSDelegate);
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
        jsval dataVal[2];

        jsval value = OBJECT_TO_JSVAL(adinfo_to_obj(s_cx, info));
        
        dataVal[0] = value;
        dataVal[1] = BOOLEAN_TO_JSVAL(available);
        
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
    
    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success)
    {
        if (!s_cx)
        {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyReward";
        
        JS::RootedObject obj(cx, _JSDelegate);
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
        jsval dataVal[4];
        jsval value = OBJECT_TO_JSVAL(adinfo_to_obj(s_cx, info));
        dataVal[0] = value;
        dataVal[1] = std_string_to_jsval(cx, currencyName);
        dataVal[2] = INT_TO_JSVAL(amount);
        dataVal[3] = BOOLEAN_TO_JSVAL(success);
        
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
    
    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info)
    {
        if (!s_cx)
        {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyStarted";
        
        JS::RootedObject obj(cx, _JSDelegate);
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
        jsval dataVal[1];

        jsval value = OBJECT_TO_JSVAL(adinfo_to_obj(s_cx, info));
        
        dataVal[0] = value;
        
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
    
    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info)
    {
        if (!s_cx)
        {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = "onAdColonyFinished";
        
        JS::RootedObject obj(cx, _JSDelegate);
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
        jsval dataVal[1];

        jsval value = OBJECT_TO_JSVAL(adinfo_to_obj(s_cx, info));
        
        dataVal[0] = value;
        
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
    
};

#if MOZJS_MAJOR_VERSION >= 31
bool js_PluginAdColonyJS_PluginAdColony_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginAdColonyJS_PluginAdColony_setListener(JSContext *cx, uint32_t argc, jsval *vp)
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
        
        JSB_PRECONDITION2(ok, cx, false, "js_PluginAdColonyJS_PluginAdColony_setIAPListener : Error processing arguments");
        AdColonyListenerWrapper* wrapper = new AdColonyListenerWrapper();
        wrapper->setJSDelegate(tmpObj);
        sdkbox::PluginAdColony::setListener(wrapper);
        
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginAdColonyJS_PluginAdColony_setIAPListener : wrong number of arguments");
    return false;
}


#if MOZJS_MAJOR_VERSION >= 31
void register_all_PluginAdColonyJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAdColony", &pluginObj);
    
    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAdColonyJS_PluginAdColony_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_all_PluginAdColonyJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginAdColony", &pluginObj);
    
    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginAdColonyJS_PluginAdColony_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif
