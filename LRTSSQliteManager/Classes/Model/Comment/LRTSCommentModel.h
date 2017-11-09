//
//  LRTSComment.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

typedef NS_ENUM(NSUInteger, LMCommentType) {
    LMCommentTypeNormal         = 1<<0,
    LMCommentTypeGood           = 1<<1,
    LMCommentTypeTop            = 1<<2,
    LMCommentTypeRestoreGood    = 1<<3,// 恢复精彩评论
};

@interface LRTSCommentModel : LRTSDBModel

@interface LMComment : LMBaseModel

@property (nonatomic       ) NSInteger      cId;
@property (nonatomic,assign) NSInteger      commentType;
@property (nonatomic,strong) NSString       *cContent;      // 评论内容
@property (nonatomic       ) NSInteger      cStarCount;     // 星数
@property (nonatomic,strong) NSString       *cNickName;     // 用户昵称
@property (nonatomic       ) NSTimeInterval cLastModify;    // 评论时间
@property (nonatomic,strong) NSString       *cCover;        // 用户头像

@property (nonatomic,assign) NSInteger      userState;

@property (nonatomic,assign) NSInteger      isReg;          // 是否是注册用户（有些老的非注册的用户也可以发表评论）
@property (nonatomic,assign) NSInteger      cUserId;        // 用户Id
@property (nonatomic,assign) NSInteger      replyUserId;    // 回复用户的id
@property (nonatomic, strong) NSString      *replyNickname; // 判断是都是回复

@property (nonatomic, assign) NSInteger     isLike;          // 是否赞
@property (nonatomic, assign) NSInteger     likeCounts;      // 赞的数目

@end
