//
//  LRTSTestViewController.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/15.
//  Copyright © 2017年 boilwater. All rights reserved.
//
//
// LRTSTestViewController 的作用是对 LRTSOperation API 的测试用例
// 给出相关使用的方法
//
//

#import "LRTSTestViewController.h"
#import <LRTSSQliteManager/LRTSDBBookModel.h>
#import <LRTSSQliteManager/LRTSDBBookModel+WCTTableCoding.h>

@interface LRTSTestViewController (){
    BOOL _isResult;
}

@property (nonatomic, strong) LRTSOperation *operation;
@property (nonatomic, strong) LRTSDBBookModel *bookModel;

@end

@implementation LRTSTestViewController

#pragma mark - Life Cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self initParamters];
    [self initHierarchy];
    
//插入测试
//    for(int i = 0; i < 5; i++) {
//        [self insertOperations];
//    }
    
//删除操作
//    [self deleteOperations];
    
//修改操作
    [self updateOperations];

//查找操作
    [self selectOperations];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

#pragma mark - Getter & Setter

#pragma mark - Event

#pragma mark - Delegate

#pragma mark - Public Method

#pragma mark - Private Method

#pragma mark -Init Hierarchy
- (void)initHierarchy {
    
}

#pragma mark -Init Paramters
- (void)initParamters {
    _bookModel = [[LRTSDBBookModel alloc] init];
    _operation = [[LRTSOperation alloc] initWithModel:_bookModel];
    
    _bookModel.bId = 100;
    _bookModel.hot = 100;
    _bookModel.name = @"仙剑传奇";
    _bookModel.author = @"无极";
    _bookModel.like = 19;
}


#pragma mark - SQLite Operations

#pragma mark -Insert

- (void)insertOperations {
    BOOL isResult;
    //单个插入
    isResult = [_operation insertObject:_bookModel into:NSStringFromClass(LRTSDBBookModel.class)];
    
    //对表格的多任务 部分属性 插入数据
    NSMutableArray *objects = [[NSMutableArray alloc] init];
    [objects addObject:_bookModel];
    
    LRTSDBBookModel *bookModel2 = [[LRTSDBBookModel alloc] init];
    bookModel2.bId = 1;
    bookModel2.name = @"《全力以赴》";
    bookModel2.author = @"礼拜";
    
    [objects addObject:bookModel2];
    
    [_operation insertOrReplaceObjects:objects onValues:{LRTSDBBookModel.bId, LRTSDBBookModel.name} into:NSStringFromClass(LRTSDBBookModel.class)];
    
}

#pragma mark -Delete

- (void)deleteOperations {
    //删除数据内容
    _isResult = [_operation deleteObjectsFromTable:NSStringFromClass(LRTSDBBookModel.class) where:LRTSDBBookModel.bId == 100];
//
    
}

#pragma mark -Update

- (void)updateOperations {
    LRTSDBBookModel *bookModel2 = [[LRTSDBBookModel alloc] init];
    bookModel2.bId = 1;
    bookModel2.name = @"《全力以赴》";
    bookModel2.author = @"礼拜 yi";
    
    _isResult = [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookModel.class) withValue:LRTSDBBookModel.author onObject:bookModel2];
    
    
}

#pragma mark -Select

- (void)selectOperations {
    
}



@end
