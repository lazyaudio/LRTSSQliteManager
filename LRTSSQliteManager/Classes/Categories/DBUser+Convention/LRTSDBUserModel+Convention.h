//
//  LRTSDBUserModel+Convention.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBUserModel.h"

@interface LRTSDBUserModel (Convention)

// 听读券转换成懒人币
- (double)ticketConvertToCoin;

// 听读券转成人民币（单位元）
- (double)ticketConvertToRMB;

// 是否绑定手机号
- (BOOL)isBindPhone;

@end
