//
//  LRTSDBCollectionModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBCollectionModel.h"
#import "LRTSDBProgrammeModel.h"
#import "LRTSDBBookDetailModel.h"
#import "LRTSDBListenCollectionModel.h"


@interface LRTSDBCollectionModel (InitializationAndConfiguration)

- (LRTSDBProgrammeModel *)createProgrammeFromCollection;
- (LRTSDBBookDetailModel *)createBookDetailFromCollection;

+ (LRTSDBCollectionModel *)initCollectionWithProgramme:(LRTSDBProgrammeModel *)programme withListenCollection:(LRTSDBListenCollectionModel *)lc;
+ (LRTSDBListenCollectionModel *)initCollectionWithBookDetail:(LRTSDBBookDetailModel *)bookDetail withListenCollection:(LRTSDBListenCollectionModel *)lc;

+ (NSArray *)convertServerDataToCollectionsFromData:(id)data;

+ (NSString *)unionTitleWithEntityTitle:(NSString *)entityTitle entityDes:(NSString *)entityDes;
+ (NSString *)getEntityTitleWithUnionTitle:(NSString *)unionTitle;
+ (NSString *)getEntityDesWithUnionTittle:(NSString *)unionTitle;

+ (LRTSDBModel *)transformToEntityWithCollection:(LRTSDBCollectionModel *)collection;

@end
