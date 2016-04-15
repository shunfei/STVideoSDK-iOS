//
//  ViewController.m
//  STVideoSDKSample
//
//  Created by East on 15/7/22.
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import "STVideoSDK.h"
#import "ViewController.h"
#import "STMNonfullScreenViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)playFullScreenVideo:(id)sender
{
    [STVideoSDK showCloseVideoButton:YES];
    [STVideoSDK setupAlertViewContent:@"我是自定义的提示内容？"];
    [STVideoSDK presentVideoPlayerViewControllerInViewController:self
                            videoPlayFinishWithCompletionHandler:nil];
}

- (IBAction)playNonScreenVideo:(id)sender
{
    STMNonfullScreenViewController *vc = [[STMNonfullScreenViewController alloc] init];
    vc.isShow = YES;
    vc.content = @"我是自定义的提示内容？";
    [self.navigationController pushViewController:vc animated:YES];
}

@end
