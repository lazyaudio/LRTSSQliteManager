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

@end
