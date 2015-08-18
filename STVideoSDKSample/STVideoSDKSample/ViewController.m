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
    [STVideoSDK initSDKWithPublishedId:@"2" AppId:@"1" PlacementId:@"1"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (IBAction)playVideo:(id)sender
{
    [STVideoSDK videoPlay:self videoPlayFinishCallBackBlock:^(int state){
        if (1 == state)
        {
            NSLog(@"---------video play finished!-------");
        }
    }];
}


@end
