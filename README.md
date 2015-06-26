# Welcome to sdkbox sampels

run `git submodule update --init` first
 
## how to run cpp

```
#define SDKBOX_STARTER_KIT_TYPE kSdkboxStarterKitTypeCpp
```
in `frameworks/runtime-src/Classes/SdkboxStarterKit.h`

- `cocos run -p ios` or `cocos run -p android`

## how to run js

```
#define SDKBOX_STARTER_KIT_TYPE kSdkboxStarterKitTypeJs
```
in `frameworks/runtime-src/Classes/SdkboxStarterKit.h`

- `cocos run -p ios` or `cocos run -p android`

## how to run lua

```
#define SDKBOX_STARTER_KIT_TYPE kSdkboxStarterKitTypeLua
```
in `frameworks/runtime-src/Classes/SdkboxStarterKit.h`

- `cocos run -p ios` or `cocos run -p android`

## where are the source code for cpp

- ui: `frameworks/runtime-src/Classes/HelloWorldScene.h` , `frameworks/runtime-src/Classes/HelloWorldScene.cpp`
- plugin event: `frameworks/runtime-src/Classes/MyPluginsMgr.h` , `frameworks/runtime-src/Classes/MyPluginsMgr.cpp`

## where are the source code for lua

- ui: `src/app/views/MainScene.lua`
- plugin event: `src/app/views/MyPluginMgr.lua`

## where are the source code for js

- ui: `src/app.js`
- plugin event: `src/mypluginsmgr.js`

-EOF-
