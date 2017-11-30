//
//  BookDetail.m
//  CTPersistance
//
//  Created by liangbai on 2017/10/27.
//  Copyright © 2017年 casa. All rights reserved.
//

#import "BookDetail.h"
#import <WCDB/WCDB.h>

@implementation BookDetail

WCDB_IMPLEMENTATION(BookDetail)

WCDB_SYNTHESIZE(BookDetail, bookID)
WCDB_SYNTHESIZE(BookDetail, bookName)
WCDB_SYNTHESIZE(BookDetail, upLoad)
WCDB_SYNTHESIZE(BookDetail, pubilsher)

//WCDB_SYNTHESIZE_COLUMN(BookDetail, pubilsher, @"出版")

WCDB_UNIQUE(BookDetail, bookID)

@end
