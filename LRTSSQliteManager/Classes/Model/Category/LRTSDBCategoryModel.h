//
//  LRTSDBCategoryModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSBaseCategoryModel.h"


typedef NS_ENUM(NSUInteger, LMCategoryLevel) {
    LMCategoryLevelTop, // 一级分类
    LMCategoryLevelSub, // 二级分类
};

//TODO  注册掉
@interface LRTSDBCategoryModel : LRTSDBModel

@property (assign, nonatomic) NSInteger cId;        // 分类ID
@property (strong, nonatomic) NSString  *cDesc;     // 分类描述
@property (assign, nonatomic) NSInteger cType;      // 标签版本改为PublishType使用
@property (assign, nonatomic) LMCategoryLevel level; // 分类的层级

+ (instancetype)categoryWithDic:(NSDictionary *)dic;

/**
 *  获取书籍封面的本地存储
 *  @param type 图片的规格  0为默认大小，1为_118x162, 2为_338x170规格的图片 3为_720x238规格的图片 *
 *  @return 图片的本地存储路径
 */
- (NSString *)getCategoryCoverLocalStorePath:(NSInteger)type;


#pragma mark - WVDB 数据绑定

//WCDB_PROPERTY(cId)
//WCDB_PROPERTY(cover)
//WCDB_PROPERTY(name)
//WCDB_PROPERTY(desc)
//WCDB_PROPERTY(openUrl)
//WCDB_PROPERTY(alert)
//WCDB_PROPERTY(publishType)
//WCDB_PROPERTY(entityName)

@end


// 书籍分类
@interface LRTSBKCategory : LRTSDBCategoryModel
@end

// 节目分类
@interface LRTSRadioCategory : LRTSDBCategoryModel

@property (strong, nonatomic) NSString *cDefaultCover; //默认的cover
+ (NSArray *)getRadioCategoryListWithDatasource:(id)dataSource;

@end

// 付费分类
@interface LRTSChargeCategory : LRTSDBCategoryModel
@end

#pragma mark - category

@interface LRTSDBCategoryModel (EntityConvert)

+ (LRTSDBEntityModel *)convertToEntityWithCategory:(LRTSBaseCategoryModel *)category;
+ (LRTSBaseCategoryModel *)convertToCategoryWithEntity:(LRTSDBEntityModel *)entity;


@end
