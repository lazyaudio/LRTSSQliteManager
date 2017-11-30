//
//  LRTSDBListenerPriceModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBListenerDiscountModel.h"
#import "LRTSPurchaseTool.h"
#import "LRTSDBModel.h"

@interface LRTSDBListenerPriceModel : LRTSDBModel

@property (nonatomic, assign) LRTSEntityType            entityType;

@property (nonatomic, assign) long                  entityId;

@property (nonatomic, assign) NSInteger             sectionCount;       //章节总数
@property (nonatomic, assign) NSInteger         estimatedSectionCount;  //预计章节数

@property (nonatomic, assign) NSInteger             canUseTicket;  //可用听读卷
@property (nonatomic, assign) LRTSChoosePriceType     choosePriceType;

@property (nonatomic, assign) LRTSPriceModelPayType             payType;

//单位:厘
@property (nonatomic, assign) NSInteger             price;

//单位:厘
@property (nonatomic, assign) NSInteger             discountPrice;

@property (nonatomic, assign) NSTimeInterval        deadlineTime;

@property (nonatomic, copy  ) NSString              *freeSectionsStr;

@property (nonatomic, copy  ) NSString              *buySectionsStr;

@property (nonatomic, copy  ) NSString              *allSectionsStr;  //节目专用

@property (nonatomic, strong) NSArray<LRTSDBListenerDiscountModel *> *discounts;

@property (nonatomic, copy)   NSString              *discountStr;

//方便使用设置的属性
@property (nonatomic, strong) NSArray               *freeSectionIndexs;  //节目是ids

@property (nonatomic, strong) NSArray               *buySectionIndexs;   //节目是ids

@property (nonatomic, strong) NSArray               *unbuySectionIndexs; //节目是ids

@property (nonatomic, copy) NSString *priceJSONStr;

@end
