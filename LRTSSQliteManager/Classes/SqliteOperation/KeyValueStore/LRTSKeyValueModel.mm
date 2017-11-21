//
//  LRTSKeyValueModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

#import "LRTSKeyValueModel.h"
#import <WCDB/WCDB.h>

@implementation LRTSKeyValueModel

WCDB_IMPLEMENTATION(LRTSKeyValueModel)

WCDB_SYNTHESIZE(LRTSKeyValueModel, itemKey)
WCDB_SYNTHESIZE(LRTSKeyValueModel, itemValue)
WCDB_SYNTHESIZE(LRTSKeyValueModel, createTime)

WCDB_UNIQUE(LRTSKeyValueModel, itemKey)


@end
