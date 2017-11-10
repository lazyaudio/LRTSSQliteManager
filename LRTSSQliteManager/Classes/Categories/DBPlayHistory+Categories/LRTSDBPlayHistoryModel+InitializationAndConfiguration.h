//
//  LRTSDBPlayHistoryModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBPlayHistoryModel.h"
#import "LRTSDBProgrammeModel.h"
#import "LRTSDBProgrammeAudioModel.h"
#import "LRTSDBBookDetailModel.h"
#import "LRTSDBSectionModel.h"

typedef void(^LRTSDBPlayHistoryBlock)(id entity,id audio);

@interface LRTSDBPlayHistoryModel (InitializationAndConfiguration)

- (void)getProgrammeFromHistory:(LRTSDBPlayHistoryBlock)historyResult;
- (void)getBookDetailFromHistory:(LRTSDBPlayHistoryBlock)historyResult;

+ (LRTSDBPlayHistoryModel *)getHistoryWithProgramme:(LRTSDBProgrammeModel *)programme audio:(LRTSDBProgrammeAudioModel *)audio;

+ (LRTSDBPlayHistoryModel *)getHistoryWithBookdetail:(LRTSDBBookDetailModel *)bookDetail section:(LRTSDBSectionModel *)section;

+ (void)transformWithPlayHistory:(LRTSDBPlayHistoryModel *)playHistory toPlayEntity:(LRTSDBPlayHistoryBlock)entityBlock;

@end
