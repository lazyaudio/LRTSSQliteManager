//
//  LRTSDBEntityModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBEntityModel.h"

#import "LRTSDBBookModel.h"
#import "LRTSDBBookDetailModel.h"
#import "LRTSDBProgrammeModel.h"
#import "LRTSDBTopicModel.h"
#import "LRTSDBAnnoucerModel.h"
#import "LRTSDBCategoryModel.h"
#import "LRTSDBCustomCategoryModel.h"
#import "LRTSDBListenCollectionModel.h"
#import "LRTSDBDiscoverCategoryModel.h"
#import "LRTSDBTecentO2AdModel.h"
#import "LRTSDBLabelResourceModel.h"


@interface LRTSDBEntityModel (InitializationAndConfiguration)

+ (NSArray *)parseDataFromRecommendBanner:(id)dataSource;

+ (NSArray *)parseDataFromPerDayRecommend:(id)dataSource;

@end

@interface LRTSDBEntityModel (Initialize)

// 将外部跳转的url转化为LRTSDBEntityModel
+ (LRTSDBEntityModel *)entityWithPushUrl:(NSString *)urlStr;

@end

@interface LRTSDBBookModel (EntityConvert)

+ (LRTSDBBookModel *)convertToBookFromEntity:(LRTSDBEntityModel *)entity;

@end

@interface LRTSDBBookDetailModel (EntityConvert)

+ (LRTSDBBookDetailModel *)convertToBookDetailFromEntity:(LRTSDBEntityModel *)entity;

@end

@interface LRTSDBProgrammeModel (EntityConvert)

+ (LRTSDBProgrammeModel *)convertToProgramFromEntity:(LRTSDBEntityModel *)entity;
+ (LRTSDBEntityModel *)convertToEntityFromProgram:(LRTSDBProgrammeModel *)programme;

@end

@interface LRTSDBTopicModel (EntityConvert)

+ (LRTSDBTopicModel *)convertToTopicFromEntity:(LRTSDBEntityModel *)entity;

@end

@interface LRTSDBAnnoucerModel (EntityConvert)

+ (LRTSDBAnnoucerModel *)convertToAnnouncerFromEntity:(LRTSDBEntityModel *)entity;

@end

@interface LMRadioCategory (EntityConvert)

+ (LMRadioCategory *)convertToRadioCategoryFromEntity:(LRTSDBEntityModel *)entity;

@end

@interface LRTSDBLaunchAdModel (EntityConvert)

+ (LRTSDBEntityModel *)convertToEntityFromAd:(LRTSDBLaunchAdModel *)ad;
+ (NSArray<LRTSDBEntityModel *> *)convertToEntityListFromAds:(NSArray<LRTSDBLaunchAdModel *> *)ads;

/**
 * 拼装banner广告和banner的原始数据
 * @param recommendBanner 推荐的banner数据
 * @param adBanners       广告banner数据
 * @return 拼装后的banner数据
 */
+ (NSArray *)combineRawBanner:(NSArray *)recommendBanner withAds:(NSArray *)adBanners;

@end

@interface LRTSDBDiscoverCategoryModel (EntityConvert)
+ (LRTSDBEntityModel *)covertToEntityFromDiscovery:(LRTSDBDiscoverCategoryModel *)category;
@end

@interface LRTSDBTecentO2AdModel (EntityConvert)
+ (LRTSDBEntityModel *)convertToEntityFromTencentAPIAd:(LRTSDBTecentO2AdModel *)model;
@end

@interface LRTSDBLabelResourceModel (EntityConvert)
+ (LRTSDBEntityModel *)convertToEntityFromLabelResource:(LRTSDBLabelResourceModel *)labelResource;
@end

