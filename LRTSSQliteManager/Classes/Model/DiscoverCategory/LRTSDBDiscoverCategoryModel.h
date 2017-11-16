//
//  LRTSDBDiscoverCategoryModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

@interface LRTSDBDiscoverCategoryModel : LRTSDBModel

@end

@interface LMDiscoveryCategoryGroup : LRTSDBModel

@property (nonatomic, strong) NSArray *categories;

@end

@interface LMDiscoveryCategoryGroup (JsonParse)
+ (instancetype)dataModelWithDict:(NSDictionary *)dict;
@end
