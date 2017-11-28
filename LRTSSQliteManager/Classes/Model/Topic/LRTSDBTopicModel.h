//
//  LRTSDBTopicModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"


@interface LRTSDBTopicModel : LRTSDBModel

@property (assign, nonatomic) NSInteger tId;    // 专题ID
@property (strong, nonatomic) NSString  *name;  // 专题名称
@property (strong, nonatomic) NSString  *desc;  // 专题简介
@property (strong, nonatomic) NSString  *cover; // 专题封面
@property (assign, nonatomic) NSInteger count;  // 该专题下的书籍列表数量
@property (assign, nonatomic) NSInteger type;   // 专题类型
@property (assign, nonatomic) NSInteger top;    // 是否是顶部显示
@property (strong, nonatomic) NSArray *booklistArray; //该专题下的书籍列表

@property (nonatomic, assign) NSInteger likeCount; //赞个数
@property (nonatomic, assign) NSInteger isLike;    //是否赞了

- (instancetype)initWithDict:(NSDictionary *)dict;

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(tId)
WCDB_PROPERTY( name)
WCDB_PROPERTY( desc)
WCDB_PROPERTY( cover)
WCDB_PROPERTY( count)
WCDB_PROPERTY( type)
WCDB_PROPERTY( top)
WCDB_PROPERTY( booklistArray)
WCDB_PROPERTY( likeCount)
WCDB_PROPERTY( isLike)



@end
