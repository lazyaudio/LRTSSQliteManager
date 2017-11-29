//
//  LRTSDBListenerDiscountModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBListenerDiscountModel.h"
#import <WCDB/WCDB.h>

@interface LRTSDBListenerDiscountModel (WCTTableCoding)

WCDB_PROPERTY(discountId)
WCDB_PROPERTY(discountType)
WCDB_PROPERTY(discountName)
WCDB_PROPERTY(discountValue)

//WCDB_PROPERTY()
//WCDB_PROPERTY()
//WCDB_PROPERTY()
//WCDB_PROPERTY()

@end
