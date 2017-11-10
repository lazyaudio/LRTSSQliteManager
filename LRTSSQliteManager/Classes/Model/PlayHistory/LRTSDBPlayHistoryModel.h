//
//  LRTSDBPlayHistoryModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBAudioEntityModel.h"


@interface LRTSDBPlayHistoryModel : LRTSDBAudioEntityModel

@property (nonatomic,assign) NSInteger historyId;       // 收听id
@property (nonatomic,assign) NSInteger audioId;         // 播放的声音id
@property (nonatomic,assign) NSInteger audioIndex;      // 所在声音的index
@property (nonatomic,assign) CGFloat progress;          // 声音播放的进度
@property (nonatomic,assign) NSInteger entityState;     // 书籍状态 0:连载 1:完结（只有书籍有，其他的没有）
@property (nonatomic,assign) NSInteger updateState;     // 书籍是否有更新 0:无更新 1:有更新(目前只有书籍有)
@property (nonatomic,assign) NSInteger enterType;       // 播放入口（0在线 1本地）
@property (nonatomic,assign) NSTimeInterval updateTime; // 最后收听时间
@property (nonatomic,assign) NSTimeInterval playSeconds;// 有效播放时长

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(historyId)
WCDB_PROPERTY(audioId)
WCDB_PROPERTY(audioIndex)
WCDB_PROPERTY(progress)


WCDB_PROPERTY(entityState)
WCDB_PROPERTY(updateState)
WCDB_PROPERTY(enterType)
WCDB_PROPERTY(updateTime)
WCDB_PROPERTY(playSeconds)



@end
