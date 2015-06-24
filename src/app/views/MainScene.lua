
local CURRENT_MODULE_NAME = ...

local MainScene = class("MainScene", cc.load("mvc").ViewBase)

MainScene.RESOURCE_FILENAME = "MainScene.csb"

function MainScene:onCreate()
	local printf = release_print
    printf("resource node = %s", tostring(self:getResourceNode()))

    local node = self:getResourceNode()
    local mgr = import(".MyPluginMgr", CURRENT_MODULE_NAME).new()

	cc.MenuItemFont:setFontName('arial')
	cc.MenuItemFont:setFontSize(32)
	local y = display.height - 50

	-- AdColony
    cc.Menu:create(cc.MenuItemFont:create("AdColony: "),
    			   cc.MenuItemFont:create("video"):onClicked(mgr.onAdColonyVideo),
    			   cc.MenuItemFont:create("v4vc"):onClicked(mgr.onAdColonyV4vc)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

    -- Chartboost
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("Chartboost: "),
    			   cc.MenuItemFont:create("default"):onClicked(mgr.onChartboostDefault),
    			   cc.MenuItemFont:create("Level-Complete"):onClicked(mgr.onChartboostLC)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

    -- Flurry Analytics
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("Flurry: "),
    			   cc.MenuItemFont:create("test"):onClicked(mgr.onFlurryTest)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

    -- Google Analytics
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("GA: "),
    			   cc.MenuItemFont:create("test"):onClicked(mgr.onGATest)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

    -- IAP
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("IAP: "),
    			   cc.MenuItemFont:create("purchase"):onClicked(mgr.onIAPPurchase)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

    -- Kochava
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("Kochava: "),
    			   cc.MenuItemFont:create("test"):onClicked(mgr.onKochavaTest)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)


    -- Tune
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("Tune: "),
    			   cc.MenuItemFont:create("test"):onClicked(mgr.onTuneTest)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

    -- Vungle
    y = y - 50
    cc.Menu:create(cc.MenuItemFont:create("Vungle: "),
    			   cc.MenuItemFont:create("video"):onClicked(mgr.onVungleVideo),
    			   cc.MenuItemFont:create("reward"):onClicked(mgr.onVungleReward)
    			   )
        :move(display.cx, y)
        :addTo(node)
        :alignItemsHorizontallyWithPadding(20)

end

return MainScene
