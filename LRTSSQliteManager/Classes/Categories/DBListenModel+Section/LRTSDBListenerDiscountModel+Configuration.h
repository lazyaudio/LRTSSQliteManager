//
//  LRTSDBListenerDiscountModel+Configuration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBListenerDiscountModel.h"

@interface LRTSDBListenerDiscountModel (Configuration)

- (instancetype)initWithDict:(NSDictionary *)dict;

+ (instancetype)discountModelWithDict:(NSDictionary *)dict;

+ (NSArray<LRTSDBListenerDiscountModel *> *)discountModelsWithDicts:(NSArray *)dicts;

+ (LRTSDBListenerDiscountModel *)discountModelForType:(LRTSDBListenerDiscountType)discountType
                               inDiscountModels:(NSArray<LRTSDBListenerDiscountModel *> *)discountModels;


@end
