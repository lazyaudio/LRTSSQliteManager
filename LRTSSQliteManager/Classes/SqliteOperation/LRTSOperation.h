//
//  LRTSOperation.h
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import "LRTSBaseOperation.h"
#import "LRTSBaseModel.h"
#import <WCDB/WCDB.h>

typedef NS_ENUM(NSInteger, LRTSOperationdPathType) {
    LRTSOperationPathTypeDefault,
    LRTSOperationPathTypeDocument,
    LRTSOperationPathTypeTmp
};

@interface LRTSOperation : LRTSBaseOperation

@property (nonatomic) LRTSOperationdPathType pathType;

@property (nonatomic, readonly) NSString  * _Nonnull databaseName;

@property (readwrite, strong) NSString * _Nonnull tableName;

@property (nonatomic, strong, setter=setTableWithModel:) LRTSBaseModel * _Nullable model;

- (nullable instancetype)initWithModel:(LRTSBaseModel * _Nonnull)model;

- (nullable instancetype)initWithPath:(NSString *_Nullable)path;

+ (nullable instancetype)wcdbWithModel:(LRTSBaseModel * _Nonnull)model;

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

- (BOOL)insertOrReplaceObjects:(NSArray<LRTSObject *> *_Nullable)objects onValues:(const LRTSValueList &)valueList into:(NSString *_Nonnull)tableName;

#pragma mark - Delete

- (BOOL)deleteAllObjectsFromTable:(NSString *_Nonnull)tableName;

- (BOOL)deleteObjectsFromTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition;

- (BOOL)deleteObjectsFormTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList;

#pragma mark - Update

- (BOOL)updateRowsInTable:(NSString *_Nonnull)tableName withValue:(const LRTSValue &)value onObject:(LRTSObject * _Nullable)object;

#pragma mark - Get
#pragma mark - Get Object

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName;

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition;

- (nullable id)getOneObjectFormTable:(NSString *_Nonnull)tableName orderBy:(const LRTSOrderByList &)orderList;

- (nullable id)getOneObjectFormTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList;

#pragma mark - Get Part Of Object

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName;

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition;

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName orderBy:(const WCTOrderByList &)orderList;

- (nullable id)getOneObjectOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const WCTOrderByList &)orderList;

#pragma mark - Get One Row

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList
                        fromTable:(NSString *_Nonnull)tableName;

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition;

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName orderBy:(const WCTOrderByList &)orderList;

- (nullable id)getOneRowOnResults:(const LRTSResultList &)resultList formTable:(NSString *_Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const WCTOrderByList &)orderList;

#pragma mark - Get Objects

- (NSArray * _Nullable)getAllObjectsForTable:(NSString * _Nonnull)tableName;

- (NSArray * _Nullable)getObjectsForTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition;

- (NSArray * _Nullable)getObjectsForTable:(NSString *_Nonnull)tableName orderBy:(const LRTSOrderByList &)orderList;

- (NSArray * _Nullable)getObjectsForTable:(NSString * _Nonnull)tableName where:(const LRTSCondition &)condition orderBy:(const LRTSOrderByList &)orderList;


@end
