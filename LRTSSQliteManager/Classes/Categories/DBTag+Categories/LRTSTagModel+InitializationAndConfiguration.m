//
//  LRTSTagModel+InitializationAndConfiguration.m
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSTagModel+InitializationAndConfiguration.h"

@implementation LRTSTagModel (InitializationAndConfiguration)

- (instancetype )initWithDict:(NSDictionary *)dic {
    if (self) {
        self.tg_type = [dic[@"type"] integerValue];
        self.tg_name = dic[@"name"];
        self.tg_bgColor = dic[@"bgColor"];
    }
    return self;
}

+ (instancetype)tagFromJson:(NSString *)jsonTag {
    LRTSTagModel *tag = nil;
    
    if (jsonTag.length > 0) {
        NSData *resultData = [jsonTag dataUsingEncoding:NSUTF8StringEncoding];
        NSDictionary *result = [NSJSONSerialization JSONObjectWithData:resultData options:NSJSONReadingMutableContainers error:NULL];
        if ([result isKindOfClass:[NSDictionary class]]) {
            tag = [[LRTSTagModel alloc] initWithDict:result];
        }
    }
    
    if (nil == tag) {
        tag = [[LRTSTagModel alloc] init];
    }
    
    return tag;
}

- (NSDictionary *)dictionaryObjec {
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:((nil == self.tg_name)?@"":self.tg_name) forKey:@"name"];
    [dict setObject:((nil == self.tg_bgColor)?@"":self.tg_bgColor) forKey:@"bgColor"];
    [dict setObject:@(self.tg_type) forKey:@"type"];
    return dict;
}

- (NSString *)jsonObjec {
    // 将tag转化成json字符串保存在数据库中
    NSString *jsonTag = @"";
    NSDictionary *tagDic = [self dictionaryObjec];
    if ([tagDic isKindOfClass:[NSDictionary class]]) {
        NSError *error;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:tagDic options:0 error:&error];
        jsonTag = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    
    return jsonTag;
}

+ (NSArray <LRTSTagModel *>*)convertToTagsFromDataSource:(id)dataSource {
    NSMutableArray *resultArray = [NSMutableArray arrayWithCapacity:0];
    
    if ([dataSource isKindOfClass:[NSArray class]]) {
        NSArray *tagSources = (NSArray *)dataSource;
        for (NSDictionary *dic in tagSources) {
            LRTSTagModel *tag = [[LRTSTagModel alloc] initWithDict:dic];
            [resultArray addObject:tag];
        }
    }
    if (resultArray.count > 0) {
        return [resultArray copy];
    }else {
        return nil;
    }
    
}

+ (NSArray *)filterViewTagFromTags:(NSArray *)tags
                      showTagTypes:(NSArray *)tagTypes {
    
    NSMutableArray *fiterArray = [NSMutableArray array];
    [tags enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([tagTypes containsObject:@(((LRTSTagModel *)obj).tg_type)] ) {
            [fiterArray addObject:obj];
        }
    }];
    
    return fiterArray;
    
}

+ (LRTSTagModel *)filterViewTagFromTags:(NSArray *)tags
                  enableTagTypes:(NSArray *)tagTypes {
    LRTSTagModel *viewTag = nil;
    
    NSPredicate *filterPre = [NSPredicate predicateWithFormat:@"tg_type in %@",tagTypes];
    viewTag = [[tags filteredArrayUsingPredicate:filterPre] firstObject];
    
    if (nil == viewTag) {
        // 无轮如何返回一个空数据的tag，方便阅读那添加
        viewTag = [[LRTSTagModel alloc] init];
    }
    
    return viewTag;
}

+ (NSArray *)normalTags {
    return @[@(LMListenBarBoutiqueTag),
             @(LMListenBarAllCountdownTag),
             @(LMVIPListenBarBookStoreTag),
             @(LMVIPListenBarWholeAnticipateTag),
             @(LMListenBarMarketingTag)];
}

+ (NSArray *)boutiqueTags {
    return @[@(LMListenBarBoutiqueTag)];
}

+ (NSArray *)marketTags {
    return @[@(LMListenBarMarketingTag)];
}

+ (NSArray *)limitMarketTags {
    return @[@(LMListenBarAllCountdownTag),
             @(LMListenBarMarketingTag)];
}

+ (NSArray *)novipTags {
    return @[@(LMListenBarBoutiqueTag),
             @(LMListenBarAllCountdownTag),
             @(LMListenBarMarketingTag)];
}

+ (NSArray *)noboutiqueTags {
    return @[@(LMListenBarAllCountdownTag),
             @(LMVIPListenBarBookStoreTag),
             @(LMVIPListenBarWholeAnticipateTag),
             @(LMListenBarMarketingTag)];
}

+ (NSArray *)boutiqueVipTags {
    return @[@(LMListenBarBoutiqueTag),
             @(LMVIPListenBarBookStoreTag),
             @(LMVIPListenBarWholeAnticipateTag)];
}

+ (NSArray *)normalReadTags {
    return @[@(LMReadCountdownTag),
             @(LMReadRecommendSpecialTag),
             @(LMReadRecommendHotTag),
             @(LMReadRecommendPotentialTag),
             @(LMReadRecommendBigGodTag),
             @(LMReadMarketingTag)];
}

+ (NSArray *)marketReadTags {
    return @[@(LMReadMarketingTag)];
}

+ (NSArray *)noTimelimitReadTags {
    return @[@(LMReadRecommendSpecialTag),
             @(LMReadRecommendHotTag),
             @(LMReadRecommendPotentialTag),
             @(LMReadRecommendBigGodTag),
             @(LMReadMarketingTag)];
}

@end
