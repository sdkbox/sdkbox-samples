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

    bool jsval_to_std_map_string_string(JSContext *cx, JS::HandleValue v, std::map<std::string,std::string> *ret)
    {
        cocos2d::ValueMap value;
        bool ok = jsval_to_ccvaluemap(cx, v, &value);
        if (!ok)
        {
            return ok;
        }
        else
        {
            for (cocos2d::ValueMap::iterator it = value.begin(); it != value.end(); it++)
            {
                ret->insert(std::make_pair(it->first, it->second.asString()));
            }
        }

        return ok;
    }

#if MOZJS_MAJOR_VERSION < 33
    void get_or_create_js_obj(JSContext* cx, JS::HandleObject obj, const std::string &name, JS::MutableHandleObject jsObj)
    {
        JS::RootedValue nsval(cx);
        JS_GetProperty(cx, obj, name.c_str(), &nsval);
        if (nsval == JSVAL_VOID) {
            jsObj.set(JS_NewObject(cx, NULL, NULL, NULL));
            nsval = OBJECT_TO_JSVAL(jsObj);
            JS_SetProperty(cx, obj, name.c_str(), nsval);
        } else {
            jsObj.set(nsval.toObjectOrNull());
        }
    }
#endif

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

    bool jsval_to_std_map_string_string(JSContext *cx, JS::HandleValue v, std::map<std::string,std::string> *ret)
    {
        cocos2d::ValueMap value;
        bool ok = jsval_to_ccvaluemap(cx, v, &value);
        if (!ok)
        {
            return ok;
        }
        else
        {
            for (cocos2d::ValueMap::iterator it = value.begin(); it != value.end(); it++)
            {
                ret->insert(std::make_pair(it->first, it->second.asString()));
            }
        }

        return ok;
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

    JSBool jsval_to_std_map_string_string(JSContext *cx, jsval v, std::map<std::string,std::string> *ret)
    {
        cocos2d::CCDictionary* value;
        bool ok = jsval_to_ccdictionary(cx, v, &value);
        if (!ok)
        {
            return ok;
        }
        else
        {
            CCDictElement* pElement;
            CCDICT_FOREACH(value, pElement)
            {
                const char*key = pElement->getStrKey();
                CCString *v = (CCString*) pElement->getObject();
                ret->insert(std::make_pair(key, v->getCString()));
            }
        }

        return ok;
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
