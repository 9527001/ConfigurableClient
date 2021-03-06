//
//  HHCache.h
//  HHKit
//
//  Created by liuwenjie on 16/7/31.
//  Copyright © 2016年 HHAuto. All rights reserved.
//
//  对象缓存

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, HHCacheOption) {
    HHCacheOptionMemoryAndDisk,//default
    HHCacheOptionMemoryOnly,
    HHCacheOptionDiskOnly
};

NS_ASSUME_NONNULL_BEGIN

@interface HHCache : NSObject

@property (nonatomic, strong) NSString *path;
@property (nonatomic, strong) NSString *maxMemoryCacheSize;//默认100M,当超过100M时则自动清空


+ (instancetype)sharedInstance;

/**
 *  保存归档对象到磁盘并且内存缓存此对象,对象必须实现归档协议
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;
/**
 *  根据指定缓存协议来缓存对象,对象必须实现归档协议
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key option:(HHCacheOption)option;

/**
 *  获取归档对象,先取内存缓存,如果没有则取磁盘缓存
 */
- (id)objectForKey:(NSString *)key;
/**
 *  根据指定缓存协议来获取对象
 */
- (id)objectForKey:(NSString *)key option:(HHCacheOption)option;

/**
 *  移除指定缓存(磁盘和内存)
 */
- (void)removeObjectForKey:(NSString *)key;
/**
 *  移除指定缓存协议和key对应的缓存对象
 */
- (void)removeObjectForKey:(NSString *)key option:(HHCacheOption)option;

/**
 *  移除所有缓存(磁盘和内存)
 */
- (void)removeAllObjects;

NS_ASSUME_NONNULL_END
@end
