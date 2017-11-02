//
//  LRTSBaseOperation.h
//  Kiwi
//
//  Created by Jack Bai on 2017/10/31.
//

#import <Foundation/Foundation.h>
#import "LRTSDeclare.h"

@interface LRTSBaseOperation : NSObject

#pragma mark - Abstract Methods

- (BOOL)insertObject:(LRTSObject *)object;

- (BOOL)deleteObjectsWhere:(const LRTSCondition &)condition;

- (BOOL)updateRowsWithValue:(const LRTSValue &)value onObject:(LRTSObject *)object;

- (id)getOneObject;

- (NSArray *)getAllObjects;

@end
