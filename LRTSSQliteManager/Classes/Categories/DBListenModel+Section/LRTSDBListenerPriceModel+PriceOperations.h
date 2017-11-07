//
//  LRTSDBListenerPriceModel+PriceOperations.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBListenerPriceModel.h"

@class LRTSDBListenerBuyModel;

@interface LRTSDBListenerPriceModel (PriceOperations)<NSCopying>

- (instancetype)initWithDict:(NSDictionary *)dict
                    entityId:(long)entityId
                  entityType:(EntityType)entityType;

+ (instancetype)priceModelWithDict:(NSDictionary *)dict
                          entityId:(long)entityId
                        entityType:(EntityType)entityType;

- (BOOL)isUnbuySectionForIndex:(NSInteger)index;

//所有付费的序号
- (NSArray *)priceModelAllPayIndexs;

//从数据加载后需调用计算未购买索引,用于数据库读取价格
- (void)caculateUnbuyIndexs;

- (void)updateWithFinishBuyModel:(LRTSDBListenerBuyModel *)buyModel;

- (BOOL)isVIP;

//无vip会员返回1.0
- (double)vipDiscountValue;

- (NSInteger)matchPrice;

@end
