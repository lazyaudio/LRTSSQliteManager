//
//  LRTSDBListenerBuyModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBListenerBuyModel.h"
#import <WCDB/WCDB.h>

@interface LRTSDBListenerBuyModel (WCTTableCoding)

WCDB_PROPERTY(coinCount)
WCDB_PROPERTY(viceCoinCount)
WCDB_PROPERTY(buyType)
WCDB_PROPERTY(action)
WCDB_PROPERTY(title)
WCDB_PROPERTY(sectionIndexs)

//WCDB_PROPERTY()
//WCDB_PROPERTY()
//WCDB_PROPERTY()

@end
