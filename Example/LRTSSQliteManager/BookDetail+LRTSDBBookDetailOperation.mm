//
//  BookDetail+LRTSDBBookDetailOperation.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/29.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import "BookDetail+LRTSDBBookDetailOperation.h"
#import "LRTSOperation.h"
#import "BookDetail+WCTTableCoding.h"

@implementation BookDetail (LRTSDBBookDetailOperation)

- (LRTSOperation *)operation {
    //初始创建数据 LAZYAUDIOLISTEB.db
    LRTSOperation *bookDetailOperation = [[LRTSOperation alloc] initWCDBWithName:LAZYAUDIOLISTEB];
    BookDetail *bookDetail = [[BookDetail alloc] init];
    //初始话创建数据表 BookDetail 数据表
    [bookDetailOperation createTableWithDBModel:bookDetail];
    return bookDetailOperation;
}


- (void)insertObjectIntoBookDetail{
    [[self operation] insertOrReplaceObject:(NSObject<WCTTableCoding> *)self into:NSStringFromClass(BookDetail.class)];
}

- (void)deleteObjectFromBookDetailModelWithBookId:(NSInteger)bookId {
    [[self operation] deleteObjectsFromTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
}

- (void)updateOneObjectFromBookDetailWithObject:(BookDetail *)model
                                    whereBookId:(NSInteger)bookId {
    [[self operation] updateRowsInTable:NSStringFromClass(BookDetail.class) onValue:BookDetail.bookName withObject:model where:BookDetail.bookID == bookId];
}

- (id)getOneObjectFromBookeDetailModelWithBookId:(NSInteger)bookId {
    return [[self operation] getObjectsForTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
}


@end
