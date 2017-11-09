//
//  LRTSDBListenCollectionModel+Convention.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBListenCollectionModel.h"

@interface LRTSDBListenCollectionModel (Convention)

// 收藏、创建的听单
+ (NSArray *)converListenCollectionListFromServerData:(id)object;

// 推荐、好评、最新听单
+ (NSArray *)converFolderListFromServerData:(id)object;

+ (NSArray *)converFolderListFromDicts:(NSArray *)dicts;

// 获取包含指定书籍的听单列表
+ (NSArray *)converFolderListIncludeEntityFromServerData:(id)object;

@end
