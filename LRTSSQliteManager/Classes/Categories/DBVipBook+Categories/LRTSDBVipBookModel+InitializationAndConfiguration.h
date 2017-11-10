//
//  LRTSDBVipBookModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBVipBookModel.h"
#import "LRTSCellDataSourceDelegate.h"


@interface LRTSDBVipBookModel (InitializationAndConfiguration)<LRTSCellDataSourceDelegate>

// 获取vip书籍
+ (NSArray<LRTSDBVipBookModel *> *)vipRecommandBookListWithDicts:(NSArray *)dicts;

@end
