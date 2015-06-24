#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
typedef JS::HandleObject one_JSObject;
#else
typedef JSObject* one_JSObject;
#endif

namespace sdkbox
{
// Spidermonkey v186+
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    bool js_to_number(JSContext *cx, JS::HandleValue v, double *dp);
    void getJsObjOrCreat(JSContext* cx, JS::HandleObject jsObj, const char* name, JS::RootedObject* retObj);
#else
    JSBool js_to_number(JSContext *cx, jsval v, double *dp);
    jsval getJsObjOrCreat(JSContext* cx, JSObject* jsObj, const char* name, JSObject** retObj);
#endif
}
