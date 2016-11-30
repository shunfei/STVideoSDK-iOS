//
//  STVideoSDK.h
//  STVideoSDK
//
//  Created by Joe on 15/11/9.
//  Copyright © 2015年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol STFullScreenVideoSDKDelegate <NSObject>

@optional

// 全屏视频广告资源加载成功
- (void)fullScreenVideoDidLoad;

// 全屏视频广告资源加载失败
- (void)fullScreenVideoDidLoadFail;

// 全屏视频广告展示成功
- (void)fullScreenVideoDidPresent;

// 全屏视频广告完整播放
- (void)fullScreenVideoDidFullPlay;

// 广告被点击
- (void)fullScreenVideoDidTap;

// 广告关闭
- (void)fullScreenVideoDidDismiss;

@end

@interface STVideoSDK : NSObject

#pragma mark - 通用 API

/**
 *  注册 SDK
 *
 *  @param publishedId published ID
 *  @param appId       app ID
 *  @param placementId placement ID
 *  @param appKey      appKey
 */
+ (void)registerSDKWithPublishedId:(NSString *)publishedId
                             appId:(NSString *)appId
                       placementId:(NSString *)placementId
                            appKey:(NSString *)appKey;

/**
 *  是否有视频广告
 *
 *  @param completionHandler 0：有视频可以播放
 *                           1：暂时没有可播放视频 - 返量
 *                           2：API调用失败
 *                           3: 留白
 */
+ (void)isHaveVideo:(void (^ __nullable)(int state))completionHandler;

/**
 *  Wi-Fi下预加载广告资源文件。默认不开启，使用该方法后开启。
 */
+ (void)preDownloadResourcesAtWifiNetwork;

/**
 *  不区分网络环境，获取广告成功后强制下载广告资源。默认不开启，使用该方法后开启。
 */
+ (void)forcedDownloadResources;

/**
 *  关闭位置广告。
 *  需要在注册 SDK 后，请求广告前使用。
 */
+ (void)disableLocationServices;

#pragma mark - 全屏广告 API

/**
 *  是否已经下载完广告资源，可以直接播放
 *
 *  @return 是否可以直接播放
 */
+ (BOOL)isReadyForPlay;

/**
 *  展示全屏视频广告
 *
 *  @param viewController    从该视图控制器展示广告
 *  @param completionHandler 视频广告相关事件回调
 */
+ (void)presentVideoPlayerViewControllerInViewController:(UIViewController *)viewController
                    videoPlayFinishWithCompletionHandler:(void (^ __nullable)(int state))completionHandler;

+ (instancetype)sharedInstance;

@property (nullable, nonatomic, weak) id<STFullScreenVideoSDKDelegate> delegate;




#pragma mark - 非全屏广告 API

/**
 *  在视图控制器的某个视图上添加非全屏视频广告
 *
 *  @param viewController    从该视图控制器展示广告
 *  @param superView         非全屏广告播放器的父视图（容器）
 *  @param completionHandler 视频广告相关事件回调
 *  @param clickHandler      视频点击交互相关回调
 */
+ (void)videoPlay:(UIViewController *)viewController videoSuperView:(UIView *)superView videoPlayFinishWithCompletionHandler:(void (^ __nullable)(void))completionHandler clickDownloadHandler:(void (^ __nullable)(void))clickHandler;

/**
 *  播放视频
 */
+ (void)playVideo;

/**
 *  暂停视频
 */
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
