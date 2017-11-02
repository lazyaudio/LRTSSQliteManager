//
//  LRTSBaseOperation.m
//  Kiwi
//
//  Created by Jack Bai on 2017/10/31.
//

#import "LRTSBaseOperation.h"

@implementation LRTSBaseOperation

- (instancetype)init {
    if ([self isMemberOfClass:[LRTSBaseOperation class]]) {
        [self doesNotRecognizeSelector:_cmd];
        return nil;
    }else {
        self = [super init];
        if (self) {
            return self;
        }
    }
    return nil;
}

#pragma mark - Abstract Methods

- (BOOL)insertObject:(LRTSObject *)object {
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

- (BOOL)deleteObjectsWhere:(const LRTSCondition &)condition {
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

- (BOOL)updateRowsWithValue:(const LRTSValue &)value onObject:(LRTSObject *)object {
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

- (id)getOneObject {
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

- (NSArray *)getAllObjects {
    [self doesNotRecognizeSelector: _cmd];
    return nil;
}

@end
