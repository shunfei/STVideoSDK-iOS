# 视频广告 iOS SDK 2.x 开发文档

## 1、开发环境

* Xcode 6.0 或更高版本。
* 支持 iOS 6.0.0+。

## 2、从 sunteng 官网获取 PublisherID、PlacementID、AppID

![pic1](https://github.com/shunfei/STVideoSDK-iOS/blob/master/Doc/pic1.png)

## 3、添加 SDK 到项目中

**SDK 的发行版本中需要添加到项目中的文件包括1个静态库、1个头文件以及1个 Bundle 文件。**

* 将上述文件，添加到您的项目中。建议直接将**STVideoSDK**文件夹添加到项目中。包含的内容，如下图：

![pic2](https://github.com/shunfei/STVideoSDK-iOS/blob/master/Doc/pic2.png)

* 需要添加的Framework：

![pic3](https://github.com/shunfei/STVideoSDK-iOS/blob/master/Doc/pic3.png)

* 更改导入静态库设置，点击程序 **Target** 文件，选择 **Build Settings** 标签页，找到 ** Linking** 下面的 **Other Linker Flags** ，添加参数 `-ObjC` 。

![pic4](https://github.com/shunfei/STVideoSDK-iOS/blob/master/Doc/pic4.png)

* iOS 8 中获取地理位置方法，在 info.plist 里加入对应的定位请求字段，值可以为空或者填写获取定位请求提示框要显示的内容。

```objc
NSLocationWhenInUseUsageDescription   // 允许在前台获取GPS的描述
NSLocationAlwaysUsageDescription   // 允许在前、后台获取GPS的描述 
```

**说明：由于部分广告会定向投递到某些城市，SDK 需要获取地理位置以支持广告的定向投放。**

*Xcode 7、iOS 9 适配*

* 关于 [*ATS*](https://developer.apple.com/library/prerelease/ios/technotes/App-Transport-Security-Technote/index.html#//apple_ref/doc/uid/TP40016240)

**解决方案1：禁用 ATS。**

在应用的 Info.plist 中添加禁用 ATS 代码。代码如下：

```XML
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
</dict>
```

**解决方案2：除特殊情况外，都不使用 ATS。即，仅在您自己支持 ATS 的服务上使用 ATS。**

在应用的 Info.plist 中添加支持 ATS API 域名的代码（以 api.biddingx.com 为例），其他 API 请求不使用 ATS。

```XML
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
	<key>NSExceptionDomains</key>
	<dict>
		<key>api.biddingx.com</key>
		<dict>
			<key>NSExceptionAllowsInsecureHTTPLoads</key>
			<false/>
		</dict>
	</dict>
</dict>
```

* 关于 Bitcode

Xcode 7 默认开启 Bitcode 编译选项（无Bitcode配置，默认为开启），SDK 1.2.3+版本开始支持 Bitcode，如果您的工程中有其它不支持 bitcode 特性的库可能编译不过。

**解决方案：请将项目对应 Target -> Build Settings -> Build Options -> Enable Bitcode 选项设置为 No**

## 4、视频广告的使用

### 4.1 广告样式1（全屏模态视频广告）

1、在应用 `AppDelegate.m` 的 `application:didFinishLaunchingWithOptions:` 方法中初始化视频 SDK

```objc
[STVideoSDK initSDKWithPublishedId:@"1234" AppId:@"2345" PlacementId:@"1"];
```
	
2、需要播放视频的地方调用

```objc
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
```

 3、返回状态码定义

```shell
0 发生其他错误，SDK 关闭。
1 广告视频播放完成，SDK关闭。
2 广告视频被跳过，SDK关闭。
3 广告素材下载失败，SDK关闭。
4 广告数据获取成功，服务端返回无广告素材，SDK 关闭。
5 网络问题，广告 API 调用失败，SDK 关闭。
```

### 4.2 广告样式2（自定义大小，可全屏的视频广告）

1、在应用 `AppDelegate.m` 的 `application:didFinishLaunchingWithOptions:` 方法中初始化视频 SDK

```objc
[STVideoSDK initSDKWithPublishedId:@"1234" AppId:@"2345" PlacementId:@"1"];
```

2、需要播放视频的地方，先调用以下方法

```objc
[STVideoSDK isHaveVideo:^(int state) {}];
```

当回调的 `state == 0` 时，表示有广告可显示，再使用以下方法创建广告

```objc
[STVideoSDK videoPlay:viewController videoSuperView:self.container videoPlayFinishWithCompletionHandler:nil clickDownloadHandler:nil];
```

3、当将广告添加在 UIScrollView、UITableView 等可滚动的控件上时，请自行在视频滚出屏幕时，使用 `+ (void)playVideo;` 和 `+ (void)pauseVideo;` 方法控制视频的暂停和继续播放。

### 4.3 高级设置

```objc
+ (void)showCloseVideoButton:(BOOL)isShow;
+ (void)setCloseAlertViewContent:(nullable NSString *)content;
```

开发者可以使用以上两个方法，自定义两种广告样式是否在左上角显示广告关闭按钮，以及关闭按钮点击后的提示语。（默认为不显示关闭按钮，默认关闭提示语为“退出视频”。）