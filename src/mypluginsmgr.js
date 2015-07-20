var MyPluginsMgr = {
    init:function() {
        sdkbox.PluginAdColony.init();
        sdkbox.PluginAdColony.setListener({
            onAdColonyChange : function (data, available) {
                // Called when AdColony finish loading
            },
            onAdColonyReward : function (data, currencyName, amount, success) {
                // Called when AdColony v4vc ad finish playing
            },
            onAdColonyStarted : function (data) {
                // Called when ad starts playing
            },
            onAdColonyFinished : function (data) {
                // Called when an ad finish displaying
            }
        });


        sdkbox.PluginChartboost.init();
        sdkbox.PluginChartboost.setListener({
            onChartboostCached : function (name) { console.log("onChartboostCached " + name) },
            onChartboostShouldDisplay : function (name) { console.log("onChartboostShouldDisplay " + name) },
            onChartboostDisplay : function (name) { console.log("onChartboostDisplay " + name) },
            onChartboostDismiss : function (name) { console.log("onChartboostDismiss " + name) },
            onChartboostClose : function (name) { console.log("onChartboostClose " + name) },
            onChartboostClick : function (name) { console.log("onChartboostClick " + name) },
            onChartboostReward : function (name, reward) { console.log("onChartboostReward " + name + " reward " + reward) },
            onChartboostFailedToLoad : function (name, e) { console.log("onChartboostFailedToLoad " + name + " load error " + e) },
            onChartboostFailToRecordClick : function (name, e) { console.log("onChartboostFailToRecordClick " + name + " click error " + e) },
            onChartboostConfirmation : function () { console.log("onChartboostConfirmation") },
            onChartboostCompleteStore : function () { console.log("onChartboostCompleteStore") },
        });


        // Flurry Analytics
        sdkbox.PluginFlurryAnalytics.init();
        sdkbox.PluginFlurryAnalytics.setListener({
            flurrySessionDidCreateWithInfo:function(info) {
                var jsonInfo = JSON.parse(info)
                console.log("session started")
                console.log("APIKey :" + jsonInfo.apiKey + " session id :" + jsonInfo.sessionId);
                sdkbox.PluginFlurryAnalytics.logEvent("test event2 js", JSON.stringify({"eKey1":"eVal1", "eKey2":"eVal2"}));
            }
        });
        sdkbox.PluginFlurryAnalytics.startSession();


        // Google Analytics
        sdkbox.PluginGoogleAnalytics.init();


        // IAP
        sdkbox.IAP.init();
        sdkbox.IAP.setListener({
            onSuccess : function (product) {
                //Purchase success
            },
            onFailure : function (product, msg) {
                //Purchase failed
                //msg is the error message
            },
            onCanceled : function (product) {
                //Purchase was canceled by user
            },
            onRestored : function (product) {
                //Purchase restored
            },
            onProductRequestSuccess : function (products) {
                //Returns you the data for all the iap products
                //You can get each item using following method
                for (var i = 0; i < products.length; i++) {
                    // loop
                }
            },
            onProductRequestFailure : function (msg) {
                //When product refresh request fails.
            }
        });


        // Kochava
        sdkbox.PluginKochava.init();


        // Tune
        sdkbox.PluginTune.init();
        sdkbox.PluginTune.setPackageName("org.cocos2dx.tune");
        sdkbox.PluginTune.setListener({
          onEnqueuedAction: function(data) { console.log(data); },
          onSucceed: function(data) { console.log(data); },
          onFailed: function(data) { console.log(data); },
          onReceiveDeeplink: function(data) { console.log(data); }
        });
        sdkbox.PluginTune.measureSession();


        // Vungle
        sdkbox.PluginVungle.init();
        sdkbox.PluginVungle.setListener({
            onVungleCacheAvailable: function() { console.log("onVungleCacheAvailable") },
            onVungleStarted: function() { console.log("onVungleStarted") },
            onVungleFinished: function() { console.log("onVungleFinished") },
            onVungleAdViewed: function(isComplete) { console.log("onVungleAdViewed" + isComplete) }
        });

        // // Facebook
        // sdkbox.PluginFacebook.init();
        // sdkbox.PluginFacebook.setListener({
        //     onLogin: function(hasLogon, data) { console.log("onFacebookLogin: " + hasLogon + data); },
        //     onAPI: function(tag, data) { console.log("onAPI: " + tag + " " + data); },
        //     onSharedSuccess: function(data) { console.log("onSharedSuccess: " + data); },
        //     onSharedFailed: function(data) { console.log("onSharedFailed: " + data); },
        //     onSharedCancel: function() { console.log("onSharedCancel"); }
        // });

        // // AgeCheq
        // sdkbox.PluginAgeCheq.init();
        // sdkbox.PluginAgeCheq.setListener({
        //     checkResponse: function(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10) { console.log("onCheckResponse: " + a0+a1+a2+a3+a4+a5+a6+a7+a8+a9+a10); },
        //     associateDataResponse: function(a, b) { console.log("onAssociateDataResponse: " + a + " " + b); }
        // });
    },
    onAdColonyAd1:function(sender) {
        console.log("AdColony: show video");
        sdkbox.PluginAdColony.show("video");
    },
    onAdColonyAd2:function(sender) {
        console.log("AdColony: show v4vc");
        sdkbox.PluginAdColony.show("v4vc");
    },  
    onChartboostDefault:function(sender) {  
        console.log("Chartboost: show default");  
        sdkbox.PluginChartboost.show("Default");
    },
    onChartboostLC:function(sender) {
        console.log("Chartboost: show LC"); 
        sdkbox.PluginChartboost.show("Level Complete");
    },
    onFlurryTest:function(sender) {
        console.log("Flurry: test");
        sdkbox.PluginFlurryAnalytics.logEvent("test event1");
    },
    onGATest:function(sender) {
        console.log("GA: test");
        sdkbox.PluginGoogleAnalytics.logTiming("Startup", 0, "timing name", "timing label");
        sdkbox.PluginGoogleAnalytics.logEvent("EventCategory 1", "EventAction 1", "EventLabel 1", 10);
        sdkbox.PluginGoogleAnalytics.logScreen("Screen1");
        sdkbox.PluginGoogleAnalytics.logEvent("Read", "Press", "Button1", 10);
        sdkbox.PluginGoogleAnalytics.logEvent("Read", "Press", "Button2", 20);
        sdkbox.PluginGoogleAnalytics.logEvent("Dispose", "Release", "Button22", 20);
        sdkbox.PluginGoogleAnalytics.logScreen("Screen2");
        sdkbox.PluginGoogleAnalytics.logSocial("twitter", "retweet", "retweet esto fu.");
        sdkbox.PluginGoogleAnalytics.logException("Algo se ha roto", false);
        sdkbox.PluginGoogleAnalytics.dispatchPeriodically(60);
    },
    onIAPPurchase:function(sender) {
        console.log("IAP: purchase test");
        sdkbox.IAP.purchase("remove_ads");
    },
    onKochavaTest:function(sender) {
        console.log("Kochava: test");
        sdkbox.PluginKochava.trackEvent("KochavaCustomEvent", "HelloWorld");
        sdkbox.PluginKochava.spatialEvent("test", 100, 101, 102);
    },
    onTuneTest:function(sender) {
        console.log("Tune: test");

        sdkbox.PluginTune.measureEventName("login");
        sdkbox.PluginTune.measureEventId(0123456789);

        var event = {};
        event.eventName = "purchase";
        event.refId = "RJ1357";
        event.searchString = "sweet srisp red apples";
        event.attribute1 = "srisp";
        event.attribute2 = "red";
        event.quantity = 3;
        sdkbox.PluginTune.measureEvent(JSON.stringify(event));
    },
    onVungleVideo:function(sender) {
        console.log("Vungle: show video");
        sdkbox.PluginVungle.show("video");
    },
    onVungleReward:function(sender) {
        console.log("Vungle: show reward");
        sdkbox.PluginVungle.show("reward");
    },
    onFacebookLogin:function(sender) {
        console.log("Facebook: login");
        sdkbox.PluginFacebook.login();
    },
    onFacebookCheckStatus:function(sender) {
        console.log("Facebook: check status");
        console.log("Facebook: permission list: "+ sdkbox.PluginFacebook.getPermissionList());
        console.log("Facebook: token: "+ sdkbox.PluginFacebook.getAccessToken());
        console.log("Facebook: user id: "+ sdkbox.PluginFacebook.getUserID());
        console.log("Facebook: FBSDK version: "+ sdkbox.PluginFacebook.getSDKVersion());
    },
    onFacebookShareLink:function(sender) {
        console.log("Facebook: share link");
        var data = {}
        data.link = "http://www.cocos2d-x.org";
        data.title = "cocos2d-x";
        data.text = "The Best Game Engine";
        data.imageUrl = "http://cocos2d-x.org/images/logo.png";
        sdkbox.PluginFacebook.share(data);
    },
    onFacebookDialogLink:function(sender) {
        console.log("Facebook: share link");
        var data = {}
        data.link = "http://www.cocos2d-x.org";
        data.title = "cocos2d-x";
        data.text = "The Best Game Engine";
        data.imageUrl = "http://cocos2d-x.org/images/logo.png";
        sdkbox.PluginFacebook.dialog(data);
    },
    onFacebookLogout:function(sender) {
        console.log("Facebook logout");
        sdkbox.PluginFacebook.logout();
    },
    onAgeCheqCheck:function(sender) {
        console.log("onAgeCheqCheck");
        sdkbox.PluginAgeCheq.check("1426");
    }
};
