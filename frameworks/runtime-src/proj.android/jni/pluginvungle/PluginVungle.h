/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/
#ifndef _PLUGIN_VUNGLE_H_
#define _PLUGIN_VUNGLE_H_

#include <string>
#include <map>

namespace sdkbox 
{
    class VungleListener
    {
    public:
        virtual void onVungleCacheAvailable() = 0;
        virtual void onVungleStarted() = 0;
        virtual void onVungleFinished() = 0;
        virtual void onVungleAdViewed(bool isComplete) = 0;
    };

    class PluginVungle
    {
    public:
        
        /*! \brief init
         *  init the instance.
         *
         *
         */
        static void init();
        
        /** @name Playing Video Ads */
        static void show(const std::string& name);
        
        static void setListener(VungleListener* listener);
        static VungleListener* getListener();
        static void removeListener();
        
        static void setDebug(bool enable);
        static bool isCacheAvailable();
        static void setUserID(const std::string& userID);

        #ifdef OBFUSCATED
        _c29ab7ccac4548cbb408b2ccf9da96e0
        #endif
    };
}

#endif