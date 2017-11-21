//
//  LRSTKeyValueStore.m
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

#import "LRSTKeyValueStore.h"
#import "LRTSOperation.h"
#import "LRTSKeyValueModel.h"

@interface LRSTKeyValueStore ()

@property (strong, nonatomic) NSString *pathCreatedSQLDatabase;
@property (strong, nonatomic) LRTSOperation *operation;
@property (strong, nonatomic) LRTSKeyValueModel *kKVModel;

@end

@implementation LRSTKeyValueStore

#pragma mark - Life Cycle

#pragma mark - Getter & Setter



#pragma mark - Event

#pragma mark - Delegate

#pragma mark - Public Method

- (BOOL)createTableWithName:(NSString *)tableName {
    _kKVModel = [[LRTSKeyValueModel alloc] init];
//    _operation = [];
}

- (BOOL)isExistTableWithName:(NSString *)tableName {
    
}

- (BOOL)clearAllObjectsOfTableWithName:(NSString *)tableName {
    
}

- (void)close {
    
}

#pragma mark - KeyValueStore Methods

#pragma mark -Put

- (BOOL)putValue:(id)value withKey:(NSString *)key into:(NSString *)tableName {
    
}

- (BOOL)putString:(NSString *)string withKey:(NSString *)key into:(NSString *)tableName {
    
}

- (BOOL)putNumber:(NSNumber *)number withKey:(NSString *)key into:(NSString *)tableName {
    
}


#pragma mark -Get

- (id)getValueWithKey:(NSString *)key formTable:(NSString *)tableName {
    
}

- (NSString *)getStringWithKey:(NSString *)key formTable:(NSString *)tableName {
    
}

- (NSNumber *)getNumberWithKey:(NSString *)key formTable:(NSString *)tableName {
    
}

- (LRSTKeyValueModel *)getKeyValueModelWithKey:(NSString *)key formTable:(NSString *)tableName {
    
}

- (NSArray<LRSTKeyValueModel *> *)getAllValuesFormTable:(NSString *)tableName {
    
}

- (NSInteger)getTotalCountFromTable:(NSString *)tableName {
    
}

#pragma mark -Delete

- (BOOL)deleteValueWithKey:(NSString *)key formTable:(NSString *)tableName {
    
}

- (BOOL)deleteValuesWithKeys:(NSArray *)keys formTable:(NSString *)tableName {
    
}

- (BOOL)deleteValuesWithKeysPrefix:(NSString *)prefixString formTable:(NSString *)tableName {
    
}

#pragma mark - Change CreateTime

- (void)updateCreateTimeAtKeyValueModelToClearStorageFormTable:(NSString *)tableName {
    
}

- (void)updateCrateTimeWithKey:(NSString *)key fromTable:(NSString *)tableName {
    
}

#pragma mark - Private Method

- (void)configurationParameter {
    _pathCreatedSQLDatabase = [self savedWCDBDatabaseWithOperationPath:LRSTKeyValueStoreDBPathTypeDefault];
}

- (NSString *)savedWCDBDatabaseWithOperationPath:(LRSTKeyValueStoreDBPathType) pathType {
    NSString *temPath;
    switch (pathType) {
        case LRSTKeyValueStoreDBPathTypeDefault:
        {
            temPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
            break;
        }
        case LRSTKeyValueStoreDBPathTypeCache:
        {
            temPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
            break;
        }
        case LRSTKeyValueStoreDBPathTypeTmp:
        {
            temPath = NSTemporaryDirectory();
            break;
        }
        default:
        {
            temPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
            break;
        }
    }
    return temPath;
}

@end
