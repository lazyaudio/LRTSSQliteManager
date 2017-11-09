//
//  LRTSDBLabelResourceModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>

@interface LRTSDBLabelResourceModel : LRTSDBModel

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *cover;
@property (nonatomic, assign) long long resourceId;
@property (nonatomic, assign) long long playCount;
@property (nonatomic, copy) NSString *anncouncer;
@property (nonatomic, copy) NSString *author;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, assign) NSInteger state; ///< 状态。1-连载中，2-全集
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, assign) EntityPublishType entityType; ///< 0书籍，2节目

- (instancetype)initWithDict:(NSDictionary *)dict;

@end
