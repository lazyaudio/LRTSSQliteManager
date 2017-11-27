//
//  LRSTKeyValueStore.h
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

@class LRSTKeyValueModel;

#import <Foundation/Foundation.h>


@interface LRSTKeyValueStore : NSObject

/**
 初始化 KeyValueStroage 创建数据库

 @param databaseName 创建的数据库名称
 @return 返回当前的实例
 */
- (instancetype)initKVSWithDatabaseName:(NSString *)databaseName;

/**
 初始化 KeyValueStroage 创建数据库

 @param path 初始化创建数据库路径，如果为 nil 默认路径为 document/LRTS_WCDB_DATABASE 文件夹
 @return 返回当前的实例
 */
- (instancetype)initKVSWithDatabasePath:(NSString *)path;

/**
 创建 KeyValueStroage 的数据库表格

 @param tableName 创建 KeyValueStorage 表名，如果为 nil 默认数据表明 LRTSKeyValueModel
 @return 返回创建数据库是否成功，创建数据成功返回 YES，失败返回 NO
 */
- (BOOL)createTableWithName:(NSString *)tableName;

/**
 检查当前数据表是否存在

 @param tableName 检测数据库中当前的数据表表表名
 @return 返回数据表是否存在，如果数据表存在返回 YES，如果不存在返回 NO
 */
- (BOOL)isExistTableWithName:(NSString *)tableName;

/**
 清空当前的数据表

 @param tableName 传入需要清空数据表的名字
 @return 返回清空数据表是否成功，如果成功返回 YES，如果不成功返回 NO。
 */
- (BOOL)clearAllObjectsOfTableWithName:(NSString *)tableName;


#pragma mark - KeyValueStore Methods

#pragma mark -Put

/**
 保存数据到数据库

 @param value 需要到数据值，在数据库中都是以 JSON 格式保存
 @param key 保存数据中 KEY 值，用以对数据库查找或者更改
 @param tableName 保存数据到数据的表名
 @return 返回保存数据是否成功，保存数据成功返回 YES，保存数据失败返回 NO
 */
- (BOOL)putValue:(id)value withKey:(NSString *)key into:(NSString *)tableName;

- (BOOL)putString:(NSString *)string withKey:(NSString *)key into:(NSString *)tableName;

- (BOOL)putNumber:(NSNumber *)number withKey:(NSString *)key into:(NSString *)tableName;


#pragma mark -Get

/**
 获取数据中数据内容
 @param key 获取数据库参照的 KEY 值
 @param tableName 获取数据的表名称
 @return 返回获取的数据内容，默认情况下返回数据为 JSON 数据类型
 */
- (id)getValueWithKey:(NSString *)key formTable:(NSString *)tableName;

- (NSString *)getStringWithKey:(NSString *)key formTable:(NSString *)tableName;

- (NSNumber *)getNumberWithKey:(NSString *)key formTable:(NSString *)tableName;

/**
 根据 KEY 来获取当前一个 model 的数据内容

 @param key 获取数据 model 的 KEY 值
 @param tableName 获取数据的数据表名称
 @return 返回当前 model 具体内容
 */
- (LRSTKeyValueModel *)getKeyValueModelWithKey:(NSString *)key formTable:(NSString *)tableName;

/**
 获取当前数据库的所有 model 的数据内容

 @param tableName 获取数据的数据表名称
 @return 返回当前数据表中所有的数据信息
 */
- (NSArray<LRSTKeyValueModel *> *)getAllValuesFormTable:(NSString *)tableName;

/**
 获取当前的数据库数据总数

 @param tableName 获取数据库名
 @return 返回数据库中数据总数
 */
- (NSInteger)getTotalCountFromTable:(NSString *)tableName;

#pragma mark -Delete

/**
 删除数据库中根据 KEY 相同的数据

 @param key 删除与 KEY 值相同的数据
 @param tableName 要删除数据库中表名
 @return 返回删除数据是否成功
 */
- (BOOL)deleteValueWithKey:(NSString *)key formTable:(NSString *)tableName;

- (BOOL)deleteValuesWithKeys:(NSArray *)keys formTable:(NSString *)tableName;

- (BOOL)deleteValuesWithKeysPrefix:(NSString *)prefixString formTable:(NSString *)tableName;

#pragma mark - Change CreateTime

/**
 跟新在数据中所有数据的 CreateTime 以此来设置在数据中数据的生命周期

 @param tableName 更改数据库中 CreateTime 数据库名
 */
- (void)updateCreateTimeAtKeyValueModelToClearStorageFormTable:(NSString *)tableName;


- (void)updateCrateTimeWithKey:(NSString *)key fromTable:(NSString *)tableName;


@end
