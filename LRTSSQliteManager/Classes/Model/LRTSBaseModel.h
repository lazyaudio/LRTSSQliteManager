//
//  LRTSBaseModel.h
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import <Foundation/Foundation.h>
#import "WCTCodingMacro.h"
#import "WCTCoding.h"
#import "WCTBinding.h"
#import "WCTProperty.h"
#import "WCTAnyProperty.h"
#import "WCTError.h"

@interface LRTSBaseModel : NSObject

/**
 * 全局实体类型
 */
typedef NS_ENUM(NSInteger, EntityType) {
    EntityTypeUnknow       = 0,// 未知
    EntityTypeSound        = 1,// 声音
    EntityTypeAlbum        = 2,// 专辑
    EntityTypeBook         = 4,// 书籍
    EntityTypeDynamic      = 5,// 动态
    EntityTypeGroupDynamic = 6,// 听友会动态
    EntityTypeListenFolder = 7,// 听单
    EntityTypeReading      = 8,// 阅读
    EntityTypeBookStore    = 10,//书架
    EntityTypeBookComment  = 11,//书评
};

/**
 播放入口,是从在线进入还是从下载进入
 */
typedef NS_ENUM(NSInteger, EnterPlayType) {
    EnterPlayTypeFromOnline = 0,
    EnterPlayTypeFromDownload,
};

typedef  NS_ENUM(NSInteger, StrategyType) {
    StrategyType_VIPFreeLimits    = 1 << 0,    // 会员限免
    StrategyType_VIPBookStore     = 1 << 1,    // 会员书库(可能是会员限免或者抢先)
    StrategyType_ScoopBook        = 1 << 2,    // 整本抢先
    StrategyType_ScoopSection     = 1 << 3,    // 章节抢先
    StrategyType_AllFreeLimits    = 1 << 4,    // 全部限免
};

@end
