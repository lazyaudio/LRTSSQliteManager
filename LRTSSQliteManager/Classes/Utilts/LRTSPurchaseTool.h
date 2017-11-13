//
//  LRTSPurchaseTool.h
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import <Foundation/Foundation.h>

@interface LRTSPurchaseTool : NSObject

//合辑类型
typedef NS_ENUM(NSUInteger, LMAlbumType) {
    LMAlbumTypeListen,  //听书合辑
    LMAlbumTypeRead     //阅读合辑
};

typedef NS_ENUM(NSUInteger, LMPriceModelPayType) {
    LMPriceModelPayTypeFree,      //免费
    LMPriceModelPayTypeBook,      //整本购买
    LMPriceModelPayTypeSection,   //按章购买
    LMPriceModelPayTypeSubscribe, //订阅购买
    LMPriceModelPayTypeWord,      //千字购买
    LMPriceModelPayTypeAlbum      //合辑购买
};

typedef NS_ENUM(NSUInteger, LMChoosePriceType) {
    LMChoosePriceTypeOriginal,  //原价购买
    LMChoosePriceTypeDiscount,  //单价折扣购买
    LMChoosePriceTypeVIP,       //会员折扣购买
    LMChoosePriceTypeDiscountAndVIP,  //会员和单价折扣购买
    LMChoosePriceTypeVIPOnly    //VIP单价购买(用于合辑)
};

@end
