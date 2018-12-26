//
//  HelloAdx.h
//  HelloAdxSDK
//
//  Created by bltech on 2018/10/24.
//  Copyright © 2018年 HelloAdx. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HelloAdxAdView, HelloAdxNative;

@protocol HelloAdxAdLoadDelegate <NSObject>

- (void)onAdLoadedWithAdID:(NSString *)adID adNative:(HelloAdxNative *)adNative andAdCtx:(NSString *)adCtx;
- (void)onAdLoadErrorWithAdID:(NSString *)adID code:(NSInteger)code andMsg:(NSString *)msg;

@end // HelloAdxAdLoadDelegate

@protocol HelloAdxAdShowDelegate <NSObject>

- (void)onAdShowWithAdView:(HelloAdxAdView *)adView adID:(NSString *)adID andAdCtx:(NSString *)adCtx;
- (void)onAdClickWithAdView:(HelloAdxAdView *)adView adID:(NSString *)adID andAdCtx:(NSString *)adCtx;
- (void)onAdActionWithAdView:(HelloAdxAdView *)adView adID:(NSString *)adID andAdCtx:(NSString *)adCtx;
- (void)onAdCloseWithAdView:(HelloAdxAdView *)adView adID:(NSString *)adID andAdCtx:(NSString *)adCtx;
- (void)onAdShowErrorWithAdView:(HelloAdxAdView *)adView adID:(NSString *)adID adCtx:(NSString *)adCtx code:(NSInteger)code andMsg:(NSString *)msg;

@end // HelloAdxAdShowDelegate

@interface HelloAdx : NSObject

+ (instancetype)sharedInstance;

- (BOOL)initializeSDKWithAppKey:(NSString *)appkey;
- (BOOL)isInitializedSDK;
- (BOOL)releaseSDK;

- (BOOL)loadAdWithAdID:(NSString *)adID andAdLoadDelegate:(id<HelloAdxAdLoadDelegate>)adLoadDelegate;
- (BOOL)loadAdWithAdID:(NSString *)adID isNative:(BOOL)isNative andAdLoadDelegate:(id<HelloAdxAdLoadDelegate>)adLoadDelegate;
- (BOOL)showAdWithAdView:(HelloAdxAdView*)adView adID:(NSString *)adID adCtx:(NSString *)adCtx andAdShowDelegate:(id<HelloAdxAdShowDelegate>)adShowDelegate;

@end // HelloAdx
