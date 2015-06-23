LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

LOCAL_SRC_FILES := hellojavascript/main.cpp

FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/ide-support/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/luabindings/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/jsbindings/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes


LOCAL_STATIC_LIBRARIES := cocos2d_js_static
LOCAL_STATIC_LIBRARIES += cocos2d_lua_static
LOCAL_STATIC_LIBRARIES += sdkbox PluginVungle PluginAdColony PluginChartboost PluginFlurryAnalytics \
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
