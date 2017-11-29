//
//  LRTSDBOperation.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/24.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import "LRTSDBOperation.h"
#import "LRTSOperation.h"
#import "BookDetail+WCTTableCoding.h"
#import "Book+WCTTableCoding.h"


#define LAZY_AUDIO_PLAYER @"lazyAudioPlayer"

@interface LRTSDBOperation ()

@property (nonatomic, strong) LRTSOperation *operation;

@property (nonatomic, strong) BookDetail *bookDetail;

@end

@implementation LRTSDBOperation

#pragma mark - Life Cycle

static LRTSDBOperation *instance;

+ (instancetype)instance {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[LRTSDBOperation alloc] init];
    });
    return instance;
}

#pragma mark - Getter & Setter

//默认在 Document 创建数据库 lazyAudioPlayer.db
- (LRTSOperation *)operation {
    if (!_operation) {
        _operation = [[LRTSOperation alloc] initWCDBWithName:LAZY_AUDIO_PLAYER];
    }
    return _operation;
}

- (BookDetail *)bookDetail {
    if (!_bookDetail) {
        _bookDetail = [[BookDetail alloc] init];
    }
    return _bookDetail;
}

#pragma mark - Event

#pragma mark - Delegate

#pragma mark - Public Method

#pragma mark -BookDetailModel Operations

- (BOOL)createBookDetailTable {
    return [self.operation createTableWithDBModel:self.bookDetail];
}

- (void)insertObjectIntoBookDetailModelWithObject:(BookDetail *)model {
    [self.operation insertOrReplaceObject:model into:NSStringFromClass(BookDetail.class)];
}

- (void)deleteObjectFromBookDetailModelWithBookId:(NSInteger)bookId {
    [self.operation deleteObjectsFromTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
}

- (void)updateOneObjectFromBookDetailWithObject:(BookDetail *)model
                                    whereBookId:(NSInteger)bookId {
    [self.operation updateRowsInTable:NSStringFromClass(BookDetail.class) onValue:BookDetail.bookName withObject:model where:BookDetail.bookID == bookId];
}

- (id)getOneObjectFromBookeDetailModelWithBookId:(NSInteger)bookId {
    return [self.operation getObjectsForTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
}

#pragma mark -Multiple Tables Operations

- (NSArray *)getRowsFromBookDetailAndBook {
    NSString *nameBookDetail = NSStringFromClass(BookDetail.class);
    NSString *nameBook = NSStringFromClass(Book.class);
    return [self.operation selectRowsOnResults:{BookDetail.bookName.inTable(nameBookDetail), Book.autor.inTable(nameBook)} fromTables:@[nameBook, nameBookDetail] where:Book.bookID == 1000];
}

#pragma mark - Private Method

@end
