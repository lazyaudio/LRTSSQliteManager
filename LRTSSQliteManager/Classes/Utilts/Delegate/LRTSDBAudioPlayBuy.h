//
//  LRTSDBAudioPlayBuy.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <Foundation/Foundation.h>

@protocol LRTSDBAudioPlayBuy <NSObject>

/**
 * 检查该曲目是否可以播放
 */
+ (BOOL)checkPlayManagerCanPlayCurTrack;

/**
 * 检查该曲目是否可以播放, 若不能播放,返回错误
 */
+ (BOOL)checkPlayManagerCanPlayCurTrackErr:(LMAPMError **)error;

/**
 *  检查指定收费章节是否可以播放（如果购买了则可以播放，否则不能）
 *
 *  @param checkSection 需要检查的声音
 *
 *  @return 返回是否可以播放
 */
+ (BOOL)checkPlayManagerCanPlayWithSubEntity:(id)subEntity
                                      entity:(id)entity;

+ (BOOL)checkPlayManagerCanPlayWithSubEntity:(id)subEntity
                                      entity:(id)entity
                                       error:(LMAPMError **)error;

@end
