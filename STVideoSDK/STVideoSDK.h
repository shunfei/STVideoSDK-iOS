//
//  STVideoSDK.h
//  STVideoSDK
//
//  Created by 许忠洲 on 15/11/9.
//  Copyright © 2015年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface STVideoSDK : NSObject

#pragma mark - 通用 API

/**
 *  注册 SDK
 *
 *  @param publishedId published ID
 *  @param appId       app ID
 *  @param placementId placement ID
 */
+ (void)registerSDKWithPublishedId:(NSString *)publishedId
                             appId:(NSString *)appId
                       placementId:(NSString *)placementId;

/**
 *  是否有视频广告
 *
 *  @param completionHandler 0：有视频可以播放
 *                           1：暂时没有可播放视频
 *                           2：API调用失败
 */
+ (void)isHaveVideo:(void (^ __nullable)(int state))completionHandler;

/**
 *  Wi-Fi下预加载广告资源文件。默认不开启，使用改方法后开启。
 */
+ (void)preDownloadResourcesAtWifiNetwork;

#pragma mark - 全屏广告 API

+ (void)presentVideoPlayerViewControllerInViewController:(UIViewController *)viewController
                    videoPlayFinishWithCompletionHandler:(void (^ __nullable)(int state))completionHandler;

#pragma mark - 非全屏广告 API

+ (void)videoPlay:(UIViewController *)viewController videoSuperView:(UIView *)superView videoPlayFinishWithCompletionHandler:(void (^ __nullable)(void))completionHandler clickDownloadHandler:(void (^ __nullable)(void))clickHandler;
+ (void)playVideo;
+ (void)pauseVideo;

/**
 *  是否显示关闭视频广告按钮，默认为 No
 *
 *  @param isShow YES or NO
 */
+ (void)showCloseVideoButton:(BOOL)isShow;

/**
 *  设置退出视频广告提示框的提示内容，默认为“退出视频”
 *
 *  @param content Alert 提示语内容
 */
+ (void)setupAlertViewContent:(nullable NSString *)content;

@end

NS_ASSUME_NONNULL_END
