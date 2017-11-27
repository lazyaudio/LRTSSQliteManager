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

@property (nonatomic, strong) LRTSRanksList *kRanksList;

@end

@implementation LRTSDBOperation

#pragma mark - Life Cycle

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

- (LRTSRanksList *)kRanksList {
    if (!_kRanksList) {
        _kRanksList = [[LRTSRanksList alloc] init];
    }
    return _kRanksList;
}

#pragma mark - Event

#pragma mark - Delegate

#pragma mark - Public Method

#pragma mark -BookDetailModel Operations

- (BOOL)createBookDetailTable {
    return [_operation createTableWithDBModel:self.bookDetail];
}

- (void)insertObjectIntoBookDetailModelWithObject:(BookDetail *)model {
    [_operation insertOrReplaceObject:model into:NSStringFromClass(BookDetail.class)];
}

- (void)deleteObjectFromBookDetailModelWithBookId:(NSInteger)bookId {
    [_operation deleteObjectsFromTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
}

- (void)updateOneObjectFromBookDetailWithObject:(BookDetail *)model
                                    whereBookId:(NSInteger)bookId {
    [_operation updateRowsInTable:NSStringFromClass(BookDetail.class) onValue:BookDetail.bookName withObject:model where:BookDetail.bookID == bookId];
}

- (id)getOneObjectFromBookeDetailModelWithBookId:(NSInteger)bookId {
    return [self.operation getObjectsForTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
}

#pragma mark -Multiple Tables Operations

- (NSArray *)getRowsFromBookDetailAndBook {
    NSString *nameBookDetail = NSStringFromClass(BookDetail.class);
    NSString *nameBook = NSStringFromClass(Book.class);
    return [_operation selectRowsOnResults:{BookDetail.bookName.inTable(nameBookDetail), Book.autor.inTable(nameBook)} fromTables:@[nameBook, nameBookDetail] where:Book.bookID == 1000];
}

//- (NSArray *)getRowsFromBookDetailAndBookOnProperty:(LRTSRanksListBlock)ranksList where:(NSInteger)bookID {
//    if (ranksList) {
//        ranksList(self.kRanksList);
//    }
//    
//    
//    
//}



#pragma mark - Private Method

@end
