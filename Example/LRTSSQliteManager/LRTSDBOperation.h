//
//  LRTSDBOperation.h
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/24.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BookDetail.h"
#import "Book.h"

@interface LRTSDBOperation : NSObject

+ (instancetype)instance;

#pragma mark - BookDetailModel

//首先要创建数据库，然后才可以对相关数据进： 增、删、改和查

- (BOOL)createBookDetailTable;

- (void)insertObjectIntoBookDetailModelWithObject:(BookDetail *)model;

- (void)deleteObjectFromBookDetailModelWithBookId:(NSInteger)bookId;

- (void)updateOneObjectFromBookDetailWithObject:(BookDetail *)model
                                    whereBookId:(NSInteger)bookId;

- (id)getOneObjectFromBookeDetailModelWithBookId:(NSInteger)bookId;

#pragma mark -Multiple Tables Operations


#pragma mark -BookDetail & Book

- (NSArray *)getRowsFromBookDetailAndBook;

//- (NSArray *)getRowsFromBookDetailAndBookOnProperty:(LRTSRanksListBlock)ranksList where:(NSInteger)bookID;



@end
