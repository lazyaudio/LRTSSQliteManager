//
//  LRTSTagModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

//LRTSTagType

/**
 用户标签数据模型类
 */
typedef NS_ENUM(NSUInteger,LRTSTagType) {
    LRTSTagTypeListenBarBoutiqueTag = 1,             // 精品标签
    LRTSTagTypeVIPListenBarCountdownTag = 2,         // vip限免标签
    LRTSTagTypeListenBarAllCountdownTag = 3,         // 全部用户限免标签
    LRTSTagTypeVIPListenBarBookStoreTag = 4,         // 会员书库标签
    LRTSTagTypeVIPListenBarWholeAnticipateTag = 5,   // vip整本抢先标签
    LRTSTagTypeVIPListenBarPartAnticipateTag = 6,    // vip章节抢先标签
    LRTSTagTypeListenBarMarketingTag = 7,            // 营销活动标签
    LRTSTagTypeVIPDiscountTag = 21,                  // 会员折扣标签
    LRTSTagTypeListenOrReadTicketTag = 22,           // 支持听读券标签
    LRTSTagTypeSubscriptionBuyTag = 23,              // 支持订阅购买标签
    LRTSTagTypeListenBarToneTag = 24,                // 音质标签（高清、超清等）
    LRTSTagTypeReadCountdownTag = 101,               // 阅读书籍限免标签
    LRTSTagTypeReadRecommendSpecialTag = 102,        // 阅读书籍推荐特价标签
    LRTSTagTypeReadRecommendHotTag = 103,            // 阅读书籍推荐热门标签
    LRTSTagTypeReadRecommendPotentialTag = 104,      // 阅读书籍推荐潜力标签
    LRTSTagTypeReadRecommendBigGodTag = 105,         // 阅读书籍推荐神作标签
    LRTSTagTypeReadMarketingTag = 120,               // 阅读书籍营销标签
};

@interface LRTSTagModel : LRTSDBModel

@property (nonatomic,assign) LRTSTagType tg_type;    // 标签类型
@property (nonatomic,copy)   NSString *tg_name;     // 标签名称
@property (nonatomic,copy)   NSString *tg_bgColor;  // 标签颜色

@end
