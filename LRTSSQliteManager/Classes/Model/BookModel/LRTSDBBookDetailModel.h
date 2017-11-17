//
//  LRTSDBBookDetailModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBListenerPriceModel.h"
#import "LRTSDBBookModel.h"

#define kSeparateMark @"#???*&" // 一个特殊的字符串，用于分割正文和附加信息

@interface LRTSDBBookDetailModel : LRTSDBBookModel

@property (nonatomic,assign) NSInteger length;          // 时长（单位分钟？？）
@property (nonatomic,assign) NSInteger download;        // 下载次数(为0 ,作废数据)
@property (nonatomic,assign) NSInteger cantDown;        // 控制书籍是否可以下载（0：可以，1：不可以）
@property (nonatomic,assign) NSInteger marked;          //　０：未收藏　１：已收藏

@property (nonatomic,strong) NSString  *desc;          // 简介、描述

@property (strong,nonatomic ) NSString  *commentMean;   // 评论平均数

@property (assign, nonatomic) NSInteger listenPrice;    //收听价格
@property (assign, nonatomic) NSInteger downloadPrice;  //下载价格

@property (nonatomic, strong) NSArray *announcerIds;    //多主播

@property (nonatomic, assign) NSUInteger bookReward;    // 是否打赏书籍（0:不是 1:是）

// 详情看 http://apidoc.lrts.me/00%E9%80%9A%E7%94%A8/%E4%B9%A6%E7%B1%8D%E4%BC%98%E6%83%A0%E7%AD%96%E7%95%A5/

@property (nonatomic, copy) NSArray *extraInfos; // 附加信息(v6.0.6), 富文本

@property (nonatomic, strong) LRTSDBListenerPriceModel *bookPrice;  // 价格信息

// 新增版本号
@property (nonatomic, copy) NSString *bookVersion;

@property (nonatomic, strong) NSArray *sysLabels; //标签系统,该书籍所属标签

@property (nonatomic, copy) NSArray *tags; // 活动标签和要点标签

@property (nonatomic,assign) NSInteger typeId; //分类id(Version6.1.4),用于播放器文字广告和详情文字广告

#pragma mark - Link

/**
 *  是否有链接
 */
@property (nonatomic, assign) BOOL haveLink;

/**
 *  链接字符串的范围
 */
@property (nonatomic, strong) NSArray *linkRanges;

/**
 *  链接的地址
 */
@property (nonatomic, strong) NSArray *linkAddresses;

/**
 *  带有链接的描述
 */
@property (nonatomic, strong) NSString *descWithLink;

/** 标签版本(v3.1.5)添加 */
@property (nonatomic, assign) NSTimeInterval createTime; ///< 资源上架时间
@property (nonatomic, copy) NSString *latestFollowLabel; ///< 资源所挂的标签中，用户最新关注的那个标签的名称
@property (nonatomic, assign) NSTimeInterval latestFollowLabelTime; ///< 资源所挂的标签中，用户最新关注的那个标签的时间

//TODO Temp paramter 
@property (nonatomic, assign) NSInteger bookID;

@end
