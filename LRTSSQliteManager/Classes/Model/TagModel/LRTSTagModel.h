//
//  LRTSTagModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>

/**
 用户标签数据模型类
 */
typedef NS_ENUM(NSUInteger,LMTagType) {
    LMListenBarBoutiqueTag = 1,             // 精品标签
    LMVIPListenBarCountdownTag = 2,         // vip限免标签
    LMListenBarAllCountdownTag = 3,         // 全部用户限免标签
    LMVIPListenBarBookStoreTag = 4,         // 会员书库标签
    LMVIPListenBarWholeAnticipateTag = 5,   // vip整本抢先标签
    LMVIPListenBarPartAnticipateTag = 6,    // vip章节抢先标签
    LMListenBarMarketingTag = 7,            // 营销活动标签
    LMVIPDiscountTag = 21,                  // 会员折扣标签
    LMListenOrReadTicketTag = 22,           // 支持听读券标签
    LMSubscriptionBuyTag = 23,              // 支持订阅购买标签
    LMListenBarToneTag = 24,                // 音质标签（高清、超清等）
    LMReadCountdownTag = 101,               // 阅读书籍限免标签
    LMReadRecommendSpecialTag = 102,        // 阅读书籍推荐特价标签
    LMReadRecommendHotTag = 103,            // 阅读书籍推荐热门标签
    LMReadRecommendPotentialTag = 104,      // 阅读书籍推荐潜力标签
    LMReadRecommendBigGodTag = 105,         // 阅读书籍推荐神作标签
    LMReadMarketingTag = 120,               // 阅读书籍营销标签
};

@interface LRTSTagModel : LRTSDBModel

@property (nonatomic,assign) LMTagType tg_type;    // 标签类型
@property (nonatomic,copy)   NSString *tg_name;     // 标签名称
@property (nonatomic,copy)   NSString *tg_bgColor;  // 标签颜色

@end
