//
//  LRTSDBBookModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBModel.h"
#import "LRTSPurchaseTool.h"


@interface LRTSDBBookModel : LRTSDBModel

@property (nonatomic,assign) NSInteger bId;          //书籍id
@property (nonatomic,assign) NSInteger hot;          //书籍人气
@property (nonatomic,assign) NSInteger sections;     //书籍总章节数
@property (nonatomic,assign) NSInteger state;        //书籍状态（１-连载中，２-全集)

@property (nonatomic) NSInteger sort;                //0正序1倒序

@property (nonatomic) NSInteger commentCount;        // 评论总数
@property (nonatomic) NSInteger isMarked;            //是否收藏 0没有 1收藏

@property (strong,nonatomic) NSString *name;         //名称
@property (strong,nonatomic) NSString *author;       //作者
@property (strong,nonatomic) NSString *announcer;    //播音
@property (strong,nonatomic) NSString *cover;        //封面
//@property (strong,nonatomic) NSString *update;       //更新时间(保留：因为从1.9.x版本恢复数据需要这个字段值，2.1.x版本之后都使用lastUpdateTime这个字段)

@property (nonatomic, assign) NSInteger refId;       //关联的书籍Id

@property (strong,nonatomic) NSString *categoryName;  // 分类名称
@property (nonatomic) NSTimeInterval lastUpdateTime;  //最后更新时间

@property (nonatomic) LRTSEnterPlayType enterPlayType;    //记住上次播放的入口 (可能已经废弃使用了)
            
//在推荐、排行、专题等客户端人为分类时用到
@property (nonatomic) NSInteger bParentId;           //父分类id
@property (nonatomic) NSInteger bCategoryId;         //分类id

@property (nonatomic) NSInteger downloadedSectionCount;

//收藏时会用到
@property (nonatomic) NSInteger recordId;            //收藏记录id
@property (nonatomic) NSInteger recordStatus;        //记录状态，－1删除，0:新增 1:已同步
@property (nonatomic) NSInteger like;                //赞
@property (nonatomic) LRTSEntityType entityType;         //播音实体类型


@property (nonatomic, strong) NSString  *extInfo;    //额外的信息，包含链接信息

@property (assign, nonatomic) LRTSPriceModelPayType payType;           //0免费 1整本 2分章 （5.5.5） 3订阅
@property (nonatomic, assign) NSInteger strategy;    // vip策略
@property (nonatomic, assign) NSTimeInterval freeEndTime;           // 限免截止时间
@property (nonatomic, assign,getter=isOverEndTime) BOOL overEndTime;// 是否已经超过了限免截止时间，超过了表示结束限免，即为收费书籍

/**
 书籍更新状态，0:为没更新,>0为有更新
 之前版本用来保存最近收听和收藏书籍之间更新的同步
 标签版本后（v3.1.5），此字段不会存储到书籍数据库表中，不会用来做同步
 在我的标签包含的资源列表中用来标记是否有更新（通过其他字段计算）
 */
@property (nonatomic, assign) NSInteger updateState;

@end
