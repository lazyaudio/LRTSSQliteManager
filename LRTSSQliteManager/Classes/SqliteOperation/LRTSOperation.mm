//
//  LRTSOperation.m
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import "LRTSOperation.h"

#define NAME_SQLDATABASE @"LRTS_WCDB_DATABASE"

@interface LRTSOperation () {
    Class _cls;
}

@property (nonatomic, strong) WCTDatabase *wcdb;

@property (strong, nonatomic) NSString *pathCreatedSQLDatabase;
@property (copy, nonatomic) NSString *mNameSQLDatabase;
@property (copy, nonatomic) NSString *mNameTable;

@end

@implementation LRTSOperation

#pragma  mark - public Methods

- (nullable instancetype)initWCDBWithName:(NSString *_Nullable)databaseName {
    [self configurationParameter];
    if (0 != databaseName.length) _mNameSQLDatabase = databaseName;
    NSString *pathSQLDB = [_pathCreatedSQLDatabase stringByAppendingPathComponent:_mNameSQLDatabase];
    return [self initWCDBWithPath:pathSQLDB];
}

- (nullable instancetype)initWCDBWithPath:(NSString *_Nullable)databasePath {
    [self configurationParameter];
    NSString *pathSQLDB;
    //判断使未设置 database 名字，默认为:LRTS_WCDB_DATABASE.db
    if (0 == databasePath.length) {
        pathSQLDB = [_pathCreatedSQLDatabase stringByAppendingPathComponent:NAME_SQLDATABASE];
    }else {
        if ([databasePath isEqualToString: _pathCreatedSQLDatabase]) {
            pathSQLDB = _pathCreatedSQLDatabase;
        }else {
            pathSQLDB = [databasePath stringByAppendingPathComponent:NAME_SQLDATABASE];
        }
    }
    _mNameSQLDatabase = [pathSQLDB lastPathComponent];
    _wcdb = [[WCTDatabase alloc] initWithPath:[NSString stringWithFormat:@"%@.db", pathSQLDB]];
    if (!_wcdb) return self;
    
    return nil;
}

- (BOOL)createTableWithDBModel:(LRTSDBModel * _Nonnull)model {
    if(nil == model) return NO;
    
    _cls = model.class;
    NSString *tableName = NSStringFromClass(_cls);
    _mNameTable = tableName;
    
    return [_wcdb createTableAndIndexesOfName:tableName withClass:_cls];
}

- (BOOL)isExistTableWithName:(NSString *)tableName {
    return [_wcdb isTableExists:tableName];
}

+ (instancetype)wcdbWithModel:(LRTSDBModel *)model {
    return [[self alloc] createTableWithModel:model];
}

#pragma  mark - Operation For SQL 增删改查
#pragma  mark - 增

- (BOOL)insertObject:(LRTSObject *)object {
    return [self insertObject:object into:_mNameTable];
}

- (BOOL)insertObject:(LRTSObject *)object into:(NSString *)tableName {
    if ([LRTSObject isEqual: nil]) return NO;
    if (![_mNameTable isEqualToString:tableName]) {
        _mNameTable = tableName;
    }
    return [_wcdb insertObject:object
                          into:_mNameTable];
}

- (BOOL)insertObjects:(NSArray<LRTSObject *> *)objects
                 into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertObjects:objects
                           into:_mNameTable];
}

- (BOOL)insertOrReplaceObject:(LRTSObject *)object
                         into:(NSString *)tableName {
    if(object == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObject:object
                                   into:_mNameTable];
}

- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *)objects
                          into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObjects:objects
                                    into:_mNameTable];
}

- (BOOL)insertObject:(LRTSObject *)object
            onValues:(const LRTSValueList &)valueList
                into:(NSString *)tableName {
    if(object == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertObject:object
                  onProperties:valueList
                          into:_mNameTable];
}

- (BOOL)insertObjects:(NSArray<LRTSObject *> *)objects
             onValues:(const LRTSValueList &)valueList
                 into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertObjects:objects
                   onProperties:valueList
                           into:_mNameTable];
}

- (BOOL)insertOrReplaceObject:(LRTSObject *)object
                     onValues:(const LRTSValueList &)valueList
                         into:(NSString *)tableName {
    if(object == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObject:object
                           onProperties:valueList
                                   into:_mNameTable];
}

- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *)objects
                      onValues:(const LRTSValueList &)valueList
                          into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObjects:objects
                            onProperties:valueList
                                    into:_mNameTable];
}

#pragma mark - 删

- (BOOL)deleteAllObjectsFromTable:(NSString *)tableName {
    [self checkOperationTableName:tableName];
    return [_wcdb deleteAllObjectsFromTable:_mNameTable];
}

- (BOOL)deleteObjectsWhere:(const LRTSCondition &)condition {
    return [self deleteObjectsFormTable:_mNameTable
                                  where:condition];
}

- (BOOL)deleteObjectsFromTable:(NSString *)tableName
                         where:(const LRTSCondition &)condition {
    [self checkOperationTableName:tableName];
    return [_wcdb deleteObjectsFromTable:_mNameTable where:condition];
}

- (BOOL)deleteObjectsFormTable:(NSString *)tableName
                         where:(const LRTSCondition &)condition {
    if (![_mNameTable isEqualToString: tableName]) {
        _mNameTable = tableName;
    }
    return [_wcdb deleteObjectsFromTable:_mNameTable
                                   where:condition];
}

/*
- (BOOL)deleteObjectsFormTable:(NSString *)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList {
    [self checkOperationTableName:tableName];
    return [_wcdb deleteObjectsFromTable:_mNameTable
                                   where:condition
                                 orderBy:orderList];
}*/

#pragma mark - 改

- (BOOL)updateRowsWithValue:(const LRTSValue &)value
                   onObject:(LRTSObject *)object {
    return [self updateRowsInTable:_mNameTable
                         withValue:value
                          onObject:object];
}

- (BOOL)updateRowsInTable:(NSString *)tableName
                withValue:(const LRTSValue &)value
                 onObject:(LRTSObject *)object{
    if ([object isEqual:nil]) {
        return YES;
    }
    if(![_mNameTable isEqualToString: tableName]) _mNameTable =tableName;
    return [_wcdb updateAllRowsInTable:_mNameTable
                            onProperty:value
                            withObject:object];
}

- (BOOL)updateRowsInTable:(NSString *_Nonnull)tableName
                withValue:(const LRTSValue &)value
                 onObject:(LRTSObject * _Nullable)object
                    where:(const LRTSCondition &)condition {
    [self checkOperationTableName:tableName];
    return [_wcdb updateRowsInTable:tableName
                         onProperty:value
                          withObject:object
                              where:condition];
}

- (BOOL)updateAllRowsInTable:(NSString *_Nonnull)tableName
                     withValues:(const LRTSValueList &)valueList
                     withRow:(LRTSOneRow *_Nonnull)row {
    [self checkOperationTableName:tableName];
    return [_wcdb updateAllRowsInTable:tableName
                          onProperties:valueList
                               withRow:row];
}

- (BOOL)updateRowsInTable:(NSString *_Nonnull)tableName
                  withValues:(const LRTSValueList &)valueList
               withObject:(WCTObject *_Nonnull)object
                    where:(const LRTSCondition &)condition {
    [self checkOperationTableName:tableName];
    return [_wcdb updateRowsInTable:tableName
                       onProperties:valueList
                         withObject:object
                              where:condition];
}

#pragma  mark - 查
#pragma  mark - Get Object

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOfClass:_cls
                            fromTable:_mNameTable];
}

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOfClass:_cls
                            fromTable:_mNameTable
                                where:condition];
}

- (nullable id)getOneObjectFormTable:(NSString *_Nonnull)tableName orderBy:(const LRTSOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOfClass:_cls
                            fromTable:_mNameTable
                              orderBy:orderList];
}

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOfClass:_cls
                            fromTable:_mNameTable
                                where:condition
                              orderBy:orderList];
}

#pragma mark - Get Part Of Object

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOnResults:resultList
                              fromTable:_mNameTable];
}

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOnResults:resultList
                              fromTable:_mNameTable
                                  where:condition];
}

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName orderBy:(const WCTOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOnResults:resultList
                              fromTable:_mNameTable
                                orderBy:orderList];
}

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const WCTOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneObjectOnResults:resultList
                              fromTable:_mNameTable
                                  where:condition
                                orderBy:orderList];
}

#pragma mark - Get One Row

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList
                        fromTable:(NSString *_Nonnull)tableName; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneRowOnResults:resultList
                           fromTable:_mNameTable];
}

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneRowOnResults:resultList
                           fromTable:_mNameTable
                               where:condition];
}

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName orderBy:(const WCTOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneRowOnResults:resultList
                           fromTable:_mNameTable
                             orderBy:orderList];
}

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const WCTOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getOneRowOnResults:resultList
                           fromTable:_mNameTable
                               where:condition
                             orderBy:orderList];
}

#pragma mark - Get Objects

- (NSArray * _Nullable)getAllObjectsForTable:(NSString * _Nonnull)tableName; {
    [self checkOperationTableName:tableName];
    return [_wcdb getAllObjectsOfClass:_cls
                             fromTable:_mNameTable];
}



- (NSArray * _Nullable)getObjectsForTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition; {
    [self checkOperationTableName:tableName];
    return [_wcdb getObjectsOfClass:_cls
                          fromTable:_mNameTable
                              where:condition];
}

- (NSArray * _Nullable)getObjectsForTable:(NSString *_Nonnull)tableName orderBy:(const LRTSOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getObjectsOfClass:_cls
                          fromTable:_mNameTable
                            orderBy:orderList];
}

- (NSArray * _Nullable)getObjectsForTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList; {
    [self checkOperationTableName:tableName];
    return [_wcdb getObjectsOfClass:_cls
                          fromTable:_mNameTable
                              where:condition
                            orderBy:orderList];
}

#pragma mark - Get Objects From Multi Tables
#pragma mark -多表查询

- (NSArray * _Nullable)selectRowsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames where:(const LRTSCondition &)condition; {
    if(0 == tableNames.count) return nil;
    WCTRowSelect *rowSelect = [[_wcdb prepareSelectRowsOnResults:resultList
                                                      fromTables:tableNames]
                               where:condition];
    return rowSelect.allRows;
}

- (NSArray * _Nullable)selectMutableObjectsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames where:(const LRTSCondition &)condition; {
    if(tableNames.count == 0) return nil;
    WCTMultiSelect *mutiSelect = [[_wcdb prepareSelectMultiObjectsOnResults:resultList
                                                                 fromTables:tableNames]
                                  where:condition];
    return mutiSelect.allMultiObjects;
}

#pragma mark - Transaction

#pragma mark -Base Transaction

- (BOOL)beginTransaction {
    return [_wcdb beginTransaction];
}

- (BOOL)commitTransaction {
    return [_wcdb commitTransaction];
}

- (BOOL)rollbackTransaction {
    return [_wcdb rollbackTransaction];
}

#pragma mark -Concrete Transaction

- (BOOL)insertOrReplaceObjectsInTransaction:(NSArray<LRTSObject *> *_Nullable)objects into:(NSString *_Nonnull)tableName {
    if (tableName.length ==0 || objects.count == 0) return NO;
    BOOL isResult = YES;
    isResult = [_wcdb commitTransaction];
    
    for (LRTSObject *object in objects) {
        isResult = [_wcdb insertOrReplaceObject:object into:tableName];
    }
    
    if (isResult) {
        isResult = [_wcdb commitTransaction];
    } else {
        isResult = [_wcdb rollbackTransaction];
    }
    
    return isResult;
}

//- (BOOL)deleteObjectsInTransaction:(NSArray<LRTSObject *> *_Nullable)objects into:(NSString *_Nonnull)tableName {
//    if (tableName.length ==0 || objects.count == 0) return NO;
//    BOOL isResult = YES;
//    isResult = [_wcdb commitTransaction];
//
//    for (LRTSObject *object in objects) {
//        isResult = [_wcdb del];
//    }
//
//    if (isResult) {
//        isResult = [_wcdb commitTransaction];
//    } else {
//        isResult = [_wcdb rollbackTransaction];
//    }
//
//    return isResult;
//}

#pragma  mark - setter & getter

- (NSString *)databaseName {
    return _mNameSQLDatabase;
}

- (NSString *)tableName {
    return [_mNameTable copy];
}

- (void)setTableWithModel:(LRTSDBModel *)model {
    if(model == nil) return;
    __unsafe_unretained Class classModel = model.class;
    if (_cls != classModel) {
        _cls = classModel;
        _mNameTable = NSStringFromClass(_cls);
    }
}

#pragma  mark - private Methods

- (instancetype)createTableWithModel:(LRTSDBModel *)dbModel {
    if(nil == dbModel) return nil;
    if ([self initWCDBWithPath:@""]) {
        BOOL ret = [_wcdb createTableAndIndexesOfName:NSStringFromClass(dbModel.class) withClass:dbModel.class];
        if (ret) {
            return self;
        }
    }
    return nil;
}

- (void)checkOperationTableName:(NSString *)tableName {
    if (![_mNameTable isEqualToString:tableName]) {
        _mNameTable =  tableName;
    }
}

- (void)configurationParameter {
    _pathCreatedSQLDatabase = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
    _mNameSQLDatabase = NAME_SQLDATABASE;
}

/*
- (void)configurationParameter {
    _pathCreatedSQLDatabase = [self savedWCDBDatabaseWithOperationPath:LRTSOperationPathTypeDefault];
    _mNameSQLDatabase = NAME_SQLDATABASE;
}

- (NSString *)savedWCDBDatabaseWithOperationPath:(LRTSOperationdPathType) pathType {
    NSString *temPath;
    switch (pathType) {
        case LRTSOperationPathTypeDefault:
        {
            temPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
            break;
        }
        case LRTSOperationPathTypeDocument:
        {
            temPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
            break;
        }
        case LRTSOperationPathTypeTmp:
        {
            temPath = NSTemporaryDirectory();
            break;
        }
        default:
        {
            temPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
            break;
        }
    }
    return temPath;
}*/


@end
