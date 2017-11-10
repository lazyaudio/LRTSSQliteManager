//
//  LRTSDBProgrammeAudioModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBProgrammeAudioModel.h"
#import "LRTSDBPlayableDelegate.h"
#import "LRTSDBDownloadableDelegate.h"
#import "LRTSDBAudioSubEntityDelegate.h"


@interface LRTSDBProgrammeAudioModel (InitializationAndConfiguration)<LRTSDBPlayableDelegate, LRTSDBDownloadableDelegate, LRTSDBAudioSubEntityDelegate>

+ (instancetype)modelWithDict:(NSDictionary *)dict;

@end
