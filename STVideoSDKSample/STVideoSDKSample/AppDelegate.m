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
    [STVideoSDK registerSDKWithPublishedId:@"2"
                                     appId:@"7"
                               placementId:@"6"];
    
    return YES;
}

@end
