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

#import "LRTSBookDetailViewController.h"

//

#import "LRTSDBBookDetailModel.h"
#import "LRTSDBBookDetailModel+WCTTableCoding.h"
#import "LRTSOperation.h"



@interface LRTSBookDetailViewController ()

@property (strong, nonatomic) LRTSOperation *operation;
@property (strong, nonatomic) LRTSDBBookDetailModel *detailModel;


@end

@implementation LRTSBookDetailViewController

#pragma mark - Life Cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initParamters];

//DetailBook
    
//insert operation
//    [self insertDetailBookModel];
    
//getOneObject
    LRTSDBBookDetailModel *detailBook = [self getOneBookInfoFromDatabaseByBookId:2];
    
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
    _detailModel = [[LRTSDBBookDetailModel alloc] init];
    
}

#pragma mark - BookDetail Of Operations For SQL

#pragma mark -Insert

- (void)insertDetailBookModel {
    if (!_detailModel) {
        _detailModel = [[LRTSDBBookDetailModel alloc] init];
    }
    _detailModel.haveLink = YES;
    _detailModel.bookVersion = @"版本1.0.0";
    _detailModel.desc = @"shantou university";
    
    [_detailModel saved];
    
//    //循环加入数据
//    NSInteger i = 1;
//
//    while (i < 5) {
//        ++i;
//        _detailModel.bId = i;
//        [_operation insertObject:_detailModel into:NSStringFromClass(LRTSDBBookDetailModel.class)];
//    }
}

- (void)deleteDetailBookModel {
    //删除所有的数据
    [_operation deleteAllObjectsFromTable:NSStringFromClass(LRTSDBBookDetailModel.class)];
    
    //条件删除
    [_operation deleteObjectsFromTable:NSStringFromClass(LRTSDBBookDetailModel.class) where:LRTSDBBookDetailModel.bId == 100];
}

- (void)updateDetailBookModel {
    if (!_detailModel) {
        _detailModel = [[LRTSDBBookDetailModel alloc] init];
    }
    _detailModel.bId = 1;
    _detailModel.bookPrice = 118;
    _detailModel.debugDescription = @"
    
    [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookDetailModel.class) onValue:LRTSDBBookDetailModel.bId withObject:_detailModel];
}

- (LRTSDBBookDetailModel *)getOneBookInfoFromDatabaseByBookId:(NSInteger)bookId {
    LRTSDBBookDetailModel *bookDetailModel = [_operation getOneObjectFormTable:NSStringFromClass(LRTSDBBookDetailModel.class) where:LRTSDBBookDetailModel.bId == bookId];
    return bookDetailModel;
}




@end
