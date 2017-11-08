//
//  LRTSDBBookDetailModel+LinkAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBBookDetailModel.h"

@interface LRTSDBBookDetailModel (LinkAndConfiguration)

- (id)initWithBook:(LRTSDBBookModel *)book;

- (void)checkLink;

- (NSString *)saveDesc;

+ (NSArray<LRTSDBBookDetailModel *> *)bookListForListDict:(NSArray *)listDict;

@end
