//
//  LRTSDBCollectionModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBAudioEntityModel.h"
#import "LRTSTagModel.h"
#import "LRTSLGDynamicEntity.h"
#import "LRTSListenCollectionModel.h"


@interface LRTSDBCollectionModel : LRTSDBAudioEntityModel

@property (nonatomic,assign) long long collectId;       // 收藏id
@property (nonatomic,assign) NSInteger hot;             // 人气
@property (nonatomic,assign) NSInteger entityState;     // 书籍状态 0:连载 1:完结（只有书籍有，其他的没有）
@property (nonatomic,assign) NSInteger updateState;     // 书籍是否有更新 0:无更新 1:有更新(目前只有书籍有)
@property (nonatomic,assign) NSTimeInterval updateTime; // 最后收藏时间

// 父类中的title将保存entityTitle和entityDesc合并后的字符串（临时解决方案，若加新字段缓存改动非常大）
@property (nonatomic,strong) NSString *entityTitle;     // 实体标题
@property (nonatomic,strong) NSString *entityDesc;      // 实体简介

// 听单相关
@property (nonatomic,assign) long long belongListenCollectionId;       // 所属听单的id
@property (nonatomic,strong) NSString *c_version;
@property (assign,nonatomic) NSInteger payType;           //0免费1整本购买2分章购买
//@property (nonatomic,assign) NSInteger strategy;          // 第1位:限时免费,第2位：会员书库,第3位:VIP整本抢先,第4位:VIP章节抢先
@property (nonatomic,strong) LRTSTagModel *tag;

WCDB_PROPERTY(

@end
