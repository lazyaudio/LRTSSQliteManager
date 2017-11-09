//
//  LRTSDBAnnoucerModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBAnnoucerModel.h"

@interface LRTSDBAnnoucerModel (InitializationAndConfiguration)

// 判断一个用户是否是主播，是主播的条件是：是社区主播或者书城主播
- (BOOL)isAnnouner;

@end
