# 视频广告 iOS SDK 2.0.3 开发文档

## 开发环境

* Xcode 7.0 或更高版本。
* 支持 iOS 6.0.0 或更高版本。

## PublisherID、PlacementID、AppID

从 [官网](http://mbv.biddingx.com/main/) 获取 PublisherID、PlacementID、AppID。

## SDK 集成

1、将 SDK 的发行版本中的头文件 `STVideoSDK.h` 、静态库 `libSTVideoSDK.a` 以及资源文件 `STVideoSDK.bundle` 添加到项目中。

2、需要添加的 Framework ：

```objc
AdSupport.framework
AVFoundation.framework
CoreGraphics.framework
CoreLocation.framework
CoreMedia.framework
CoreTelephony.framework
Foundation.framework
MobileCoreServices.framework
QuartzCore.framework
Security.framework
SystemConfiguration.framework
UIKit.framework
libz.tbd
```

3、设置对应 **target** 的编译选项，在『Build Settings』->『Linking』->『Other Linker Flags』，添加 `-ObjC` 参数。

4、iOS 8.0+ 中获取地理位置方法，在 info.plist 里加入对应的定位请求字段，值可以为空或者填写获取定位请求提示框要显示的内容。

```XML
<key>NSLocationWhenInUseUsageDescription</key>
<string>iOS 8 定位权限请求提示语！</string>
<key>NSLocationUsageDescription</key>
<string>iOS 10 定位权限请求提示语！</string>
```

**说明：由于部分广告会定向投递到某些城市，SDK 需要获取地理位置以支持广告的定向投放。**

5、Xcode 7.0+ 、iOS 9.0+ 适配

* 关于 [*ATS*](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240)

	**解决方案：禁用 ATS。**

	在应用的 Info.plist 中添加禁用 ATS 代码。代码如下：

```XML
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
</dict>
```

* 关于 Bitcode

	Xcode 7 默认开启 **Bitcode** 编译选项（无 **Bitcode** 配置，默认为开启），SDK 1.2.3+ 版本开始支持 **Bitcode** ，如果您的工程中有其它不支持 **Bitcode** 特性的库可能编译不过。

	**解决方案：请将项目对应 『Target』->『Build Settings』->『Build Options』->『Enable Bitcode』选项设置为 No 。**

## SDK 使用

### 全屏视频广告

#### 初始化 SDK

在应用 `AppDelegate.m` 的 `application:didFinishLaunchingWithOptions:` 方法中初始化视频 SDK

```objc
#import "STVideoSDK.h"

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions {
    [STVideoSDK registerSDKWithPublishedId:@"2" appId:@"36" placementId:@"40" appKey:@"Ac7Kd3lJ^KQX9Hjkn_Z(UO9jqViFh*q1"];
    return YES;
}
```
	
#### 展示全屏视频广告

```objc
[STVideoSDK presentVideoPlayerViewControllerInViewController:self
                        videoPlayFinishWithCompletionHandler:^(int state) {
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
            NSLog(@"服务端返回无广告素材——返量，SDK关闭。");
            break;
        case 5:
            NSLog(@"网络问题，广告 API 调用失败。");
            break;
        case 6:
            NSLog(@"服务端返回无广告素材——留白，SDK关闭。");
            break;
    }];
```

**返回状态码定义**

```shell
0	发生其他错误，SDK 关闭。
1	广告视频播放完成，SDK关闭。
2	广告视频被跳过，SDK关闭。
3	广告素材下载失败，SDK关闭。
4	返量，SDK 关闭（无广告素材）。
5	网络问题，广告 API 调用失败，SDK 关闭。
6	留白，SDK关闭（无广告素材）。
```

#### 提前获取广告数据、Wi-Fi 网络下提前下载广告资源、全网强制下载广告资源

```objc
// 提前获取广告数据
[STVideoSDK isHaveVideo:^(int state) {}];

// Wi-Fi 网络下提前下载广告资源
[STVideoSDK preDownloadResourcesAtWifiNetwork];

// 全网强制下载广告资源
[STVideoSDK forcedDownloadResources];

// 检查是否有已经下载完素材，能直接播放的视频广告
BOOL isReadyForPlay = [STVideoSDK isReadyForPlay];
if (isReadyForPlay) {
    [STVideoSDK presentVideoPlayerViewControllerInViewController:self
                            videoPlayFinishWithCompletionHandler:^(int state) {}];
}
```

#### 全屏视频广告 Delegate

```objc
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
```

---

### 非全屏视频广告

#### 初始化 SDK

在应用 `AppDelegate.m` 的 `application:didFinishLaunchingWithOptions:` 方法中初始化视频 SDK

```objc
#import "STVideoSDK.h"

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions {
    [STVideoSDK registerSDKWithPublishedId:@"1234" appId:@"2345" placementId:@"1"];
    return YES;
}
```

#### 展示非全屏视频广告

1、先调用以下方法

```objc
[STVideoSDK isHaveVideo:^(int state) {}];
```

2、当回调的 `state == 0` 时，表示有广告可显示，再使用以下方法创建广告

```objc
[STVideoSDK videoPlay:self videoSuperView:self.container videoPlayFinishWithCompletionHandler:nil clickDownloadHandler:nil];
```

3、当将广告添加在 UIScrollView、UITableView 等可滚动的控件上时，请自行在视频滚出屏幕时，使用 `+ (void)playVideo;` 和 `+ (void)pauseVideo;` 方法控制视频的暂停和继续播放。

#### 高级设置

```objc
+ (void)showCloseVideoButton:(BOOL)isShow;
+ (void)setCloseAlertViewContent:(nullable NSString *)content;
```

开发者可以使用以上两个方法，自定义两种广告样式是否在左上角显示广告关闭按钮，以及关闭按钮点击后的提示语。（默认为不显示关闭按钮，默认关闭提示语为“退出视频”。）