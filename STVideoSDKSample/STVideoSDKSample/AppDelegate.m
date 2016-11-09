//
//  AppDelegate.m
//  STVideoSDKSample
//
//  Created by East on 15/7/22.
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import "AppDelegate.h"
#import "STVideoSDK.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    // 注册 SDK
    [STVideoSDK registerSDKWithPublishedId:@"2"
                                     appId:@"36"
                               placementId:@"40"
                                    appKey:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"];
    
    return YES;
}

@end
