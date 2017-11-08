//
//  LRTSDBSectionModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBSectionModel.h"
#import "LRTSDBPlayableDelegate.h"
#import "LRTSDBDownloadableDelegate.h"
#import "LRTSDBAudioSubEntityDelegate.h"

@interface LRTSDBSectionModel (InitializationAndConfiguration)<LRTSDBAudioSubEntityDelegate, LRTSDBDownloadableDelegate, LRTSDBPlayableDelegate>

-(id)initWithDict:(NSDictionary *)data;
-(BOOL)isEqualToLMSection:(LRTSDBSectionModel *)ls;

@end
