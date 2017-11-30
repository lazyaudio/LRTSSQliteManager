//
//  LRTSPurchaseTool.h
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import <Foundation/Foundation.h>

//LRTSAlbumType
//LRTSPriceModelPayType
//LRTSChoosePriceType

//合辑类型
typedef NS_ENUM(NSUInteger, LRTSAlbumType) {
    LRTSAlbumTypeListen,  //听书合辑
    LRTSAlbumTypeRead     //阅读合辑
};

typedef NS_ENUM(NSUInteger, LRTSPriceModelPayType) {
    LRTSPriceModelPayTypeFree,      //免费
    LRTSPriceModelPayTypeBook,      //整本购买
    LRTSPriceModelPayTypeSection,   //按章购买
    LRTSPriceModelPayTypeSubscribe, //订阅购买
    LRTSPriceModelPayTypeWord,      //千字购买
    LRTSPriceModelPayTypeAlbum      //合辑购买
};

typedef NS_ENUM(NSUInteger, LRTSChoosePriceType) {
    LRTSChoosePriceTypeOriginal,  //原价购买
    LRTSChoosePriceTypeDiscount,  //单价折扣购买
    LRTSChoosePriceTypeVIP,       //会员折扣购买
    LRTSChoosePriceTypeDiscountAndVIP,  //会员和单价折扣购买
    LRTSChoosePriceTypeVIPOnly    //VIP单价购买(用于合辑)
};

@interface LRTSPurchaseTool : NSObject

+ (NSArray *)indexsWithSectionStr:(NSString *)string;

+ (NSString *)sectionStrWithIndexs:(NSArray *)indexs;

+ (NSArray *)combineIndexs:(NSArray *)aIndexs
                withIndexs:(NSArray *)bIndexs;

+ (NSArray *)unintersectionIndexs:(NSArray *)indexs
                       IndexCount:(NSInteger)count;

+ (NSString *)stringOfPrice:(double)price;

@end
