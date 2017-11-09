//
//  LRTSDBDownloadModel+InitializationAndCategories.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBDownloadModel.h"
#import "LRTSDBBookModel.h"
#import "LRTSDBSectionModel.h"

@interface LRTSDBDownloadItemModel (InitializationAndCategories)

- (instancetype)initWithDict:(NSDictionary *)dict;
// 使用书籍模型类初始化
- (instancetype)initWithBook:(LRTSDBBookModel *)book;
// 使用章节模型类初始化
- (instancetype)initWithSection:(LRTSDBSectionModel *)section;

// 根据LMDownloadModel的TaskID
- (instancetype) initWithTaskId:(NSString *)taskId;

// 根据dId，dEntityId，entityType得到taskID
- (NSString *)getTaskId;

+ (instancetype)downloadWithTaskId:(NSString *)taskId;

@end
