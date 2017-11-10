//
//  NSObject+userStateVerify.h
//  lazyaudio
//
//  Created by lazy-iOS2 on 16/12/16.
//
//

#import <Foundation/Foundation.h>

// 判断用户的状态，权限
typedef NS_ENUM(NSInteger, LMUserStateType) {
    LMUserStateTypePassWordProtect = 1<<0,     // 存在密保
    LMUserStateTypeHasEmail = 1<<1,            // 存在邮箱
    LMUserStateTypeHasVerifyEmail = 1<<2,      // 邮箱通过验证
    LMUserStateTypeIsManager = 1<<3,           // 是否为管理员用户,管理员用户可以删除评论
    LMUserStateTypeBindSina = 1<<4,            // 绑定新浪微博
    LMUserStateTypeBindTencent = 1<<5,         // 绑定QQ
    LMUserStateTypeBindWeixin = 1<<7,          // 绑定微信
    LMUserStateTypeAnnouncer = 1<<8,           // 是否为书城主播
    
    /*已经强制进入过新手引导的选择兴趣页面（每个用户强制进入一次）*/
    LMUserStateTypeEnteredInterest = 1<<9,
    /*已经强制进入过新手引导的关注推荐主播页面（每个用户强制进入一次）*/
    LMUserStateTypeEnteredAnnouncer = 1<<10,
    
    LMUserStateTypeLetter = 1<<11,             // 只接收被关注着的私信
    LMUserStateTypeOrganizationManage = 1<<12, // 是否为机构管理
    LMUserStateTypeVerifyEmail = 1<<13,        // 邮箱验证
    LMUserStateTypeVIP = 1<<14,                // 充值会员
    LMUserStateTypeVerifiedAnnouncer  = 1<<15, // 认证主播
    LMUserStateTypeGroupMember = 1<<16,        // 小组成员
    LMUserStateTypeCommunityAnnouncer  = 1<<17,// 社区主播
    LMUserStateTypeBindXiaoMiAccount = 1<<18,  // 绑定小米
    LMUserStateTypeUnverifiedAnnouncer = 1<<19,// 非认证主播
};

@protocol NSObjectUserStateVerify <NSObject>

@optional
- (void)setUserState:(LMUserStateType)type;
- (LMUserStateType)userState;

@end

@interface NSObject (LRTSUserStateVerify)<NSObjectUserStateVerify>

- (BOOL)isTrueOfUserStateType:(LMUserStateType)type;

- (BOOL)isVIP;

- (BOOL)isVerifiedAnnouncer;

- (BOOL)isUnverifiedAnnouncer;

- (void)disableUnverifiedAnnouncerFlag;

@end

