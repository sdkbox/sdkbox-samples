/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _PLUGIN_CHARTBOOST_H_
#define _PLUGIN_CHARTBOOST_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox {
/*! "Startup" - Initial startup of game. */
extern const char* CB_Location_Startup;
/*! "Home Screen" - Home screen the player first sees. */
extern const char* CB_Location_HomeScreen;
/*! "Main Menu" - Menu that provides game options. */
extern const char* CB_Location_MainMenu;
/*! "Game Screen" - Game screen where all the magic happens. */
extern const char* CB_Location_GameScreen;
/*! "Achievements" - Screen with list of achievements in the game. */
extern const char* CB_Location_Achievements;
/*! "Quests" - Quest, missions or goals screen describing things for a player to do. */
extern const char* CB_Location_Quests;
/*!  "Pause" - Pause screen. */
extern const char* CB_Location_Pause;
/*! "Level Start" - Start of the level. */
extern const char* CB_Location_LevelStart;
/*! "Level Complete" - Completion of the level */
extern const char* CB_Location_LevelComplete;
/*! "Turn Complete" - Finishing a turn in a game. */
extern const char* CB_Location_TurnComplete;
/*! "IAP Store" - The store where the player pays real money for currency or items. */
extern const char* CB_Location_IAPStore;
/*! "Item Store" - The store where a player buys virtual goods. */
extern const char* CB_Location_ItemStore;
/*! "Game Over" - The game over screen after a player is finished playing. */
extern const char* CB_Location_GameOver;
/*! "Leaderboard" - List of leaders in the game. */
extern const char* CB_Location_LeaderBoard;
/*! "Settings" - Screen where player can change settings such as sound. */
extern const char* CB_Location_Settings;
/*! "Quit" - Screen displayed right before the player exits a game. */
extern const char* CB_Location_Quit;
/*! "Default" - Supports legacy applications that only have one "Default" location */
extern const char* CB_Location_Default;

enum CB_StatusBarBehavior
{
    /*! Ignore status bar altogether; fullscreen ads will use the space of the status bar. */
    CB_StatusBarBehaviorIgnore,
    /*! Respect the status bar partially; fullscreen ads will use the space of the status bar but any user interactive buttons will not. */
    CB_StatusBarBehaviorRespectButtons,
    /*! Respect the status bar fully; fullscreen ads will not use the status bar space. */
    CB_StatusBarBehaviorRespect
};

enum CB_LoadError {
    /*! Unknown internal error. */
    CB_LoadErrorInternal = 0,
    /*! Network is currently unavailable. */
    CB_LoadErrorInternetUnavailable,
    /*! Too many requests are pending for that location.  */
    CB_LoadErrorTooManyConnections,
    /*! Interstitial loaded with wrong orientation. */
    CB_LoadErrorWrongOrientation,
    /*! Interstitial disabled, first session. */
    CB_LoadErrorFirstSessionInterstitialsDisabled,
    /*! Network request failed. */
    CB_LoadErrorNetworkFailure,
    /*!  No ad received. */
    CB_LoadErrorNoAdFound,
    /*! Session not started. */
    CB_LoadErrorSessionNotStarted,
    /*! User manually cancelled the impression. */
    CB_LoadErrorUserCancellation,
    /*! No location detected. */
    CB_LoadErrorNoLocationFound,
    /*! Video Prefetching is not finished */
    CB_LoadErrorPrefetchingIncomplete,

    CB_LoadErrorImpressionAlreadyVisible,
    CB_LoadErrorNoHostActivity,
    CB_LoadErrorVideoIDMissing,
    CB_LoadErrorErrorPlayingVideo,
    CB_LoadErrorInvalidResponse,
    CB_LoadErrorAssetsDownloadFailure,
    CB_LoadErrorErrorCreatingView,
    CB_LoadErrorErrorDisplayingView,
    CB_LoadErrorIncompatibleApiVersion
};

enum CB_ClickError
{
    /*! Invalid URI. */
    CB_ClickErrorUriInvalid = 0,
    /*! The device does not know how to open the protocol of the URI  */
    CB_ClickErrorUriUnrecognized,
    /*! User failed to pass the age gate. */
    CB_ClickErrorAgeGateFailure,
    /*! Unknown internal error */
    CB_ClickErrorInternal,
    /*! Android only no host activity */
    CB_ClickErrorNoHostActivity
};

class ChartboostListener
{
public:

    //Ad callbacks
    virtual void onChartboostCached(const std::string& name) = 0;
    virtual bool onChartboostShouldDisplay(const std::string& name) = 0;
    virtual void onChartboostDisplay(const std::string& name) = 0;
    virtual void onChartboostDismiss(const std::string& name) = 0;
    virtual void onChartboostClose(const std::string& name) = 0;
    virtual void onChartboostClick(const std::string& name) = 0;
    virtual void onChartboostReward(const std::string& name, int reward) = 0;
    virtual void onChartboostFailedToLoad(const std::string& name, CB_LoadError e) = 0;
    virtual void onChartboostFailToRecordClick(const std::string& name, CB_ClickError e) = 0;

    //Miscellaneous callbacks
    virtual void onChartboostConfirmation() = 0;
    virtual void onChartboostCompleteStore() = 0;
};
    
class PluginChartboost
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
    static void setListener(ChartboostListener* listener);
    static ChartboostListener* getListener();
    static void removeListener();

    static bool isAnyViewVisible();
    static bool isAvailable(const std::string& name);

    static void cache(const std::string& name);
    static void setAutoCacheAds(bool shouldCache);
    static bool getAutoCacheAds();
    static void closeImpression();
    static void setStatusBarBehavior(CB_StatusBarBehavior behavior);

    static void didPassAgeGate(bool pass);
    static void setShouldPauseClickForConfirmation(bool shouldPause);

    static bool handleOpenURL(const std::string& url, const std::string& sourceApp);
    static void setCustomID(const std::string& customID);
    static std::string getCustomID();
    static void setShouldRequestInterstitialsInFirstSession(bool shouldRequest);
    static void setShouldDisplayLoadingViewForMoreApps(bool shouldDisplay);
    static void setShouldPrefetchVideoContent(bool shouldPrefetch);

    #ifdef OBFUSCATED
    _8a7ca32cfe3a4f1e8da46a1be00e1903
    #endif
};

}

#endif