//
//  LRTSDBListenerBuyModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSPurchaseTool.h"

typedef NS_OPTIONS(NSUInteger, LRTSAudioPayItemAction) {
    LRTSAudioPayItemActionPay  = 1 << 0,           //支付
    LRTSAudioPayItemActionChooseCount  = 1 << 1,   //选择章节数目
};

@interface LRTSDBListenerBuyModel : LRTSDBModel

@property (nonatomic, assign) NSInteger coinCount;

@property (nonatomic, assign) NSInteger viceCoinCount;

@property (nonatomic, assign) LRTSPriceModelPayType buyType;

@property (nonatomic, assign) LRTSAudioPayItemAction action;// 用来区分是否弹出自定义框

@property (nonatomic, strong) NSString *title; //注释

@property (nonatomic, strong) NSArray *sectionIndexs; //整本购买,sectionIndexs为空

@end
