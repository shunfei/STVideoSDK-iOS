//
//  ViewController.m
//  STVideoSDKSample
//
//  Created by East on 15/7/22.
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import "ViewController.h"
#import "STVideoSDK.h"
#import "STMNonfullScreenViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // 开启广告资源 Wi-Fi 下提前下载
    [STVideoSDK preDownloadResourcesAtWifiNetwork];
    
    // 手动触发获取广告数据请求
    [STVideoSDK isHaveVideo:^(int state) {}];
}

- (IBAction)playFullScreenVideo:(id)sender
{
    // 检查是否有已经下载完素材，能直接播放的视频广告
    BOOL isReadyForPlay = [STVideoSDK isReadyForPlay];
    if (isReadyForPlay) {
        [STVideoSDK showCloseVideoButton:YES];
        [STVideoSDK setupAlertViewContent:@"我是自定义的提示内容？"];
        [STVideoSDK presentVideoPlayerViewControllerInViewController:self
                                videoPlayFinishWithCompletionHandler:nil];
    }
}

- (IBAction)playNonScreenVideo:(id)sender
{
    STMNonfullScreenViewController *vc = [[STMNonfullScreenViewController alloc] init];
    vc.isShow = YES;
    vc.content = @"我是自定义的提示内容？";
    [self.navigationController pushViewController:vc animated:YES];
}

@end
