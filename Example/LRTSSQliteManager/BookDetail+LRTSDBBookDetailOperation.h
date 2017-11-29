//
//  BookDetail+LRTSDBBookDetailOperation.h
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/29.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import "BookDetail.h"

#define LAZYAUDIOLISTEB @"lazyAudioListen"

@interface BookDetail (LRTSDBBookDetailOperation)

- (BOOL)createBookDetailTable;

- (void)insertObjectIntoBookDetail;

- (void)deleteObjectFromBookDetailModelWithBookId:(NSInteger)bookId;

- (void)updateOneObjectFromBookDetailWithObject:(BookDetail *)model
                                    whereBookId:(NSInteger)bookId;

@end
