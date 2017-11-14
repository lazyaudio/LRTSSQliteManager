//
//  LRTSOperation.m
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import "LRTSOperation.h"

#define NAME_SQLDATABASE @"lrts_wcbd_sqldatebase"

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

- (instancetype)initWithModel:(LRTSDBModel *)model {
    if (model == nil) return nil;
    [self configurationParameter];
    _cls = model.class;
    NSString *path = [_pathCreatedSQLDatabase stringByAppendingPathComponent:_mNameSQLDatabase];
 
    NSString *tableName = NSStringFromClass(model.class);
    if (!_mNameTable) {
        _mNameTable = tableName;
    }
    return [self initWithPath:path];
}

- (instancetype)initWithPath:(NSString *)path {
    if(path.length == 0) return nil;
    _pathCreatedSQLDatabase = path;
    NSString *tableName = _mNameTable;
    
    _wcdb = [[WCTDatabase alloc] initWithPath:_pathCreatedSQLDatabase];
    if(!_wcdb) return nil;
    
    BOOL ret = [_wcdb createTableAndIndexesOfName:tableName withClass:_cls];
    
    if (ret) {
        return self;
    }
    return nil;
}

+ (instancetype)wcdbWithModel:(LRTSDBModel *)model {
    return [[self alloc] initWithModel:model];
}

+ (instancetype)wcdbWithPath:(NSString *)path {
    return [[self alloc] initWithPath:path];
}

#pragma  mark -Operation For SQL 增删改查
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

- (BOOL)insertObjects:(NSArray<LRTSObject *> *)objects into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertObjects:objects
                           into:_mNameTable];
}

- (BOOL)insertOrReplaceObject:(LRTSObject *)object into:(NSString *)tableName {
    if(object == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObject:object
                                   into:_mNameTable];
}

- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *)objects into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObjects:objects
                                    into:_mNameTable];
}

- (BOOL)insertObject:(LRTSObject *)object onValues:(const LRTSValueList &)valueList into:(NSString *)tableName {
    if(object == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertObject:object
                  onProperties:valueList
                          into:_mNameTable];
}

- (BOOL)insertObjects:(NSArray<LRTSObject *> *)objects onValues:(const LRTSValueList &)valueList into:(NSString *)tableName {
    if(objects == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertObjects:objects
                   onProperties:valueList
                           into:_mNameTable];
}

- (BOOL)insertOrReplaceObject:(LRTSObject *)object onValues:(const LRTSValueList &)valueList into:(NSString *)tableName {
    if(object == nil) return NO;
    [self checkOperationTableName:tableName];
    return [_wcdb insertOrReplaceObject:object
                           onProperties:valueList
                                   into:_mNameTable];
}

- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *)objects onValues:(const LRTSValueList &)valueList into:(NSString *)tableName {
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

- (BOOL)deleteObjectsFromTable:(NSString *)tableName where:(const LRTSCondition &)condition {
    [self checkOperationTableName:tableName];
    return [_wcdb deleteObjectsFromTable:_mNameTable where:condition];
}

- (BOOL)deleteObjectsFormTable:(NSString *)tableName where:(const LRTSCondition &)condition {
    if (![_mNameTable isEqualToString: tableName]) {
        _mNameTable = tableName;
    }
    return [_wcdb deleteObjectsFromTable:_mNameTable
                                   where:condition];
}

- (BOOL)deleteObjectsFormTable:(NSString *)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList {
    [self checkOperationTableName:tableName];
    return [_wcdb deleteObjectsFromTable:_mNameTable
                                   where:condition
                                 orderBy:orderList];
}

#pragma mark - 改

- (BOOL)updateRowsWithValue:(const LRTSValue &)value onObject:(LRTSObject *)object {
    return [self updateRowsInTable:_mNameTable
                         withValue:value
                          onObject:object];
}

- (BOOL)updateRowsInTable:(NSString *)tableName withValue:(const LRTSValue &)value onObject:(LRTSObject *)object{
    if ([object isEqual:nil]) {
        return YES;
    }
    if(![_mNameTable isEqualToString: tableName]) _mNameTable =tableName;
    return [_wcdb updateAllRowsInTable:_mNameTable
                            onProperty:value
                            withObject:object];
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

- (NSArray * _Nullable)selectRowsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames; {
    return [self selectRowsOnResults:resultList
                          fromTables:tableNames
                               where:nil];
}

- (NSArray * _Nullable)selectRowsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames where:(const LRTSCondition &)condition; {
    if(0 == tableNames.count) return nil;
    WCTRowSelect *rowSelect = [[_wcdb prepareSelectRowsOnResults:resultList
                                                      fromTables:tableNames]
                               where:condition];
    return rowSelect.allRows;
}

- (NSArray * _Nullable)selectMutableObjectsOnResults:(const LRTSResultList &)resultList fromTables:(NSArray<NSString *> *_Nonnull)tableNames; {
    return [self selectMutableObjectsOnResults:resultList
                                    fromTables:tableNames
                                         where:nil];
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

- (void)setTableName:(NSString *)tableName {
    if (tableName.length != 0 && ![_mNameTable isEqualToString:tableName]) {
        _mNameTable = tableName;
    }
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

- (void)checkOperationTableName:(NSString *)tableName {
    if (![_mNameTable isEqualToString:tableName]) {
        _mNameTable =  tableName;
    }
}

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
}

@end
