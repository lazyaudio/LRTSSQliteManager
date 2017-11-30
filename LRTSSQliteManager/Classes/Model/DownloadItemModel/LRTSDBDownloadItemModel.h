//
//  LRTSDBDownloadModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDownloadState.h"
#import <WCDB/WCDB.h>

@interface LRTSDBDownloadItemModel : LRTSDBModel

// 新加字段 上面字段都需要弃用
@property (assign, nonatomic) NSInteger      dId;                   // 下载资源的id
@property (nonatomic, assign) NSInteger      dEntityId;             // 资源所属实体ID
@property (assign, nonatomic) long long      fileSize;              // 下载文件大小
@property (strong, nonatomic) NSString       *name;                 // 下载任务标题
@property (assign, nonatomic) LRTSDownloadStatus downloadStatus;        // 下载状态
@property (assign, nonatomic) CGFloat        downloadProgress;      // 下载进度
@property (assign, nonatomic) NSInteger      dSection;              // 下载资源在列表中的序号
@property (assign, nonatomic) NSInteger      dHasLyric;             // 下载内容是否有文本
@property (strong, nonatomic) NSString       *dSourceUrl;           // 下载资源的url
@property (assign, nonatomic) LRTSEntityType     entityType;            // 实体类型

//TODO 注册掉
//@property (nonatomic, strong) id             belong;                // 属于的实体(书籍或者节目)
@property (nonatomic, assign) NSTimeInterval insertDBTime;          // 插入数据库的时间
@property (nonatomic, strong) NSString       *targetPath;           // 文件的本地下载目标路径

@property (nonatomic, strong) NSString       *entityName;           //资源标题
@property (nonatomic, assign) NSInteger      countAudio;           //有多少个资源
@property (nonatomic, strong) NSString       *announer;             //主播

@property (nonatomic, strong) NSString *cover;


#pragma mark - WCDB 数据绑定

WCDB_PROPERTY(dId)
WCDB_PROPERTY(dEntityId)
WCDB_PROPERTY(fileSize)
WCDB_PROPERTY(name)
WCDB_PROPERTY(downloadStatus)
WCDB_PROPERTY(downloadProgress)
WCDB_PROPERTY(dSection)
WCDB_PROPERTY(dHasLyric)
WCDB_PROPERTY(dSourceUrl)
WCDB_PROPERTY(entityType)


//WCDB_PROPERTY(belong)
WCDB_PROPERTY(insertDBTime)
WCDB_PROPERTY(targetPath)
WCDB_PROPERTY(entityName)
WCDB_PROPERTY(countAudio)
WCDB_PROPERTY(announer)
WCDB_PROPERTY(cover)

@end
