//
//  LRTSSystemNotice.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBModel.h"
#import "LRTSDBMessageState.h"
#import "LRTSDBPublicTypeDefine.h"
#import <WCDB/WCDB.h>


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

@property (assign, nonatomic) LRTSEntityPublishType pulishType;
@property (strong, nonatomic) NSString       *linkUrl;
@property (strong, nonatomic) NSString       *urlParam;
@property (strong, nonatomic) NSString       *pvUrl;
@property (strong, nonatomic) NSString       *pvParam;
@property (strong, nonatomic) NSString       *cover;

@property (strong, nonatomic) NSString       *showTitle;    //跳转至页面显示的标题

@property (assign, nonatomic) CGFloat cellRowHeight;
@property (strong, nonatomic) NSString      *dateStr;

#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(msgId)
WCDB_PROPERTY(userId)
WCDB_PROPERTY(userNickName)
WCDB_PROPERTY(userCover)
WCDB_PROPERTY(userState)
WCDB_PROPERTY(createTime)
WCDB_PROPERTY(content)
WCDB_PROPERTY(readState)
WCDB_PROPERTY(title)

WCDB_PROPERTY(pulishType)
WCDB_PROPERTY(linkUrl)
WCDB_PROPERTY(urlParam)
WCDB_PROPERTY(pvUrl)
WCDB_PROPERTY(pvParam)
WCDB_PROPERTY(cover)

WCDB_PROPERTY(showTitle)

WCDB_PROPERTY(cellRowHeight)
WCDB_PROPERTY(dateStr)

@end
