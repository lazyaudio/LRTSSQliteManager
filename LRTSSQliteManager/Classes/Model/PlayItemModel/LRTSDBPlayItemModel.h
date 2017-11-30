//
//  LRTSDBPlayItemModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDBAudioTrackDelegate.h"

@interface LRTSDBPlayItemModel : LRTSDBModel <LRTSDBAudioTrackDelegate>

@property (nonatomic, assign) NSInteger      pId;
@property (nonatomic, copy  ) NSString       *pName;
@property (nonatomic, copy  ) NSString       *pUrl;
@property (nonatomic, strong) NSString       *coverUrl;
@property (nonatomic, assign) NSInteger      section;// 第几集
@property (nonatomic, assign) LRTSEntityType     entityType;// 实体类型
@property (nonatomic, assign) NSInteger      haslyric;// 是否有歌词
@property (nonatomic, assign) NSTimeInterval currentTime;// 当前播放位置
@property (nonatomic, assign) NSTimeInterval duration;// 总时长
@property (nonatomic, assign) LRTSEnterPlayType  enterType;// 播放入口是下载列表还是在线列表
@property (nonatomic, assign) NSTimeInterval playSeconds;// 有效播放时长
@property (nonatomic, copy  ) NSString       *freeUrl;//免流播放地址

@property (nonatomic, assign) BOOL isRequestedCoverUrl;  //记录是否请求过封面地址

//当前有效的url,section或audio有url,则取它们的url,没有取book或album的url
@property (nonatomic, copy, readonly) NSString *validCoverUrl;

@end
