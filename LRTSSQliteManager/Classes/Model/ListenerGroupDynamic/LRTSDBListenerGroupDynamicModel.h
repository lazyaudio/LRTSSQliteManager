//
//  LRTSDBListenerGroupDynamicModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

typedef enum : NSUInteger {
    LMDynamicUserRoleTypeNone          = 0,//无角色
    LMDynamicUserRoleTypePresident     = 1,//会长
    LMDynamicUserRoleTypeVicePresident = 2,//副会长
} LMDynamicUserRoleType;//动态用户角色类型

typedef enum : NSUInteger {
    LMDynamicContentTypeNormal      = 0,//普通
    LMDynamicContentTypeTop         = 1,//置顶
    LMDynamicContentTypeRecommend   = 2,//推荐
} LMDynamicContentType;//动态所属分类

typedef enum : NSUInteger {
    LMDynamicContentSourceTypeSound     = 1,//声音
    LMDynamicContentSourceTypeRecommend = 16,//推荐
    LMDynamicContentSourceTypeTopic     = 17,//帖子
} LMDynamicContentSourceType;//动态的产生类型

typedef enum : NSUInteger {
    LMLGDynamicTypeNormalByTime    = 1,//按照时间排序（发布时间）获取小组动态
    LMLGDynamicTypeSoundByTime     = 2,//按照时间排序（上传时间）获取小组声音
    LMLGDynamicTypeByLikeCount     = 3,//按照被赞数获取小组声音动态(v2.1.7以前)
    LMLGDynamicTypeRecommend       = 4,//获取小组推荐动态(v2.1.7以前)
    LMLGDynamicTypeRecommendByTime = 5,//按照时间排序（推荐时间）获取小组推荐
    LMLGDynamicTypeNormalByHot     = 6,//按照热度排序获取小组动态
    LMLGDynamicTypeSoundByHot      = 7,//按照热度排序获取小组声音
    LMLGDynamicTypeRecommendByHot  = 8,// 按照热度排序获取小组推荐
    LMLGDynamicTypeUserByTime      = 100//根据用户按照时间排序获取小组动态
    
} LMLGDynamicType;


@interface LRTSDBListenerGroupDynamicModel : LRTSDBModel

/**
 *  动态ID
 */
@property (nonatomic, assign) NSInteger contentId;

/**
 *  动态的用户Id
 */
@property (nonatomic, assign) NSInteger userId;

/**
 *  动态的用户昵称
 */
@property (nonatomic, strong) NSString * userNick;

/**
 *  动态的用户头像
 */
@property (nonatomic, strong) NSString * userCover;

/**
 *  用户角色
 */
@property (nonatomic, assign) LMDynamicUserRoleType userRoleType;

/**
 *  全局flag
 */
@property (nonatomic, assign) NSInteger flag;

/**
 *  动态描述
 */
@property (nonatomic, strong) NSString * dynamicDesc;

/**
 *  动态详情界面的动态描述
 */
@property (nonatomic, strong) NSString * dynamicDescForDetail;

/**
 *  动态创建时间
 */
@property (nonatomic, assign) NSTimeInterval createTime;

/**
 *  动态评论总数
 */
@property (nonatomic, assign) NSInteger commentCount;

/**
 *  被赞数
 */
@property (nonatomic, assign) NSInteger likeCount;

/**
 *  缩略图地址
 */
@property (nonatomic, strong) NSString * topicPic;

/**
 *  听友会ID
 */
@property (nonatomic, assign) NSInteger groupID;

/**
 *  大图的地址
 *  加载过一次大图地址后，就把大图地址记录下来，下次在加载时就不用再请求大图地址了
 */
@property (nonatomic, strong) NSString * bigTopicPic;

/**
 *  动态所属类型
 */
@property (nonatomic, assign) LMDynamicContentType contentType;

/**
 *  动态的产生类型
 */
@property (nonatomic, assign) LMDynamicContentSourceType contentSource;

/**
 *  动态实体
 */
@property (nonatomic, strong) LMLGDynamicEntity * entity;

/**
 *  是否是充值会员
 */
@property (nonatomic, assign, getter=isMember) BOOL member;

/**
 *  是否要显示重发按钮
 */
@property (nonatomic, assign, getter=isShowRepublish) BOOL showRepublish;


#pragma mark - check url and topic

/**
 *  带属性链接的字符串（目前只支持话题链接，后期会考虑把url链接也加进来）
 */
@property (nonatomic, strong) NSArray * attributies;

/**
 *  针对话题详情的带属性链接的字符串（目前只支持话题链接，后期会考虑把url链接也加进来）
 */
@property (nonatomic, strong) NSArray * attributiesForDetail;

/**
 *  是否存在链接
 */
@property (nonatomic, assign, getter=isHaveLink) BOOL haveLink;

/**
 *  表示链接的字符串的范围
 */
@property (nonatomic, assign) NSRange linkStrRange;

/**
 *  链接地址
 */
@property (nonatomic, strong) NSString * linkAddress;

/**
 *  图片的路径，用于缓存带图片的帖子
 */
@property (nonatomic, strong) NSString * imageFilePath;

/**
 *  书评所属资源id(v6.1.1)
 */
@property (nonatomic,assign) NSInteger resourceId;

/**
 *  瀑布流排序参数(v6.1.1)
 */
@property (nonatomic,assign) NSInteger referId;

              
#pragma mark - WCDB
              
WCDB_PROPERTY(contentId)
WCDB_PROPERTY(userId)
WCDB_PROPERTY(userNick)
WCDB_PROPERTY(userCover)
WCDB_PROPERTY(userRoleType)
WCDB_PROPERTY(flag)
WCDB_PROPERTY(dynamicDesc)
WCDB_PROPERTY(dynamicDescForDetail)
WCDB_PROPERTY(createTime)
WCDB_PROPERTY(commentCount)
WCDB_PROPERTY(likeCount)
WCDB_PROPERTY(topicPic)
WCDB_PROPERTY(groupID)
WCDB_PROPERTY(bigTopicPic)
WCDB_PROPERTY(contentType)
WCDB_PROPERTY(contentSource)
WCDB_PROPERTY(entity)
WCDB_PROPERTY(member)
WCDB_PROPERTY(showRepublish)
WCDB_PROPERTY(attributies)
WCDB_PROPERTY(attributiesForDetail)
WCDB_PROPERTY(haveLink)
WCDB_PROPERTY(linkStrRange)
WCDB_PROPERTY(linkAddress)
//
WCDB_PROPERTY(imageFilePath)
WCDB_PROPERTY(resourceId)
WCDB_PROPERTY(referId)

@end
