#include "SDKBoxJSHelper.h"
#include <string>
#include <sstream>
#include "cocos2d_specifics.hpp"
#include "Sdkbox/Sdkbox.h"

#if defined(MOZJS_MAJOR_VERSION)
#include "cocos2d_specifics.hpp"
#endif

namespace sdkbox
{

// Spidermonkey v186+
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 26
    bool js_to_number(JSContext *cx, JS::HandleValue v, double *dp)
    {
        return JS::ToNumber( cx, v, dp) && !isnan(*dp);
    }
    
    void getJsObjOrCreat(JSContext* cx, JS::HandleObject jsObj, const char* name, JS::RootedObject* retObj) {
        JS::RootedObject parent(cx);
        JS::RootedObject tempObj(cx);
        bool first = true;
        
        std::stringstream ss(name);
        std::string sub;
        const char* subChar;
        while(getline(ss, sub, '.')) {
            if(sub.empty())continue;
            
            subChar = sub.c_str();
            if (first) {
                get_or_create_js_obj(cx, jsObj, subChar, &tempObj);
                first = false;
            } else {
                parent = tempObj;
                get_or_create_js_obj(cx, parent, subChar, &tempObj);
            }
        }
        
        *retObj = tempObj;
    }
#else
    JSBool js_to_number(JSContext *cx, jsval v, double *dp)
    {
        return JS::ToNumber( cx, v, dp) && !isnan(*dp);
    }
    
    jsval getJsObjOrCreat(JSContext* cx, JSObject* jsObj, const char* name, JSObject** retObj) {
        JSObject* parent = NULL;
        JSObject* tempObj = jsObj;
        jsval tempVal;
        
        std::stringstream ss(name);
        std::string sub;
        const char* subChar;
        
        while(getline(ss, sub, '.')) {
            if(sub.empty())continue;
            
            subChar = sub.c_str();
            parent = tempObj;
            JS_GetProperty(cx, parent, subChar, &tempVal);
            if (tempVal == JSVAL_VOID) {
                tempObj = JS_NewObject(cx, NULL, NULL, NULL);
                tempVal = OBJECT_TO_JSVAL(tempObj);
                JS_SetProperty(cx, parent, subChar, &tempVal);
            } else {
                JS_ValueToObject(cx, tempVal, &tempObj);
            }
        }
        
        *retObj = tempObj;
        return tempVal;
    }
#endif

// Spidermonkey v186 and earlier
#else
    JSBool js_to_number(JSContext *cx, jsval v, double *dp)
    {
        return JS_ValueToNumber(cx, v, dp);
    }
    
    jsval getJsObjOrCreat(JSContext* cx, JSObject* jsObj, const char* name, JSObject** retObj) {
        JSObject* parent = NULL;
        JSObject* tempObj = jsObj;
        jsval tempVal;
        
        std::stringstream ss(name);
        std::string sub;
        const char* subChar;
        
        while(getline(ss, sub, '.')) {
            if(sub.empty())continue;
            
            subChar = sub.c_str();
            parent = tempObj;
            JS_GetProperty(cx, parent, subChar, &tempVal);
            if (tempVal == JSVAL_VOID) {
                tempObj = JS_NewObject(cx, NULL, NULL, NULL);
                tempVal = OBJECT_TO_JSVAL(tempObj);
                JS_SetProperty(cx, parent, subChar, &tempVal);
            } else {
                JS_ValueToObject(cx, tempVal, &tempObj);
            }
        }
        
        *retObj = tempObj;
        return tempVal;
    }
#endif

}
