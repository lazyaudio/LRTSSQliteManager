//
//  LRTSDBVipBookModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSTagModel.h"
#import "LRTSDBPublicTypeDefine.h"


@interface LRTSDBVipBookModel : LRTSDBModel

@property (nonatomic) NSInteger bId;                        //书籍id
@property (strong,nonatomic) NSString *name;                //名称
@property (strong,nonatomic) NSString *cover;               //封面
@property (strong,nonatomic) NSString *author;              //作者
@property (strong,nonatomic) NSString *announcer;           //播音
@property (nonatomic, assign)NSInteger hot;                 // 热度
@property (nonatomic) NSInteger state;                      //书籍状态（１-连载中，２-全集）
@property (nonatomic) NSInteger sort;                       //0正序1倒序
@property (nonatomic, strong) NSString *lastUpdateTime;     // 最后更新时间
@property (nonatomic,assign)NSInteger listenPrice;          // 收听全本的价格
@property (nonatomic,assign) NSInteger downPrice;           // 下载本书价格
@property (nonatomic) NSInteger commentCount;               //评论总数
@property (nonatomic, strong)NSString *desc;                //书籍详情
@property (assign,nonatomic) NSInteger payType;             //0免费1整本购买2分章购买
@property (nonatomic,assign) NSInteger strategy;          // vip策略
@property (nonatomic,strong) LRTSTagModel *tag;                    // 标签
@property (nonatomic,assign) EntityPublishType publishType; // 跳转类型

@end
