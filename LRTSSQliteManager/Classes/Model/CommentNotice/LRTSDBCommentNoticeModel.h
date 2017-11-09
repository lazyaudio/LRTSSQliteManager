//
//  LRTSDBCommentNoticeModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

typedef NS_ENUM(NSInteger, CommentType) {
    CommentTypeEntity,      // 对实体的评论
    CommentTypeComment,     // 对评论的回复
};

@interface LRTSDBCommentNoticeModel : LRTSDBModel

@property (assign, nonatomic) NSInteger      msgId;//评论消息ID
@property (assign, nonatomic) NSInteger      userId;//发评论的用户ID
@property (copy,   nonatomic) NSString       *userNickName;//发评论的用户昵称
@property (copy,   nonatomic) NSString       *userCover;//发评论的用户头像

@property (assign, nonatomic) NSTimeInterval createTime;//评论创建时间
@property (copy,   nonatomic) NSString       *content;//评论内容

@property (assign, nonatomic) NSInteger      entityId;//被评论的原实体ID
@property (copy,   nonatomic) NSString       *entityName;//被评论的原实体名称
@property (copy,   nonatomic) NSString       *entityCover;//被评论的原实体封面
@property (assign, nonatomic) EntityType     entityType;//被评论的原实体类型，1.声音，2. 节目，4.书籍
@property (copy,   nonatomic) NSString       *entityAnthor;//被评论的原实体作者
@property (copy,   nonatomic) NSString       *entityAnnouncer;//被评论的原实体播音

@property (assign, nonatomic) NSInteger      commentId;//产生评论通知的评论ID
@property (assign, nonatomic) CommentType    commentType;//评论类型

@property (assign, nonatomic) EntityType     cEntityType;//被评论的实体类型
@property (assign, nonatomic) NSInteger      cEntityId;//被评论的实体ID
@property (assign, nonatomic) NSInteger      entitySource;//来源：1.原创，2.采集
@property (copy, nonatomic  ) NSString       *pContent;//上一条评论

@property (copy, nonatomic  ) NSString       *extInfo;//额外信息

@property (assign, nonatomic) ReadState      readState;// 已读未读状态

@property (nonatomic, assign) NSInteger      userState;

@end
