//
//  LRTSSystemNotice.m
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSSystemNotice.h"
#import <WCDB/WCDB.h>

@implementation LRTSSystemNotice

WCDB_IMPLEMENTATION(LRTSSystemNotice)

WCDB_SYNTHESIZE(LRTSSystemNotice, msgId)
WCDB_SYNTHESIZE(LRTSSystemNotice, userId)
WCDB_SYNTHESIZE(LRTSSystemNotice, userNickName)
WCDB_SYNTHESIZE(LRTSSystemNotice, userCover)
WCDB_SYNTHESIZE(LRTSSystemNotice, userState)
WCDB_SYNTHESIZE(LRTSSystemNotice, createTime)
WCDB_SYNTHESIZE(LRTSSystemNotice, content)
WCDB_SYNTHESIZE(LRTSSystemNotice, readState)
WCDB_SYNTHESIZE(LRTSSystemNotice, title)

WCDB_SYNTHESIZE(LRTSSystemNotice, pulishType)
WCDB_SYNTHESIZE(LRTSSystemNotice, linkUrl)
WCDB_SYNTHESIZE(LRTSSystemNotice, urlParam)
WCDB_SYNTHESIZE(LRTSSystemNotice, pvUrl)
WCDB_SYNTHESIZE(LRTSSystemNotice, pvParam)
WCDB_SYNTHESIZE(LRTSSystemNotice, cover)

WCDB_SYNTHESIZE(LRTSSystemNotice, showTitle)

WCDB_SYNTHESIZE(LRTSSystemNotice, cellRowHeight)
WCDB_SYNTHESIZE(LRTSSystemNotice, dateStr)

//
//WCDB_SYNTHESIZE(LRTSDBUserModel, )
//WCDB_SYNTHESIZE(LRTSDBUserModel, )
//WCDB_SYNTHESIZE(LRTSDBUserModel, )
//WCDB_SYNTHESIZE(LRTSDBUserModel, )
//WCDB_SYNTHESIZE(LRTSDBUserModel, )
//WCDB_SYNTHESIZE(LRTSDBUserModel, )

@end
