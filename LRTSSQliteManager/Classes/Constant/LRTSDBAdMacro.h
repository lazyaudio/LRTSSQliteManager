//
//  LRTSDBAdMacro.h
//  Pods
//
//  Created by JackJin on 2017/11/9.
//

#ifndef LRTSDBAdMacro_h
#define LRTSDBAdMacro_h

// realIndexPath是修改之前的indexPath，没有加入广告逻辑的indexPath
#define DefineIndexPathCopy(indexPath) NSIndexPath *realIndexPath = [indexPath copy];

/** 信息流广告相关的宏 */

#define HandleNativeAdAsRowReturnVoid(indexPath) NSArray *ads = [self handlerAdsAsListRowWithIndexPath:&indexPath adCategory:AdCategoryNativeAd];\
if (ads.count) {\
return;\
}

#define HandleNativeAdAsRowReturnCellForRowAtIndexPath(indexPath, showInSection) DefineIndexPathCopy(indexPath)\
if (indexPath.section == showInSection) {\
NSArray *ads = [self handlerAdsAsListRowWithIndexPath:&indexPath adCategory:AdCategoryNativeAd];\
if (ads.count) {\
return [self.adSession createAdCellWithAds:ads indexPath:realIndexPath];\
}\
}

#define HandleNativeAdAsRowReturnHeightForRowAtIndexPath(indexPath, showInSection) if (indexPath.section == showInSection) {\
NSArray *ads = [self handlerAdsAsListRowWithIndexPath:&indexPath adCategory:AdCategoryNativeAd];\
if (ads.count) {\
return [self.adSession heightForCellWithAdCategory:AdCategoryNativeAd];\
}\
}

#define NumberOfNativeAdCell [self.adSession numberOfAdCellWithCategory:AdCategoryNativeAd]

/** 小Banner广告相关的宏 */

#define HandleSmallBannerAdAsSectionReturnVoid(indexPath) NSArray *ads = [self handlerAdsAsListSectionWithIndexPath:&indexPath adCategory:AdCategorySmallBannerAd];\
if (ads) {\
return;\
}

#define HandleSmallBannerAdAsSectionReturnCellForRowAtIndexPath(indexPath) DefineIndexPathCopy(indexPath)\
NSArray *ads = [self handlerAdsAsListSectionWithIndexPath:&indexPath adCategory:AdCategorySmallBannerAd];\
if (ads) {\
return [self.adSession createAdCellWithAdCategory:AdCategorySmallBannerAd indexPath:realIndexPath];\
}

#define HandleSmallBannerAdAsSectionReturnHeightForRowAtIndexPath(indexPath) NSArray *ads = [self handlerAdsAsListSectionWithIndexPath:&indexPath adCategory:AdCategorySmallBannerAd];\
if (ads) {\
return [self.adSession heightForCellWithAdCategory:AdCategorySmallBannerAd];\
}

#define HandleSmallBannerAdAsSectionReturnNumberOfRowAtSection(section) NSArray *ads = [self handlerAdsAsListSectionWithSection:&section adCategory:AdCategorySmallBannerAd];\
if (ads) {\
return 1;\
}

#define NumberOfSmallBannerAdSection [self.adSession numberOfAdCellWithCategory:AdCategorySmallBannerAd]

/**
 广告的分类
 
 - AdCategoryOpenLaunchAd: 开屏广告
 - AdCategoryNativeAd: 信息流广告
 - AdCategoryInterstitialAd: 插屏广告
 - AdCategorySmallBannerAd: 小Banner广告
 - AdCategoryBannerAd: Banner广告
 - AdCategorySuspensionAd: 悬浮广告（详情页）
 - AdCategoryDiscoverAd: 发现页小Banner广告
 - AdCategoryDetailTextAd: 详情页文字广告
 - AdCategoryHomeNavAd: 首页导航广告
 - AdCategoryPlayerTextAd: 播放器文字广告
 - AdCategoryPlayerCoverAd:播放器封面广告
 - AdCategoryPlayerIconAd:播放器图标广告
 - AdCategoryFloatAd: 浮动广告
 */
typedef NS_OPTIONS(NSUInteger, AdCategory) {
    AdCategoryOpenLaunchAd = 1 << 0,
    AdCategoryNativeAd = 1 << 1,
    AdCategoryInterstitialAd = 1 << 2,
    AdCategorySmallBannerAd = 1 << 3,
    AdCategoryBannerAd = 1 << 4,
    AdCategorySuspensionAd = 1 << 5,
    AdCategoryDiscoverAd = 1 << 6,
    AdCategoryDetailTextAd = 1 << 7,
    AdCategoryHomeNavAd = 1 << 8,
    AdCategoryPlayerTextAd = 1 << 9,
    AdCategoryPlayerCoverAd = 1 << 10,
    AdCategoryPlayerIconAd = 1 << 11,
    AdCategoryFloatAd      = 1 << 12,
};

#endif /* LRTSDBAdMacro_h */
