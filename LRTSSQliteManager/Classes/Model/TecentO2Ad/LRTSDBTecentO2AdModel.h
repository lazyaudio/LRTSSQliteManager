//
//  LRTSDBTecentO2AdModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import <WCDB/WCDB.h>


@interface LRTSDBTecentO2AdModel : LRTSDBModel

@property (nonatomic, assign) CGFloat width;   // 素材宽度
@property (nonatomic, assign) CGFloat height;  // 素材高度
@property (nonatomic, strong) NSString *scheduleId; // 排期id
@property (nonatomic, strong) NSString *gameId;     // 游戏id
@property (nonatomic, strong) NSString *locationId; // 广告位id
@property (nonatomic, strong) NSString *channelId;  // 渠道id
@property (nonatomic, strong) NSString *desc;       // 广告描述
@property (nonatomic, strong) NSString *appName;    // 广告中的应用名称
@property (nonatomic, strong) NSString *sign;  // 签名
@property (nonatomic, strong) NSString *sourceUrl;   // 素材地址(图片地址)
@property (nonatomic, strong) NSURL    *pvUrl; // 展示时的上报url
@property (nonatomic, strong) NSURL    *cvUrl; // 点击时的上报url
@property (nonatomic, strong) NSURL    *downloadUrl; // 跳转到App Store的地址

- (instancetype)initWithDict:(NSDictionary *)dict;


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(width)
WCDB_PROPERTY(height)
WCDB_PROPERTY(scheduleId)
WCDB_PROPERTY(gameId)
WCDB_PROPERTY(locationId)
WCDB_PROPERTY(channelId)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(appName)
WCDB_PROPERTY(sign)
WCDB_PROPERTY(sourceUrl)
WCDB_PROPERTY(pvUrl)
WCDB_PROPERTY(cvUrl)
WCDB_PROPERTY(downloadUrl)


@end
