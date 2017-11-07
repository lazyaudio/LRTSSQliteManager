//
//  LRTSDBListenerBuyModel+SectionIndex.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBListenerBuyModel.h"

@class LRTSDBListenerPriceModel;

@interface LRTSDBListenerBuyModel (SectionIndex)

+ (NSArray *)listenBuyModelsWithPriceModel:(LRTSDBListenerPriceModel *)priceModel
                              sectionIndex:(NSInteger)sectionIndex;

+ (NSArray *)listenBuyModelsWithPriceModel:(LRTSDBListenerPriceModel *)priceModel
                                 sectionId:(long)sectionId;

@end
