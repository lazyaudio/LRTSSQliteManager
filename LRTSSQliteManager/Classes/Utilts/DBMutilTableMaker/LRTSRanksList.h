//
//  LRTSRanksList.h
//  Kiwi
//
//  Created by JackJin on 2017/11/23.
//

#import <Foundation/Foundation.h>

#define kModel @"kDBModel"

//extern kOnProperty;
//extern kIn;

@interface LRTSRanksList : NSObject

@property (nonatomic, readonly) NSMutableArray<NSMutableDictionary *> *ranksList;


- (LRTSRanksList *(^)(NSString *model))model;

- (LRTSRanksList *(^)(NSString *onProperty))onProperty;



@end
