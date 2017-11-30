//
//  LRTSDBListenerBuyModel+SectionIndex.m
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBListenerBuyModel+SectionIndex.h"
#import "LRTSDBListenerPriceModel.h"
#import "LRTSDBListenerPriceModel+PriceOperations.h"

@implementation LRTSDBListenerBuyModel (SectionIndex)

+ (NSArray *)listenBuyModelsWithPriceModel:(LRTSDBListenerPriceModel *)priceModel
                              sectionIndex:(NSInteger)sectionIndex {
    NSInteger positionOfIndex = [priceModel.unbuySectionIndexs indexOfObject:@(sectionIndex)];
    if ([priceModel.buySectionsStr isEqualToString:@"all"]
        || !priceModel.unbuySectionIndexs.count
        || positionOfIndex == NSNotFound) {
        return nil;
    }
    
    NSInteger currentPrice = [priceModel matchPrice];
    
    NSMutableArray *buyModels = [NSMutableArray array];
    if (priceModel.payType == LRTSPriceModelPayTypeBook
        || priceModel.payType == LRTSPriceModelPayTypeSubscribe) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [[LRTSDBListenerBuyModel alloc] init];
        currentIndexBuyModel.sectionIndexs = priceModel.unbuySectionIndexs;
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = priceModel.payType == LRTSPriceModelPayTypeBook?@"购买本书":@"订阅本书";
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = priceModel.payType == LRTSPriceModelPayTypeBook?@"购买节目":@"订阅节目";
        }
        
        currentIndexBuyModel.coinCount = currentPrice/10;
        currentIndexBuyModel.viceCoinCount = currentPrice/10*[priceModel vipDiscountValue];
        
        if (priceModel.isVIP) {
            NSInteger tempPrice = currentIndexBuyModel.coinCount;
            currentIndexBuyModel.coinCount = currentIndexBuyModel.viceCoinCount;
            currentIndexBuyModel.viceCoinCount = tempPrice;
        }
        
        currentIndexBuyModel.buyType = priceModel.payType;
        [buyModels addObject:currentIndexBuyModel];
        return [buyModels copy];
    }
    
    
    NSRange lastIndexsRange = NSMakeRange(positionOfIndex,
                                          priceModel.unbuySectionIndexs.count-positionOfIndex);
    NSArray *lastIndexs = [priceModel.unbuySectionIndexs subarrayWithRange:lastIndexsRange];
    
    LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:@[@(sectionIndex)] priceModel:priceModel];
    if (priceModel.entityType == LRTSEntityTypeBook) {
        currentIndexBuyModel.title = @"本集";
    } else if (priceModel.entityType == LRTSEntityTypeAlbum){
        currentIndexBuyModel.title = @"本期";
    }
    [buyModels addObject:currentIndexBuyModel];
    
    if (lastIndexs.count >1 && lastIndexs.count < 10) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:lastIndexs priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd集",lastIndexs.count];
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd期",lastIndexs.count];
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count >= 10) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:[lastIndexs subarrayWithRange:NSMakeRange(0, 10)] priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = @"后10集";
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = @"后10期";
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count > 10 && lastIndexs.count < 50) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:lastIndexs priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd集",lastIndexs.count];
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd期",lastIndexs.count];
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count >= 50) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:[lastIndexs subarrayWithRange:NSMakeRange(0, 50)] priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = @"后50集";
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = @"后50期";
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count > 50) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:lastIndexs priceModel:priceModel];
        currentIndexBuyModel.title = @"自定义";
        currentIndexBuyModel.action = LRTSAudioPayItemActionChooseCount;
        [buyModels addObject:currentIndexBuyModel];
    }
    return [buyModels copy];
}

+ (NSArray *)listenBuyModelsWithPriceModel:(LRTSDBListenerPriceModel *)priceModel
                                 sectionId:(long)sectionId {
    NSInteger positionOfIndex = [priceModel.unbuySectionIndexs indexOfObject:@(sectionId)];
    if ([priceModel.buySectionsStr isEqualToString:@"all"]
        || !priceModel.unbuySectionIndexs.count
        || positionOfIndex == NSNotFound) {
        return nil;
    }
    
    NSInteger currentPrice = [priceModel matchPrice];
    
    NSMutableArray *buyModels = [NSMutableArray array];
    if (priceModel.payType == LRTSPriceModelPayTypeBook
        || priceModel.payType == LRTSPriceModelPayTypeSubscribe) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [[LRTSDBListenerBuyModel alloc] init];
        currentIndexBuyModel.sectionIndexs = priceModel.unbuySectionIndexs;
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = priceModel.payType == LRTSPriceModelPayTypeBook?@"购买本书":@"订阅本书";
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = priceModel.payType == LRTSPriceModelPayTypeBook?@"购买节目":@"订阅节目";
        }
        currentIndexBuyModel.coinCount = currentPrice/10;
        currentIndexBuyModel.viceCoinCount = currentPrice/10*[priceModel vipDiscountValue];
        
        if (priceModel.isVIP) {
            NSInteger tempPrice = currentIndexBuyModel.coinCount;
            currentIndexBuyModel.coinCount = currentIndexBuyModel.viceCoinCount;
            currentIndexBuyModel.viceCoinCount = tempPrice;
        }
        
        currentIndexBuyModel.buyType = priceModel.payType;
        [buyModels addObject:currentIndexBuyModel];
        return [buyModels copy];
    }
    
    
    NSRange lastIndexsRange = NSMakeRange(positionOfIndex,
                                          priceModel.unbuySectionIndexs.count-positionOfIndex);
    NSArray *lastIndexs = [priceModel.unbuySectionIndexs subarrayWithRange:lastIndexsRange];
    LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:@[@(sectionId)] priceModel:priceModel];
    if (priceModel.entityType == LRTSEntityTypeBook) {
        currentIndexBuyModel.title = @"本集";
    } else if (priceModel.entityType == LRTSEntityTypeAlbum){
        currentIndexBuyModel.title = @"本期";
    }
    [buyModels addObject:currentIndexBuyModel];
    if (lastIndexs.count >1 && lastIndexs.count < 10) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:lastIndexs priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd集",lastIndexs.count];
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd期",lastIndexs.count];
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count >= 10) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:[lastIndexs subarrayWithRange:NSMakeRange(0, 10)] priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = @"后10集";
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = @"后10期";
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count > 10 && lastIndexs.count < 50) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:lastIndexs priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd集",lastIndexs.count];
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = [NSString stringWithFormat:@"剩余%zd期",lastIndexs.count];
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count >= 50) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:[lastIndexs subarrayWithRange:NSMakeRange(0, 50)] priceModel:priceModel];
        if (priceModel.entityType == LRTSEntityTypeBook) {
            currentIndexBuyModel.title = @"后50集";
        } else if (priceModel.entityType == LRTSEntityTypeAlbum){
            currentIndexBuyModel.title = @"后50期";
        }
        [buyModels addObject:currentIndexBuyModel];
    }
    if (lastIndexs.count > 50) {
        LRTSDBListenerBuyModel *currentIndexBuyModel = [LRTSDBListenerBuyModel buyModelWithIndexs:lastIndexs priceModel:priceModel];
        currentIndexBuyModel.title = @"自定义";
        currentIndexBuyModel.action = LRTSAudioPayItemActionChooseCount;
        [buyModels addObject:currentIndexBuyModel];
    }
    return [buyModels copy];
}

#pragma mark - privated Methods

+ (LRTSDBListenerBuyModel *)buyModelWithIndexs:(NSArray *)sectionIndexs
                              priceModel:(LRTSDBListenerPriceModel *)priceModel{
    LRTSDBListenerBuyModel *buyModel = [[LRTSDBListenerBuyModel alloc] init];
    
    NSInteger currentPrice = [priceModel matchPrice];
    buyModel.coinCount = currentPrice*sectionIndexs.count/10;
    buyModel.viceCoinCount = currentPrice*sectionIndexs.count/10*[priceModel vipDiscountValue];
    buyModel.buyType = priceModel.payType;
    buyModel.sectionIndexs = sectionIndexs;
    if (priceModel.isVIP) {
        NSInteger tempPrice = buyModel.coinCount;
        buyModel.coinCount = buyModel.viceCoinCount;
        buyModel.viceCoinCount = tempPrice;
    }
    return buyModel;
}

@end
