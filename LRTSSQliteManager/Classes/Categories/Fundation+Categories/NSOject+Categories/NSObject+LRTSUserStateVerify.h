//
//  NSObject+userStateVerify.h
//  lazyaudio
//
//  Created by lazy-iOS2 on 16/12/16.
//
//

#import <Foundation/Foundation.h>

//LRTSUserStateType

// 判断用户的状态，权限
typedef NS_ENUM(NSInteger, LRTSUserStateType) {
    LRTSUserStateTypePassWordProtect = 1<<0,     // 存在密保
    LRTSUserStateTypeHasEmail = 1<<1,            // 存在邮箱
    LRTSUserStateTypeHasVerifyEmail = 1<<2,      // 邮箱通过验证
    LRTSUserStateTypeIsManager = 1<<3,           // 是否为管理员用户,管理员用户可以删除评论
    LRTSUserStateTypeBindSina = 1<<4,            // 绑定新浪微博
    LRTSUserStateTypeBindTencent = 1<<5,         // 绑定QQ
    LRTSUserStateTypeBindWeixin = 1<<7,          // 绑定微信
    LRTSUserStateTypeAnnouncer = 1<<8,           // 是否为书城主播
    
    /*已经强制进入过新手引导的选择兴趣页面（每个用户强制进入一次）*/
    LRTSUserStateTypeEnteredInterest = 1<<9,
    /*已经强制进入过新手引导的关注推荐主播页面（每个用户强制进入一次）*/
    LRTSUserStateTypeEnteredAnnouncer = 1<<10,
    
    LRTSUserStateTypeLetter = 1<<11,             // 只接收被关注着的私信
    LRTSUserStateTypeOrganizationManage = 1<<12, // 是否为机构管理
    LRTSUserStateTypeVerifyEmail = 1<<13,        // 邮箱验证
    LRTSUserStateTypeVIP = 1<<14,                // 充值会员
    LRTSUserStateTypeVerifiedAnnouncer  = 1<<15, // 认证主播
    LRTSUserStateTypeGroupMember = 1<<16,        // 小组成员
    LRTSUserStateTypeCommunityAnnouncer  = 1<<17,// 社区主播
    LRTSUserStateTypeBindXiaoMiAccount = 1<<18,  // 绑定小米
    LRTSUserStateTypeUnverifiedAnnouncer = 1<<19,// 非认证主播
};

@protocol NSObjectUserStateVerify <NSObject>

@optional
- (void)setUserState:(LRTSUserStateType)type;
- (LRTSUserStateType)userState;

@end

@interface NSObject (LRTSUserStateVerify)<NSObjectUserStateVerify>

- (BOOL)isTrueOfUserStateType:(LRTSUserStateType)type;

- (BOOL)isVIP;

- (BOOL)isVerifiedAnnouncer;

- (BOOL)isUnverifiedAnnouncer;

- (void)disableUnverifiedAnnouncerFlag;

@end

