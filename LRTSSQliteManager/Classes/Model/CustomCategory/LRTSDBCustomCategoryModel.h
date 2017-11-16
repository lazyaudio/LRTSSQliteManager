//
//  LRTSDBCustomCategoryModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"


@interface LRTSDBCustomCategoryModel : LRTSDBModel

/**
 "类型1:用户置顶,2:后台编辑(排行榜数据列表时会用到)
 ccType=1调用ClientGetBookList.action接口传递参数sortType.
 ccType=2调用/bookclient/ClientGetBookByTopic.action接口传递参数topicId"
 */
@property (assign, nonatomic) NSInteger ccType;

/**
 在推荐列表中：
 当ccType为1时该字段为0,当ccType=2时该字段会当做参数传递给新接口
 排序方式.当ccType为2时该字段为0,当ccType=1该字段会当做参数传递给新接口
 
 在专题列表中：
 　表示是否重点推荐（1:重点推荐 0:不是重点推荐）
 */
@property (assign, nonatomic) NSInteger ccOther;
@property (assign, nonatomic) NSInteger cFId;       // 分类父id
@property (strong, nonatomic) NSString *desc;       // 专题详细信息(简介)
@property (strong, nonatomic) NSString *insideCover;// 内部精品封面
@property (assign, nonatomic) NSTimeInterval lastUpdateTime;

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(ccType)
WCDB_PROPERTY(ccOther)
WCDB_PROPERTY(cFId)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(insideCover)
WCDB_PROPERTY(lastUpdateTime)



@end
