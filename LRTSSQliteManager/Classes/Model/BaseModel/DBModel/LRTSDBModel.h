//
//  LRTSDBModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//
//
//  数据库的操作 model，依托 LRTSOperation 
//
//  实现对 model 的最基本的操作实现
//

#import "LRTSModel.h"

//LRTSEntityType
//LRTSEnterPlayType
//LRTSStrategyType

/**
 * 全局实体类型
 */
typedef NS_ENUM(NSInteger, LRTSEntityType) {
    LRTSEntityTypeUnknow       = 0,// 未知
    LRTSEntityTypeSound        = 1,// 声音
    LRTSEntityTypeAlbum        = 2,// 专辑
    LRTSEntityTypeBook         = 4,// 书籍
    LRTSEntityTypeDynamic      = 5,// 动态
    LRTSEntityTypeGroupDynamic = 6,// 听友会动态
    LRTSEntityTypeListenFolder = 7,// 听单
    LRTSEntityTypeReading      = 8,// 阅读
    LRTSEntityTypeBookStore    = 10,//书架
    LRTSEntityTypeBookComment  = 11,//书评
};

/**
 * 播放入口,是从在线进入还是从下载进入
 */
typedef NS_ENUM(NSInteger, LRTSEnterPlayType) {
    LRTSEnterPlayTypeFromOnline = 0,
    LRTSEnterPlayTypeFromDownload,
};

typedef NS_ENUM(NSInteger, LRTSLRTSStrategyType) {
    LRTSStrategyType_VIPFreeLimits    = 1 << 0,    // 会员限免
    LRTSStrategyType_VIPBookStore     = 1 << 1,    // 会员书库(可能是会员限免或者抢先)
    LRTSStrategyType_ScoopBook        = 1 << 2,    // 整本抢先
    LRTSStrategyType_ScoopSection     = 1 << 3,    // 章节抢先
    LRTSStrategyType_AllFreeLimits    = 1 << 4,    // 全部限免
};


@interface LRTSDBModel : LRTSModel 


@end





