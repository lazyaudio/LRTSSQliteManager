//
//  LRTSDBLabelResourceModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDBPublicTypeDefine.h"
#import <WCDB/WCDB.h>

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
@property (nonatomic, assign) LRTSEntityPublishType entityType; ///< 0书籍，2节目

- (instancetype)initWithDict:(NSDictionary *)dict;


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(name)
WCDB_PROPERTY(cover)
WCDB_PROPERTY(resourceId)
WCDB_PROPERTY(playCount)
WCDB_PROPERTY(anncouncer)
WCDB_PROPERTY(author)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(state)
WCDB_PROPERTY(tags)
WCDB_PROPERTY(entityType)



@end
