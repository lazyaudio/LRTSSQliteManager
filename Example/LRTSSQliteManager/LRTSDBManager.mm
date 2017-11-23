//
//  LRTSDBManager.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/23.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import "LRTSDBManager.h"
#import "LRTSDBModel.h"
#import <objc/runtime.h>
#import "LRTSDBBookDetailModel+WCTTableCoding.h"

@implementation LRTSDBManager

- (void)selectMutailObjectsOnProperty:(void (^)(LRTSRanksList *ranksList))ranks {
    LRTSRanksList *rankList = [[LRTSRanksList alloc] init];
    if (ranks) {
        ranks(rankList);
    }
    
    NSLog(@"ranks:%@", rankList.ranksList);
    
    [rankList.ranksList enumerateObjectsUsingBlock:^(NSMutableDictionary * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"obj : %@", obj);
        NSString *className = [obj objectForKey:kModel];
        __unsafe_unretained Class modelClass = NSClassFromString(className);
        
        LRTSDBBookDetailModel *bookDetailModel = (LRTSDBBookDetailModel *)[[modelClass alloc] init];
        NSLog(@"bId==%d", bookDetailModel.bId);
        if ([modelClass isEqual: NSStringFromClass(LRTSDBBookDetailModel.class)]) {
//            LRTSDBBookDetailModel.bId
        }
        //转换为 -->LRTSDBBookDetailModel.bId
//        A.publisher
//        B.publisher
        
        
    }];
}

- (void)selectMutailObjectsOnProperty:(void (^)(LRTSRanksList *ranksList))ranks forTableModels:(NSArray <LRTSDBModel *> *)models {
    LRTSRanksList *rankList = [[LRTSRanksList alloc] init];
    if (ranks) {
        ranks(rankList);
    }
    
    NSLog(@"ranks:%@", rankList.ranksList);
    
    [rankList.ranksList enumerateObjectsUsingBlock:^(NSMutableDictionary * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"obj : %@", obj);
        NSString *className = [obj objectForKey:kModel];
        __unsafe_unretained Class modelClass = NSClassFromString(className);
        
        LRTSDBBookDetailModel *bookDetailModel = (LRTSDBBookDetailModel *)[[modelClass alloc] init];
        NSLog(@"bId==%d", bookDetailModel.bId);
        //转换为 -->LRTSDBBookDetailModel.bId
        //        A.publisher
        //        B.publisher
        
    }];
}


@end
