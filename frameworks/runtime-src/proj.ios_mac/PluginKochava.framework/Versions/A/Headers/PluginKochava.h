/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/
#ifndef _PLUGIN_KOCHAVA_H_
#define _PLUGIN_KOCHAVA_H_

#include <map>
#include <string>

namespace sdkbox
{
    class PluginKochava
    {
    public:
        
        // @brief init the kochava service
        static void init();
        
        // @brief shutdown the kochava service
        static void shutdown();
        
        // @brief enable kochava api logging
        static void enableLogging(bool enabled);
        
        //
        // Kochava Tracking Service Methods
        //
        
        // @brief track a single event
        // http://support.kochava.com/support/solutions/articles/1000059874-ios-sdk-documentation#caleve
        static void trackEvent(const char* event, const char* value);
        
        // @brief link an id to the kochava id
        // http://support.kochava.com/support/solutions/articles/1000059874-ios-sdk-documentation#iden
        //static void identityLinkEvent(const std::map<std::string, std::string>* data);
        
        // @brief spatial event to help visualize data
        // http://support.kochava.com/support/solutions/articles/1000059874-ios-sdk-documentation#senspa
        static void spatialEvent(const char* title, float x, float y, float z);
        
        // @brief turn on/off ad tracking
        // http://support.kochava.com/support/solutions/articles/1000059874-ios-sdk-documentation#toglim
        static void setLimitAdTracking(bool limitAdTracking);
        
        // @brief returns the attribution data
        // http://support.kochava.com/support/solutions/articles/1000059874-ios-sdk-documentation#attr
        static const std::map<std::string, std::string>* retrieveAttribution();
        
        // @brief
        //
        static void sendDeepLink(const char* url, const char* application);
        
        // standard kochava callback to be notified of attribution and beacon crossings.        
        typedef void (*kochavaCallbackDict)(const std::map<std::string, std::string>*);
        typedef void (*kochavaCallbackString)(const char*);

        // @brief specify callback for attribution
        static void setAttributionCallback(kochavaCallbackDict callback);

        // @brief specify beacon transition callback
        static void setBeaconCallback(kochavaCallbackString callback);

        #ifdef OBFUSCATED
        _0f2cab5557d6b4eb9487f2531e50b644
        #endif
    };
}

#endif
