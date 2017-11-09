//
//  LRTSDBPlayItemModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBPlayItemModel.h"

@implementation LRTSDBPlayItemModel

WCDB_IMPLEMENTATION(LRTSDBPlayItemModel)

WCDB_SYNTHESIZE(LRTSDBPlayItemModel, pId)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, pName)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, pUrl)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, coverUrl)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, section)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, entityType)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, haslyric)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, currentTime)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, duration)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, enterType)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, playSeconds)
WCDB_SYNTHESIZE(LRTSDBPlayItemModel, freeUrl)

WCDB_SYNTHESIZE(LRTSDBPlayItemModel, isRequestedCoverUrl)

WCDB_SYNTHESIZE(LRTSDBPlayItemModel, validCoverUrl)

//WCDB_SYNTHESIZE(LRTSDBPlayItemModel, )
//WCDB_SYNTHESIZE(LRTSDBPlayItemModel, )
//WCDB_SYNTHESIZE(LRTSDBPlayItemModel, )
//
//WCDB_SYNTHESIZE(LRTSDBPlayItemModel, )

@end
