//
//  MyPluginsMgr.cpp
//  template
//
//
//

#include "MyPluginsMgr.h"
#include "cocos2d.h"

#include "PluginAdColony/PluginAdColony.h"

USING_NS_CC;
using namespace sdkbox;

/**********************************************************************************
 ******************************* AdColony *****************************************
 **********************************************************************************/

class ADListener : public sdkbox::AdColonyListener
{
public:
    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available)
    {
        if (available)
        {
            CCLOG("AdColony Zone: %s available", info.zoneID.c_str());
        }
        else
        {
            CCLOG("AdColony Zone: %s not available", info.zoneID.c_str());
        }
    }
    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success)
    {
        if(success)
        {
            CCLOG("AdColony reward zone: %s, reward: %d %s ", info.zoneID.c_str(), amount, currencyName.c_str());
        }
        else
        {
            CCLOG("AdColony reward failed.");
        }
    }
    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info)
    {
        CCLOG("Ad Started: %s", info.zoneID.c_str());
    }
    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info)
    {
        if (info.shown)
        {
            CCLOG("AdColony Ad shown");
        }
        else
        {
            CCLOG("AdColony Ad not shown");
        }
    }
};

void MyPluginsMgr::initAdColony()
{
    PluginAdColony::init();
    PluginAdColony::setListener(new ADListener);
    PluginAdColony::getStatus("video");
    PluginAdColony::setCustomID("test");
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventAdColony1, [](EventCustom *) { PluginAdColony::show("video"); });
    eventDispatcher->addCustomEventListener(kMenuEventAdColony2, [](EventCustom *) { PluginAdColony::show("v4vc"); });
}


/***
 * CharBoost
 */

#include "PluginChartboost/PluginChartboost.h"
class CBListener : public sdkbox::ChartboostListener
{
public:
    //Ad callbacks
    void onChartboostCached(const std::string& name)
    {
        CCLOG("Chartboost ad: %s cached", name.c_str());
    }
    bool onChartboostShouldDisplay(const std::string& name)
    {
        CCLOG("Chartboost ad: %s should display", name.c_str());
        return true;
    }
    void onChartboostDisplay(const std::string& name)
    {
        CCLOG("Chartboost ad: %s display", name.c_str());
    }
    void onChartboostDismiss(const std::string& name)
    {
        CCLOG("Chartboost ad: %s dismiss", name.c_str());
    }
    void onChartboostClose(const std::string& name)
    {
        CCLOG("Chartboost ad: %s close", name.c_str());
    }
    void onChartboostClick(const std::string& name)
    {
        CCLOG("Chartboost ad: %s click", name.c_str());
    }
    void onChartboostReward(const std::string& name, int reward)
    {
        CCLOG("Chartboost ad: %s reward: %d", name.c_str(), reward);
    }
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e)
    {
        CCLOG("Chartboost ad: %s Failed to load: error: %d", name.c_str(), e);
    }
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e)
    {
        CCLOG("Chartboost ad: %s Failed to record click: %d", name.c_str(), e);
    }
    
    //Miscellaneous callbacks
    void onChartboostConfirmation()
    {
        CCLOG("Chartboost ad confirmation show your confirmation dialog here");
    }
    void onChartboostCompleteStore()
    {
        CCLOG("Chartboost ad coming back from store");
    }
};

void MyPluginsMgr::initCharBoost()
{
    sdkbox::PluginChartboost::init();
    sdkbox::PluginChartboost::setListener(new CBListener);
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventChartboost1, [](EventCustom *) {
        sdkbox::PluginChartboost::show(sdkbox::CB_Location_Default);
    });
    eventDispatcher->addCustomEventListener(kMenuEventChartboost2, [](EventCustom *) {
        sdkbox::PluginChartboost::show("Level Complete");
    });
}



/**
 * FlurryAnalytics
 */

#include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"
static bool flurryAnalyticsSendData() {
    std::string ret;
    
    bool retBool = sdkbox::PluginFlurryAnalytics::activeSessionExists();
    if (!retBool) {
        CCLOG("session not exist return");
        return false;
    }
    
    ret = sdkbox::PluginFlurryAnalytics::getSessionID();
    CCLOG("Flurry analytics session : %s", ret.c_str());
    
    std::string origin = "this is origin name";
    std::string originVersion = "origin version";
    sdkbox::PluginFlurryAnalytics::addOrigin(origin, originVersion);
    
    origin = "other origin";
    originVersion = "other origin version";
    std::map<std::string, std::string> params;
    params.insert(std::make_pair("key1", "value1"));
    params.insert(std::make_pair("key2", "value2"));
    sdkbox::PluginFlurryAnalytics::addOrigin(origin, originVersion, params);
    
    ret = "test event1";
    sdkbox::PluginFlurryAnalytics::logEvent(ret);
    
    ret = "test event2";
    params.clear();
    params.insert(std::make_pair("eKey1", "eVal1"));
    params.insert(std::make_pair("eKey2", "eVal2"));
    sdkbox::PluginFlurryAnalytics::logEvent(ret, params);
    
    ret = "test event3";
    sdkbox::PluginFlurryAnalytics::logEvent(ret, true);
    sdkbox::PluginFlurryAnalytics::endTimedEvent(ret);
    
    ret = "test event4";
    params.clear();
    params.insert(std::make_pair("eKey3", "eVal3"));
    params.insert(std::make_pair("eKey4", "eVal4"));
    sdkbox::PluginFlurryAnalytics::logEvent(ret, params, true);
    sdkbox::PluginFlurryAnalytics::endTimedEvent(ret, params);
    
    ret = "error test";
    std::string msg = "log errror msg";
    std::string ifno = "log error info";
    sdkbox::PluginFlurryAnalytics::logError(ret, msg, ifno);
    
    sdkbox::PluginFlurryAnalytics::logPageView();
    
    ret = "this is user id";
    sdkbox::PluginFlurryAnalytics::setUserID(ret);
    sdkbox::PluginFlurryAnalytics::setAge(11);
    ret = "m"; // m:male  f:female  u:unkonw
    sdkbox::PluginFlurryAnalytics::setGender(ret);
    
    sdkbox::PluginFlurryAnalytics::pauseBackgroundSession();
    
    sdkbox::PluginFlurryAnalytics::setReportLocation(true);
    
    sdkbox::PluginFlurryAnalytics::clearLocation();
    //chendu, sichuan, china
    sdkbox::PluginFlurryAnalytics::setLatitude(104.06, 30.67, 0, 0);
    
    sdkbox::PluginFlurryAnalytics::setSessionReportsOnCloseEnabled(true);
    sdkbox::PluginFlurryAnalytics::setSessionReportsOnPauseEnabled(true);
    sdkbox::PluginFlurryAnalytics::setBackgroundSessionEnabled(true);
    
    sdkbox::PluginFlurryAnalytics::setEventLoggingEnabled(true);
    sdkbox::PluginFlurryAnalytics::setPulseEnabled(true);
    
    sdkbox::PluginFlurryAnalytics::endSession();
    
    CCLOG("Flurry analytics send data finish");
    
    return  true;
}
class FAListener : public sdkbox::FlurryAnalyticsListener {
    
public:
    void flurrySessionDidCreateWithInfo(std::map<std::string, std::string>& info)
    {
        CCLOG("FlurryAnalytics callback entry");
        CCLOG("MAP INFO BEGIN");
        for (auto item : info) {
            CCLOG("Item %s : %s", item.first.c_str(), item.second.c_str());
        }
        CCLOG("MAP INFO END");
    }
};

void MyPluginsMgr::initFlurry()
{
    bool bInit = sdkbox::PluginFlurryAnalytics::init();
    if (!bInit) {
        CCLOG(">>> FAIL! init flurry analytics fail<<<");
        return ;
    }
    
    //must call befor start session
    std::string ret = sdkbox::PluginFlurryAnalytics::getFlurryAgentVersion();
    CCLOG("FlurryVersion: %s", ret.c_str());
    sdkbox::PluginFlurryAnalytics::setShowErrorInLogEnabled(true);
    
    CCLOG("invoke set listener");
    sdkbox::FlurryAnalyticsListener *listener = new FAListener();
    sdkbox::PluginFlurryAnalytics::setListener(listener);
    
    //start session
    sdkbox::PluginFlurryAnalytics::startSession();
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventFA1, [](EventCustom *) {
        CCLOG("[Flurry Analytics] sending data");
        
        flurryAnalyticsSendData();
    });
}

/**
 * google analytics
 */
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"
void MyPluginsMgr::initGoogleAnalytics()
{
    PluginGoogleAnalytics::init();
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventGA1, [](EventCustom *) {
        CCLOG("[GoogleAnalytics] sending data");
        
        PluginGoogleAnalytics::logTiming("Startup", 0, "timing name", "timing label");
        PluginGoogleAnalytics::logEvent("EventCategory 1", "EventAction 1", "EventLabel 1", 10);
        PluginGoogleAnalytics::logScreen("Screen1");
        PluginGoogleAnalytics::logEvent("Read", "Press", "Button1", 10);
        PluginGoogleAnalytics::logEvent("Read", "Press", "Button2", 20);
        PluginGoogleAnalytics::logEvent("Dispose", "Release", "Button22", 20);
        PluginGoogleAnalytics::logScreen("Screen2");
        PluginGoogleAnalytics::logSocial("twitter", "retweet", "retweet esto fu.");
        PluginGoogleAnalytics::logException("Algo se ha roto", false);
        PluginGoogleAnalytics::dispatchPeriodically(60);
    });
}

/**
 * IAP
 */
#include "PluginIAP/PluginIAP.h"
class IAPListenerDemo : public sdkbox::IAPListener
{
public:
    IAPListenerDemo()
    {
        Product test;
        test.name = "remove_ads";
        
        _products.push_back(test);
        updateIAP(_products);
    }
    
    // a selector callback
    void onShowAds(cocos2d::Ref* sender)
    {
        CCLOG("Show Ads");
    }
    void onRequestIAP(cocos2d::Ref* sender)
    {
        IAP::refresh();
    }
    void onRestoreIAP(cocos2d::Ref* sender)
    {
        IAP::restore();
    }
    void onIAP(cocos2d::Ref* sender)
    {
        auto btn = static_cast<Node*>(sender);
        Product* p = (Product*)btn->getUserData();
        
        CCLOG("Start IAP %s", p->name.c_str());
        IAP::purchase(p->name);
    }
    
private:
    
    void updateIAP(const std::vector<sdkbox::Product>& products)
    {
        
    }
    
    virtual void onSuccess(sdkbox::Product const& p) override
    {
    }
    
    virtual void onFailure(sdkbox::Product const& p, const std::string &msg) override
    {
        
    }
    
    virtual void onCanceled(sdkbox::Product const& p) override
    {
        
    }
    
    virtual void onRestored(sdkbox::Product const& p) override
    {
        
    }
    
    virtual void onProductRequestSuccess(std::vector<sdkbox::Product> const &products) override
    {
        
    }
    
    virtual void onProductRequestFailure(const std::string &msg) override
    {
        
    }
    
    std::vector<sdkbox::Product> _products;
};

void MyPluginsMgr::initIAP()
{
    IAP::init();
    IAP::setDebug(true);
    IAP::setListener(new IAPListenerDemo);
    
    //
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventIAP1, [](EventCustom *) {
        Product test;
        test.name = "remove_ads";
        
        CCLOG("Start IAP %s", test.name.c_str());
        IAP::purchase(test.name);
    });
}


/**
 * Kochava
 */
#include "PluginKochava/PluginKochava.h"
void MyPluginsMgr::initKochava()
{
    sdkbox::PluginKochava::init();
    
    sdkbox::PluginKochava::trackEvent("KochavaCustomEvent", "HelloWorld");
    
    auto callback = [](const std::map<std::string, std::string>* attribution)
    {
        if (attribution)
        {
            typedef std::map<std::string, std::string> map_type;
            const map_type& m = *attribution;
            
            for (map_type::const_iterator it = m.begin(); it != m.end(); ++it)
            {
                const map_type::value_type& kv = *it;
                printf("%s -> %s", kv.first.c_str(), kv.second.c_str());
            }
        }
    };
    
    sdkbox::PluginKochava::setAttributionCallback(callback);
    
    //
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventKochava1, [](EventCustom *) {
        sdkbox::PluginKochava::trackEvent("KochavaCustomEvent", "HelloWorld");
        sdkbox::PluginKochava::spatialEvent("test", 100, 101, 102);
    });
}

/**
 * Tune: MATracking
 */
#include "PluginTune/PluginTune.h"
class TuneListenerDemo : public sdkbox::TuneListener
{
public:
    void onMobileAppTrackerEnqueuedActionWithReferenceId(const std::string &referenceId) override
    {
        CCLOG("%s: %s", __FUNCTION__, referenceId.data());
    }
    void onMobileAppTrackerDidSucceedWithData(const std::string &data) override
    {
        CCLOG("%s: %s", __FUNCTION__, data.data());
    }
    void onMobileAppTrackerDidFailWithError(const std::string &errorString) override
    {
        CCLOG("%s: %s", __FUNCTION__, errorString.data());
    }
    void onMobileAppTrackerDidReceiveDeeplink(const std::string &deeplink) override
    {
        CCLOG("%s: %s", __FUNCTION__, deeplink.data());
    }
};

// https://developers.mobileapptracking.com/category/mobile-sdks/mobile-sdks-events/
static void testTuneMeasureEvent()
{
    // https://developers.mobileapptracking.com/event-function-templates/
    {
        PluginTune::measureEventName("purchase");
        PluginTune::measureEventId(1122334455);
        
        TuneEvent event;
        event.eventName = "purchase2";
        event.refId     = "RJ1357";
        event.searchString = "sweet srisp red apples";
        event.attribute1 = "srisp";
        event.attribute2 = "red";
        event.quantity = 3;
        PluginTune::measureEvent(event);
    }
    
    {
        TuneEventItem item1;
        item1.item = "ball1";
        item1.unitPrice = 3.99;
        item1.quantity = 2;
        
        TuneEventItem item2;
        item2.item = "ball2";
        item2.unitPrice = 9.99;
        item2.quantity = 1;
        item2.revenue = 9.99;
        item2.attribute1 = "red";
        item2.attribute2 = "inflatable";
        
        
        PluginTune::setUserId("US13579");
        PluginTune::setFacebookUserId("321321321321");
        PluginTune::setGoogleUserId("11223344556677");
        PluginTune::setTwitterUserId("1357924680");
        PluginTune::setLatitude(9.142276, -79.724052, 15);
        
        TuneEvent event;
        event.eventName = "purchase";
        event.eventItems.push_back(item1);
        event.eventItems.push_back(item2);
        event.refId = "ref13571";
        event.revenue = 13.97;
        event.currencyCode = "USD";
        
        PluginTune::measureEvent(event);
        
    }
    
    // https://developers.mobileapptracking.com/settings-for-pre-loaded-apps/
    {
        TunePreloadData pd;
        pd.publisherId = "112233";
        pd.offerId = "offer_id";
        pd.agencyId = "agency_id";
        pd.publisherReferenceId = "publisher_ref_id";
        pd.publisherSub1 = "pub_sub1";
        pd.publisherSub2 = "pub_sub2";
        pd.publisherSub3 = "pub_sub3";
        pd.publisherSub4 = "pub_sub4";
        pd.publisherSub5 = "pub_sub5";
        pd.publisherSubAd = "pub_sub_ad";
        pd.publisherSubAdgroup = "pub_sub_adgroup";
        pd.publisherSubCampaign = "pub_sub_campaign";
        pd.publisherSubKeyword = "pub_sub_keyword";
        pd.publisherSubPublisher = "pub_sub_publisher";
        pd.publisherSubSite = "pub_sub_site";
        pd.advertiserSubAd = "ad_sub_ad";
        pd.advertiserSubAdgroup = "ad_sub_adgroup";
        pd.advertiserSubCampaign = "ad_sub_campaign";
        pd.advertiserSubKeyword = "ad_sub_keyword";
        pd.advertiserSubPublisher = "ad_sub_publisher";
        pd.advertiserSubSite = "ad_sub_site";
        
        PluginTune::setPreloadData(pd);
        PluginTune::measureSession();
    }
}

void MyPluginsMgr::initTune()
{
    PluginTune::init();
//    PluginTune::setPackageName("your.package.name");
    PluginTune::setListener(new TuneListenerDemo);
    PluginTune::measureSession();
    
//    PluginTune::setAllowDuplicateRequests(true);
    PluginTune::checkForDeferredDeeplinkWithTimeout(60);
    PluginTune::automateIapEventMeasurement(true);
    PluginTune::setCurrencyCode("RMB");
    PluginTune::setUserEmail("natalie@somedomain.com");
    PluginTune::setUserName("natalie123");
    PluginTune::setAge(43);
    PluginTune::setGender(PluginTune::GenderFemale);
    PluginTune::setUserId("US13579");
    PluginTune::setFacebookUserId("321321321321");
    PluginTune::setGoogleUserId("11223344556677");
    PluginTune::setTwitterUserId("1357924680");
    PluginTune::setLatitude(9.142276, -79.724052, 15);
    PluginTune::setAppAdTracking(true);
    PluginTune::measureEventName("login");
    
    
    //
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventTune1, [](EventCustom *) {
        testTuneMeasureEvent();
    });
}


/**
 * Vungle
 */
#include "PluginVungle/PluginVungle.h"
class VungleListenerDemo : public sdkbox::VungleListener
{
public:
    void onVungleCacheAvailable()
    {
        CCLOG("Cache Available");
    }
    void onVungleStarted()
    {
        CCLOG("Start Displaying ad, disable game/music here");
    }
    void onVungleFinished()
    {
        CCLOG("Finish Displaying ad, resume game/music here");
    }

    void onVungleAdViewed(bool isComplete)
    {
        if (isComplete) {
            CCLOG("User finish viewing the ad");
        } else {
            CCLOG("User didn't finish viewing the ad");
        }
    }
};

void MyPluginsMgr::initVungle()
{
    sdkbox::PluginVungle::init();
    sdkbox::PluginVungle::setDebug(true);
    sdkbox::PluginVungle::setListener(new VungleListenerDemo);
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->addCustomEventListener(kMenuEventVungle1, [](EventCustom *) {
        CCLOG("show video");
        sdkbox::PluginVungle::show("video");
    });
    eventDispatcher->addCustomEventListener(kMenuEventVungle2, [](EventCustom *) {
        CCLOG("show reward");
        sdkbox::PluginVungle::show("reward");
    });
}

///////////////////////////////////
MyPluginsMgr::MyPluginsMgr()
{
}

MyPluginsMgr *MyPluginsMgr::getInstance()
{
    static MyPluginsMgr *instance = 0;
    if (!instance)
    {
        instance = new MyPluginsMgr();
    }
    return instance;
}

bool MyPluginsMgr::init()
{
   initAdColony();
   initCharBoost();
   initFlurry();
   initGoogleAnalytics();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
   // FIXME: crash with android
   initIAP();
#endif

   initKochava();
   initTune();
   initVungle();
    
    return true;
}

bool MyPluginsMgr::runAll()
{
    return true;
}

void MyPluginsMgr::applicationWillEnterForeground()
{
//    PluginTune::measureSession();
}
