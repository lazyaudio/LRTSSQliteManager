//
//  LRTSBookDetailViewController.m
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/18.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import "LRTSBookDetailViewController.h"
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
    _operation = [[LRTSOperation alloc] initWithModel:_detailModel];
    
//    NSDictionary
}

#pragma mark -BookDetail Of Operations For SQL

- (void)insertDetailBookModel {
    if (!_detailModel) {
        _detailModel = [[LRTSDBBookDetailModel alloc] init];
    }
    _detailModel.haveLink = YES;
    _detailModel.bookVersion = @"版本1.0.0";
    _detailModel.desc = @"shantou university";
    //循环加入数据
    NSInteger i = 1;
    
    while (i < 5) {
        ++i;
        _detailModel.bId = i;
        [_operation insertObject:_detailModel into:NSStringFromClass(LRTSDBBookDetailModel.class)];
    }
}

- (LRTSDBBookDetailModel *)getOneBookInfoFromDatabaseByBookId:(NSInteger)bookId {
    LRTSDBBookDetailModel *bookDetailModel = [_operation getOneObjectFormTable:NSStringFromClass(LRTSDBBookDetailModel.class) where:LRTSDBBookDetailModel.bId == bookId];
    return bookDetailModel;
}




@end
