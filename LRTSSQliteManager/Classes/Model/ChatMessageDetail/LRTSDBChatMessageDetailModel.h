//
//  LRTSDBChatMessageDetailModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDBMessageHeader.h"
#import <WCDB/WCDB.h>

//LRTSChatMessageSendState
//LRTSChatMessageDisplayCreateTime
//ChatMessageDetailFakeType

typedef NS_ENUM(NSInteger, LRTSChatMessageSendState) {
    LRTSChatMessageSendStateFailure = -1,
    LRTSChatMessageSendStateSuccess,
    LRTSChatMessageSendStateSending,
};

typedef NS_ENUM(NSInteger, LRTSChatMessageDisplayCreateTime) {
    LRTSChatMessageDisplayCreateTimeNone = 0,  // 不知道是否显示还是隐藏
    LRTSChatMessageDisplayCreateTimeShow,
    LRTSChatMessageDisplayCreateTimeHide,
};

typedef NS_ENUM(NSInteger, LRTSChatMessageDetailFakeType) {
    LRTSChatMessageDetailFakeTypeTrue,
    LRTSChatMessageDetailFakeTypeFake
};

/**
 *  一个私信会话中的用户发送的一条信息
 */
@interface LRTSDBChatMessageDetailModel : LRTSDBModel

@property (assign, nonatomic) NSInteger             sendId;              // 在发送对列中的id
//@property (assign, nonatomic) NSInteger             order;               // 显示顺序
@property (assign, nonatomic) NSInteger             msgId;               // 私信id
@property (assign, nonatomic) NSInteger             senderId;            // 该条私信的发送用户id
@property (assign, nonatomic) NSInteger             otherUserId;         // 私信涉及的另一方的用户id
@property (copy,   nonatomic) NSString              *otherUserNick;      // 私信涉及的另一方用户名
@property (copy,   nonatomic) NSString              *otherUserCover;     // 私信涉及的另一方用户的头像
@property (nonatomic, assign) NSInteger             userState;
@property (copy,   nonatomic) NSString              *content;            // 私信内容
@property (assign, nonatomic) NSTimeInterval        createTime;          // 私信创建时间
@property (assign, nonatomic) LRTSChatMessageSendState  sendOk;              // 是否发送成功
@property (assign, nonatomic) LRTSReadState             readState;           // 已读未读状态

@property (assign, nonatomic) CGFloat               contentStrWidth;     // 内容宽度
@property (assign, nonatomic) CGFloat               contentStrHeight;    // 内容高度

@property (assign, nonatomic) LRTSChatMessageDetailFakeType             fake;                // 手动写入的数据库中的不是服务器的真实数据

@property (assign, nonatomic) LRTSChatMessageDisplayCreateTime displayCreateTime;   // 显示时间



#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(sendId)
WCDB_PROPERTY(msgId)
WCDB_PROPERTY(senderId)
WCDB_PROPERTY(otherUserId)
WCDB_PROPERTY(otherUserNick)
WCDB_PROPERTY(otherUserCover)
WCDB_PROPERTY(userState)
WCDB_PROPERTY(content)
WCDB_PROPERTY(createTime)
WCDB_PROPERTY(sendOk)
WCDB_PROPERTY(readState)
WCDB_PROPERTY(contentStrWidth)
WCDB_PROPERTY(contentStrHeight)
WCDB_PROPERTY(fake)
WCDB_PROPERTY(displayCreateTime)



@end
