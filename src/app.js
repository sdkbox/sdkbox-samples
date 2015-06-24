
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask the window size
        var size = cc.winSize;

        var mainscene = ccs.load(res.MainScene_json);
        this.addChild(mainscene.node);

        // plugins
        var mgr = Object.create(MyPluginsMgr);
        mgr.init();
        this.mgr = mgr;

        // Example
        cc.MenuItemFont.setFontName('arial');
        cc.MenuItemFont.setFontSize(32);

        var size = cc.director.getWinSize();
        var y = size.height - 50
        // AdColony
        {
            var item = new cc.MenuItemFont("AdColony: ");
            var item1 = new cc.MenuItemFont("video", mgr.onAdColonyAd1, mgr);
            var item2 = new cc.MenuItemFont("v4vc", mgr.onAdColonyAd2, mgr);

            var menu = new cc.Menu(item, item1, item2);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }

        // Chartboost
        {
            y -= 50
            var item = new cc.MenuItemFont("Chartboost: ");
            var item1 = new cc.MenuItemFont("default", mgr.onChartboostDefault, mgr);
            var item2 = new cc.MenuItemFont("Level-Complete", mgr.onChartboostLC, mgr);

            var menu = new cc.Menu(item, item1, item2);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }

        // Flurry Analytics
        {
            y -= 50
            var item = new cc.MenuItemFont("Flurry: ");
            var item1 = new cc.MenuItemFont("test", mgr.onFlurryTest, mgr);

            var menu = new cc.Menu(item, item1);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }

        // Google Analytics
        {
            y -= 50
            var item = new cc.MenuItemFont("GA: ");
            var item1 = new cc.MenuItemFont("test", mgr.onGATest, mgr);

            var menu = new cc.Menu(item, item1);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }

        // IAP
        {
            y -= 50
            var item = new cc.MenuItemFont("IAP: ");
            var item1 = new cc.MenuItemFont("purchase", mgr.onIAPPurchase, mgr);

            var menu = new cc.Menu(item, item1);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }

        // Kochava
        {
            y -= 50
            var item = new cc.MenuItemFont("Kochava: ");
            var item1 = new cc.MenuItemFont("test", mgr.onKochavaTest, mgr);

            var menu = new cc.Menu(item, item1);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }


        // Tune
        {

            y -= 50
            var item = new cc.MenuItemFont("Tune: ");
            var item1 = new cc.MenuItemFont("test", mgr.onTuneTest, mgr);

            var menu = new cc.Menu(item, item1);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }


        // Vungle
        {
            y -= 50
            var item = new cc.MenuItemFont("Vungle: ");
            var item1 = new cc.MenuItemFont("video", mgr.onVungleVideo, mgr);
            var item2 = new cc.MenuItemFont("reward", mgr.onVungleReward, mgr);

            var menu = new cc.Menu(item, item1, item2);
            menu.setPosition(size.width/2, y);
            menu.alignItemsHorizontallyWithPadding(20);
            this.addChild(menu)
        }

        return true;
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

