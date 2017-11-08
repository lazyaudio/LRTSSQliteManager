//
//  LRTSDBAudioSubEntityDelegate.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <Foundation/Foundation.h>
#import "LRTSDBModel.h"

@protocol LRTSDBAudioSubEntityDelegate <NSObject>

@required 

@optional
- (NSInteger)hasBuy;

- (NSInteger)payType;

- (NSInteger)strategy;

- (EntityType) entityType;

@end
