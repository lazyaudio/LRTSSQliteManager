//
//  LRTSViewController.m
//  LRTSSQliteManager
//
//  Created by boilwater on 10/30/2017.
//  Copyright (c) 2017 boilwater. All rights reserved.
//

#import "LRTSViewController.h"
#import "BookDetail.h"
#import "BookDetail+WCTTableCoding.h"
#import "LRTSOperation.h"

#import "LRTSDBBookModel.h"

@interface LRTSViewController (){
    Class _cls;
}

@end

@implementation LRTSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
//    [self initSQLWithWCDB];
    
    LRTSDBBookModel *bookModel = [[LRTSDBBookModel alloc] init];
    bookModel.bId = 1;
//    bookModel.cover = @"www.baidu.com";
    LRTSOperation *operation = [[LRTSOperation alloc] initWithModel:bookModel];
    BOOL ret = [bookModel saved];
    NSArray *array = nil;
//    [bookModel saveModels:array];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
//    UITableView
}

- (void)initSQLWithWCDB {

//    BookDetail *bookDetail = [[BookDetail alloc] init];
//
//    bookDetail.bookID = 1;
//    bookDetail.pubilsher = @"中国出版社";
//    bookDetail.bookName = @"菲悦科技传";
//
//    NSString *className = NSStringFromClass(BookDetail.class);
//    NSString *path = [NSTemporaryDirectory() stringByAppendingPathComponent:className];
//
    LRTSDBBookModel *bookModel = [[LRTSDBBookModel alloc] init];
    bookModel.bId = 1;
    bookModel.commentCount = 3;
    NSString *className = NSStringFromClass(LRTSDBBookModel.class);
    NSString *path = [NSTemporaryDirectory() stringByAppendingPathComponent:className];
    
    NSString *tableName = className;
    WCTDatabase *wcdb = [[WCTDatabase alloc] initWithPath:path];
    
    _cls = LRTSDBBookModel.class;
    
    BOOL ret = [wcdb createTableAndIndexesOfName:tableName withClass:_cls];

    
//    LRTSOperation *operation = [[LRTSOperation alloc] initWithModel:bookDetail];

    
//    BOOL ret = [operation insertObject:bookDetail into:@"name"];

//    NSArray *book = [operation getAllObjectsOfClass:BookDetail.class forTable:@"name"];
    
    
}

//LMBaseModel:NSObject

/*在此 Model 的属性为 nil, 基本的枚举类型中有相关参数
 *
 * EntityType 包含书籍信息：声音、专辑、书籍、动态等
 * EnterPlayType 音频文件播放状态：在线播放、下载后播放
 * StrategyType 书籍状态要求：会员限免、整本购买、整本抢先、章节抢先和全部限免
 */


//LMBook:LMBaseModel

/*书籍的节本
 *
 *书籍 ID、书籍人气、书籍章节、书籍状态（1-连载，2-全集）、展示方式（正序和倒序）、评论总数、是否和收藏
 * 名称、作者、播音、封面、更新时间、关联书籍 ID、分类名称、父分类 ID最、分类 ID、收藏记录 ID
 * 最后更新时间、记录状态、赞👍、播音实体类型、额外信息、付款类型、VIP 策略、限免时间、是否超过限免时间
 * 更新状态
 *
 * 书籍初始化
 */

//LMBookDetail:LMBook

/*书籍的相关细节
 *
 *时长、下载次数、书籍是否下载、简介描述、评论数目、收听价格、下载价格、多主播、是否打赏、富文本
 * 价格信息、书本版本、标签系统、标签、分类（用于在播放器广告和详情文字广告）
 * 是否有链接、链接范围、链接地址、链接描述、资源上架时间、资源所挂的标签、用户最新关注时间标签
 *
 * 初始化书籍
 * 检查是否有标签链接
 *
 * 类目：获取书籍的相关详细信息
 */

//对数据进行操作的 model 类型
//
//（1）LMBookDetail 获取数据基本类型、付费类型、删除书籍、书籍限时免费、保存书籍详细、更新评论
//    更新实体评论数字、存储收藏书籍、查找书籍、检查数据列表书籍更新，更新书籍更新状态、查询书籍详细
//    更新数目收藏状态
//
//（2）LMSection 通过数据页码获取数据、获取具体书本的章节、检查对应章节保存、储存相关章节、获取数据中存储的 ID、删除系列（）、更新购买书籍的章节、更新购买章节，指定具体章节付费类型，更新正本书籍的购买状态
//
//（3）LMDownloadItem 查询下载状态、
//
//（4）LMUser 获取书籍下载状态、更新书籍最后下载时间、是章节列表失败、查询章节更新时间、查询数据
//
//（5）消息中心 私信列表 增删改查
//
//（6）消息中心 私信详情
//
//（7）消息中心 评论通知
//
//（8）消息中心 通知信息
//
//（9）LMProgramme LMProgrammeAudio 节目相关
//
//（10） 节目资源列表
//
//（11）LMAnnouncer 主播列表
//
//（12）关注/取消
//
//（13）LMPlayHistory 收听记录
//
//（14）LMCollection 收藏记录
//
//（15）LMProgramme 节目列表
//
//（16）新的下载列表操作方法
//
//（17）赞
//
//（18）LMAudio 录音列表相关
//
//（19）LMListenerGroupDynamic 带图片的帖子
//


// （1）model 中 包含属性 model 来进行连表的数据修改
//

// （2）数据库升级过程中版本的数据字段修改
//解决方案：在实现数据库升级过程中增加相应的字段，只需在相关的属性列表中对属性字段进行相关修改就可以完成数据库字段修改过程。但是 SQLite 不支持对数据字段的删除，所以在字段修改过程中可以对相关字段进行忽略即可。
//

// （3）model 中数据根据字段的链表查询
//

// （4）具体 model 的具体操作
//
// （5）数据的事务同意过程的处理
//
// （6）数据库安全的处理反注入
//
// （7）数据库加密
//
//
//
//
//
//
//

@end
