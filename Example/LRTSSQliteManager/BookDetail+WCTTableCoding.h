//
//  BookDetail+WCTTableCoding.h
//  CTPersistance
//
//  Created by liangbai on 2017/10/27.
//  Copyright © 2017年 casa. All rights reserved.
//

#import "BookDetail.h"
#import <WCDB/WCDB.h>

//@property int bookID;
//@property(assign) const char *bookName;
//@property(retain) NSDate *upLoad;
//@property(retain) NSString *pubilsher;

@interface BookDetail (WCTTableCoding)<WCTTableCoding>

WCDB_PROPERTY(bookID)
WCDB_PROPERTY(bookName)
WCDB_PROPERTY(upLoad)
WCDB_PROPERTY(pubilsher)

@end
