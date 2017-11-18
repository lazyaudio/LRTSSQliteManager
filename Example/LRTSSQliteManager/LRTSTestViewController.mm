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
#import <LRTSSQliteManager/LRTSDBBookDetailModel.h>
#import <LRTSSQliteManager/LRTSDBBookDetailModel+WCTTableCoding.h>

@interface LRTSTestViewController (){
    BOOL _isResult;
}

@property (nonatomic, strong) LRTSOperation *operation;
@property (nonatomic, strong) LRTSDBBookModel *bookModel;
@property (nonatomic, strong) LRTSDBBookDetailModel *bookDetailModel;

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
//    [self updateOperations];

//查找操作
//    [self selectOperations];
    
//获取操作
    [self getOperations];

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
    _bookDetailModel = [[LRTSDBBookDetailModel alloc] init];
    _operation = [[LRTSOperation alloc] initWithModel:_bookModel];
    
    LRTSOperation *bookOperation = [[LRTSOperation alloc] initWithModel:_bookDetailModel];
    
    //初始 BookModel
    _bookModel.bId = 100;
    _bookModel.hot = 100;
    _bookModel.name = @"仙剑传奇";
    _bookModel.author = @"无极";
    _bookModel.like = 19;
    
    //初始话 BookDetailModel
//    _bookDetailModel.bookID = 100;
    _bookDetailModel.length = 10000;
    _bookDetailModel.bookVersion = @"广州出版社";
    _bookDetailModel.desc = @"广州市人民教育出版社";
}


#pragma mark - SQLite Operations

#pragma mark -Insert

- (void)insertOperations {
    BOOL isResult;
    //单个插入
    /*
    isResult = [_operation insertObject:_bookDetailModel into:NSStringFromClass(LRTSDBBookDetailModel.class)];
     */

    //对表格的多任务 部分属性 插入数据
    NSMutableArray *objects = [[NSMutableArray alloc] init];
    [objects addObject:_bookModel];
    
    LRTSDBBookModel *bookModel2 = [[LRTSDBBookModel alloc] init];
    bookModel2.bId = 2;
    bookModel2.name = @"《全力以赴》";
    bookModel2.author = @"礼拜";
    [objects addObject:bookModel2];
    
    LRTSDBBookModel *bookModel3 = [[LRTSDBBookModel alloc] init];
    bookModel3.bId = 3;
    bookModel3.name = @"《全力以赴》";
    bookModel3.author = @"礼拜";
    [objects addObject:bookModel3];
    
    LRTSDBBookModel *bookModel4 = [[LRTSDBBookModel alloc] init];
    bookModel4.bId = 4;
    bookModel4.name = @"《全力以赴》";
    bookModel4.author = @"礼拜";
    [objects addObject:bookModel4];
    
    LRTSDBBookModel *bookModel5 = [[LRTSDBBookModel alloc] init];
    bookModel5.bId = 5;
    bookModel5.name = @"《全力以赴》";
    bookModel5.author = @"礼拜";
    [objects addObject:bookModel5];
    
    LRTSDBBookModel *bookModel6 = [[LRTSDBBookModel alloc] init];
    bookModel6.bId = 6;
    bookModel6.name = @"《全力以赴》";
    bookModel6.author = @"礼拜";
    [objects addObject:bookModel6];
    
    
    [_operation insertOrReplaceObjects:objects onValues:{LRTSDBBookModel.bId, LRTSDBBookModel.name} into:NSStringFromClass(LRTSDBBookModel.class)];
    
}

#pragma mark -Delete

- (void)deleteOperations {
    //删除数据内容
    _isResult = [_operation deleteObjectsFromTable:NSStringFromClass(LRTSDBBookModel.class) where:LRTSDBBookModel.bId == 100];
//
    _isResult = [_operation deleteAllObjectsFromTable:NSStringFromClass(LRTSDBBookModel.class)];
    
}

#pragma mark -Update

- (void)updateOperations {
    LRTSDBBookModel *bookModel2 = [[LRTSDBBookModel alloc] init];
    bookModel2.bId = 1;
    bookModel2.name = @"心系广州";
    bookModel2.author = @"双休日";
    
//    _isResult = [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookModel.class) withValue:LRTSDBBookModel.author onObject:bookModel2];
    
//    _isResult = [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookModel.class)
//                                     onValues:{LRTSDBBookModel.bId, LRTSDBBookModel.author}
//                                   withObject:bookModel2
//                                        where:LRTSDBBookModel.bId == 100];
    
//    [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookModel.class)
//                        withValue:LRTSDBBookModel.author
//                         onObject:bookModel2
//                            where:LRTSDBBookModel.bId == 100];
    
    [_operation updateRowsInTable:NSStringFromClass(LRTSDBBookModel.class) withValues:{LRTSDBBookModel.author, LRTSDBBookModel.name} withObject:bookModel2 where:LRTSDBBookModel.bId == 100];
    
}

#pragma mark -Select

- (void)selectOperations {
    NSString *bookName = NSStringFromClass(LRTSDBBookModel.class);
    NSString *bookDetailName = NSStringFromClass(LRTSDBBookDetailModel.class);
    
//    NSArray *rows = [_operation selectRowsOnResults:{LRTSDBBookModel.name.inTable(bookName), LRTSDBBookDetailModel.desc.inTable(bookDetailName)} fromTables:@[bookName, bookDetailName] where:LRTSDBBookModel.bId == 1];
    
    NSArray *mutableObjects = [_operation selectMutableObjectsOnResults:{LRTSDBBookModel.name.inTable(bookName), LRTSDBBookDetailModel.desc.inTable(bookDetailName)} fromTables:@[bookName, bookDetailName] where:LRTSDBBookModel.bId == 1];
    
}

#pragma mark -Get

- (void)getOperations {
    NSArray *objects = [NSArray array];
    NSString *bookName = NSStringFromClass(LRTSDBBookModel.class);
    NSString *bookDetailName = NSStringFromClass(LRTSDBBookDetailModel.class);
    
//    NSArray *objects = [_operation getAllObjectsForTable:bookName];
    //获取数据库中第一条数据
//    objects = [_operation getOneObjectFormTable:bookName];
    
    //获取多个 Object 类型的数据
//    objects = [_operation getObjectsForTable:bookName where:LRTSDBBookModel.bId >= 4];
  
    objects = [_operation getObjectsForTable:bookName where:LRTSDBBookModel.bId >= 4 orderBy:LRTSDBBookModel.bId.order(WCTOrderedAscending)];
    
}






@end









