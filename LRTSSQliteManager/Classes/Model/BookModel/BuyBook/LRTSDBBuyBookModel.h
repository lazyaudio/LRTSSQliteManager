//
//  LRTSDBBuyBookModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSTagModel.h"
#import "LRTSDBPublicTypeDefine.h"

@interface LRTSDBBuyBookModel : LRTSDBModel

@property (assign, nonatomic) NSInteger      pId;           // 书籍ID
@property (copy  , nonatomic) NSString       *name;         // 书籍名称
@property (copy  , nonatomic) NSString       *desc;         // 书籍描述
@property (copy  , nonatomic) NSString       *author;       // 作者
@property (copy  , nonatomic) NSString       *cover;        // 书籍封面

@property (copy,   nonatomic) NSString       *type;          // 书籍分类
@property (assign, nonatomic) NSInteger      playCount;     // 播放数
@property (copy,   nonatomic) NSString       *announcer;    // 播音员

@property (assign, nonatomic) NSInteger      state;         // 状态。1-连载中，2-完结
@property (assign, nonatomic) NSInteger      payType;       // 支付类型0免费1整本2分章
@property (nonatomic,assign) NSInteger strategy;            // vip策略
@property (nonatomic,strong) LRTSTagModel *tag;
@property (nonatomic,assign) EntityPublishType publishType; // 跳转类型

@end
