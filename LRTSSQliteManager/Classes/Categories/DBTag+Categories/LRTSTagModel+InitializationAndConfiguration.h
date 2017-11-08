//
//  LRTSTagModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSTagModel.h"

@interface LRTSTagModel (InitializationAndConfiguration)

// 将服务器请求回来的数据转化为LMTag类型数组
+ (NSArray <LRTSTagModel *>*)convertToTagsFromDataSource:(id)dataSource;

// 从json字符串中初始化tag
+ (instancetype)tagFromJson:(NSString *)jsonTag;

// 根据字段初始化tag
- (instancetype )initWithDict:(NSDictionary *)dic;

// 获取tag对象的字典
- (NSDictionary *)dictionaryObjec;

// 将tag转化成json字符串
- (NSString *)jsonObjec;

/**
 返回需要展示的要点标签数组
 
 @param tags tags数组
 @param tagTypes 要展示的数组
 @return 返回匹配的数组
 */
+ (NSArray *)filterViewTagFromTags:(NSArray *)tags
                      showTagTypes:(NSArray *)tagTypes;

/**
 根据服务器返回的tag数组，过滤出最终界面需要显示的tag
 *
 * param: tags 服务器返回的tag数组
 * param: tagTypes 可以显示的tag（数组元素为tag的type，由界面自己决定要显示哪些类型的tag）
 *
 * return: 返回过滤后的tag，如果为空则不显示tag
 */
+ (LRTSTagModel *)filterViewTagFromTags:(NSArray *)tags
                  enableTagTypes:(NSArray *)tagTypes;

// 获取页面可展示的标签数组
+ (NSArray *)normalTags;
+ (NSArray *)boutiqueTags;
+ (NSArray *)marketTags;
+ (NSArray *)limitMarketTags;
+ (NSArray *)novipTags;
+ (NSArray *)noboutiqueTags;
+ (NSArray *)boutiqueVipTags;

+ (NSArray *)normalReadTags;
+ (NSArray *)marketReadTags;
+ (NSArray *)noTimelimitReadTags;

@end
