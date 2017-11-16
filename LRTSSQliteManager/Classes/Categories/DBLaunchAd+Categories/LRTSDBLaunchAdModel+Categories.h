//
//  LRTSDBLaunchAdModel+Categories.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBLaunchAdModel.h"
#import "LRTSDBTecentO2AdModel.h"
#import "LRTSDBAdMacro.h"
#import "LRTSDBPublicTypeDefine.h"

@interface LRTSDBLaunchAdModel (Categories)

// 将缓存数据解析为广告数据模型，可能是懒人开屏广告，也可能是第三方开屏广告
+ (NSArray *)getLaunchAdWithData:(id)dataSource;

// 将字典转换为广告模型
+ (LRTSDBLaunchAdModel *)getLaunchAdWithDic:(NSDictionary *)dic;

// 将开屏广告模型转换为字典，用于缓存
- (NSDictionary *)dicFromLMLaunchAd;

/** 广告类型返回一个指定的名称 */
- (NSString *)typeName;

/** 是否是商业广告 */
- (BOOL)isCommercialAd;

@end

@interface LRTSDBLaunchAdModel (AddUrlParams)
+ (NSString *)addParamByUrl:(NSString *)urlStr argu:(NSDictionary *)argu;
@end

// 下载广告图片
@interface LRTSDBLaunchAdModel (DownloadAdImage)

/** 下载广告图片 */
- (BOOL)dowloadAdImg;
- (BOOL)downloadAdImageWithCompletion:(void (^)(UIImage *image))completion;
- (BOOL)downloadAdImageWithUrl:(NSString *)url Completion:(void (^)(UIImage *image))completion;

/** 广告图片是否已经下载 */
- (BOOL)checkAdImageDownloaded;

/** 返回真实的广告图片链接，添加了640x765等后缀，目前仅用于开屏广告 */
- (NSString *)realImageUrl;

@end

//@class LMTecentO2AdModel;
@interface LRTSDBLaunchAdModel (TencentO2)

- (BOOL)isTencentO2LaunchAd;
+ (LRTSDBLaunchAdModel *)constructAdFromTencentO2LaunchAd:(LRTSDBTecentO2AdModel *)tencentAd;

@end
