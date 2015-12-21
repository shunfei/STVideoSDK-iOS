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

/**
 *  SDK初始化
 *
 *  @param publishedId    发布商id
 *  @param appId          appid
 *  @param placementId    广告位id
 */
+ (void)registerSDKWithPublishedId:(NSString *)publishedId
                             appId:(NSString *)appId
                       placementId:(NSString *)placementId;


/*****************************全屏广告 API*************************************/

/**
 *  播放视频广告(全屏)
 *
 *  @param  viewController    播放视频广告的viewcontroller
 *  @param  completionHandler 处理回调
 *
 *  @return state    状态码  //0 发生其他错误，SDK 关闭;
 *                          //1 广告视频播放完成，SDK关闭;
 *                          //2 广告视频被跳过，SDK关闭;
 *                          //3 广告素材下载失败，SDK关闭;
 *                          //4 广告数据获取成功，后端返回无广告素材;
 *                          //5 网络问题，广告API调用失败;
 */
+ (void)presentVideoPlayerViewControllerInViewController:(UIViewController *)viewController
                    videoPlayFinishWithCompletionHandler:(void (^ __nullable)(int state))completionHandler;

/****************************************************************************/


/****************************非全屏广告 API************************************/

/**
 *  是否有视频广告
 *
 *  @param completionHandler 回调
 *  
 *  @return state //0：有视频可以播放
 *                //1：暂时没有可播放视频
 *                //2：获取API失败
 */
+ (void)isHaveVideo:(void (^ __nullable)(int state))completionHandler;

/**
 *  播放视频广告(非全屏)
 *
 *  @param viewController    播放视频广告的viewcontroller
 *  @param superView         用于播放视频广告的view，可以自定义大小及位置
 *  @param completionHandler 视频播放完成的回调
 *  @param clickHandler      点击下载后的回调
 */
+ (void)videoPlay:(UIViewController *)viewController videoSuperView:(UIView *)superView videoPlayFinishWithCompletionHandler:(void (^ __nullable)(void))completionHandler clickDownloadHandler:(void (^ __nullable)(void))clickHandler;

//当将广告添加在 UIScrollView、UITableView 等可滚动的控件上时，请自行在视频滚出屏幕时，使用 + (void)playVideo; 和 + (void)pauseVideo; 方法控制视频的暂停和继续播放。

/**
 *  播放视频广告
 */
+ (void)playVideo;

/**
 *  暂停视频广告
 */
+ (void)pauseVideo;

/**
 *  控制视频广告关闭按钮
 *
 *  @param isShow 是否显示关闭按钮，默认为 No
 */
+ (void)showCloseVideoButton:(BOOL)isShow;


/**
 *  设置退出视频广告提示框的提示内容
 *
 *  @param content 自定义提示内容，填空则默认为“退出视频”
 */
+ (void)setCloseAlertViewContent:(nullable NSString *)content;


/****************************************************************************/

@end

NS_ASSUME_NONNULL_END
