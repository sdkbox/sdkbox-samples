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

        /*!
         * ad cache is available.
         */
        virtual void onVungleCacheAvailable() = 0;

        /*!
         * Vungle is running and available.
         */
        virtual void onVungleStarted() = 0;

        /*!
         * Vungle is not running/has stopped.
         */
        virtual void onVungleFinished() = 0;

        /*!
         * Vungle ad has been viewed.
         */
        virtual void onVungleAdViewed(bool isComplete) = 0;
    };

    class PluginVungle
    {
    public:

        /*!
         * initialize the plugin instance.
         */
        static void init();

        /*!
         * show ad with a provided name.
         */
        static void show(const std::string& name);

        /*!
         * set provided listener.
         */
        static void setListener(VungleListener* listener);

        /*!
         * get provided listener.
         */
        static VungleListener* getListener();

        /*!
         * remove listeners.
         */
        static void removeListener();

        /*!
         * enable or disable debug mode.
         */
        static void setDebug(bool enable);

        /*!
         * is there a cached video available.
         */
        static bool isCacheAvailable();

        /*!
         * sets the userID for rewarded ads.
         */
        static void setUserID(const std::string& userID);

        #ifdef OBFUSCATED
        _c29ab7ccac4548cbb408b2ccf9da96e0
        #endif
    };
}

#endif
