//
//  ViewController.m
//  STVideoSDKSample
//
//  Created by East on 15/7/22.
//  Copyright (c) 2015年 sunteng. All rights reserved.
//

#import "ViewController.h"
#import "MobileAdSDK.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [MobileAdSDK initSDKWithPublishedId:@"2" AppId:@"1" PlacementId:@"1"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)playVideo:(id)sender
{
    [MobileAdSDK MVAVideoPlay:self videoPlayFinishCallBackBlock:^(BOOL isFinished){
        if (isFinished)
        {
            NSLog(@"---------video play finished!-------");
        }
        else
        {
            NSLog(@"---------video play not finished!---------");
        }
    }];
}


@end
