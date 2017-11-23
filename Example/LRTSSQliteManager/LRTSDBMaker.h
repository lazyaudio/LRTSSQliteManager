//
//  LRTSDBMaker.h
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/23.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kModel @"kDBModel"

@interface LRTSDBMaker : NSObject

@property (nonatomic, strong, readonly) NSMutableArray<NSDictionary *> *conditions;

- (LRTSDBMaker *(^)(NSString *onProperty))onProperty;

- (LRTSDBMaker *(^)(NSString *model))model;


@end
