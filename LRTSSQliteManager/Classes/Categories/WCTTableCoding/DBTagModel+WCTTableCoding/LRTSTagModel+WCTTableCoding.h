//
//  LRTSTagModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSTagModel.h"
#import <WCDB/WCDB.h>

@interface LRTSTagModel (WCTTableCoding)

WCDB_PROPERTY(tg_type)
WCDB_PROPERTY(tg_name)
WCDB_PROPERTY(tg_bgColor)


//WCDB_PROPERTY()
//WCDB_PROPERTY()
//WCDB_PROPERTY()

@end
