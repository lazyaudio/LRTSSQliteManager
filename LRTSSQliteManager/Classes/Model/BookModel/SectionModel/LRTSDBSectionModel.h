//
//  LRTSDBSection.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDownloadState.h"

@interface LRTSDBSectionModel : LRTSDBModel

@property (nonatomic) NSInteger sId;                  // 书籍资源在数据库中的编号
@property (nonatomic) NSInteger sBookId;        // 该本书籍的id

@property (nonatomic) NSInteger section;              // 书籍资源对应的章节编号
@property (nonatomic) NSInteger length;               // 时长
@property (nonatomic) NSInteger size;                 // 资源文件大小

@property (strong, nonatomic) NSString *name;    // 书籍资源名称
@property (strong, nonatomic) NSString *path;    // 服务器资源路径
@property (strong, nonatomic) NSString *localPath;//本地资源路径

@property (assign, nonatomic) NSInteger downloadPrice;//下载价格
@property (assign, nonatomic) NSInteger listenPrice;//收听价格
@property (assign, nonatomic) NSInteger haslyric;//是否含有文本
@property (assign, nonatomic) NSInteger pageNumber;//章节所在的页码

@property (assign, nonatomic) NSInteger hasBuy;// 0未购 1已购
@property (assign, nonatomic) NSInteger payType;// 0免费 1整本购买 2分章购买

@property (assign, nonatomic) NSTimeInterval playTime; //播放进度

//章节详情
@property (strong,nonatomic) NSString *announcer;//播音员
@property (strong,nonatomic) NSString *desc;    //简介、描述
@property (strong,nonatomic) NSString *text;    //对应文本(类似于歌词)

@property (assign, nonatomic) DownloadStatus downloadStatus;  // 下载状态
@property (assign, nonatomic) CGFloat downloadProgress; // 下载进度

@property (nonatomic,assign) NSInteger  strategy; // 1 VIP限时免费 2 VIP限时免费（会员书库） 3 VIP整本抢先听 4 VIP章节抢先听 5 全部限免

@end
