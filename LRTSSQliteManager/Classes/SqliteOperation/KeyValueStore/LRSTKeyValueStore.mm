//
//  LRSTKeyValueStore.m
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

#import "LRSTKeyValueStore.h"
#import "LRTSOperation.h"
#import "LRTSKeyValueModel.h"
#import "LRTSKeyValueModel+WCTTableCoding.h"

#define NAME_KEYVALUESTORAGE_DATABASE @"name_keyvaluestorage_database"

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

- (instancetype)init {
    return [self initKVSWithDatabaseName:@"NAME_KEYVALUESTORAGE_DATABASE"];
}

- (instancetype)initKVSWithDatabaseName:(NSString *)databaseName {
    _operation = [[LRTSOperation alloc] initWCDBWithName:databaseName];
    if (_operation) {
        return self;
    }
    return nil;
}

- (instancetype)initKVSWithDatabasePath:(NSString *)path {
    _operation = [[LRTSOperation alloc] initWCDBWithPath:path];
    if (_operation) {
        return self;
    }
    return nil;
}

- (BOOL)createTableWithName:(NSString *)tableName {
    _kKVModel = [[LRTSKeyValueModel alloc] init];
    _operation.tableName = tableName;
    return [_operation createTableWithDBModel:_kKVModel];
}

- (BOOL)isExistTableWithName:(NSString *)tableName {
    return [_operation isExistTableWithName:tableName];
}

- (BOOL)clearAllObjectsOfTableWithName:(NSString *)tableName {
    return [_operation deleteAllObjectsFromTable:tableName];
}

#pragma mark - KeyValueStore Methods

#pragma mark -Put

- (BOOL)putValue:(id)value withKey:(NSString *)key into:(NSString *)tableName {
    if(0 == tableName.length) return NO;
    LRTSKeyValueModel *keyValueModel = [self keyValueModelWithKey:key value:value];
    if (keyValueModel) {
        [_operation insertOrReplaceObject:keyValueModel into:tableName];
    }
    return NO;
}

- (BOOL)putString:(NSString *)string withKey:(NSString *)key into:(NSString *)tableName {
    return [self putValue:@[string] withKey:key into:tableName];
}

- (BOOL)putNumber:(NSNumber *)number withKey:(NSString *)key into:(NSString *)tableName {
    return [self putValue:@[number] withKey:key into:tableName];
}


#pragma mark -Get

- (id)getValueWithKey:(NSString *)key formTable:(NSString *)tableName {
    if (0 == key.length || 0 == tableName.length) return nil;
    
    return [_operation getOneObjectFormTable:tableName where:LRTSKeyValueModel.itemKey == key];
}

- (NSString *)getStringWithKey:(NSString *)key formTable:(NSString *)tableName {
    return [self getValueWithKey:key formTable:tableName];
}

- (NSNumber *)getNumberWithKey:(NSString *)key formTable:(NSString *)tableName {
    return [self getValueWithKey:key formTable:tableName];
}

- (LRSTKeyValueModel *)getKeyValueModelWithKey:(NSString *)key formTable:(NSString *)tableName {
    return [self getValueWithKey:key formTable:tableName];
}

- (NSArray<LRSTKeyValueModel *> *)getAllValuesFormTable:(NSString *)tableName {
    return [_operation getAllObjectsForTable:tableName];
}

- (NSInteger)getTotalCountFromTable:(NSString *)tableName {
    return [_operation getAllObjectsForTable:tableName].count;
}

#pragma mark -Delete

- (BOOL)deleteValueWithKey:(NSString *)key formTable:(NSString *)tableName {
    if (0 == key.length || 0 == tableName.length) return NO;
    return [_operation deleteObjectsFromTable:tableName where:LRTSKeyValueModel.itemKey == key];
}

- (BOOL)deleteValuesWithKeys:(NSArray *)keys formTable:(NSString *)tableName {
    if (0 == keys.count || 0 == tableName.length) return NO;
    
    BOOL ret = [_operation beginTransaction];
    
    for (NSString *key in keys) {
        ret = [_operation deleteObjectsFromTable:tableName where:LRTSKeyValueModel.itemKey == key];
    }
    if (ret) {
        ret = [_operation commitTransaction];
    }else {
        ret = [_operation rollbackTransaction];
    }
    return ret;
}

- (BOOL)deleteValuesWithKeysPrefix:(NSString *)prefixString formTable:(NSString *)tableName {
    
}

#pragma mark - Change CreateTime

- (void)updateCreateTimeAtKeyValueModelToClearStorageFormTable:(NSString *)tableName {
    if(0 == tableName.length) return;
    NSArray *row = [NSArray arrayWithObject:@"0"];
    [_operation updateAllRowsInTable:tableName onValues:LRTSKeyValueModel.createTime withRow:row];
}

- (void)updateCrateTimeWithKey:(NSString *)key fromTable:(NSString *)tableName {
    if(0 == key || 0 == tableName.length) return;
    
    if(nil == _kKVModel) _kKVModel = [[LRTSKeyValueModel alloc] init];
    _kKVModel.createTime = 0;
    _kKVModel.itemKey = key;
    
    [_operation updateRowsInTable:tableName onValue:LRTSKeyValueModel.createTime withObject:_kKVModel where:LRTSKeyValueModel.itemKey == key];
}

#pragma mark - Private Method

- (void)configurationParamter {
    _kKVModel = [[LRTSKeyValueModel alloc] init];
}

- (LRTSKeyValueModel *)keyValueModelWithKey:(id)key value:(id)value {
    if (!_kKVModel) {
        _kKVModel = [[LRTSKeyValueModel alloc] init];
    }
    
    if (!value) {
        return nil;
    }
    
    NSError *error = nil;
    NSData *data = [NSJSONSerialization dataWithJSONObject:value options:0 error:&error];
    
    if (!data || error) {
        NSLog(@"Error: LRTSKeyValueStorage translate value into data.");
        return nil;
    }
    
    NSString *jsonValue = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    NSString *jsonKey = [[NSString alloc] initWithFormat:@"%@", key];
    
    NSDate *createDate = [NSDate date];
    
    _kKVModel.itemValue = jsonValue;
    _kKVModel.itemKey = jsonKey;
    _kKVModel.createTime = createDate;
    
    if (_kKVModel) {
        return _kKVModel;
    }
    return nil;
}

@end
