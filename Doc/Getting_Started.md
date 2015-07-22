## 视频广告 iOS SDK 1.x 开发文档
### 1.开发环境
- xcode6或更高版本。
- 运行环境为ios7.0或更高版本。

### 2.从sunteng官网获取PublisherID & PlacementID & AppID
![pic1]()

### 3.添加SDK到项目中
> SDK 的发行版本中需要添加到项目中的文件包括1个静态库、1个头文件以及1个 Bundle 文件。 

- 将上述文件,添加到您的项目中。建议直接将“MobileAdSDK”文件夹添加到项目中。 包含的内容,如下图:

![pic2]()

- 需要添加的Framework：

![pic3]()

- 更改导入静态库设置，点击程序Target文件，选择Build Settings标签页，找到Linking下面的Other Linker Flags，添加参数-all_load。

![pic4]()

- iOS8中获取地理位置方法,在 info.plist里加入对应的缺省字段 ，值设置为YES。
> NSLocationWhenInUseUsageDescription   //允许在前台获取GPS的描述
> NSLocationAlwaysUsageDescription   //允许在前、后台获取GPS的描述 
> 说明:由于部分广告会定向投递到某些城市, SDK 需要获取地理位置以支持广告的定向投放。 

### 4.视频广告的使用
###### 1.在应用初始化中初始化视频sdk
	[MobileAdSDK initSDKWithPublishedId:@"1234" AppId:@"2345" PlacementId:@“1"];
###### 2.需要播放视频的地方调用
	[MobileAdSDK MVAVideoPlay:self videoPlayFinishCallBackBlock:^(BOOL isFinished){
			 if (isFinished)
			 {
				 NSLog(@“视频播放结束！");
			 }
			 else
			 {
				 NSLog(@“视频播放中断！");
			 }
		  }];
