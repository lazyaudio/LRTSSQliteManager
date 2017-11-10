//
//  LRTSLGDynamicEntity.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSAudioEntityModel.h"

typedef enum : NSUInteger {
    LMLGDynamicEntitySourceOriginal = 1,    //原创
    LMLGDynamicEntitySourceForwarding = 2,  //转发
} LMLGDynamicEntitySource;

@interface LRTSLGDynamicEntity : LRTSDBModel

/**
 *  动态实体Id
 */
@property (nonatomic, assign) NSInteger entityId;

/**
 *  实体类型
 */
@property (nonatomic, assign) EntityType entityType;

/**
 *  动态实体名称
 */
@property (nonatomic, strong) NSString * entityName;

/**
 *  封面图片
 */
@property (nonatomic, strong) NSString * entityCover;

/**
 *  播音
 */
@property (nonatomic, strong) NSString * announcer;

/**
 *  书籍或者节目的播放次数
 */
@property (nonatomic, assign) NSInteger playCount;

/**
 *  书籍或者节目的章节总数
 */
@property (nonatomic, assign) NSInteger sections;

/**
 *  来源
 */
@property (nonatomic, assign) LMLGDynamicEntitySource source;

/**
 *  动态标志
 *  0位 是否收藏过动态实体
 *  1位 是否赞过动态实体
 *  2位 是否收藏过帖子
 *  3位 是否赞过帖子
 */
@property (nonatomic, assign) NSInteger entityFlag;

/**
 *  被赞数
 */
@property (nonatomic, assign) NSInteger likeCount;

/**
 *  播放时长
 */
@property (nonatomic, assign) NSInteger playTime;

/**
 *  播放地址
 */
@property (nonatomic, strong) NSString * playUrl;

// 如果是要上传的声音的，需要一个fileId，用于上传
@property (nonatomic, assign) NSInteger fileId;

+ (instancetype)LGDynamicEntityWithDict:(NSDictionary *)dict;


WCDB_PROPERTY(entityId)
WCDB_PROPERTY(entityType)
WCDB_PROPERTY(entityName)
WCDB_PROPERTY(entityCover)


WCDB_PROPERTY(announcer)
WCDB_PROPERTY(playCount)
WCDB_PROPERTY(sections)
WCDB_PROPERTY(source)
WCDB_PROPERTY(entityFlag)
WCDB_PROPERTY(likeCount)
WCDB_PROPERTY(playTime)
WCDB_PROPERTY(playUrl)
WCDB_PROPERTY(fileId)


@end
