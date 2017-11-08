//
//  LRTSDBOperationDelegate.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import <Foundation/Foundation.h>
#import "LRTSDeclare.h"

@class LRTSDBModel;

@protocol LRTSDBOperationDelegate <NSObject>

@required

- (BOOL)saved;

//- (BOOL)deleted;

- (id)getModelsWhere:(const LRTSCondition &)condition;

@optional


/**
 反人类的接口

 @param dbModels 传入需要保存的数据 Model 类
 @return 返回是否成功
 */

- (BOOL)saveModels:(NSArray <LRTSObject *> *)dbModels;

//- (BOOL)deleteModelWhere:(const LRTSCondition &)condition;

@end
