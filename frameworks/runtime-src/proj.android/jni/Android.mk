LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

LOCAL_SRC_FILES := hellojavascript/main.cpp

LOCAL_SRC_FILES += \
../../Classes/AppDelegate.cpp \
../../Classes/HelloWorldScene.cpp \
../../Classes/MyPluginsMgr.cpp \
../../Classes/ide-support/SimpleConfigParser.cpp

LOCAL_SRC_FILES += \
../../Classes/luabindings/PluginAdColonyLua.cpp \
../../Classes/luabindings/PluginAdcolonyLuaHelper.cpp \
../../Classes/luabindings/PluginChartboostLua.cpp \
../../Classes/luabindings/PluginChartboostLuaHelper.cpp \
../../Classes/luabindings/PluginFlurryAnalyticsLua.cpp \
../../Classes/luabindings/PluginFlurryAnalyticsLuaHelper.cpp \
../../Classes/luabindings/PluginGoogleAnalyticsLua.cpp \
../../Classes/luabindings/PluginIAPLua.cpp \
../../Classes/luabindings/PluginIAPLuaHelper.cpp \
../../Classes/luabindings/PluginKochavaLua.cpp \
../../Classes/luabindings/PluginTuneLua.cpp \
../../Classes/luabindings/PluginTuneLuaHelper.cpp \
../../Classes/luabindings/PluginVungleLua.cpp \
../../Classes/luabindings/PluginVungleLuaHelper.cpp \
../../Classes/luabindings/SDKBoxLuaHelper.cpp 

LOCAL_SRC_FILES += \
../../Classes/jsbindings/PluginAdColonyJS.cpp \
../../Classes/jsbindings/PluginAdColonyJSHelper.cpp \
../../Classes/jsbindings/PluginChartboostJS.cpp \
../../Classes/jsbindings/PluginChartboostJSHelper.cpp \
../../Classes/jsbindings/PluginFlurryAnalyticsJS.cpp \
../../Classes/jsbindings/PluginFlurryAnalyticsJSHelper.cpp \
../../Classes/jsbindings/PluginGoogleAnalyticsJS.cpp \
../../Classes/jsbindings/PluginIAPJS.cpp \
../../Classes/jsbindings/PluginIAPJSHelper.cpp \
../../Classes/jsbindings/PluginKochavaJS.cpp \
../../Classes/jsbindings/PluginTuneJS.cpp \
../../Classes/jsbindings/PluginTuneJSHelper.cpp \
../../Classes/jsbindings/PluginVungleJS.cpp \
../../Classes/jsbindings/PluginVungleJSHelper.cpp \
../../Classes/jsbindings/SDKBoxJSHelper.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes


LOCAL_STATIC_LIBRARIES := cocos2d_js_static
LOCAL_STATIC_LIBRARIES += cocos2d_lua_static
LOCAL_STATIC_LIBRARIES += sdkbox PluginAdColony PluginChartboost PluginFlurryAnalytics \
                          PluginGoogleAnalytics PluginIAP PluginKochava PluginTune PluginVungle


include $(BUILD_SHARED_LIBRARY)


$(call import-add-path,$(LOCAL_PATH))
$(call import-module, ./sdkbox)
$(call import-module, ./pluginadcolony)
$(call import-module, ./pluginchartboost)
$(call import-module, ./pluginflurryanalytics)
$(call import-module, ./plugingoogleanalytics)
$(call import-module, ./pluginiap)
$(call import-module, ./pluginkochava)
$(call import-module, ./plugintune)
$(call import-module, ./pluginvungle)

$(call import-module,scripting/lua-bindings/proj.android/prebuilt-mk)
$(call import-module,scripting/js-bindings/proj.android/prebuilt-mk)
