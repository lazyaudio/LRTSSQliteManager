//
//  LRTSDBListenerDiscountModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"

typedef NS_ENUM(NSInteger, LRTSDBListenerDiscountType) {
    LRTSDBListenerDiscountTypeNone,
    LRTSDBListenerDiscountTypeVIP,
};

@interface LRTSDBListenerDiscountModel : LRTSDBModel

@property (nonatomic, assign) NSInteger discountId;

@property (nonatomic, assign) LRTSDBListenerDiscountType discountType;

@property (nonatomic, copy) NSString *discountName;

@property (nonatomic, copy) NSString *discountValue;

@end
