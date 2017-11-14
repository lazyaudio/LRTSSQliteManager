//
//  LRTSOperation.h
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

//#import "LRTSBaseOperation.h"
#import <Foundation/Foundation.h>
#import "LRTSDBModel.h"
#import "LRTSDBBookModel.h"
#import <WCDB/WCDB.h>

typedef NS_ENUM(NSInteger, LRTSOperationdPathType) {
    LRTSOperationPathTypeDefault,
    LRTSOperationPathTypeDocument,
    LRTSOperationPathTypeTmp
};

@interface LRTSOperation : NSObject

@property (nonatomic) LRTSOperationdPathType pathType;

@property (nonatomic, readonly) NSString  * _Nonnull databaseName;

@property (readwrite, strong) NSString * _Nonnull tableName;

@property (nonatomic, strong, setter=setTableWithModel:) LRTSDBModel * _Nullable model;

- (nullable instancetype)initWithModel:(LRTSDBModel *_Nullable)model;

- (nullable instancetype)initWithPath:(NSString *_Nullable)path;

+ (nullable instancetype)wcdbWithModel:(LRTSDBModel * _Nonnull)model;

+ (nullable instancetype)wcdbWithPath:(NSString *_Nullable)path;

- (nullable instancetype)init UNAVAILABLE_ATTRIBUTE;

+ (nullable instancetype)new UNAVAILABLE_ATTRIBUTE;

//增、删、改、查

#pragma mark - Operations For SQLlite
#pragma mark - Insert

- (BOOL)insertObject:(LRTSObject *_Nullable)object into:(NSString * _Nonnull)tableName;

- (BOOL)insertObjects:(NSArray<LRTSObject *> *_Nullable)objects into:(NSString *_Nonnull)tableName;

- (BOOL)insertOrReplaceObject:(LRTSObject *_Nullable)object into:(NSString *_Nonnull)tableName;

- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *_Nullable)objects into:(NSString *_Nonnull)tableName;

- (BOOL)insertObject:(LRTSObject *_Nullable)object onValues:(const LRTSValueList &)valueList into:(NSString *_Nonnull)tableName;

- (BOOL)insertObjects:(NSArray<LRTSObject *> *_Nullable)objects onValues:(const LRTSValueList &)valueList into:(NSString *_Nonnull)tableName;

- (BOOL)insertOrReplaceObject:(LRTSObject *_Nullable)object onValues:(const LRTSValueList &)valueList into:(NSString *_Nonnull)tableName;


/**
 对数据库进行 insert 或者 replace 操作，实现已有的数据字段更新

 @param objects 需要实现添加和替换的数据字段内容，添加格式 Model.BookId
 @param valueList 添加或者是修改字段在 model 中属性的定义
 @param tableName 修改相关 table 名字
 @return 修改相关字段是否成功
 */
- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *_Nullable)objects onValues:(const LRTSValueList &)valueList into:(NSString *_Nonnull)tableName;

#pragma mark - Delete

- (BOOL)deleteAllObjectsFromTable:(NSString *_Nonnull)tableName;

- (BOOL)deleteObjectsFromTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition;


/**
 对数据库 delete 操作，根据相关条件和排列顺序删除对应表格的数据

 @param tableName 删除操作表格的名字
 @param condition 删除表格的相关条件
 @param orderList 删除表格的相关顺序
 @return 返回表格操作结果
 */
- (BOOL)deleteObjectsFormTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList;

#pragma mark - Update


/**
 对 数据库进行 update 操作

 @param tableName 更新数据库名字
 @param value 需要更新数据的值
 @param object 更新数据的具体的 model
 @return 数据更新后返回结果
 */
- (BOOL)updateRowsInTable:(NSString *_Nonnull)tableName withValue:(const LRTSValue &)value onObject:(LRTSObject * _Nullable)object;

#pragma mark - Get
#pragma mark - Get Object

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName;

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition;

- (nullable id)getOneObjectFormTable:(NSString *_Nonnull)tableName orderBy:(const LRTSOrderByList &)orderList;

/**
 获取当前数据库一组数据

 @param tableName 获取当前数据库数据的名字
 @param condition 需要获取数据的条件
 @param orderList 数据的排列条件
 @return 返回数据库在相关条件下数据内容
 */
- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList;

#pragma mark - Get Part Of Object

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName;

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition;

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName orderBy:(const WCTOrderByList &)orderList;

/**
 获取数据库内容中的一部分数据

 @param resultList 需要获取数据库内容相关字段
 @param tableName 获取数据库的名字
 @param condition 查询的条件设置
 @param orderList 数据的排列条件
 @return 返回查询的数据
 */
- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const WCTOrderByList &)orderList;

#pragma mark - Get One Row

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList
                        fromTable:(NSString *_Nonnull)tableName;

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition;

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName orderBy:(const WCTOrderByList &)orderList;

/**
 获取数据库中相关字段的一行内容

 @param resultList 需要获取数据库内容相关字段
 @param tableName 获取数据库的名字
 @param condition 查询的条件设置
 @param orderList 数据的排列条件
 @return 返回查询的数据
 */
- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const WCTOrderByList &)orderList;

#pragma mark - Get Objects

- (NSArray * _Nullable)getAllObjectsForTable:(NSString * _Nonnull)tableName;

- (NSArray * _Nullable)getObjectsForTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition;

- (NSArray * _Nullable)getObjectsForTable:(NSString *_Nonnull)tableName orderBy:(const LRTSOrderByList &)orderList;

/**
 获取数据表格中多个数据 model 内容

 @param tableName 获取数据库的名字
 @param condition 条件设置
 @param orderList 数据的排列条件
 @return 返回查询的数据
 */
- (NSArray * _Nullable)getObjectsForTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList;

#pragma mark - Get Objects From Multi Tables

- (NSArray * _Nullable)selectRowsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames;

- (NSArray * _Nullable)selectRowsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames where:(const LRTSCondition &)condition;

- (NSArray * _Nullable)selectMutableObjectsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames;

/**
 链表查询获取相关条件下，数据表格中字段内容

 @param resultList 需要获取数据库内容相关字段
 @param tableNames 连表查询的多个表格的名字
 @param condition 条件设置
 @return 返回多表查询当前字段内容
 */
- (NSArray * _Nullable)selectMutableObjectsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames where:(const LRTSCondition &)condition;


#pragma mark - Transaction

#pragma mark -Base Transaction

- (BOOL)beginTransaction;

- (BOOL)commitTransaction;

- (BOOL)rollbackTransaction;


#pragma mark -Concrete Transaction

- (BOOL)insertOrReplaceObjectsInTransaction:(NSArray<LRTSObject *> *_Nullable)objects into:(NSString *_Nonnull)tableName;



@end
