//
//  LRTSDBBookModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBBookModel.h"
#import <WCDB/WCDB.h>

@implementation LRTSDBBookModel

WCDB_IMPLEMENTATION(LRTSDBBookModel)

WCDB_SYNTHESIZE(LRTSDBBookModel, bId)
WCDB_SYNTHESIZE(LRTSDBBookModel, hot)
WCDB_SYNTHESIZE(LRTSDBBookModel, sections)
WCDB_SYNTHESIZE(LRTSDBBookModel, state)

WCDB_SYNTHESIZE(LRTSDBBookModel, sort)

WCDB_SYNTHESIZE(LRTSDBBookModel, commentCount)
WCDB_SYNTHESIZE(LRTSDBBookModel, isMarked)

WCDB_SYNTHESIZE(LRTSDBBookModel, name)
WCDB_SYNTHESIZE(LRTSDBBookModel, author)
WCDB_SYNTHESIZE(LRTSDBBookModel, announcer)
WCDB_SYNTHESIZE(LRTSDBBookModel, cover)
//WCDB_SYNTHESIZE(LRTSDBBookModel, update)

WCDB_SYNTHESIZE(LRTSDBBookModel, refId)

WCDB_SYNTHESIZE(LRTSDBBookModel, categoryName)
WCDB_SYNTHESIZE(LRTSDBBookModel, lastUpdateTime)

WCDB_SYNTHESIZE(LRTSDBBookModel, enterPlayType)

WCDB_SYNTHESIZE(LRTSDBBookModel, bParentId)
WCDB_SYNTHESIZE(LRTSDBBookModel, bCategoryId)

WCDB_SYNTHESIZE(LRTSDBBookModel, downloadedSectionCount)

WCDB_SYNTHESIZE(LRTSDBBookModel, recordId)
WCDB_SYNTHESIZE(LRTSDBBookModel, recordStatus)
WCDB_SYNTHESIZE(LRTSDBBookModel, like)
WCDB_SYNTHESIZE(LRTSDBBookModel, entityType)

WCDB_SYNTHESIZE(LRTSDBBookModel, extInfo)

WCDB_SYNTHESIZE(LRTSDBBookModel, strategy)
WCDB_SYNTHESIZE(LRTSDBBookModel, freeEndTime)
WCDB_SYNTHESIZE(LRTSDBBookModel, overEndTime)
WCDB_SYNTHESIZE(LRTSDBBookModel, updateState)


@end
