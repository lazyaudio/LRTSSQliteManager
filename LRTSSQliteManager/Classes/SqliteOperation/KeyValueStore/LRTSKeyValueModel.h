//
//  LRTSKeyValueModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/21.
//

#import <Foundation/Foundation.h>

@interface LRTSKeyValueModel : NSObject

@property (strong, nonatomic) NSString *itemKey;
@property (strong, nonatomic) NSObject *itemValue;
@property (strong, nonatomic) NSDate *createTime;

@end
