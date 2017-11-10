//
//  NSObject+LRTSVipAndBoutique.m
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "NSObject+LRTSVipAndBoutique.h"

//#import "LMBookDetail.h"
//#import "LMBook.h"
//#import "LMBuyBook.h"
//#import "LMCollection.h"
//#import "LMVipBook.h"
//
//#import "LRTSDBSectionModel.h"
//#import "LRTSDBProgrammeAudioModel.h"
//#import "LRTSDBDetailPriceCellModel.h"

#import "LRTSDBBookDetailModel.h"
#import "LRTSDBBookModel.h"
#import "LRTSBuyBookModel.h"
#import "LRTSDBCollectionModel.h"
#import "LRTSDBVipBookModel.h"
#import "LRTSDBSectionModel.h"
#import "LRTSDBProgrammeAudioModel.h"
#import "LRTSDBDetailPriceCellModel.h"


@implementation NSObject (LRTSVipAndBoutique)

- (BOOL)strategy_isVIPOrLimitTimeListenWholeBook {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    //分章抢先,列表不显示标签
    
    if ([self respondsToSelector:@selector(strategy)]) {
        return ([self strategy] & (strategyType_VIPBookStore | strategyType_ScoopBook)) > 0;
    }
    
    return NO;
}

- (BOOL)strategy_isLimitTimeListenWholeBook {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    if ([self respondsToSelector:@selector(strategy)]) {
        return ([self strategy] & strategyType_ScoopBook) > 0;
    }
    
    return NO;
}

- (BOOL)strategy_isAnyLimitTimeListenBook {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    if ([self respondsToSelector:@selector(strategy)]) {
        return ([self strategy] & (strategyType_ScoopBook | strategyType_ScoopSection)) > 0;
    }
    
    return NO;
}

- (BOOL)payType_isBoutique {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    if ([self respondsToSelector:@selector(payType)]) {
        return ([self payType] != 0) > 0;
    }
    
    return NO;
}

- (BOOL)strategy_isMemberFreeLimits {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    if ([self respondsToSelector:@selector(strategy)]) {
        return ([self strategy] & strategyType_VIPFreeLimits) > 0;
    }
    return NO;
}

- (BOOL)strategy_isFreeLimits {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    if ([self respondsToSelector:@selector(strategy)]) {
        return ([self strategy] & strategyType_AllFreeLimits) > 0;
    }
    
    return NO;
}

- (BOOL)strategy_isAnyFreeLimits {
    
#if DEBUG
    BOOL isValidModel = [self isKindOfClass:[LRTSDBSectionModel class]]
    || [self isKindOfClass:[LRTSDBDetailPriceCellModel class]]
    || [self isKindOfClass:[LRTSDBProgrammeAudioModel class]];
    NSAssert(isValidModel, @"该分类仅供LRTSDBSectionModel,LRTSDBProgrammeAudioModel使用");
#endif
    
    if ([self respondsToSelector:@selector(strategy)]) {
        return ([self strategy] & (strategyType_AllFreeLimits | strategyType_VIPFreeLimits)) > 0;
    }
    
    return NO;
}

@end
