//
//  LRTSSystemNotice.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSMessageState.h"


@interface LRTSSystemNotice : LRTSDBModel

@property (assign, nonatomic) NSInteger      msgId;
@property (assign, nonatomic) NSInteger      userId;
@property (copy,   nonatomic) NSString       *userNickName;
@property (copy,   nonatomic) NSString       *userCover;
@property (assign, nonatomic) NSInteger      userState;
@property (assign, nonatomic) NSTimeInterval createTime;
@property (copy,   nonatomic) NSString       *content;
@property (assign, nonatomic) LRTSMessageState      readState;
@property (strong, nonatomic) NSString       *title;

@property (assign, nonatomic) EntityPublishType pulishType;
@property (strong, nonatomic) NSString       *linkUrl;
@property (strong, nonatomic) NSString       *urlParam;
@property (strong, nonatomic) NSString       *pvUrl;
@property (strong, nonatomic) NSString       *pvParam;
@property (strong, nonatomic) NSString       *cover;

@property (strong, nonatomic) NSString       *showTitle;    //跳转至页面显示的标题

@property (assign, nonatomic) CGFloat cellRowHeight;
@property (strong, nonatomic) NSString      *dateStr;

@end
