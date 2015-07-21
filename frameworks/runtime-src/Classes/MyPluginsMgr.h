//
//  MyPluginsMgr.h
//  template
//
//
//

#ifndef __template__MyPluginsMgr__
#define __template__MyPluginsMgr__

#include <string>
#include "SdkboxStarterKit.h"

static const std::string kMenuEvent1 = "b1";
static const std::string kMenuEvent2 = "b2";

static const std::string kMenuEventAdColony1 = "adcolony1";
static const std::string kMenuEventAdColony2 = "adcolony2";

static const std::string kMenuEventChartboost1 = "chartboost1";
static const std::string kMenuEventChartboost2 = "chartboost2";

static const std::string kMenuEventFA1 = "fa1";

static const std::string kMenuEventGA1 = "ga1";

static const std::string kMenuEventIAP1 = "iap1";

static const std::string kMenuEventKochava1 = "kochava1";

static const std::string kMenuEventTune1 = "tune1";

static const std::string kMenuEventVungle1 = "vungle1";
static const std::string kMenuEventVungle2 = "vungle2";

static const std::string kMenuEventAgeCheg1 = "agecheg1";
static const std::string kMenuEventAgeCheg2 = "agecheg2";


class MyPluginsMgr
{
public:
    static MyPluginsMgr *getInstance();

    bool init();
    
    void applicationWillEnterForeground();

private:
    MyPluginsMgr();

    void initAdColony();
    void initCharBoost();
    void initFlurry();
    void initGoogleAnalytics();
    void initIAP();
    void initKochava();
    void initTune();
    void initVungle();
//    void initFacebook();
//    void initAgeCheq();
};

#endif /* defined(__template__MyPluginsMgr__) */
