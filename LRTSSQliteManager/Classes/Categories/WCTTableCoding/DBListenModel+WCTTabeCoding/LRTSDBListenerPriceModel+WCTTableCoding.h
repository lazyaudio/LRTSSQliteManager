//
//  LRTSDBListenerPriceModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBListenerPriceModel.h"

@interface LRTSDBListenerPriceModel (WCTTableCoding)

WCDB_PROPERTY(entityType)
WCDB_PROPERTY(entityId)
WCDB_PROPERTY(sectionCount)
WCDB_PROPERTY(estimatedSectionCount)
WCDB_PROPERTY(canUseTicket)
WCDB_PROPERTY(choosePriceType)
WCDB_PROPERTY(payType)
WCDB_PROPERTY(price)
WCDB_PROPERTY(discountPrice)
WCDB_PROPERTY(deadlineTime)
WCDB_PROPERTY(freeSectionsStr)
WCDB_PROPERTY(buySectionsStr)
WCDB_PROPERTY(allSectionsStr)

// LRTSDBListenerDiscountModel
WCDB_PROPERTY(discounts)

WCDB_PROPERTY(discountStr)
WCDB_PROPERTY(freeSectionIndexs)
WCDB_PROPERTY(buySectionIndexs)
WCDB_PROPERTY(unbuySectionIndexs)
WCDB_PROPERTY(priceJSONStr)

//WCDB_PROPERTY()
//WCDB_PROPERTY()
//WCDB_PROPERTY()

@end
