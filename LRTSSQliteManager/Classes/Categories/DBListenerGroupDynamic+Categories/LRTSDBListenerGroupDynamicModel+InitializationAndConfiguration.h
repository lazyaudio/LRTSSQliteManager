//
//  LRTSDBListenerGroupDynamicModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBListenerGroupDynamicModel.h"

@interface LRTSDBListenerGroupDynamicModel (InitializationAndConfiguration)

+ (instancetype)listenerGroupDynamicWithDict:(NSDictionary *)dict andShowRepublish:(BOOL)showRepublishBtn;

/**
 *  检测链接
 */
- (void)checkLink;

- (BOOL)isTrueOfStateType:(LMUserStateType)type;

@end
