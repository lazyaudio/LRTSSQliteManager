//
//  LRTSDBDetailPriceCellModel+InitizializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBDetailPriceCellModel.h"

@interface LRTSDBDetailPriceCellModel (InitizializationAndConfiguration)

/**
 是否限免
 */
- (BOOL)isLimitFree;


/**
 会员限免
 */
- (BOOL)isMemberFreeLimits;

/**
 是否折扣，用来区分显示是限免倒计时或者折扣倒计时
 */
- (BOOL)isDiscount;

/**
 返回多少懒人币，是否是原价内部计算
 */
- (NSString*)coin;

/**
 返回懒人币/期 的文件string
 */
- (NSString *)coinDesc;

/**
 返回原价的文字描述
 */
- (NSAttributedString *)originDesc;

/**
 原价
 */
- (NSString*)originCoin;

/**
 初始化函数
 */
- (instancetype)initWithDetailType:(LRTSDetailPriceModelType)type;

@end
