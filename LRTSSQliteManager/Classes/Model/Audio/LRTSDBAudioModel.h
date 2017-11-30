//
//  LRTSDBAudioModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import <WCDB/WCDB.h>

//LRTSPublishStatus

//　发布声音的状态
typedef NS_ENUM(NSUInteger, LRTSPublishStatus) {
    PublishDefault = 0,             // 默认状态
    PublishFailureForToken = 1,     // 获取token失败
    PublishFailureForFieldId = 2,   // 获取fileId失败
    PublishFailureForBackUp = 3,    // 懒人服务器备份声音失败
    PublishSuccess = 4              // 上传成功
};

@interface LRTSDBAudioModel : LRTSDBModel

@property (nonatomic, strong) NSString *audioName;                  // 声音名字
@property (nonatomic, strong) NSString *audioPath;                  // 声音路径
@property (nonatomic, strong) NSString *audioDesc;                  // 声音描述
@property (nonatomic, assign) NSInteger audioSecondsCount;          // 时长
@property (nonatomic, assign) unsigned long audioSize;              // 文件大小
@property (nonatomic, assign) NSTimeInterval audioCreateTime;       // 创建时间
@property (nonatomic, assign) NSInteger audioGroupId;               // 听友会Id
@property (nonatomic, assign) NSInteger fileId;                     // 已经发布声音的文件id
@property (nonatomic, assign) NSInteger audioUserId;                // 用户id
@property (nonatomic, strong) NSString *audioUserNick;              // 用户昵称
@property (nonatomic, assign) LRTSPublishStatus pStatus;                // 声音发布状态(暂时不用)


#pragma mark - WCDB 数据绑定

WCDB_PROPERTY(audioName)
WCDB_PROPERTY(audioPath)
WCDB_PROPERTY(audioDesc)
WCDB_PROPERTY(audioSecondsCount)
WCDB_PROPERTY(audioSize)
WCDB_PROPERTY(audioCreateTime)
WCDB_PROPERTY(audioGroupId)
WCDB_PROPERTY(fileId)
WCDB_PROPERTY(audioUserId)
WCDB_PROPERTY(audioUserNick)
WCDB_PROPERTY(pStatus)

@end
