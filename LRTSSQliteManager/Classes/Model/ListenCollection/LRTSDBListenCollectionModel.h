//
//  LRTSDBListenCollectionModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSTagModel.h"
#import <WCDB/WCDB.h>

@class LMSubEntity;

typedef NS_ENUM(NSInteger, LMListenCollectionType) {
    LMListenCollectionTypeMine = 1,          // 我创建的听单
    LMListenCollectionTypeCollect = 2        // 我收藏的听单
};

@interface LRTSDBListenCollectionModel : LRTSDBModel


@property (nonatomic, assign) long long folderId;                           // 听单Id
@property (nonatomic, assign) long long collectFolderId;                    // 收藏听单的id

@property (nonatomic, copy) NSString *collectionName;                       // 听单名
@property (nonatomic, copy) NSString *collectionCover;                      // 听单封面
@property (nonatomic, assign) NSInteger itemsCount;                         // 书籍（节目）数
@property (nonatomic, assign) NSInteger collectedCount;                     // 收藏数
@property (nonatomic, assign) NSTimeInterval updateTime;                    // 更新时间
@property (nonatomic, assign) NSTimeInterval collectFolderTime;             // 收藏听单的时间
@property (nonatomic, assign) NSTimeInterval entityUpdateTime;              // 听单下实体的更新时间
@property (nonatomic, assign) NSInteger commentCount;
@property (nonatomic, strong) NSString *desc;                               // 听单描述

@property (nonatomic, assign) LMListenCollectionType colectionType;         // 听单类型
@property (nonatomic, assign) NSInteger updateCount;                        // 更新的条目数，默认为0，表示没有更新 (本地管理)
@property (nonatomic, assign) NSInteger lc_state;                           // 状态标记 0正常 －1删除

@property (nonatomic, assign) NSInteger authorId;

@property (nonatomic, assign) NSInteger backFolderType;                     // 用来标记返回数据是否是默认听单（1）
@property (nonatomic, assign, getter=isCoverValid) BOOL coverValid;         // 标记听单封面是否有效

@property (nonatomic, assign) long long referId;                            // 分页时会用到

@property (nonatomic, strong) NSString *nickName;                           // 听单创建者昵称

@property (nonatomic, strong) NSArray<LMSubEntity *> *subEntitys;


WCDB_PROPERTY(folderId)
WCDB_PROPERTY(collectFolderId)
WCDB_PROPERTY(collectionName)
WCDB_PROPERTY(collectionCover)
WCDB_PROPERTY(itemsCount)
WCDB_PROPERTY(collectedCount)
WCDB_PROPERTY(updateTime)
WCDB_PROPERTY(collectFolderTime)
WCDB_PROPERTY(entityUpdateTime)
WCDB_PROPERTY(commentCount)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(colectionType)
WCDB_PROPERTY(updateCount)
WCDB_PROPERTY(lc_state)
WCDB_PROPERTY(authorId)
WCDB_PROPERTY(backFolderType)
WCDB_PROPERTY(coverValid)
WCDB_PROPERTY(referId)
WCDB_PROPERTY(nickName)
WCDB_PROPERTY(subEntitys)

@end

@interface LMSubEntity : NSObject

@property (nonatomic, copy) NSString *cover;
@property (nonatomic, assign) NSInteger entityId;
@property (nonatomic, assign) EntityType entityType;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSInteger strategy;
@property (nonatomic, strong) LRTSTagModel *tag;

- (instancetype)initWithDict:(NSDictionary *)dict;
+ (instancetype)subEntityWithDict:(NSDictionary *)dict;
+ (NSArray<LMSubEntity *> *)subEntitysWithDicts:(NSArray *)dicts;


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(cover)
WCDB_PROPERTY(entityId)
WCDB_PROPERTY(entityType)
WCDB_PROPERTY(name)
WCDB_PROPERTY(strategy)
WCDB_PROPERTY(tag)


@end
