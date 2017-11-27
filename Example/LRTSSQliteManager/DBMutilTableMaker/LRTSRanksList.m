//
//  LRTSRanksList.m
//  Kiwi
//
//  Created by JackJin on 2017/11/23.
//

#import "LRTSRanksList.h"

#define kIn @"kIn"
#define kOnProperty @"kOnProperty"

@interface LRTSRanksList ()

@property (nonatomic, strong) NSMutableArray<NSMutableDictionary *> *ranksList;

@end


@implementation LRTSRanksList

#pragma mark - Get & Set

- (NSMutableArray <NSMutableDictionary *> *)ranksList {
    if (!_ranksList) {
        _ranksList = [[NSMutableArray alloc] init];
    }
    return _ranksList;
}


#pragma mark - Public Methods

- (LRTSRanksList *(^)(NSString *model))model {
    return ^id(NSString *model){
        NSMutableDictionary *dicRL = [[NSMutableDictionary alloc] init];
        dicRL[kModel] = model;
        [self.ranksList addObject:dicRL];
        return self;
    };
}

- (LRTSRanksList *(^)(NSString *onProperty))onProperty {
    return ^id(NSString *onProperty){
        NSMutableDictionary *dicRL = self.ranksList.lastObject;
        dicRL[kIn] = @".";
        dicRL[kOnProperty] = onProperty;
        return self;
    };
}


@end
