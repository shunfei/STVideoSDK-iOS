//
//  ViewController.m
//  STVideoSDKSample
//
//  Created by East on 15/7/22.
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import "ViewController.h"
#import "STVideoSDK.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [STVideoSDK initSDKWithPublishedId:@"2" AppId:@"7" PlacementId:@"6"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)playVideo:(id)sender
{
    [STVideoSDK videoPlay:self videoPlayFinishCallBackBlock: ^(int state) {
        switch (state) {
            case 0:
                NSLog(@"发生其他错误，SDK 关闭。");
                break;
            case 1:
                NSLog(@"广告视频播放完成，SDK关闭。");
                break;
            case 2:
                NSLog(@"广告视频被跳过，SDK关闭。");
                break;
            case 3:
                NSLog(@"广告素材下载失败，SDK关闭。");
                break;
            case 4:
                NSLog(@"广告数据获取成功，服务端返回无广告素材，SDK关闭。");
                break;
            case 5:
                NSLog(@"网络问题，广告 API 调用失败。");
                break;
        }
    }];
}


@end
