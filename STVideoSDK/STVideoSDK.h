//
//  MobileAdSDK.h
//  MobileAdSDK
//
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface STVideoSDK : NSObject

/**
 *  SDK初始化
 *
 *  @param publishedId    发布商id
 *  @param appId          appid
 *  @param placementId    广告位id
 */
+ (void)initSDKWithPublishedId:(NSString *)publishedId AppId:(NSString *)appId PlacementId:(NSString *)placementId;

/**
 *  播放视频广告
 *
 *  @param  vctl     播放视频广告的viewcontroller
 *  @param  block    处理回调
 *
 *  @return state    状态码  //0 其他错误;
 *                          //1 广告视频播放完成，SDK关闭;
 *                          //2 广告视频被跳过，SDK关闭;
 *                          //3 广告素材下载失败，SDK关闭;
 *                          //4 广告数据获取成功，后端返回无广告素材;
 *                          //5 网络问题，广告API调用失败;
 *
 */
+ (void)videoPlay:(UIViewController *)vctl videoPlayFinishCallBackBlock:(void (^)(int state))block;

@end
