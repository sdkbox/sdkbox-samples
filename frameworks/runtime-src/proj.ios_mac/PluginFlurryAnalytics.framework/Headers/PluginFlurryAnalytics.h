/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _PLUGIN_FLURRY_ANALYTICS_H_
#define _PLUGIN_FLURRY_ANALYTICS_H_

#include <string>
#include <map>

namespace sdkbox {

    typedef enum {
        FlurryLogLevelNone = 0,         //No output
        FlurryLogLevelCriticalOnly,     //Default, outputs only critical log events
        FlurryLogLevelDebug,            //Debug level, outputs critical and main log events
        FlurryLogLevelAll               //Highest level, outputs all log events
    } FA_FlurryLogLevel;

    typedef enum {
        FlurryEventFailed = 0,
        FlurryEventRecorded,
        FlurryEventUniqueCountExceeded,
        FlurryEventParamsCountExceeded,
        FlurryEventLogCountExceeded,
        FlurryEventLoggingDelayed
    } FA_FlurryEventRecordStatus;


    class FlurryAnalyticsListener
    {
    public:

        /*!
         *  @brief Invoked when analytics session is created,
         *
         *  This method informs the app that an analytics session is created.
         *
         *  @see Flurry#startSession for details on session.
         *
         *  @param info A dictionary of session information: sessionID, apiKey, null on android
         */
        virtual void flurrySessionDidCreateWithInfo(std::map<std::string, std::string>& info) = 0;
    };

    class PluginFlurryAnalytics
    {
    public:
        ~PluginFlurryAnalytics();

        // init plugin, must be first invoke
        static bool init();


        /*!
         *  @brief Explicitly specifies the App Version that Flurry will use to group Analytics data.
         *
         *  This is an optional method that overrides the App Version Flurry uses for reporting. Flurry will
         *  use the CFBundleVersion in your info.plist file when this method is not invoked.
         *
         *  @note There is a maximum of 605 versions allowed for a single app. \n
         *  This method must be called prior to invoking #startSession:.
         *
         *  @param version The custom version name.
         *
         *  @related function
         *   android:   setVersionName(String version)
         *   ios:       setAppVersion(NString version)
         *
         */
        static void setAppVersion(std::string& version);


        /*!
         *  @brief Retrieves the Flurry Agent Build Version.
         *
         *  This is an optional method that retrieves the Flurry Agent Version the app is running under. 
         *  It is most often used if reporting an unexpected behavior of the SDK to <a href="mailto:iphonesupport@flurry.com">
         *  Flurry Support</a>
         *
         *  @note This method must be called prior to invoking #startSession:. \n
         *  FAQ for the iPhone SDK is located at <a href="http://wiki.flurry.com/index.php?title=IPhone_FAQ">
         *  Support Center - iPhone FAQ</a>.
         *
         *  @see #setLogLevel: for information on how to view debugging information on your console.
         *
         *  @return The agent version of the Flurry SDK.
         *
         *  @related function
         *   android:   getReleaseVersion()
         *   ios:       getFlurryAgentVersion()
         *
         */
        static std::string getFlurryAgentVersion();

        /*!
         *  @brief Displays an exception in the debug log if thrown during a Session.
         *
         *  This is an optional method that augments the debug logs with exceptions that occur during the session.
         *  You must both capture exceptions to Flurry and set debug logging to enabled for this method to
         *  display information to the console. The default setting for this method is @c NO.
         *
         *  @note This method must be called prior to invoking #startSession:.
         *
         *  @see #setLogLevel: for information on how to view debugging information on your console. \n
         *  #logError:message:exception: for details on logging exceptions. \n
         *  #logError:message:error: for details on logging errors.
         *
         *  @param value @c YES to show errors in debug logs, @c NO to omit errors in debug logs.
         *
         *  @related function
         *   ios:       setShowErrorInLogEnabled()
         *
         */
        static void setShowErrorInLogEnabled(bool value);


        /*!
         *  @brief Generates debug logs to console.
         *
         *  This is an optional method that displays debug information related to the Flurry SDK.
         *  display information to the console. The default setting for this method is @c NO 
         *  which sets the log level to @c FlurryLogLevelCriticalOnly.
         *  When set to @c YES the debug log level is set to @c FlurryLogLevelDebug
         *
         *  @note This method must be called prior to invoking #startSession:. If the method, setLogLevel is called later in the code, debug logging will be automatically enabled.
         *
         *  @param value @c YES to show debug logs, @c NO to omit debug logs.
         *
         *  @related function
         *   android:   setLogEnabled
         *   ios:       setDebugLogEnabled()
         *
         */
        static void setDebugLogEnabled(bool value);


        /*!
         *  @brief Generates debug logs to console.
         *
         *  This is an optional method that displays debug information related to the Flurry SDK.
         *  display information to the console. The default setting for this method is @c FlurryLogLevelCritycalOnly.
         *
         *  @note Its good practice to call this method prior to invoking #startSession:. If debug logging is disabled earlier, this method will enable it.
         *
         *  @param value Log level
         *
         *  @related function
         *   android:   setLogLevel
         *   ios:       setLogLevel
         *
         */
        static void setLogLevel(FA_FlurryLogLevel value);


        /*!
         *  @brief Set the timeout for expiring a Flurry session.
         * 
         *  This is an optional method that sets the time the app may be in the background before 
         *  starting a new session upon resume.  The default value for the session timeout is 10 
         *  seconds in the background.
         * 
         *  @note This method must be called prior to invoking #startSession:.
         * 
         *  @param seconds The time in seconds to set the session timeout to.
         *
         *  @related function
         *   android:   setContinueSessionMillis
         *   ios:       setSessionContinueSeconds
         *
         */
        static void setSessionContinueSeconds(float seconds);


        /*!
         *  @brief Enable automatic collection of crash reports.
         *
         *  This is an optional method that collects crash reports when enabled. The
         *  default value is @c NO.
         *
         *  @note This method must be called prior to invoking #startSession:.
         *
         *  @param value @c YES to enable collection of crash reports.
         *
         *  @related function
         *   android:   setCaptureUncaughtExceptions
         *   ios:       setCrashReportingEnabled
         *
         */
        static void setCrashReportingEnabled(bool value);




        /*!
         *  @brief Start a Flurry session for the project denoted by @c apiKey.
         * 
         *  This method serves as the entry point to Flurry Analytics collection.  It must be
         *  called in the scope of @c applicationDidFinishLaunching.  The session will continue 
         *  for the period the app is in the foreground until your app is backgrounded for the 
         *  time specified in #setSessionContinueSeconds:. If the app is resumed in that period
         *  the session will continue, otherwise a new session will begin.
         *
         *  Crash reporting will not be enabled. See #setCrashReportingEnabled: for
         *  more information.
         * 
         *  @note If testing on a simulator, please be sure to send App to background via home
         *  button. Flurry depends on the iOS lifecycle to be complete for full reporting.
         * 
         * @see #setSessionContinueSeconds: for details on setting a custom session timeout.
         *
         * 
         * @param apiKey The API key for this project.
         *
         *  @related function
         *   android:   onStartSession
         *   ios:       startSession
         *
         */
        static void startSession();


        /*!
         *  @brief end session, just valid on android
         *
         * @related function
         *  android:    onEndSession()
         */
        static void endSession();


        /*!
         *  @brief Start a Flurry session for the project denoted by @c apiKey.
         *
         * @related function
         *  android:    isSessionActive
         *  ios:        activeSessionExists
         *
         */
        static bool activeSessionExists();


        /*!
         *  @brief Start a Flurry session for the project denoted by @c apiKey.         
         *
         * @related function
         * android: getSessionId()
         * ios:     getSessionID()
         *
         */
        static std::string getSessionID();


        /*!
         *  @brief Pauses a Flurry session left running in background. on valid on ios
         *
         *  This method should be used in case of #setBackgroundSessionEnabled: set to YES. It can be
         *  called when application finished all background tasks (such as playing music) to pause session.
         *
         * @see #setBackgroundSessionEnabled: for details on setting a custom behaviour on resigning activity.
         *
         *
         * @related function
         * ios:     pauseBackgroundSession()
         *
         */
        static void pauseBackgroundSession();


        /*!
         *  @brief Adds an SDK origin specified by @c originName and @c originVersion.
         *
         *  This method allows you to specify origin within your Flurry SDK wrapper. As a general rule
         *  you should capture all the origin info related to your wrapper for Flurry SDK after every session start.
         *
         *  @see #addOrigin:withVersion:withParameters: for details on reporting origin info with parameters. \n
         *
         *
         *  @param originName    Name of the origin.
         *  @param originVersion Version string of the origin wrapper
         *
         * @related function
         * android: addOrigin (String originName, String originVersion)
         * ios:     addOrigin: (NSString *) originName withVersion: (NSString *) originVersion
         *
         */
        static void addOrigin(std::string& originName, std::string& originVersion);


        /*!
         *  @brief Adds a custom parameterized origin specified by @c originName with @c originVersion and @c parameters.
         *
         *  This method overrides #addOrigin to allow you to associate parameters with an origin attribute. Parameters
         *  are valuable as they allow you to store characteristics of an origin.
         *
         *  @note You should not pass private or confidential information about your origin info in a
         *  custom origin. \n
         *  A maximum of 9 parameter names may be associated with any origin. Sending
         *  over 10 parameter names with a single origin will result in no parameters being logged
         *  for that origin.
         *
         *
         *
         *  @param originName    Name of the origin.
         *  @param originVersion Version string of the origin wrapper
         *  @param parameters An immutable copy of map containing Name-Value pairs of parameters.
         *
         * @related function
         * android: addOrigin (String originName, String originVersion, Map< String, String > originParameters)
         * ios:     addOrigin: (NSString *) originName withVersion: (NSString *) originVersion withParameters: (NSDictionary *) parameters
         *
         */
        static void addOrigin(std::string& originName, std::string& originVersion, std::map<std::string, std::string>& parameters);

        /*!
         * @brief just for lua, js binding, have the same function with addOrigin(string, string, map)
         */
        static void addOrigin(std::string& originName, std::string& originVersion, std::string& parameters);

        /*!
         *  @brief Records a custom event specified by @c eventName.
         * 
         *  This method allows you to specify custom events within your app.  As a general rule
         *  you should capture events related to user navigation within your app, any action 
         *  around monetization, and other events as they are applicable to tracking progress
         *  towards your business goals. 
         * 
         *  @note You should not pass private or confidential information about your users in a
         *  custom event. \n
         *  Where applicable, you should make a concerted effort to use timed events with
         *  parameters (#logEvent:withParameters:timed:) or events with parameters 
         *  (#logEvent:withParameters:). This provides valuable information around the time the user
         *  spends within an action (e.g. - time spent on a level or viewing a page) or characteristics
         *  of an action (e.g. - Buy Event that has a Parameter of Widget with Value Golden Sword).
         * 
         *  @see #logEvent:withParameters: for details on storing events with parameters. \n
         *  #logEvent:timed: for details on storing timed events. \n
         *  #logEvent:withParameters:timed: for details on storing timed events with parameters. \n
         *  #endTimedEvent:withParameters: for details on stopping a timed event and (optionally) updating 
         *  parameters.
         *
         * 
         *  @param eventName Name of the event. For maximum effectiveness, we recommend using a naming scheme
         *  that can be easily understood by non-technical people in your business domain.
         *
         *  @return enum FA_FlurryEventRecordStatus for the recording status of the logged event.
         *
         * @related function
         * android: logEvent (String eventId)
         * ios:     logEvent:(NSString *)eventName
         *
         */
        static int logEvent(std::string& eventName);

        /*!
         *  @brief Records a custom parameterized event specified by @c eventName with @c parameters.
         * 
         *  This method overrides #logEvent to allow you to associate parameters with an event. Parameters
         *  are extremely valuable as they allow you to store characteristics of an action. For example,
         *  if a user purchased an item it may be helpful to know what level that user was on.
         *  By setting this parameter you will be able to view a distribution of levels for the purcahsed
         *  event on the <a href="http://dev.flurry.com">Flurrly Dev Portal</a>.
         * 
         *  @note You should not pass private or confidential information about your users in a
         *  custom event. \n
         *  A maximum of 10 parameter names may be associated with any event. Sending
         *  over 10 parameter names with a single event will result in no parameters being logged
         *  for that event. You may specify an infinite number of Parameter values. For example,
         *  a Search Box would have 1 parameter name (e.g. - Search Box) and many values, which would
         *  allow you to see what values users look for the most in your app. \n
         *  Where applicable, you should make a concerted effort to use timed events with
         *  parameters (#logEvent:withParameters:timed:). This provides valuable information 
         *  around the time the user spends within an action (e.g. - time spent on a level or 
         *  viewing a page).
         * 
         *  @see #logEvent:withParameters:timed: for details on storing timed events with parameters. \n
         *  #endTimedEvent:withParameters: for details on stopping a timed event and (optionally) updating 
         *  parameters.
         *
         * 
         *  @param eventName Name of the event. For maximum effectiveness, we recommend using a naming scheme
         *  that can be easily understood by non-technical people in your business domain.
         *  @param parameters An immutable copy of map containing Name-Value pairs of parameters.
         *
         *  @return enum FA_FlurryEventRecordStatus for the recording status of the logged event.
         *
         * @related function
         * android: logEvent (String eventId, Map< String, String > parameters)
         * ios:     logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;
         *
         */
        static int logEvent(std::string& eventName, std::map<std::string, std::string>& parameters);


        /*!
         * @brief just for lua, js binding, have same function with logEvent(string, map)
         */
        static int logEvent(std::string& eventName, std::string& parameters);


        /*!
         *  @brief Records a timed event specified by @c eventName.
         * 
         *  This method overrides #logEvent to allow you to capture the length of an event. This can
         *  be extremely valuable to understand the level of engagement with a particular action. For
         *  example, you can capture how long a user spends on a level or reading an article.
         * 
         *  @note You should not pass private or confidential information about your users in a
         *  custom event. \n
         *  Where applicable, you should make a concerted effort to use parameters with your timed 
         *  events (#logEvent:withParameters:timed:). This provides valuable information 
         *  around the characteristics of an action (e.g. - Buy Event that has a Parameter of Widget with 
         *  Value Golden Sword).
         * 
         *  @see #logEvent:withParameters:timed: for details on storing timed events with parameters. \n
         *  #endTimedEvent:withParameters: for details on stopping a timed event and (optionally) updating 
         *  parameters.
         *
         * 
         *  @param eventName Name of the event. For maximum effectiveness, we recommend using a naming scheme
         *  that can be easily understood by non-technical people in your business domain.
         *  @param timed Specifies the event will be timed..
         *
         *  @return enum FA_FlurryEventRecordStatus for the recording status of the logged event.
         *
         * @related function
         * android: logEvent (String eventId, boolean timed)
         * ios:     logEvent:(NSString *)eventName timed:(BOOL)timed;
         *
         */
        static int logEvent(std::string& eventName, bool timed);


        /*!
         *  @brief Records a custom parameterized timed event specified by @c eventName with @c parameters.
         * 
         *  This method overrides #logEvent to allow you to capture the length of an event with parameters. 
         *  This can be extremely valuable to understand the level of engagement with a particular action 
         *  and the characteristics associated with that action. For example, you can capture how long a user 
         *  spends on a level or reading an article. Parameters can be used to capture, for example, the
         *  author of an article or if something was purchased while on the level.
         * 
         *  @note You should not pass private or confidential information about your users in a
         *  custom event.
         *
         *  @see #endTimedEvent:withParameters: for details on stopping a timed event and (optionally) updating 
         *  parameters.
         *
         * 
         *  @param eventName Name of the event. For maximum effectiveness, we recommend using a naming scheme
         *  that can be easily understood by non-technical people in your business domain.
         *  @param parameters An immutable copy of map containing Name-Value pairs of parameters.
         *  @param timed Specifies the event will be timed..
         *
         *  @return enum FA_FlurryEventRecordStatus for the recording status of the logged event.
         *
         * @related function
         * android: logEvent (String eventId, Map< String, String > parameters, boolean timed)
         * ios:     logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters timed:(BOOL)timed;
         *
         */
        static int logEvent(std::string& eventName, std::map<std::string, std::string>& parameters, bool timed);

        /*!
         * @brief just for lua, js binding, have the same function with logEvent(string, map, bool)
         */
        static int logEvent(std::string& eventName, std::string& parameters, bool timed);


        /*!
         * @brief End a timed event
         *
         * @related function
         * android: endTimedEvent (String eventId)
         *
         */
        static void endTimedEvent(std::string& eventId);

        /*!
         *  @brief Ends a timed event specified by @c eventName and optionally updates parameters with @c parameters.
         * 
         *  This method ends an existing timed event.  If parameters are provided, this will overwrite existing
         *  parameters with the same name or create new parameters if the name does not exist in the parameter
         *  map set by #logEvent:withParameters:timed:.
         * 
         *  @note You should not pass private or confidential information about your users in a
         *  custom event. \n
         *  If the app is backgrounded prior to ending a timed event, the Flurry SDK will automatically
         *  end the timer on the event. \n 
         *  #endTimedEvent:withParameters: is ignored if called on a previously
         *  terminated event.
         *
         *  @see #logEvent:withParameters:timed: for details on starting a timed event with parameters.
         *
         * 
         *  @param eventName Name of the event. For maximum effectiveness, we recommend using a naming scheme
         *  that can be easily understood by non-technical people in your business domain.
         *  @param parameters An immutable copy of map containing Name-Value pairs of parameters.
         *
         * @related function
         * android: endTimedEvent (String eventId, Map< String, String > parameters)
         * ios:     endTimedEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;
         *
         */
        static void endTimedEvent(std::string& eventName, std::map<std::string, std::string>& parameters);

        /*!
         * @brief just for lua, js binding, have same function with endTimeEvent(string, map)
         *
         */
        static void endTimedEvent(std::string& eventName, std::string& parameters);

        /*!
         *  @brief Records an app exception. Commonly used to catch unhandled exceptions.
         * 
         *  This method captures an exception for reporting to Flurry. We recommend adding an uncaught
         *  exception listener to capture any exceptions that occur during usage that is not
         *  anticipated by your app.
         * 
         *  @see #logError:message:error: for details on capturing errors.
         *
         * 
         *  @param errorID Name of the error.
         *  @param message The message to associate with the error.
         *  @param info android: error class, ios: no use
         *
         * @related function
         * android: onError (String errorId, String message, String errorClass)
         * ios:     logError:(NSString *)errorID message:(NSString *)message error:nullptr;
         *
         */
        static void logError(std::string& errorID, std::string& message, std::string& info);
        

        /*!
         *  @brief Explicitly track a page view during a session.
         * 
         *  This method increments the page view count for a session when invoked. It does not associate a name
         *  with the page count. To associate a name with a count of occurences see #logEvent:.
         *
         *  @see #logAllPageViews for details on automatically incrementing page view count based on user
         *  traversing navigation or tab bar controller.
         *
         * @related function
         * android: onPageView
         * ios:     logPageView
         *
         */
        static void logPageView();


        /*!
         *  @brief Assign a unique id for a user in your app.
         * 
         *  @note Please be sure not to use this method to pass any private or confidential information
         *  about the user.
         *
         *  @param userID The app id for a user.
         *
         * @related function
         * android: setUserId (String userId)
         * ios:     setUserID:(NSString *)userID
         *
         */
        static void setUserID(std::string& userID);


        /*!
         *  @brief Set your user's age in years.
         * 
         *  Use this method to capture the age of your user. Only use this method if you collect this
         *  information explictly from your user (i.e. - there is no need to set a default value).
         *
         *  @note The age is aggregated across all users of your app and not available on a per user
         *  basis.
         *
         *  @param age Reported age of user.
         *
         * @related function
         * android: setAge (int age)
         * ios:     setAge:(int)age;
         *
         */
        static void setAge(int age);
        

        /*!
         *  @brief Set your user's gender.
         * 
         *  Use this method to capture the gender of your user. Only use this method if you collect this
         *  information explictly from your user (i.e. - there is no need to set a default value). Allowable
         *  values are @c @"m" or @c @"f"
         *
         *  @note The gender is aggregated across all users of your app and not available on a per user
         *  basis.
         *
         *  @param gender Reported gender of user.
         *                  "u" -1 unknow
         *                  "m" 1 male
         *                  "f" 0 female
         *
         *
         * @related function
         * android: setGender (byte gender)
         * ios:     setGender:(NSString *)gender;
         *
         */
        static void setGender(std::string& gender);	// user's gender m or f


        /*!
         * @brief Set whether Flurry should record location via GPS. Defaults to true. valid on android
         *
         * @related function
         * android: setReportLocation (boolean reportLocation)
         *
         */
        static void setReportLocation(bool reportLocation);

        /*!
         *  @brief Set the location of the session.
         * 
         *  Use information from the CLLocationManager to specify the location of the session. Flurry does not
         *  automatically track this information or include the CLLocation framework.
         *
         *  @note Only the last location entered is captured per session. \n
         *  Regardless of accuracy specified, the Flurry SDK will only report location at city level or higher. \n
         *  Location is aggregated across all users of your app and not available on a per user basis. \n
         *  This information should only be captured if it is germaine to the use of your app.
         *
         *
         *  After starting the location manager, you can set the location with Flurry. You can implement
         *  CLLocationManagerDelegate to be aware of when the location is updated. Below is an example 
         *  of how to use this method, after you have recieved a location update from the locationManager.
         *
         *  @param latitude The latitude.
         *  @param longitude The longitude.
         *  @param horizontalAccuracy The radius of uncertainty for the location in meters.
         *          no use on android
         *  @param verticalAccuracy The accuracy of the altitude value in meters.
         *          no use on android
         *
         * @related function
         * android: setLocation (float lat, float lon)
         * ios:     setLatitude:(double)latitude longitude:(double)longitude horizontalAccuracy:(float)horizontalAccuracy verticalAccuracy:(float)verticalAccuracy;
         *
         */
        static void setLatitude(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy);

        /*!
         * @brief clear the default location.valid on andriod
         *
         * @related function
         * android: clearLocation ()
         *
         */
        static void clearLocation();

        /*!
         *  @brief Set session to report when app closes.valid on ios
         * 
         *  Use this method report session data when the app is closed. The default value is @c YES.
         *
         *  @note This method is rarely invoked in iOS >= 3.2 due to the updated iOS lifecycle.
         *
         *  @see #setSessionReportsOnPauseEnabled:
         *
         *  @param sendSessionReportsOnClose YES to send on close, NO to omit reporting on close.
         *
         * @related function
         * ios: setSessionReportsOnCloseEnabled:(bool) sendSessionReportsOnClose
         *
         */
        static void setSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose);


        /*!
         *  @brief Set session to report when app is sent to the background.valid on ios
         * 
         *  Use this method report session data when the app is paused. The default value is @c YES.
         *
         *  @param setSessionReportsOnPauseEnabled YES to send on pause, NO to omit reporting on pause.
         *
         * @related function
         * ios: setSessionReportsOnPauseEnabled:(bool) setSessionReportsOnPauseEnabled
         *
         */
        static void setSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled);


        /*!
         *  @brief Set session to support background execution.valid on ios
         *
         *  Use this method to enable reporting of errors and events when application is 
         *  running in backgorund (such applications have  UIBackgroundModes in Info.plist).
         *  You should call #pauseBackgroundSession when appropriate in background mode to 
         *  pause the session (for example when played song completed in background)
         *
         *  Default value is @c NO
         *
         *  @see #pauseBackgroundSession for details
         *
         *  @param setBackgroundSessionEnabled YES to enbale background support and 
         *  continue log events and errors for running session.
         *
         * @related function
         * ios:         setBackgroundSessionEnabled:(bool) setBackgroundSessionEnabled
         *
         * @
         */
        static void setBackgroundSessionEnabled(bool setBackgroundSessionEnabled);

        /*!
         *  @brief Enable custom event logging.
         * 
         *  Use this method to allow the capture of custom events. The default value is @c YES.
         *
         *  @param value YES to enable event logging, NO to stop custom logging.
         *
         * @related function
         * android:     setLogEvents (boolean logEvents)
         * ios:         setEventLoggingEnabled:(bool) value
         *
         */
        static void setEventLoggingEnabled(bool value);


        /*!
         *  @brief Enables Flurry Pulse
         *
         *  @note: Please see https://developer.yahoo.com/flurry-pulse/ for more details
         *
         *  @param value YES to enable event logging, NO to stop custom logging.
         *
         *
         * @related function
         * android:     setPulseEnabled (boolean isEnabled)
         * ios:         setPulseEnabled:(BOOL)value;
         *
         */
        static void setPulseEnabled(bool value);


        /*!
         * @brief set listener for session callback
         *
         */
        static void setListener(FlurryAnalyticsListener *listener);


        /*!
         * @brief get listener
         *
         */
        static FlurryAnalyticsListener* getListener();

        /*!
         * @brief remove listener, just set null, will not delete it
         *         the user should delete listener self 
         *
         */
        static void removeListener();


    #ifdef OBFUSCATED
        _fde6d02d541f4f1ab57ec133f7e74444
    #endif

    };

}

#endif