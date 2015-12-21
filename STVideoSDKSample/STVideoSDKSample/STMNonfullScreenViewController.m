//
//  STMNonfullScreenViewController.m
//  STVideoSDKSample
//
//  Created by 许忠洲 on 15/12/9.
//  Copyright © 2015年 Sunteng Information Technology Co., Ltd. All rights reserved.
//

#import "STMNonfullScreenViewController.h"
#import "STVideoSDK.h"

@interface STMNonfullScreenViewController ()

//用户自定义的view，用来播放视频广告
@property (nonatomic, strong) UIView *containerView;

@end

@implementation STMNonfullScreenViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    //自定义view的大小、位置、autolayout
    _containerView = [[UIView alloc] init];
    _containerView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.containerView];
    
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:_containerView attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterX multiplier:1.0 constant:0.0]];
    
    // center _containerView vertically in self.view
    [self.view addConstraint:[NSLayoutConstraint constraintWithItem:_containerView attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:self.view attribute:NSLayoutAttributeCenterY multiplier:1.0 constant:0.0]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:[_containerView(==220)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(_containerView)]];
    
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[_containerView(==140)]" options:0 metrics:nil views:NSDictionaryOfVariableBindings(_containerView)]];
    
    
    // Do any additional setup after loading the view.
    if ([self respondsToSelector:@selector(setAutomaticallyAdjustsScrollViewInsets:)]) {
        self.automaticallyAdjustsScrollViewInsets = NO;
    }
    
    [STVideoSDK showCloseVideoButton:self.isShow];
    [STVideoSDK setCloseAlertViewContent:self.content];
    [STVideoSDK isHaveVideo:^(int state) {
        if (state == 0) {
            [STVideoSDK videoPlay:self videoSuperView:self.containerView videoPlayFinishWithCompletionHandler:nil clickDownloadHandler:nil];
        }
    }];
}

@end
