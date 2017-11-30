//
//  LRTSDBListenerPriceModel+PriceOperations.m
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBListenerPriceModel+PriceOperations.h"
#import "LRTSDBListenerDiscountModel.h"
#import "LRTSDBListenerDiscountModel+Configuration.h"
#import "LRTSDBListenerBuyModel.h"
#import "LRTSPurchaseTool.h"

@implementation LRTSDBListenerPriceModel (PriceOperations)

- (instancetype)initWithDict:(NSDictionary *)dict
                    entityId:(long)entityId
                  entityType:(LRTSEntityType)entityType{
    if (self = [super init]) {
        self.entityId = entityId;
        self.entityType = entityType;
        self.sectionCount = [[dict objectForKey:@"sections"] integerValue];
        self.estimatedSectionCount = [[dict objectForKey:@"estimatedSections"] integerValue];
        self.payType = (LRTSPriceModelPayType)[[dict objectForKey:@"priceType"] integerValue];
        self.price = [[dict objectForKey:@"price"] integerValue];
        self.discountPrice = [[dict objectForKey:@"discountPrice"] integerValue];
        self.deadlineTime = [[dict objectForKey:@"deadlineTime"] doubleValue];
        self.canUseTicket = [[dict objectForKey:@"canUseTicket"] integerValue];
        self.choosePriceType = (LRTSChoosePriceType)[[dict objectForKey:@"choosePrice"] integerValue];
        
        NSString *frees = [dict objectForKey:@"frees"];
        if (![frees isKindOfClass:[NSNull class]] && frees.length) {
            self.freeSectionsStr = frees;
        }
        NSString *buys = [dict objectForKey:@"buys"];
        if (![buys isKindOfClass:[NSNull class]] && buys.length) {
            self.buySectionsStr = buys;
        }
        
        [self caculateUnbuyIndexs];
        NSArray *discountDicts = [dict objectForKey:@"discounts"];
        if (discountDicts.count) {
            self.discounts = [LRTSDBListenerDiscountModel discountModelsWithDicts:discountDicts];
            NSData *priceData = [NSJSONSerialization dataWithJSONObject:@{@"discounts":discountDicts} options:NSJSONWritingPrettyPrinted error:NULL];
            self.discountStr = [[NSString alloc] initWithData:priceData
                                                 encoding:NSUTF8StringEncoding];
        }
    }
    return self;
}

- (id)copyWithZone:(NSZone *)zone {
    LRTSDBListenerPriceModel *copyModel = [[[self class] allocWithZone:zone] init];
    copyModel.entityId = self.entityId;
    copyModel.entityType = self.entityType;
    copyModel.sectionCount = self.sectionCount;
    copyModel.estimatedSectionCount = self.estimatedSectionCount;
    copyModel.payType = self.payType;
    copyModel.price = self.price;
    copyModel.discountPrice = self.discountPrice;
    copyModel.deadlineTime = self.deadlineTime;
    copyModel.canUseTicket = self.canUseTicket;
    copyModel.choosePriceType = self.choosePriceType;
    copyModel.freeSectionsStr = self.freeSectionsStr;
    copyModel.buySectionsStr = self.buySectionsStr;
    copyModel.discounts = [self.discounts copy];
    copyModel.discountStr = self.discountStr;
    copyModel.freeSectionIndexs = [self.freeSectionIndexs copy];
    copyModel.buySectionIndexs = [self.buySectionIndexs copy];
    copyModel.unbuySectionIndexs = [self.unbuySectionIndexs copy];
    
    return copyModel;
}

+ (instancetype)priceModelWithDict:(NSDictionary *)dict
                          entityId:(long)entityId
                        entityType:(LRTSEntityType)entityType{
    return [[self alloc] initWithDict:dict entityId:entityId entityType:entityType];
}

- (BOOL)isUnbuySectionForIndex:(NSInteger)index{
    return [self.unbuySectionIndexs containsObject:@(index)];
}

- (NSArray *)priceModelAllPayIndexs{
    if (self.entityType == LRTSEntityTypeBook) {
        return [LRTSPurchaseTool unintersectionIndexs:self.freeSectionIndexs
                                         IndexCount:self.sectionCount];
    } else if (self.entityType == LRTSEntityTypeAlbum) {
        NSMutableArray *mArray = [NSMutableArray arrayWithArray:self.unbuySectionIndexs];
        [mArray addObjectsFromArray:self.buySectionIndexs];
        return [NSSet setWithArray:mArray].allObjects;
    } else {
        return nil;
    }
}

#pragma mark - setter & getter
//读取数据库使用
- (void)setDiscountStr:(NSString *)discountStr{
    self.discountStr = discountStr;
    if (!self.discounts.count && discountStr.length) {
        NSDictionary *dict = [NSJSONSerialization JSONObjectWithData:[discountStr dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableContainers error:NULL];
        self.discounts = [LRTSDBListenerDiscountModel discountModelsWithDicts:[dict objectForKey:@"discounts"]];
    }
}


- (void)setFreeSectionsStr:(NSString *)freeSectionsStr{
    if (![self.freeSectionsStr isEqualToString:freeSectionsStr]) {
        self.freeSectionsStr = freeSectionsStr;
        
        if (self.entityType == LRTSEntityTypeBook) {
            if ([self.freeSectionsStr isEqualToString:@"all"]) {
                self.freeSectionIndexs = [LRTSPurchaseTool unintersectionIndexs:nil
                                                                   IndexCount:self.sectionCount];
            } else {
                self.freeSectionIndexs = [LRTSPurchaseTool indexsWithSectionStr:freeSectionsStr];
            }
        } else {
            if (![self.freeSectionsStr isEqualToString:@"all"]
                && self.freeSectionsStr.length > 0) {
                //                NSArray *strArray = [_freeSectionsStr componentsSeparatedByString:@","];
                //                NSMutableArray *numArray = [NSMutableArray array];
                //                for (NSString *str in strArray) {
                //                    [numArray addObject:@(str.longLongValue)];
                //                }
                //                self.freeSectionIndexs = numArray.count?[numArray copy]:nil;
                self.freeSectionIndexs = [LRTSPurchaseTool indexsWithSectionStr:self.freeSectionsStr];
            }
        }
        
    }
}

- (void)setBuySectionsStr:(NSString *)buySectionsStr{
    if (![self.buySectionsStr isEqualToString:buySectionsStr]) {
        self.buySectionsStr = buySectionsStr;
        
        if (self.entityType == LRTSEntityTypeBook) {
            if ([self.buySectionsStr isEqualToString:@"all"]) {
                self.buySectionIndexs = [LRTSPurchaseTool unintersectionIndexs:nil
                                                                  IndexCount:self.sectionCount];
            } else {
                self.buySectionIndexs = [LRTSPurchaseTool indexsWithSectionStr:buySectionsStr];
            }
        } else {
            if (![self.buySectionsStr isEqualToString:@"all"]
                && self.buySectionsStr.length > 0) {
                //                NSArray *strArray = [_buySectionsStr componentsSeparatedByString:@","];
                //                NSMutableArray *numArray = [NSMutableArray array];
                //                for (NSString *str in strArray) {
                //                    [numArray addObject:@(str.longLongValue)];
                //                }
                //                self.buySectionIndexs = numArray.count?[numArray copy]:nil;
                self.buySectionIndexs = [LRTSPurchaseTool indexsWithSectionStr:self.buySectionsStr];
            }
        }
        
    }
}

- (void)setAllSectionsStr:(NSString *)allSectionsStr{
    if (self.entityType == LRTSEntityTypeAlbum) {
        if (![self.allSectionsStr isEqualToString:allSectionsStr]) {
            self.allSectionsStr = allSectionsStr;
            
            NSArray *strArray = [self.allSectionsStr componentsSeparatedByString:@","];
            NSMutableArray *numArray = [NSMutableArray array];
            for (NSString *str in strArray) {
                [numArray addObject:@(str.longLongValue)];
            }
            NSArray *allIndexs = numArray.count?[numArray copy]:nil;
            if ([self.freeSectionsStr isEqualToString:@"all"]) {
                self.freeSectionIndexs = allIndexs;
            } else if ([self.buySectionsStr isEqualToString:@"all"]) {
                self.buySectionIndexs = allIndexs;
            }
            [numArray removeObjectsInArray:self.freeSectionIndexs];
            [numArray removeObjectsInArray:self.buySectionIndexs];
            self.unbuySectionIndexs = numArray.count?[numArray copy]:nil;
        }
    }
}

- (void)caculateUnbuyIndexs{
    if (self.entityType == LRTSEntityTypeBook) {
        NSArray *tempIndexs = [LRTSPurchaseTool combineIndexs:self.freeSectionIndexs
                                                 withIndexs:self.buySectionIndexs];
        self.unbuySectionIndexs = [LRTSPurchaseTool unintersectionIndexs:tempIndexs
                                                            IndexCount:self.sectionCount];
    }
}

- (void)updateWithFinishBuyModel:(LRTSDBListenerBuyModel *)buyModel{
    if (buyModel.buyType == LRTSPriceModelPayTypeBook
        || buyModel.buyType == LRTSPriceModelPayTypeSubscribe) {
        self.buySectionsStr = @"all";
        self.unbuySectionIndexs = nil;
        self.buySectionIndexs = [LRTSPurchaseTool unintersectionIndexs:self.unbuySectionIndexs
                                                          IndexCount:self.sectionCount];
    } else {
        NSArray *newBuyIndexs = [LRTSPurchaseTool combineIndexs:self.buySectionIndexs withIndexs:buyModel.sectionIndexs];
        self.buySectionsStr = [LRTSPurchaseTool sectionStrWithIndexs:newBuyIndexs];
        self.buySectionIndexs = newBuyIndexs;
        [self caculateUnbuyIndexs];
    }
}

- (BOOL)isVIP {
    return self.choosePriceType >= LRTSChoosePriceTypeVIP;
}

- (NSInteger)matchPrice {
    NSInteger mPrice = 0;
    
    switch (self.choosePriceType) {
        case LRTSChoosePriceTypeOriginal:
            mPrice = self.price;
            break;
        case LRTSChoosePriceTypeDiscount:
            mPrice = self.discountPrice;
            break;
        case LRTSChoosePriceTypeVIP:
            mPrice = self.price;
            break;
        case LRTSChoosePriceTypeDiscountAndVIP:
            mPrice = self.discountPrice;
            break;
        default:
            break;
    }
    return mPrice;
}

- (double)vipDiscountValue{
    LRTSDBListenerDiscountModel *vipDiscountModel = [self vipDiscount];
    if (nil == vipDiscountModel) {
        return 1.0;
    }
    return vipDiscountModel.discountValue.doubleValue;
}

- (LRTSDBListenerDiscountModel *)vipDiscount {
    LRTSDBListenerDiscountModel *discountModel = nil;
    for (LRTSDBListenerDiscountModel *discount in self.discounts) {
        if (discount.discountType == LRTSDBListenerDiscountTypeVIP){
            discountModel = discount;
            break;
        }
    }
    return discountModel;
}

@end
