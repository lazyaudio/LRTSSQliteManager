//
//  LRTSDBChatMessageDetailModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBChatMessageDetailModel.h"
#import <WCDB/WCDB.h>

@implementation LRTSDBChatMessageDetailModel

WCDB_IMPLEMENTATION(LRTSDBChatMessageDetailModel)

WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, sendId)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, msgId)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, senderId)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, otherUserId)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, otherUserNick)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, otherUserCover)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, userState)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, content)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, createTime)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, sendOk)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, readState)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, contentStrWidth)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, contentStrHeight)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, fake)
WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, displayCreateTime)


//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
////
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )
//WCDB_SYNTHESIZE(LRTSDBChatMessageDetailModel, )

@end
