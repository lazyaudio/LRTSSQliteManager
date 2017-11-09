//
//  LRTSDBProgrammeModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBProgrammeModel.h"

@interface LRTSDBProgrammeModel (InitializationAndConfiguration)

- (void)combineProgramme:(LRTSDBProgrammeModel *)programme;

+ (NSArray<LRTSDBProgrammeModel *> *)programListWithListDict:(NSArray *)listDict;

@end
