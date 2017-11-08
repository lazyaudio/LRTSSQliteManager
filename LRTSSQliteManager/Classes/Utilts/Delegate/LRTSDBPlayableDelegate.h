//
//  LRTSPlayableDelegate.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <Foundation/Foundation.h>
#import "LRTSDBPlayItemModel.h"

@protocol LRTSDBPlayableDelegate <NSObject>

@required

@optional
/*** 模型类转换成播放模型类 */
- (LRTSDBPlayItemModel *)convertToPlayItem;

+ (LRTSDBModel *)convertToBaseModel:(LRTSDBPlayItemModel *)playItem;

@end
