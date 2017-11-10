//
//  LRTSDBCategoryModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>

@interface LRTSDBCategoryModel : LRTSDBModel

@property (nonatomic, assign) NSInteger cId;
@property (nonatomic, strong) NSString *cover;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSString *openUrl;
@property (nonatomic, assign) NSInteger alert;
@property (nonatomic, assign) NSInteger publishType;
@property (nonatomic, strong) NSString *entityName;

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(cId)
WCDB_PROPERTY(cover)
WCDB_PROPERTY(name)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(openUrl)
WCDB_PROPERTY(alert)
WCDB_PROPERTY(publishType)
WCDB_PROPERTY(entityName)



@end
