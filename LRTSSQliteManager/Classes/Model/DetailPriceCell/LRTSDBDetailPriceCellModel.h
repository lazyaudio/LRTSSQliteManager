//
//  LRTSDBDetailPriceCellModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDBListenerPriceModel.h"
#import <WCDB/WCDB.h>

/**
 详情价格栏cell 模型类
 */

//LRTSDetailPriceModelType

typedef NS_ENUM(NSInteger, LRTSDetailPriceModelType) {
    LRTSDetailPriceModelTypeBook = 0, // 书籍
    LRTSDetailPriceModelTypeProgramme // 节目
};

@interface LRTSDBDetailPriceCellModel : LRTSDBModel

@property (nonatomic, strong) NSArray *tags;    //标签

@property (nonatomic, strong) LRTSDBListenerPriceModel *priceModel;   //价格模型

@property (nonatomic,assign) LRTSDetailPriceModelType detailType; // 详情类型

@property (nonatomic, assign) NSTimeInterval freeEndTime;       // 限免截止时间

@property (nonatomic,assign) NSTimeInterval discountEndTime;    // 折扣截止时间

@property (nonatomic, assign) NSInteger strategy;          // vip策略

#pragma mark - WCDB 数据绑定

WCDB_PROPERTY(tags)
WCDB_PROPERTY(priceModel)
WCDB_PROPERTY(detailType)
WCDB_PROPERTY(freeEndTime)

WCDB_PROPERTY(discountEndTime)
WCDB_PROPERTY(strategy)

@end
