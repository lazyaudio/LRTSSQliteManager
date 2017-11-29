//
//  LRTSDBProgrammeAudioModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDownloadState.h"
#import <WCDB/WCDB.h>


@interface LRTSDBProgrammeAudioModel : LRTSDBModel

@property (assign, nonatomic) long aId;        // 资源ID
@property (nonatomic, assign) long programmeId;     // 节目ID
@property (copy  , nonatomic) NSString  *name;      // 资源名
@property (copy  , nonatomic) NSString  *url;       // 资源文件路径
@property (assign, nonatomic) NSInteger length;     // 音频时长
@property (assign, nonatomic) NSInteger size;       // 声音文件大小
@property (assign, nonatomic) NSInteger section;    // 第几个声音
@property (assign, nonatomic) NSTimeInterval insertDBTime;// 插入数据库的时间
@property (assign, nonatomic) CGFloat        downloadProgress; // 下载进度
@property (assign, nonatomic) DownloadStatus downloadStatus;// 下载状态
@property (assign, nonatomic) NSTimeInterval playTime;//播放进度
@property (nonatomic, strong) NSString  *cover;     // 声音封面

@property (nonatomic, assign) NSInteger hasBuy;
@property (nonatomic, assign) NSInteger payType;
@property (nonatomic, assign) long strategy;
@property (nonatomic, assign) NSInteger pageNum;

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(aId)
WCDB_PROPERTY(programmeId)
WCDB_PROPERTY(name)
WCDB_PROPERTY(url)
WCDB_PROPERTY(length)
WCDB_PROPERTY(size)
WCDB_PROPERTY(section)
WCDB_PROPERTY(insertDBTime)
WCDB_PROPERTY(downloadProgress)
WCDB_PROPERTY(downloadStatus)
WCDB_PROPERTY(playTime)
WCDB_PROPERTY(cover)

WCDB_PROPERTY(hasBuy)
WCDB_PROPERTY(payType)
WCDB_PROPERTY(strategy)
WCDB_PROPERTY(pageNum)



@end
