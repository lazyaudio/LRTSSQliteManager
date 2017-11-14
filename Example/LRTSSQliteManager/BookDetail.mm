//
//  BookDetail.m
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

@implementation BookDetail

WCDB_IMPLEMENTATION(BookDetail)

WCDB_SYNTHESIZE(BookDetail, bookID)
WCDB_SYNTHESIZE(BookDetail, bookName)
WCDB_SYNTHESIZE(BookDetail, upLoad)
WCDB_SYNTHESIZE(BookDetail, pubilsher)


WCDB_UNIQUE(BookDetail, bookID)



@end
