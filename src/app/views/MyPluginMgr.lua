local MyPluginMgr = class("MyPluginMgr")
local print = release_print

function MyPluginMgr:ctor()
	print("MyPluginMgr")

	-- AdColony
	sdkbox.PluginAdColony:init()
	sdkbox.PluginAdColony:setListener(function(args)
	    if "onAdColonyChange" == args.name then
	        local info = args.info  -- sdkbox::AdColonyAdInfo
	        local available = args.available -- boolean
					dump(info, "onAdColonyChange:")
	        print("available:", available)
	    elseif "onAdColonyReward" ==  args.name then
	        local info = args.info  -- sdkbox::AdColonyAdInfo
	        local currencyName = args.currencyName -- string
	        local amount = args.amount -- int
	        local success = args.success -- boolean
					dump(info, "onAdColonyReward:")
	        print("currencyName:", currencyName)
	        print("amount:", amount)
	        print("success:", success)
	    elseif "onAdColonyStarted" ==  args.name then
	        local info = args.info  -- sdkbox::AdColonyAdInfo
					dump(info, "onAdColonyStarted:")
	    elseif "onAdColonyFinished" ==  args.name then
	        local info = args.info  -- sdkbox::AdColonyAdInfo
					dump(info, "onAdColonyFinished:")
	    end
	end)


	-- Chartboost
	sdkbox.PluginChartboost:init()
	sdkbox.PluginChartboost:setListener(function(args)
	    if "onChartboostCached" == args.func then
	        local name = args.name -- string
	        print("onChartboostCached")
	        print("name:", args.name)
	    elseif "onChartboostShouldDisplay" == args.func then
	        local name = args.name -- string
	        print("onChartboostShouldDisplay")
	        print("name:", args.name)
	    elseif "onChartboostDisplay" == args.func then
	        local name = args.name -- string
	        print("onChartboostDisplay")
	        print("name:", args.name)
	    elseif "onChartboostDismiss" == args.func then
	        local name = args.name -- string
	        print("onChartboostDismiss")
	        print("name:", args.name)
	    elseif "onChartboostClose" == args.func then
	        local name = args.name -- string
	        print("onChartboostClose")
	        print("name:", args.name)
	    elseif "onChartboostClick" == args.func then
	        local name = args.name -- string
	        print("onChartboostClick")
	        print("name:", args.name)
	    elseif "onChartboostReward" == args.func then
	        local name = args.name -- string
	        local reward = args.reward -- int
	        print("onChartboostReward")
	        print("name:", args.name)
	        print("reward:", reward)
	    elseif "onChartboostFailedToLoad" == args.func then
	        local name = args.name -- string
	        local e = args.e -- int
	        print("onChartboostFailedToLoad")
	        print("name:", args.name)
	        print("error:", e)
	    elseif "onChartboostFailToRecordClick" == args.func then
	        local name = args.name -- string
	        local e = args.e -- int
	        print("onChartboostFailToRecordClick")
	        print("name:", args.name)
	        print("error:", e)
	    elseif "onChartboostConfirmation" == args.func then
	        local name = args.name -- string
	        print("onChartboostConfirmation")
	    elseif "onChartboostCompleteStore" == args.func then
	        local name = args.name -- string
	        print("onChartboostCompleteStore")
	    end
	end)


	-- Flurry
	sdkbox.PluginFlurryAnalytics:init()
	sdkbox.PluginFlurryAnalytics:setListener(function(data)
	        local ret = json.decode(data)
	        print("apiKey:", ret.apiKey, "sessionId:", ret.sessionId)
	        -- check session state
	        print("Flurry analytics session exist: ", f:activeSessionExists())
	        print("Flurry analytics session: ", f:getSessionID())
	        local eventName = "test event1"
	        sdkbox.PluginFlurryAnalytics:logEvent(eventName);
	    end)
	sdkbox.PluginFlurryAnalytics:startSession()


	-- Google Analytics
	sdkbox.PluginGoogleAnalytics:init()


	-- IAP
	-- sdkbox.IAP:init()
	-- sdkbox.IAP:setListener(function(args)
	-- 		if "onSuccess" == args.event then
	-- 				local product = args.product
	-- 				dump(product, "onSuccess:")
	-- 		elseif "onFailure" == args.event then
	-- 				local product = args.product
	-- 				local msg = args.msg
	-- 				dump(product, "onFailure:")
	-- 				print("msg:", msg)
	-- 		elseif "onCanceled" == args.event then
	-- 				local product = args.product
	-- 				dump(product, "onCanceled:")
	-- 		elseif "onRestored" == args.event then
	-- 				local product = args.product
	-- 				dump(product, "onRestored:")
	-- 		elseif "onProductRequestSuccess" == args.event then
	-- 				local products = args.products
	-- 				dump(products, "onProductRequestSuccess:")
	-- 		elseif "onProductRequestFailure" == args.event then
	-- 				local msg = args.msg
	-- 				print("msg:", msg)
	-- 		else
	-- 				print("unknow event ", args.event)
	-- 		end
	-- end)


	-- Kochava
	sdkbox.PluginKochava:init()


	-- Tune
	sdkbox.PluginTune:init()
	sdkbox.PluginTune:setPackageName("org.cocos2dx.tune")
	sdkbox.PluginTune:setListener(function(eventName, eventData)
	        print(eventName, eventData)
	    end)
	sdkbox.PluginTune:measureSession()


	-- Vungle
	sdkbox.PluginVungle:init()
	sdkbox.PluginVungle:setListener(function(name, isComplete)
	    if "onVungleCacheAvailable" == name then
	        print("onVungleCacheAvailable")
	    elseif "onVungleStarted" ==  name then
	        print("onVungleStarted")
	    elseif "onVungleFinished" ==  name then
	        print("onVungleFinished")
	    elseif "onVungleAdViewed" ==  name then
	        print("onVungleAdViewed:", isComplete)
	    end
	end)
end


function MyPluginMgr:onAdColonyVideo()
	print("AdColony: show video")
	sdkbox.PluginAdColony:show("video")
end

function MyPluginMgr:onAdColonyV4vc()
	print("AdColony: show v4vc")
	sdkbox.PluginAdColony:show("v4vc")
end

function MyPluginMgr:onChartboostDefault()
	print("Chartboost: show default")
	sdkbox.PluginChartboost:show("Default")
end

function MyPluginMgr:onChartboostLC()
    print("Chartboost: show LC")
    sdkbox.PluginChartboost:show("Level Complete")
end

function MyPluginMgr:onFlurryTest()
    print("Flurry: test")
    sdkbox.PluginFlurryAnalytics:logEvent("test event1")
end
function MyPluginMgr:onGATest()
	print("GA: test")
	sdkbox.PluginGoogleAnalytics:logTiming("Startup", 0, "timing name", "timing label")
	sdkbox.PluginGoogleAnalytics:logEvent("EventCategory 1", "EventAction 1", "EventLabel 1", 10)
	sdkbox.PluginGoogleAnalytics:logScreen("Screen1")
	sdkbox.PluginGoogleAnalytics:logEvent("Read", "Press", "Button1", 10)
	sdkbox.PluginGoogleAnalytics:logEvent("Read", "Press", "Button2", 20)
	sdkbox.PluginGoogleAnalytics:logEvent("Dispose", "Release", "Button22", 20)
	sdkbox.PluginGoogleAnalytics:logScreen("Screen2")
	sdkbox.PluginGoogleAnalytics:logSocial("twitter", "retweet", "retweet esto fu.")
	sdkbox.PluginGoogleAnalytics:logException("Algo se ha roto", false)
	sdkbox.PluginGoogleAnalytics:dispatchPeriodically(60)
end
function MyPluginMgr:onIAPPurchase()
    print("IAP: purchase test")
    sdkbox.IAP:purchase("remove_ads")
end
function MyPluginMgr:onKochavaTest()
    print("Kochava: test")
    sdkbox.PluginKochava:trackEvent("KochavaCustomEvent", "HelloWorld")
    sdkbox.PluginKochava:spatialEvent("test", 100, 101, 102)
end
function MyPluginMgr:onTuneTest()
    print("Tune: test")

    sdkbox.PluginTune:measureEventName("login")
    sdkbox.PluginTune:measureEventId(0123456789)

    -- var event = {}
    -- event.eventName = "purchase"
    -- event.refId = "RJ1357"
    -- event.searchString = "sweet srisp red apples"
    -- event.attribute1 = "srisp"
    -- event.attribute2 = "red"
    -- event.quantity = 3
    -- sdkbox.PluginTune:measureEvent(JSON.stringify(event))
end
function MyPluginMgr:onVungleVideo()
    print("Vungle: show video")
    sdkbox.PluginVungle:show("video")
end
function MyPluginMgr:onVungleReward()
    print("Vungle: show reward")
    sdkbox.PluginVungle:show("reward")
end

return MyPluginMgr
