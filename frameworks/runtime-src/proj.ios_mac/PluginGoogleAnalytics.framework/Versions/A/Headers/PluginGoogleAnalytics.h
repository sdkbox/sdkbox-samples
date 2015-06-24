/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/
#ifndef _PLUGIN_GA_
#define _PLUGIN_GA_

#include <string>
#include <vector>

using namespace std;

namespace sdkbox 
{

    class PluginGoogleAnalytics 
    {
    public:

        PluginGoogleAnalytics();
        ~PluginGoogleAnalytics();

        static void init();

        static void startSession();
        static void stopSession();

        static void dispatchHits();
        static void dispatchPeriodically( int seconds );
        static void stopPeriodicalDispatch();
        static void logScreen(string title);
        static void logEvent(string eventCategory, string eventAction, string eventLabel, int value);
        static void logException(string exceptionDescription, bool isFatal);
        static void logTiming(string timingCategory, int timingInterval, string timingName, string timingLabel);
        static void logSocial(string socialNetwork, string socialAction, string socialTarget);
        static void setDryRun( bool dr );
        static void enableAdvertisingTracking( bool e );
        static void createTracker( string trackerId );
        static void enableTracker( string trackerId );

        #ifdef OBFUSCATED
        _f2c23a1f452545d1b214e79dbf1beba5
        #endif
    };

}

#endif