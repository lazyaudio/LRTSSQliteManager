//
//  LRTSDBUserModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

@interface LRTSDBUserModel : LRTSDBModel

@property (nonatomic)        NSInteger userId;       //用户id

@property (nonatomic,assign ) NSInteger      userState;//用户状态
@property (nonatomic,strong ) NSString       *account;//用户账户名
@property (nonatomic,strong ) NSString       *token;//授权的token
@property (nonatomic,assign ) NSInteger      gender;//1-男，2-女
@property (nonatomic,strong ) NSString       *nickname;//昵称
@property (nonatomic,strong ) NSString       *cover;//用户头像
@property (nonatomic,strong ) NSString       *backCover;//用户主页背景
@property (nonatomic,strong ) NSString       *areaIds;//地区id
@property (nonatomic,strong ) NSString       *address;//用户地区
@property (nonatomic,strong ) NSString       *desrc;//用户描述
@property (nonatomic,strong ) NSString       *birthday;//用户生日

@property (nonatomic,strong ) NSString       *phone;//手机号
@property (nonatomic,strong ) NSString       *email;//电子邮箱
@property (nonatomic,strong ) NSString       *state;//账户状态，1-正常，2-需要激活
@property (nonatomic,strong ) NSString       *purchaseTime;//购买时间
@property (nonatomic,assign ) NSInteger      point;//积分
@property (nonatomic,assign ) NSInteger      timeRemaining;//剩余时间(天)
@property (nonatomic,assign ) NSInteger      mSectionCount;//会员免费下载章节
@property (nonatomic,assign ) NSInteger      sectionCount;//普通用户剩余下载章节
@property (nonatomic,assign ) NSInteger      grade;//用户等级
@property (nonatomic,assign ) double         coin;//虚拟币，懒人币以及金额计算的建议使用double，否则会计算错误
@property (nonatomic,assign ) NSInteger      newPoint; // 积分

@property (nonatomic,assign ) NSInteger      receiveLetter;// 接受私信的状态

@property (nonatomic,strong ) NSString       *questionA;
@property (nonatomic,strong ) NSString       *anwserA;
@property (nonatomic,strong ) NSString       *questionB;
@property (nonatomic,strong ) NSString       *anwserB;
@property (nonatomic,assign ) NSInteger      isFollowLogin;
@property (nonatomic,assign ) NSInteger      isFollow;

@property (nonatomic, assign) NSInteger      attentionCount;//关注数量
@property (nonatomic, assign) NSInteger      fansCount;//粉丝数量

// 需要缓存到本地数据库中
@property (nonatomic, assign) NSInteger      collectionCount;//用户收藏的听单数量
@property (nonatomic, assign) NSInteger      albumCount;//用户发布的节目数量
@property (nonatomic, assign) NSInteger      bookCount;//用户发布的书籍数量
@property (nonatomic, assign) NSUInteger     bbCount;   // 用户购买的有声书籍/节目数量
@property (nonatomic, assign) NSUInteger     bbReadCount;// 用户购买的阅读书籍数量
@property (nonatomic, assign) NSUInteger     collectReadCount;// 用户收藏到书架上的阅读书籍数量
@property (nonatomic, assign) NSUInteger     ticketBalance;   // 用户听读卷余额（单位: 分）

//用户登录成功后，控制是否显示添加主播关注界面，1是显示　0不显示
@property (nonatomic,assign ) NSInteger      isShowGuide;


@end
