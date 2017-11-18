//
//  LRTSDBBookDetailModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBBookDetailModel.h"

@implementation LRTSDBBookDetailModel

WCDB_IMPLEMENTATION(LRTSDBBookDetailModel)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, length)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, download)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, cantDown)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, marked)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, desc)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, commentMean)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, listenPrice)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, downloadPrice)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, announcerIds)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, bookReward)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, extraInfos)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, bookPrice)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, bookVersion)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, sysLabels)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, tags)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, typeId)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, haveLink)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, linkRanges)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, linkAddresses)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, descWithLink)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, createTime)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, latestFollowLabel)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, latestFollowLabelTime)


//WCDB_SYNTHESIZE(LRTSDBBookDetailModel, )

#pragma mark - BookModel

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, bId)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, hot)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, sections)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, state)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, sort)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, commentCount)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, isMarked)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, name)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, author)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, announcer)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, cover)
//WCDB_SYNTHESIZE(LRTSDBBookDetailModel, update)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, refId)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, categoryName)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, lastUpdateTime)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, enterPlayType)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, bParentId)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, bCategoryId)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, downloadedSectionCount)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, recordId)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, recordStatus)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, like)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, entityType)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, extInfo)

WCDB_SYNTHESIZE(LRTSDBBookDetailModel, strategy)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, freeEndTime)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, overEndTime)
WCDB_SYNTHESIZE(LRTSDBBookDetailModel, updateState)


@end
