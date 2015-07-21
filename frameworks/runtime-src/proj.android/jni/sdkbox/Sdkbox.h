/****************************************************************************
 
 Copyright (c) 2014-2015 Chukong Technologies
 
 ****************************************************************************/

#ifndef _CC_SDKBOX_H_
#define _CC_SDKBOX_H_

#define SDKBOX_ENV(projectType) static sdkbox::Sdkbox a847d3a56731602fd63dc63307c12896 = \
 									   sdkbox::Sdkbox(projectType)
namespace sdkbox
{
    class Sdkbox
    {
    public:
    	// @brief
    	Sdkbox(const char *projectType);
        
        // @brief initialize all services
        static void init();
        
        // @brief set project type lua,js or cpp, cpp is default
        static void setProjectType(const char* type);

        // @brief get sdkbox version string
        static const char* getVersionStr();
        
        // @brief get sdkbox version int
        static int getVersion();

    };
    
    namespace device
    {
        const char* getAdvertisingIdentifier();
        bool isAdvertisingTrackingEnabled();
    }
}

#endif//_CC_SDKBOX_H_