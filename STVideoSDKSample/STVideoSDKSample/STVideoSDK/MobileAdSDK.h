//
//  MobileAdSDK.h
//  MobileAdSDK
//
// 
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MobileAdSDK : NSObject

/**
 *  SDK初始化
 *
 *  @param publishedId 发布商id
 *  @param appId       appid
 *  @param placementId 广告位id
 */
+ (void)initSDKWithPublishedId:(NSString*)publishedId AppId:(NSString*)appId PlacementId:(NSString*)placementId;

/**
 *  视频广告调起请求
 *
 *  @param vctl  当前viewcontroller
 *  @param block 视频播放回调
 */
+(void)MVAVideoPlay:(UIViewController *)vctl videoPlayFinishCallBackBlock:(void(^)(BOOL isFinished))block;

@end
