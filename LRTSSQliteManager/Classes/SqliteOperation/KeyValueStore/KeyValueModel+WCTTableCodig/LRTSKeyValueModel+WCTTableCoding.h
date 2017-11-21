//
//  LRTSKeyValueModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

#import "LRTSKeyValueModel.h"
#import <WCDB/WCDB.h>

@interface LRTSKeyValueModel (WCTTableCoding)

WCDB_PROPERTY(itemKey)
WCDB_PROPERTY(itemValue)
WCDB_PROPERTY(createTime)

//WCDB_SYNTHESIZE(LRTSKeyValueModel, itemIndex)
//WCDB_SYNTHESIZE(LRTSKeyValueModel, itemObject)
//WCDB_SYNTHESIZE(LRTSKeyValueModel, createTime)

@end
