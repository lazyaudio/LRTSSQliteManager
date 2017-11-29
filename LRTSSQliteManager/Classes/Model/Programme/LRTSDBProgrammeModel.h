//
//  LRTSDBProgrammeModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDBListenerPriceModel.h"
#import <WCDB/WCDB.h>

typedef NS_ENUM(NSInteger, SourceType) {
    SourceTypeOriginal   = 1,       // 原创
    SourceTypeCollection = 2        // 采集
};

@interface LRTSDBProgrammeModel : LRTSDBModel

@property (assign, nonatomic) long      pId;           // 节目ID
@property (copy  , nonatomic) NSString       *name;         // 节目名称
@property (copy  , nonatomic) NSString       *desc;         // 节目描述
@property (copy  , nonatomic) NSString       *author;       // 作者
//@property (assign, nonatomic) NSInteger      announcerId;   // 播音ID
@property (nonatomic, strong) NSArray        *announcerIds; //多主播

@property (copy  , nonatomic) NSString       *announcer;    // 播音名
@property (assign, nonatomic) SourceType     sourceType;    // 采集还是原创
@property (assign, nonatomic) NSInteger      playCount;     // 播放次数
@property (copy  , nonatomic) NSString       *cover;        // 书籍封面
@property (assign, nonatomic) NSInteger      sections;      // 声音数
@property (assign, nonatomic) NSInteger      totalLength;   // 声音总时长
@property (assign, nonatomic) NSTimeInterval updateTime;    // 更新时间
@property (copy  , nonatomic) NSString       *category;     // 所属分类
@property (copy  , nonatomic) NSString       *commentMean;  // 评论平均分
@property (assign, nonatomic) NSInteger      commentCount;  // 评论总数
@property (assign, nonatomic) NSTimeInterval insertDBTime;  // 插入到数据库中的时间
@property (strong, nonatomic) NSString       *nickName;     // 原创或采集者
@property (nonatomic, assign) NSInteger      insertType;    // 列表插入类型
@property (nonatomic, assign) NSInteger      userOrder;     // 用户选择的排序类型
@property (nonatomic, assign) NSInteger      like;          // 赞（0未赞 1赞）
@property (nonatomic, assign) NSInteger      state;                    //节目状态（１-连载中，２-全集）
@property (nonatomic, assign) NSInteger      sort;                    //章节排序 0正序 1倒序(v6.0.6)
@property (nonatomic, copy) NSArray *extraInfos; // 附加信息(v6.0.6), 富文本

@property (assign, nonatomic) LMPriceModelPayType payType;           //0免费 1整本 2分章 （5.5.5） 3订阅
@property (nonatomic, assign) NSInteger strategy;          // vip策略
@property (nonatomic, assign) NSTimeInterval freeEndTime;       // 限免截止时间
@property (nonatomic, assign,getter=isOverEndTime) BOOL overEndTime;// 是否已经超过了限免截止时间，超过了表示结束限免，即为收费书籍
@property (assign, nonatomic) NSInteger pType;
@property (assign, nonatomic) NSInteger pFlag;              // 节目是否有认证
@property (assign, nonatomic) NSInteger downloadedAudioCount;// 已经下载的声音数量
@property (strong, nonatomic) NSString *programmeVersion;
@property (assign, nonatomic) NSUInteger proReward;         // 是否打赏节目（0:不是 1:是）
@property (nonatomic, strong) NSArray *sysLabels; // 系统标签
@property (nonatomic, copy) NSArray *tags; // 活动标签和要点标签
@property (nonatomic, strong) LRTSDBListenerPriceModel *priceModel;  // 价格信息
@property (nonatomic,assign) BOOL cantDown; // 0能下载1不能下载（v5.5.3）

/** 标签版本(3.1.5)添加 */
@property (nonatomic, assign) NSTimeInterval createTime; ///< 资源上架时间
@property (nonatomic, strong) NSString *latestFollowLabel; ///< 资源所挂的标签中，用户最新关注的那个标签的名称
@property (nonatomic, assign) NSTimeInterval latestFollowLabelTime; ///< 资源所挂的标签中，用户最新关注的那个标签的时间

/**
 节目更新状态，0:为没更新,>0为有更新
 标签版本（v3.1.5）新加
 在我的标签包含的资源列表中用来标记是否有更新（通过其他字段计算）
 */
@property (nonatomic, assign) NSUInteger updateState;

@property (nonatomic,assign) NSInteger typeId; // 分类id


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(pId)
WCDB_PROPERTY(name)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(author)
WCDB_PROPERTY(announcerIds)

WCDB_PROPERTY(announcer)
WCDB_PROPERTY(sourceType)
WCDB_PROPERTY(playCount)
WCDB_PROPERTY(cover)
WCDB_PROPERTY(sections)
WCDB_PROPERTY(totalLength)
WCDB_PROPERTY(updateTime)
WCDB_PROPERTY(category)
WCDB_PROPERTY(commentMean)
WCDB_PROPERTY(commentCount)
WCDB_PROPERTY(insertDBTime)
WCDB_PROPERTY(nickName)
WCDB_PROPERTY(insertType)
WCDB_PROPERTY(userOrder)
WCDB_PROPERTY(like)
WCDB_PROPERTY(state)

WCDB_PROPERTY(sort)
WCDB_PROPERTY(extraInfos)
WCDB_PROPERTY(payType)
//
WCDB_PROPERTY(strategy)
WCDB_PROPERTY(freeEndTime)
WCDB_PROPERTY(overEndTime)
WCDB_PROPERTY(pType)
WCDB_PROPERTY(pFlag)
WCDB_PROPERTY(downloadedAudioCount)

WCDB_PROPERTY(programmeVersion)
WCDB_PROPERTY(proReward)
WCDB_PROPERTY(sysLabels)
WCDB_PROPERTY(tags)
WCDB_PROPERTY(priceModel)
WCDB_PROPERTY(cantDown)
WCDB_PROPERTY(createTime)
WCDB_PROPERTY(latestFollowLabel)
WCDB_PROPERTY(latestFollowLabelTime)
WCDB_PROPERTY(updateState)
WCDB_PROPERTY(typeId)



@end
