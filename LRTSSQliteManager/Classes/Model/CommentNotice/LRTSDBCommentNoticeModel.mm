//
//  LRTSDBCommentNoticeModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBCommentNoticeModel.h"
#import <WCDB/WCDB.h>

@implementation LRTSDBCommentNoticeModel

WCDB_IMPLEMENTATION(LRTSDBCommentNoticeModel)

WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, msgId)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, userId)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, userNickName)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, userCover)

WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, createTime)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, content)

WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entityId)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entityName)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entityCover)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entityType)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entityAnthor)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entityAnnouncer)

WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, commentId)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, commentType)

WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, cEntityType)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, cEntityId)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, entitySource)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, pContent)

WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, extInfo)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, readState)
WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, userState)


//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
////
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//WCDB_SYNTHESIZE(LRTSDBCommentNoticeModel, )
//
@end

