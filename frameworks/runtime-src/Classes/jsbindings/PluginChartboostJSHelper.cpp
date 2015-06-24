
#include "PluginChartboostJsHelper.h"
#include "cocos2d_specifics.hpp"
#include "PluginChartboost/PluginChartboost.h"
#include "SDKBoxJSHelper.h"

static JSContext* s_cx = nullptr;

class ChartboostListenerJsHelper : public sdkbox::ChartboostListener {

public:
    void setJSDelegate(JSObject* delegate)
    {
        mJsDelegate = delegate;
    }
    
    JSObject* getJSDelegate()
    {
        return mJsDelegate;
    }
    
    //Ad callbacks
    void onChartboostCached(const std::string& name) {
        invokeDelegate("onChartboostCached", name.c_str(), 0, 1);
    }
    bool onChartboostShouldDisplay(const std::string& name) {
        invokeDelegate("onChartboostShouldDisplay", name.c_str(), 0, 1);
        return true;
    }
    void onChartboostDisplay(const std::string& name) {
        invokeDelegate("onChartboostDisplay", name.c_str(), 0, 1);
    }
    void onChartboostDismiss(const std::string& name) {
        invokeDelegate("onChartboostDismiss", name.c_str(), 0, 1);
    }
    void onChartboostClose(const std::string& name) {
        invokeDelegate("onChartboostClose", name.c_str(), 0, 1);
    }
    void onChartboostClick(const std::string& name) {
        invokeDelegate("onChartboostClick", name.c_str(), 0, 1);
    }
    void onChartboostReward(const std::string& name, int reward) {
        invokeDelegate("onChartboostReward", name.c_str(), reward, 2);
    }
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e) {
        invokeDelegate("onChartboostFailedToLoad", name.c_str(), e, 2);
    }
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e) {
        invokeDelegate("onChartboostFailToRecordClick", name.c_str(), e, 2);
    }
    
    //Miscellaneous callbacks
    void onChartboostConfirmation() {
        invokeDelegate("onChartboostConfirmation", nullptr, 0, 0);
    }
    void onChartboostCompleteStore() {
        invokeDelegate("onChartboostCompleteStore", nullptr, 0, 0);
    }
    
private:
    void invokeDelegate(const char* fName, const char* name, int intVal, int argc) {
        if (!s_cx) {
            return;
        }
        JSContext* cx = s_cx;
        const char* func_name = fName;
        
        JS::RootedObject obj(cx, mJsDelegate);
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

        if (2 == argc) {
            dataVal[0] = c_string_to_jsval(cx, name);
            dataVal[1] = INT_TO_JSVAL(intVal);
        } else if (1 == argc) {
            dataVal[0] = c_string_to_jsval(cx, name);
        }

        if (JS_HasProperty(cx, obj, func_name, &hasAction) && hasAction) {
            if(!JS_GetProperty(cx, obj, func_name, &func_handle)) {
                return;
            }
            if(func_handle == JSVAL_VOID) {
                return;
            }
            
#if MOZJS_MAJOR_VERSION >= 31
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::empty(), &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, JS::HandleValueArray::fromMarkedLocation(argc, dataVal), &retval);
            }
#else
            if (0 == argc) {
                JS_CallFunctionName(cx, obj, func_name, 0, nullptr, &retval);
            } else {
                JS_CallFunctionName(cx, obj, func_name, argc, dataVal, &retval);
            }
#endif
        }
    }

private:
    JSObject* mJsDelegate;
    
};

#if MOZJS_MAJOR_VERSION >= 31
bool js_PluginChartboostJS_PluginChartboost_setListener(JSContext *cx, uint32_t argc, jsval *vp)
#else
JSBool js_PluginChartboostJS_PluginChartboost_setListener(JSContext *cx, unsigned argc, JS::Value *vp)
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
        
        JSB_PRECONDITION2(ok, cx, false, "js_PluginChartboostJS_PluginChartboost_setListener : Error processing arguments");
        ChartboostListenerJsHelper* lis = new ChartboostListenerJsHelper();
        lis->setJSDelegate(tmpObj);
        sdkbox::PluginChartboost::setListener(lis);

        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginChartboostJS_PluginChartboost_setListener : wrong number of arguments");
    return false;
}

#if MOZJS_MAJOR_VERSION >= 31
void register_PluginChartboostJs_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedObject pluginObj(cx);
    sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginChartboost", &pluginObj);
    
    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginChartboostJS_PluginChartboost_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#else
void register_PluginChartboostJs_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.PluginChartboost", &pluginObj);

    JS_DefineFunction(cx, pluginObj, "setListener", js_PluginChartboostJS_PluginChartboost_setListener, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}
#endif



