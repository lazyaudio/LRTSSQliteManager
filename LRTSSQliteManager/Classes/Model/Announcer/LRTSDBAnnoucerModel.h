//
//  LRTSDBAnnoucerModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import <WCDB/WCDB.h>

//LRTSFollowType
//LRTSAnnouncerType

typedef NS_ENUM(NSInteger, LRTSFollowType) {
    LRTSFollowTypeUnKnow   = -1, // 未标记为任何类型
    LRTSFollowTypeUnFollow = 0,  // 未关注
    LRTSFollowTypeFollowed = 1,  // 关注
};

// 获取时所属的类别
typedef NS_ENUM(NSInteger, LRTSAnnouncerType) {
    LRTSAnnouncerTypeRecommend = 1,       // 推荐主播
    LRTSAnnouncerTypeNewCome = 2          // 新晋主播
};

@interface LRTSDBAnnoucerModel : LRTSDBModel

@property (nonatomic,assign) long  aId;            //主播id
@property (nonatomic,strong) NSString   *account;       //主播账户
@property (nonatomic,strong) NSString   *nickName;      //主播昵称
@property (nonatomic,strong) NSString   *cover;         //主播头像
@property (nonatomic,assign) LRTSFollowType isFollow;       //是否关注0:未关注　1:已经关注
@property (nonatomic,strong) NSString   *desc;          //主播简介
@property (nonatomic,strong) NSString   *sign;          //个性签名

//目前只能验证 3个状态 VIP 认证主播 非认证主播
@property (nonatomic,assign) NSInteger userState;       //用户状态

@property (nonatomic,assign) NSInteger isFollowLogin;   //主播是否关注登录用户
// 请求更多数据时的标示ID
@property (nonatomic,assign) NSInteger aReferId;

@property (assign,nonatomic) LRTSAnnouncerType aType;

// 最近更新
@property (nonatomic, strong) NSString *recentProgramme;

// 最近常听
@property (nonatomic, strong) NSString *recentListen;

// 节目数
@property (nonatomic, assign) NSInteger programmeCount;

@property (nonatomic, assign) NSInteger bookCount;

// 粉丝
@property (nonatomic, assign) NSInteger fansCount;

// 关注的人
@property (nonatomic, assign) NSInteger followsCount;

// 描述
@property (nonatomic, strong) NSString *announcerDescription;

// 个性签名
@property (nonatomic, strong) NSString *personalSign;

// 头像
@property (nonatomic, strong) NSString *aCover;

//新用户
@property (nonatomic, assign, getter=isMemberNew) BOOL memberNew;


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(aId)
WCDB_PROPERTY(account)
WCDB_PROPERTY(nickName)
WCDB_PROPERTY(cover)
WCDB_PROPERTY(isFollow)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(sign)

WCDB_PROPERTY(userState)
WCDB_PROPERTY(isFollowLogin)
WCDB_PROPERTY(aReferId)
WCDB_PROPERTY(aType)
WCDB_PROPERTY(recentProgramme)
WCDB_PROPERTY(recentListen)
WCDB_PROPERTY(programmeCount)
WCDB_PROPERTY(bookCount)
WCDB_PROPERTY(fansCount)
WCDB_PROPERTY(followsCount)
WCDB_PROPERTY(announcerDescription)
WCDB_PROPERTY(personalSign)
WCDB_PROPERTY(aCover)
WCDB_PROPERTY(memberNew)


@end
