//
//  LRTSBaseCategoryModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/16.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"


@interface LRTSBaseCategoryModel : LRTSDBModel

@property (assign, nonatomic) NSInteger pt;                             // publishType
@property (strong, nonatomic) NSString  *url;                           // 根据不同的pt，保存不同的数据，可能为url或id
@property (strong, nonatomic) NSString  *cName;                         // 分类标题
@property (strong, nonatomic) NSString  *cCover;                        // 分类封面
//@property (assign, nonatomic) NSInteger size;                           // 展开的个数
@property (nonatomic, strong) NSArray<LRTSBaseCategoryModel *> *subCategory;   //子分类，如果是末端分类，则为空
@property (nonatomic, assign) NSInteger redPoint;                            // 是否显示小红点 1 显示  2不显示
@property (nonatomic, assign) BOOL isMore;  //是否显示更多按钮
// 根据字典创建模型
- (instancetype)initWithDict:(NSDictionary *)dict;
// 根据json返回json数组
+ (NSArray *)categoriesWithJsonArray:(id)jsonArray;

- (NSString *)lmCategoryTagCell_name;

- (NSString *)lmCategoryTagCell_cover;

- (NSString *)lmCTagSubCellProtocol_name;

@end
