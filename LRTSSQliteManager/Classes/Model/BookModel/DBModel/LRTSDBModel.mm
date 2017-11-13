//
//  LRTSDBModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBModel.h"
#import "LRTSOperation.h"

@implementation LRTSDBModel

- (BOOL)saved {
    return [[self lrtsOperation] insertOrReplaceObject:(NSObject<WCTTableCoding> *)self into:NSStringFromClass(self.class)];
}

- (id)getModelsWhere:(const LRTSCondition &)condition {
    return [[self lrtsOperation] getObjectsForTable:NSStringFromClass(self.class) where:condition];
}

- (BOOL)saveModels:(NSArray <LRTSObject *> *)dbModels {
    return [[self lrtsOperation] insertOrReplaceObjects:dbModels into:NSStringFromClass(self.class)];
}

#pragma mark - Private Methods

- (LRTSOperation *)lrtsOperation {
    return [[LRTSOperation alloc] initWithModel:(LRTSDBModel *)self];
}

@end
