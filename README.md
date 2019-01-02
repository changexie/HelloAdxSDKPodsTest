# HelloAdxSDK

##### <font color="#AE1916">广告展示关键思想：根据开发者提供的HelloAdxAdView，SDK根据广告展示需求往HelloAdxAdView上填充相应的控件。</font>

#### 第一步：确认是否有以下资料及运行环境是否符合
广告参数与文件名称 | 是否必须 | 说明
--------- | --------- | ---------
appkey | 是 | 媒体唯一标识（如果没有，请向运营人员获取）
adid | 是 | 广告位唯一标识（如果灭有，请向运营人员获取）
HelloAdxSDK.framework | 是 | 库文件
HelloAdxSDKSample | 否 | 样例代码

#### 第二步：加入库文件
将HelloAdxSDK.framework放入工程中, 并且在`TARGETS`-`General`-`Embedded Binaries`和`Linked Frameworks and Libraries`完成配置，配置完成后如下图所示。

![HelloAdxSDK.framework配置图片001](/Users/bltech/Desktop/img_001.png)

![HelloAdxSDK.framework配置图片002](/Users/bltech/Desktop/img_002.png)

#### 第三步：Info.plist配置
* http请求支持权限<font color="#AE1916">（必须配置）</font> 

	```
	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>
	```

* 地理位置信息获取权限（可选配置，开启后可以获取更精确的广告投放）

	``` 
	<key>NSLocationWhenInUseUsageDescription</key>
	<string>获取地理位置</string>
	```

说明：地理位置信息获取权限并不一定非要设置这一个，还有其他两个Privacy - Location Always Usage Description与Privacy - Location Always and When In Use Usage Description，只要确保CLLocationManager能正常工作即可

#### 第四步：SDK初始化
``` objc
[[HelloAdx sharedInstance] initializeSDKWithAppKey: AppKey];
```

#### 第五步：广告加载
``` objc
/**
 发起广告加载
 
 @param adID 需要加载的adID
 @param isNative 是否获取原生信息
 @param adLoadDelegate 设置的广告加载代理
 @return 是否成功发起广告加载请求
 */
- (BOOL)loadAdWithAdID:(NSString *)adID 
              isNative:(BOOL)isNative 
     andAdLoadDelegate:(id<HelloAdxAdLoadDelegate>)adLoadDelegate;

// 发起非原生广告加载(等同于上面的方法isNative传入NO)
- (BOOL)loadAdWithAdID:(NSString *)adID
     andAdLoadDelegate:(id<HelloAdxAdLoadDelegate>)adLoadDelegate;
```

<font color="#175778"><h6>广告加载代理HelloAdxAdLoadDelegate</h6></font>
``` objc
/**
 广告加载成功时在主线程回调
 
 @param adID 加载广告时传入的adID
 @param adNative 原生广告信息
 @param adCtx 本次广告加载产生的广告上下文，后续广告操作（如：展示）时使用
 */
- (void)onAdLoadedWithAdID:(NSString *)adID
                  adNative:(HelloAdxNative *)adNative
                  andAdCtx:(NSString *)adCtx;
```
说明：原生广告信息如何使用，详见[加载原生广告附加说明](#加载原生广告附加说明)
<br>

``` objc
/**
 广告加载错误时在主线程回调
 
 @param adID 加载广告时传入的adID
 @param code 错误码
 @param msg 错误信息
 */
- (void)onAdLoadErrorWithAdID:(NSString *)adID
                         code:(NSInteger)code
                       andMsg:(NSString *)msg;
```

#### 第六步：广告展示
``` objc
/**
 发起广告展示，须在主线程调用，若loadAd isNative参数为YES，则该函数会执行失败（无法回调）
 
 @param adView 用于展示广告的adView
 @param adID 加载广告时传入的adID
 @param adCtx 广告加载产生的广告上下文
 @param adShowDelegate 设置的广告展示代理
 @return 是否成功发起广告展示请求
 */
- (BOOL)showAdWithAdView:(HelloAdxAdView *)adView
                    adID:(NSString *)adID
                   adCtx:(NSString *)adCtx
       andAdShowDelegate:(id<HelloAdxAdShowDelegate>)adShowDelegate;
```

<font color="#175778"><h6>广告展示代理HelloAdxAdShowDelegate</h6></font>
``` objc
/**
 广告曝光时在主线程回调
 
 @param adView 广告展示时传入的adView
 @param adID 加载广告时传入的adID
 @param adCtx 广告加载时产生的广告上下文
 */
- (void)onAdShowWithAdView:(HelloAdxAdView *)adView
                      adID:(NSString *)adID
                  andAdCtx:(NSString *)adCtx;
```
``` objc
/**
 广告点击时在主线程回调
 
 @param adView 广告展示时传入的adView
 @param adID 加载广告时传入的adID
 @param adCtx 广告加载时产生的广告上下文
 */
- (void)onAdClickWithAdView:(HelloAdxAdView *)adView
                       adID:(NSString *)adID
                   andAdCtx:(NSString *)adCtx;
```
``` objc
/**
 广告发生A事件时在主线程回调
 
 @param adView 广告展示时传入的adView
 @param adID 加载广告时传入的adID
 @param adCtx 广告加载时产生的广告上下文
 */
- (void)onAdActionWithAdView:(HelloAdxAdView *)adView
                        adID:(NSString *)adID
                    andAdCtx:(NSString *)adCtx;
```
``` objc
/**
 由SDK控制的广告关闭（如开屏倒计时后、点击SDK自带的关闭按钮等）时，在主线程回调，需由媒体控制关闭后的动作
 	
 @param adView 广告展示时传入的adView
 @param adID 加载广告时传入的adID
 @param adCtx 广告加载时产生的广告上下文
 */
- (void)onAdCloseWithAdView:(HelloAdxAdView *)adView
                       adID:(NSString *)adID
                   andAdCtx:(NSString *)adCtx;
```
``` objc
/**
 广告曝光后整个生命周期（点击、展示、事件等）发生错误时，在主线程回调

 @param adView 广告展示时传入的adView
 @param adID 加载广告时传入的adID
 @param adCtx 广告加载时产生的广告上下文
 @param code 错误码
 @param msg 错误信息
 */
- (void)onAdShowErrorWithAdView:(HelloAdxAdView *)adView
                           adID:(NSString *)adID
                          adCtx:(NSString *)adCtx
                           code:(NSInteger)code
                         andMsg:(NSString *)msg;
```

#### 第七步：HelloAdxAdView 状态控制（非原生广告视频素材控制）
``` objc
// 视频素材开始播放（广告展示出来的时候会自动开始播放）
- (void)start;

// 视频素材暂停播放
- (void)pause;

// 视频素材恢复播放
- (void)resume;

// 视频素材停止播放
- (void)stop;
```

#### 第八步：SDK退出
``` objc
[[HelloAdx sharedInstance] releaseSDK];
```

#### 附录（<span id="加载原生广告附加说明">加载原生广告附加说明</span>）：
* 在 - (void)onAdLoadedWithAdID:(NSString *)adID adNative:(HelloAdxNative *)adNative andAdCtx:(NSString *)adCtx; 回调中，adNative仅在加载原生广告的时候才有值

* HelloAdxNative使用说明：
	``` objc
	@interface HelloAdxNative : NSObject

	@property (nonatomic, copy, readonly) NSString *title;
	@property (nonatomic, copy, readonly) NSString *subtitle;
	@property (nonatomic, copy, readonly) NSString *desc;
	@property (nonatomic, copy, readonly) NSString *packageName;
	@property (nonatomic, copy, readonly) NSString *appName;
	@property (nonatomic, copy, readonly) NSString *HTMLString;
	@property (nonatomic, assign, readonly) BOOL isHTML;
	@property (nonatomic, strong, readonly) HelloAdxMaterial *icon;
	@property (nonatomic, strong, readonly) NSArray<HelloAdxMaterial *> *materialList;
	
	// 在自己构建的用于显示广告的视图已经显示的时候，调用该方法进行广告的曝光上报
	- (void)exposeAdWithView:(UIView *)v;
	
	/**
	 在自己构建的用于显示广告的视图被点击的时候，调用该方法进行广告的点击上报和完成跳转
	 
	 @param v 显示广告的视图
	 @param vp 在父视图中的点击坐标
	 @param wp 在屏幕中的点击坐标
	 */
	- (void)clickAdWithView:(UIView *)v atViewPoint:(CGPoint)vp andWindowPoint:(CGPoint)wp;
	
	// 视频类素材开始播放的时候，调用该方法
	- (void)videoPlayWithView:(UIView *)v;
	
	// 视频类素材完成播放的时候，调用该方法
	- (void)videoCompleteWithView:(UIView *)v;

	@end // HelloAdxNative
	```
	
* HelloAdxMaterial使用说明:
	``` objc
	@interface HelloAdxMaterial : NSObject

	@property (nonatomic, copy) NSString *url;
	@property (nonatomic, assign) NSInteger w;
	@property (nonatomic, assign) NSInteger h;
	
	/**
	 广告素材类型
	  · 为1，代表素材是图片；
	  · 为2，代表素材是视频流；
	  · 为3，代表素材是GIF。
	 */
	@property (nonatomic, assign) NSInteger type;

	@end // HelloAdxMaterial
	```







