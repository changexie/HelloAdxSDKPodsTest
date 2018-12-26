//
//  HelloAdxAdView.h
//  AdxHomeSDK
//
//  Created by Frank on 2018/8/14.
//  Copyright © 2018年 HelloAdx. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface HelloAdxAdView : UIView

/**
 是否在需要的情况下布局父控件
 
 if (adView.isAllowedLayoutSuperviewIfNeeded) {
    [adView.superview setNeedsLayout];
    [adView.superview layoutIfNeeded];
 }
 */
@property (nonatomic, assign, getter=isAllowedLayoutSuperviewIfNeeded) BOOL allowLayoutSuperviewIfNeeded; // default is YES.

/**
 HelloAdxAdView涉及重用时(tableview的cell中使用adview), 需要调用此方法
 */
- (void)removeAllViews;

/**
 视频素材开始播放(广告展示出来的时候会自动开始播放)
 */
- (void)start;

/**
 视频素材暂停播放
 */
- (void)pause;

/**
 视频素材恢复播放
 */
- (void)resume;

/**
 视频素材停止播放
 */
- (void)stop;

@end
