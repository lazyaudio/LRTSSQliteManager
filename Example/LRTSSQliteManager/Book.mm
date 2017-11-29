//
//  Book.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/13.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import "Book.h"
#import <WCDB/WCDB.h>

@implementation Book

WCDB_IMPLEMENTATION(Book)


WCDB_SYNTHESIZE(Book, bookName)
WCDB_SYNTHESIZE(Book, bookID)
WCDB_SYNTHESIZE(Book, autor)
//WCDB_SYNTHESIZE(Book, version)
WCDB_SYNTHESIZE(Book, totalPage)
WCDB_SYNTHESIZE(Book, bookeDetail)
WCDB_SYNTHESIZE(Book, pubilsher)

//WCDB_SYNTHESIZE_COLUMN(className, propertyName, columnName)



WCDB_UNIQUE(Book, bookID)


@end
