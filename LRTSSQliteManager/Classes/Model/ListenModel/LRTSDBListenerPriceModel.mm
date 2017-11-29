//
//  LRTSDBListenerPriceModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBListenerPriceModel.h"
#import <WCDB/WCDB.h>

@implementation LRTSDBListenerPriceModel

WCDB_IMPLEMENTATION(LRTSDBListenerPriceModel)

WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, entityType)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, entityId)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, sectionCount)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, estimatedSectionCount)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, canUseTicket)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, choosePriceType)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, payType)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, price)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, discountPrice)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, deadlineTime)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, freeSectionsStr)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, buySectionsStr)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, allSectionsStr)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, discounts)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, discountStr)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, freeSectionIndexs)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, buySectionIndexs)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, unbuySectionIndexs)
WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, priceJSONStr)


//WCDB_SYNTHESIZE(LRTSDBListenerPriceModel, )

@end
