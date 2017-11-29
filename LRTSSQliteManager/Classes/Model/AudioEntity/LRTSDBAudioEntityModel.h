//
//  LRTSDBAudioEntityModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import <WCDB/WCDB.h>

//记录在数据库列表中的标识（服务于同步记录）
typedef NS_ENUM(NSInteger, RecrodStateType) {
    RecordStateDelete = -1, //删除标记
    RecordStateNewAdd = 0,  //新增标记
    RecordStateServer = 1   //服务器记录标记
};

@interface LRTSDBAudioEntityModel : LRTSDBModel

@property (nonatomic,assign) NSInteger entityId;        // 实体id
@property (nonatomic,assign) EntityType entityType;     // 实体类型
@property (nonatomic,strong) NSString *cover;           // 封面
@property (nonatomic,strong) NSString *title;           // 标题
@property (nonatomic,strong) NSString *author;          // 表示是采集还是原创主播
@property (nonatomic,strong) NSString *announcer;       // 播音
@property (nonatomic,assign) NSInteger audioCount;      // 声音数量
@property (nonatomic,assign) NSInteger commentCount;    // 评论数量
@property (nonatomic,assign) NSInteger source;          // 节目中标记播音是采集的还是原创的（1:原创 2:采集）

@property (nonatomic,assign) RecrodStateType stateType; // 在数据库中标记的修改状态

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(entityId)
WCDB_PROPERTY(entityType)
WCDB_PROPERTY(cover)
WCDB_PROPERTY(title)
WCDB_PROPERTY(author)
WCDB_PROPERTY(announcer)
WCDB_PROPERTY(audioCount)
WCDB_PROPERTY(commentCount)
WCDB_PROPERTY(source)
WCDB_PROPERTY(stateType)



@end
