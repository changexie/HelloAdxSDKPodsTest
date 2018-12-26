//
//  HelloAdxNative.h
//  HelloAdxSDK
//
//  Created by bltech on 2018/12/7.
//  Copyright © 2018年 HelloAdx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface HelloAdxMaterial : NSObject

@property (nonatomic, copy) NSString *url;
@property (nonatomic, assign) NSInteger w;
@property (nonatomic, assign) NSInteger h;
@property (nonatomic, assign) NSInteger type;

@end // HelloAdxMaterial


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

- (void)exposeAdWithView:(UIView *)v;
- (void)clickAdWithView:(UIView *)v atViewPoint:(CGPoint)vp andWindowPoint:(CGPoint)wp;
- (void)videoPlayWithView:(UIView *)v;
- (void)videoCompleteWithView:(UIView *)v;

@end // HelloAdxNative
