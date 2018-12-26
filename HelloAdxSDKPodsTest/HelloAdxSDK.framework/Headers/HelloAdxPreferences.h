//
//  HelloAdxPreferences.h
//  HelloAdxSDK
//
//  Created by bltech on 2018/12/26.
//  Copyright © 2018年 HelloAdx. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HelloAdxPreferences : NSObject

+ (BOOL)isNumberForKey:(NSString *)key;
+ (BOOL)setNumber:(double)val forKey:(NSString *)key;
+ (double)numberForKey:(NSString *)key usingDefaultValue:(double)val;

+ (BOOL)isBoolForKey:(NSString *)key;
+ (BOOL)setBool:(BOOL)val forKey:(NSString *)key;
+ (BOOL)boolForKey:(NSString *)key usingDefaultValue:(BOOL)val;

+ (BOOL)isStringForKey:(NSString *)key;
+ (BOOL)setString:(NSString *)val forKey:(NSString *)key;
+ (NSString *)stringForKey:(NSString *)key usingDefaultValue:(NSString *)val;

+ (BOOL)isNilForKey:(NSString *)key;
+ (BOOL)setNilforKey:(NSString *)key;
+ (BOOL)nilForKey:(NSString *)key;

+ (BOOL)containsValueForKey:(NSString *)key;
+ (void)removeValueForKey:(NSString *)key;
+ (void)clear;

@end
