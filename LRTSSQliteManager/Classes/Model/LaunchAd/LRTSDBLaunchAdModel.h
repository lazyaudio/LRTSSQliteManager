//
//  LRTSDBLaunchAdModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>

typedef NS_ENUM(NSInteger, AdType) {
    AdTypeRecommend             = 1, // 精品推荐
    AdTypeTopicCategory         = 2, // 客户端专题分类广告
    AdTypeLaunch                = 3, // 懒人开屏广告
    AdTypeHomeBanner            = 4, // 听书首页banner广告
    AdTypeCategoryBanner        = 5, // 分类banner广告
    AdTypeHomeBannerAd          = 6, // 首页横幅广告
    AdTypeProgramBannerAd       = 7, // 主播电台banner统计
    AdTypeMission               = 11, // 任务广告
    AdTypeInterstitial          = 12, // 插屏广告
    AdTypeDiscoverBanner        = 13, // 发现页Banner广告
    AdTypeHomeNav               = 15, // app首页导航菜单广告
    AdTypeSmallBanner           = 16, // 列表小Banner广告
    AdTypeNative                = 17, // 信息流广告
    AdTypeBookDetailText        = 18, // 书籍详情页文字广告
    AdTypeProgramDetailText     = 19, // 节目详情页文字广告
    AdTypeDefalutNative         = 20, // 默认信息流广告
    AdTypeBookPlayerText        = 28, // 书籍播放器文字广告
    AdTypeProgramPlayerText     = 29, // 节目播放器文字广告
    AdTypeListenGroupBannerAd   = 30, // 听友会广告
    AdTypeBookPlayerIcon        = 33, // 书籍图标广告
    AdTypeProgrammePlayerIcon   = 34, // 节目播放器图标广告
    AdTypeBookPlayerCover       = 36, // 书籍播放器封面广告
    AdTypeProgrammePlayerCover  = 37, // 节目播放器封面广告
    AdTypeFloatAd               = 38, // 页脚悬浮广告
    
    // 上面是与服务器约定的广告类型，以下为自定义广告类型
    AdTypeInMobiLaunchAd        = 1001,// InMobi开屏广告
    AdTypeTouTiaoLaunchAd       = 1002,// 今日头条开屏广告
    AdTypeBaiduNativeAd         = 1003,// 百度信息流广告
    AdTypeGDTLaunchAd           = 1004,// 腾讯广点通广告
};

/**
 广告优先级
 
 - LMAdPriorityDefault: 默认优先级
 - LMAdPriorityHeight: 高优先级
 - LMAdPriorityLow: 低优先级
 */
typedef NS_ENUM(NSUInteger, LMAdPriority) {
    LMAdPriorityDefault = 0,
    LMAdPriorityHeight = 1,
    LMAdPriorityLow = 5,
};

// 广告子类型
typedef NS_ENUM(NSUInteger, LMAdSubType) {
    LMAdSubTypeDefault  = 0,
    LMAdSubTypeO2       = 301,
    LMAdSubTypeMaila    = 2701,
};

@interface LRTSDBLaunchAdModel : LRTSDBModel

/**
 基础参数
 */

/** 广告id */
@property (nonatomic, strong) NSString          *adId;
/** 广告名称，仅用于点击广告跳转时，下一个界面的标题 */
@property (nonatomic, strong) NSString          *adName;
/** 广告主 */
@property (nonatomic, strong) NSString          *owner;
/** 广告图片url */
@property (nonatomic, strong) NSString          *adIcon;
/** 广告显示的标题 */
@property (nonatomic, strong) NSString          *adTitle;
/** 广告描述 */
@property (nonatomic, strong) NSString          *adDesc;
/** 广告类型 */
@property (nonatomic, assign) AdType            adType;
/** 广告分类 */
@property (nonatomic, assign) AdCategory        adCategory;

/** 广告icon数组，多个广告图片 (Version 6.1.4) */
@property (nonatomic, copy) NSArray <NSString *>* adIconList;

/**
 广告点击与展示相关参数
 */

/** 广告处理行为类型,v3.0.3开始同publishType */
@property (nonatomic, assign) EntityPublishType adClickType;
/** 广告跳转链接/targetId，根据不同adPublishType含义不同，例如跳转到书籍详情，则该属性代表书籍ID */
@property (nonatomic, strong) NSString          *adClickUrl;
/** 广告生效日期(单位毫秒) */
@property (nonatomic, assign) NSTimeInterval    adShowStartTime;
/** 广告失效日期(单位毫秒) */
@property (nonatomic, assign) NSTimeInterval    adShowEndTime;
/** 广告显示的时间(单位秒) */
@property (nonatomic, assign) NSInteger         adStayTime;
/** 广告显示顺序 */
@property (nonatomic, assign) NSInteger         sort;
/** 广告的优先级，目前仅用于开屏广告，v3.0.3 */
@property (nonatomic, assign) LMAdPriority      adPriority;
/** 广告是否已经展示过，目前仅用于插屏广告 */
@property (nonatomic, assign) BOOL              isShowed;


/**
 请求广告的页面相关参数，目前仅用于信息流，小Banner等与页面相关的广告
 */

/** 请求广告的页面 */
@property (nonatomic, assign) EntityPublishType adPagePublishType;
/** 页面的TargetId，-1表示所有子栏目 */
@property (nonatomic, assign) long targetId;
/** 页面父TargetId，目前仅用在标签筛选页（PublishType为108），表示标签分类Id */
@property (nonatomic, assign) long parentTargetId;
/** 目标页面类型 */
@property (nonatomic, assign) NSInteger targetType;
/** 投放的页面子类型 0：详情页面， 1：资源列表页面 */
@property (nonatomic, assign) NSInteger subTargetType;
/** 是否展示动画*/
@property (nonatomic, assign) NSInteger animated;

/**
 广告统计相关的参数
 */

/** 广告展示是否带参数，0:不带参数 2:带参数，参数viewParam */
@property (nonatomic, assign) NSInteger         showUrlAddParam;
/** 广告点击是否带参数，0:不带参数 1:带参数，参数clickParam */
@property (nonatomic, assign) NSInteger         openUrlAddParam;
/** 广告点击统计url的参数 */
@property (nonatomic, strong) NSDictionary      *openArguDic;
/** 广告点击统计的参数字符串 */
@property (nonatomic, strong) NSString          *openArgName;
/** 广告展示统计url的参数 */
@property (nonatomic, strong) NSDictionary      *showArguDic;
/** 广告展示统计的参数字符串 */
@property (nonatomic, strong) NSString          *showArgName;
/** 广告显示PV统计链接 */
@property (nonatomic, strong) NSArray           *showStatisticUrls;
/** 广告点击PV统计链接 */
@property (nonatomic, strong) NSArray           *clickStatisticUrls;
/** 广告加载完成PV统计链接，目前只有InMobi开屏广告用到 */
@property (nonatomic, strong) NSArray           *loadedStatisticUrls;
/** 子广告类型: 默认：0， 腾讯O2广告：301，麦啦：2071 */
@property (nonatomic, assign) LMAdSubType       advertSubType;
/** 附带的模型类(因为LMLaunchAd对象的字段不能和其他广告平台的数据字段一一对应上，比如腾讯O2广告，而调用的地方又很多，所以加了一个attachModel) */
@property (nonatomic, strong) id attachModel;

/** 第三方SDK广告模型，目前仅用于百度信息流广告 */
@property (nonatomic, strong) id sdkAdModel;


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(adId)
WCDB_PROPERTY(adName)
WCDB_PROPERTY(owner)
WCDB_PROPERTY(adIcon)
WCDB_PROPERTY(adTitle)
WCDB_PROPERTY(adDesc)
WCDB_PROPERTY(adType)
WCDB_PROPERTY(adCategory)
WCDB_PROPERTY(adIconList)
WCDB_PROPERTY(adClickType)
WCDB_PROPERTY(adClickUrl)
WCDB_PROPERTY(adShowStartTime)
WCDB_PROPERTY(adShowEndTime)
WCDB_PROPERTY(adStayTime)
WCDB_PROPERTY(sort)
WCDB_PROPERTY(adPriority)
WCDB_PROPERTY(isShowed)
WCDB_PROPERTY(adPagePublishType)
WCDB_PROPERTY(targetId)
WCDB_PROPERTY(parentTargetId)
WCDB_PROPERTY(targetType)
WCDB_PROPERTY(subTargetType)
WCDB_PROPERTY(animated)
WCDB_PROPERTY(showUrlAddParam)
WCDB_PROPERTY(openUrlAddParam)
WCDB_PROPERTY(openArguDic)
WCDB_PROPERTY(openArgName)
WCDB_PROPERTY(showArguDic)
WCDB_PROPERTY(showArgName)
WCDB_PROPERTY(showStatisticUrls)
WCDB_PROPERTY(clickStatisticUrls)
WCDB_PROPERTY(loadedStatisticUrls)
WCDB_PROPERTY(advertSubType)
WCDB_PROPERTY(attachModel)
WCDB_PROPERTY(sdkAdModel)



@end
