//
//  LRTSBookDetailViewController.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/18.
//  Copyright © 2017年 boilwater. All rights reserved.
//
//  测试接口类的实例 Demo
//
//  测试内容三个方面：（1）LRTSOperation 基础接口；（2）LRTSDBDetailBookModel 操作实现；（3）LRTSKeyValueStroage 接口
//
//  测试的 model ：LRTSDBDetailBookModel
//  测试 model 继承关系：LRTSDBDetailBookModel : LRTSDBBookModel : LRTSDBModel : LRTSModel
//
// （1）基于 LRTSDBDetailBookModel 来实现 LRTSOperation 的基础操作
//
// （2）基于 LRTSDBDetailBookModel 实现基本的 add,get,update
//
//  (3)基于 LRTSKeyValueStroage 整体界面的数据储存
//
//
//  目前来说有个问题：
//  引入的文件是会变成 C++代码引入
//  可以在中间层作为封装在代码实现中做中间层的处理，这样就可以避免在引入变量编写 C++ 的代码
//
//  就是做一个总的操作的接口层
//
/****************************************************************************/
//（1）数据库的连表查询实现完成，在 Operation 数据库连表查询
//
//（2）在 LRTSDBDetailBookModel 的 .mm 文件中对属性 WCDB_SYNTHESIZE(tableName, property) 进行注册和修改即可
//
//（3）连表修改双表的数据采用任务的形式进行数据表格的修改
//
//（4）在实例中 Operation 数据查找中实现
//
//（5）实现
//
//（6）
//
//
//
//
//
/****************************************************************************/
//
//


#import "LRTSBookDetailViewController.h"
//#import "LRTSSelectOperation.h"

/*
#pragma mark -
#import "LRTSDBBookDetailModel.h"
#import "LRTSDBBookDetailModel+WCTTableCoding.h"
#import "LRTSOperation.h"

#pragma mark -
#import "LRSTKeyValueStore.h"
*/

#import "LRTSDBOperation.h"

#import "BookDetail+LRTSDBBookDetailOperation.h"

@interface LRTSBookDetailViewController ()

//@property (strong, nonatomic) LRTSOperation *operation;
//@property (strong, nonatomic) LRTSDBBookDetailModel *detailModel;

@end

@implementation LRTSBookDetailViewController

#pragma mark - Life Cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initParamters];
    
//    [self dbOperationTest];
    [self bookDetailCategoryOperation];
}

#pragma mark - Getter & Setter

#pragma mark - Event

#pragma mark - Delegate

#pragma mark - Public Method

#pragma mark - Private Method

#pragma mark - Init Configuration

#pragma mark -Init Hierarchy

- (void)initHierarchy {
    self.view.backgroundColor = [UIColor whiteColor];
    
}


#pragma mark -Init Paramters

- (void)initParamters {
//    _detailModel = [[LRTSDBBookDetailModel alloc] init];
    
}

/*
#pragma mark - BookDetail Of Operations For SQL

#pragma mark -
#pragma mark - LRTSOperation (1)

#pragma mark -Insert

- (void)insertDetailBookModel {
    if (!_detailModel) {
        _detailModel = [[LRTSDBBookDetailModel alloc] init];
    }
    _detailModel.haveLink = YES;
    _detailModel.bookVersion = @"版本1.0.0";
    _detailModel.desc = @"shantou university";
    
//    [_detailModel saved];
    
//    //循环加入数据
//    NSInteger i = 1;
//
//    while (i < 5) {
//        ++i;
//        _detailModel.bId = i;
//        [_operation insertObject:_detailModel into:NSStringFromClass(LRTSDBBookDetailModel.class)];
//    }
}

#pragma mark -Delete

- (void)deleteDetailBookModel {
    //删除所有的数据
    [_operation deleteAllObjectsFromTable:NSStringFromClass(LRTSDBBookDetailModel.class)];
    
    //条件删除
    [_operation deleteObjectsFromTable:NSStringFromClass(LRTSDBBookDetailModel.class) where:LRTSDBBookDetailModel.bId == 100];
}

#pragma mark -Update

- (void)updateDetailBookModel {
    if (!_detailModel) {
        _detailModel = [[LRTSDBBookDetailModel alloc] init];
    }
    _detailModel.bId = 1;
    _detailModel.commentMean = @"118";
    _detailModel.desc = @"LRTS Book Detail Model";
    
    //更新单个数据
    [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookDetailModel.class) onValue:LRTSDBBookDetailModel.bId withObject:_detailModel];
    
    //跟新在某一个数据条件 某一个参数 是使用 Model
    [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookDetailModel.class) onValue:LRTSDBBookDetailModel.author withObject:_detailModel where:LRTSDBBookDetailModel.bId == 10];
}

#pragma mark -Get

- (void)getDBBookDetailModel {
    //获取所有的数据
    [_operation getAllObjectsForTable:NSStringFromClass(LRTSDBBookDetailModel.class)];
    
    //
    [_operation getOneObjectFormTable:NSStringFromClass(LRTSDBBookDetailModel.class) where:LRTSDBBookDetailModel.bId == 100];
    
    //数据的连表查询
    [_operation selectMutableObjectsOnResults:{LRTSDBBookDetailModel.bookPrice, LRTSDBBookModel.version} fromTables:@[NSStringFromClass(LRTSDBBookDetailModel.class), NSStringFromClass(LRTSDBBookModel.class)] where:LRTSDBBookDetailModel.bId == LRTSDBBookModel.version];
}

#pragma mark -
#pragma mark - LRTSDBDetailBookModel (2)

- (void)operationDetailBookModel {
    LRTSDBBookDetailModel *bookDetailModel = [[LRTSDBBookDetailModel alloc] init];
    
    bookDetailModel.commentMean = @"LRTS Detail Model";
    bookDetailModel.desc = @"Lazy Audio";
    bookDetailModel.bId = 100;
    
    //保存
    [bookDetailModel saved];
    
    //数据查询
    [bookDetailModel getModelsWhere:LRTSDBBookDetailModel.bId == 100];
    
    //数据多组查询
    NSMutableArray *modelsArray ;
    [modelsArray addObject:bookDetailModel];
    
    LRTSDBBookDetailModel *bookDetailModel2 = [[LRTSDBBookDetailModel alloc] init];
    bookDetailModel2.commentMean = @"LRTS Detail Model";
    bookDetailModel2.desc = @"Lazy Audio";
    bookDetailModel2.bId = 100;
    
    [modelsArray addObject:bookDetailModel2];
    
    [bookDetailModel saveModels:modelsArray];
}

#pragma mark -
#pragma mark - LRTSKeyValueStorage (3)

- (void)keyValueSrorage {
    //创建数据库
    LRSTKeyValueStore *keyValueStore = [[LRSTKeyValueStore alloc] initKVSWithDatabaseName:@"KeyValueStorage"];
    [keyValueStore createTableWithName:@"valueStroage"];
    
    //数据插入
    [keyValueStore putString:@"value" withKey:@"key" into:@"valueStroage"];
    
    //获取数据
    [keyValueStore getStringWithKey:@"key" formTable:@"valueStroage"];
    
    //删除数据
    [keyValueStore deleteValueWithKey:@"key" formTable:@"valueStroage"];
    
    //修改数据
    [keyValueStore updateCrateTimeWithKey:@"CreateTime" fromTable:@"valueStroage"];
}
*/

/*
- (LRTSDBBookDetailModel *)getOneBookInfoFromDatabaseByBookId:(NSInteger)bookId {
    LRTSDBBookDetailModel *bookDetailModel = [_operation getOneObjectFormTable:NSStringFromClass(LRTSDBBookDetailModel.class) where:LRTSDBBookDetailModel.bId == bookId];
    return bookDetailModel;
}
*/

/*****************************LRTSDBOperation 操作*********************/
/*****************************LRTSDBOperation 操作*********************/
/*****************************LRTSDBOperation 操作*********************/
/*****************************LRTSDBOperation 操作*********************/

#pragma mark -

- (void)dbOperationTest {
    BOOL ret = [[LRTSDBOperation instance] createBookDetailTable];
    
    
    BookDetail *bookDetail = [[BookDetail alloc] init];
    bookDetail.bookID = 1008611;
    bookDetail.bookName = @"book";
    bookDetail.upLoad = [NSDate date];
    
    [[LRTSDBOperation instance] insertObjectIntoBookDetailModelWithObject:bookDetail];
    
    BookDetail *newBookDetail = [[BookDetail alloc] init];
    newBookDetail.bookID = 123456789;
    newBookDetail.bookName = @"new Book";
    
    [[LRTSDBOperation instance] updateOneObjectFromBookDetailWithObject:newBookDetail whereBookId:1008611];
}

- (void)bookDetailCategoryOperation {
    BookDetail *bookDetail = [[BookDetail alloc] init];
    bookDetail.bookID = 10086114;
    bookDetail.bookName = @"book";
    bookDetail.upLoad = [NSDate date];
    
    [bookDetail insertObjectIntoBookDetail];
    
    [bookDetail deleteObjectFromBookDetailModelWithBookId:10086112];
    
    BookDetail *newBookDetail = [[BookDetail alloc] init];
    newBookDetail.bookID = 123456789;
    newBookDetail.bookName = @"new Book";
    
    [bookDetail updateOneObjectFromBookDetailWithObject:newBookDetail whereBookId:10086113];
}


@end
