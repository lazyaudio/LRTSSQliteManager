//
//  LRSTKeyValueStore.h
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

@class LRSTKeyValueModel;

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LRSTKeyValueStoreDBPathType) {
    LRSTKeyValueStoreDBPathTypeDefault,
    LRSTKeyValueStoreDBPathTypeCache,
    LRSTKeyValueStoreDBPathTypeTmp
};

@interface LRSTKeyValueStore : NSObject

@property (nonatomic, assign) LRSTKeyValueStoreDBPathType dbPathType;

- (instancetype)initKVSWithDatabaseName:(NSString *)databaseName;

- (instancetype)initKVSWithDatabasePath:(NSString *)path;

- (BOOL)createTableWithName:(NSString *)tableName;

- (BOOL)isExistTableWithName:(NSString *)tableName;

- (BOOL)clearAllObjectsOfTableWithName:(NSString *)tableName;


#pragma mark - KeyValueStore Methods

#pragma mark -Put

- (BOOL)putValue:(id)value withKey:(NSString *)key into:(NSString *)tableName;

- (BOOL)putString:(NSString *)string withKey:(NSString *)key into:(NSString *)tableName;

- (BOOL)putNumber:(NSNumber *)number withKey:(NSString *)key into:(NSString *)tableName;


#pragma mark -Get

- (id)getValueWithKey:(NSString *)key formTable:(NSString *)tableName;

- (NSString *)getStringWithKey:(NSString *)key formTable:(NSString *)tableName;

- (NSNumber *)getNumberWithKey:(NSString *)key formTable:(NSString *)tableName;

- (LRSTKeyValueModel *)getKeyValueModelWithKey:(NSString *)key formTable:(NSString *)tableName;

- (NSArray<LRSTKeyValueModel *> *)getAllValuesFormTable:(NSString *)tableName;

- (NSInteger)getTotalCountFromTable:(NSString *)tableName;

#pragma mark -Delete

- (BOOL)deleteValueWithKey:(NSString *)key formTable:(NSString *)tableName;

- (BOOL)deleteValuesWithKeys:(NSArray *)keys formTable:(NSString *)tableName;

- (BOOL)deleteValuesWithKeysPrefix:(NSString *)prefixString formTable:(NSString *)tableName;

#pragma mark - Change CreateTime

- (void)updateCreateTimeAtKeyValueModelToClearStorageFormTable:(NSString *)tableName;

- (void)updateCrateTimeWithKey:(NSString *)key fromTable:(NSString *)tableName;


@end
