//
//  NSObject+LRTSVipAndBoutique.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <Foundation/Foundation.h>

@protocol NSObjectStrategyVerify <NSObject>

@optional
- (void)setStrategy:(long)strategy;
- (long)strategy;
- (void)setPayType:(long)payType;
- (long)payType;


@end

@interface NSObject (LRTSVipAndBoutique)<NSObjectStrategyVerify>

/**
 判断是否是vip限免或者整本全部限免
 */
- (BOOL)strategy_isVIPOrLimitTimeListenWholeBook;

//是否为整本抢先听
- (BOOL)strategy_isLimitTimeListenWholeBook;

//是否抢先听
- (BOOL)strategy_isAnyLimitTimeListenBook;

/**
 判断是否是是精品
 */
- (BOOL)payType_isBoutique;

- (BOOL)strategy_isMemberFreeLimits;

- (BOOL)strategy_isFreeLimits;

- (BOOL)strategy_isAnyFreeLimits;

@end
