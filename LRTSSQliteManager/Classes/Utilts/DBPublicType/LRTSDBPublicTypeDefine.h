//
//  LRTSDBPublicTypeDefine.h
//  Pods
//
//  Created by JackJin on 2017/11/9.
//

#ifndef LRTSDBPublicTypeDefine_h
#define LRTSDBPublicTypeDefine_h

typedef NS_ENUM(NSInteger,EntityPublishType) {
    EntityPublishTypeNone                = -1,// 没有跳转动作
    // 与服务器约定的跳转
    EntityPublishBookDetail          = 0,// 书籍详情
    EntityPublishInnerActivity       = 1,// 内部活动
    EntityPublishProgramDetail       = 2,// 节目详情
    EntityPublishTopicDetail         = 3,// 专题详情
    EntityPublishAnnouncerHome       = 4,// 主播首页
    EntityPublishBookSubCategory     = 5,// 书籍分类（二级分类）
    EntityPublishAnnouncerRadio      = 6,// 主播电台
    EntityPublishOuterAds            = 7,// 外部广告
    EntityPublishBookTopCategory     = 8,// 书籍分类（一级分类）
    EntityPublishListenGroupHome     = 9,// 听友会详情
    EntityPublishGameCenter          = 10,// 游戏中心
    EntityPublishGameDetail          = 11,// 游戏详情
    EntityPublishUnHyperLinkAds      = 12,// 无连接广告
    EntityPublishListenFolderDetail  = 13,// 听单详情
    EntityPublishProgramCategoryList = 14,// 节目分类列表
    EntityPublishTopicList           = 15,// 专题列表
    EntityPublishAnnouncerList       = 16,// 主播列表
    EntityPublishListenGroupList     = 17,// 听友会列表
    EntityPublishListenFolderList    = 18,// 听单列表
    EntityPublishReadDetail          = 19,// 阅读书籍详情
    EntityPublishBookSigleCategory   = 20,// 书籍独立分类，没有二级分类的一级分类(听书)
    EntityPublishTypeReadHome        = 21,// 阅读书城首页
    EntityPublishTypeReadCategory    = 22,// 阅读二级分类
    EntityPublishTypeReadShelf       = 23,// 阅读书架
    EntityPublishTypeHotChannel      = 24,// 热门频道（不能跳转）
    EntityPublishTypeCopyrightZone   = 25,// 版权专区
    EntityPublishTypeCopyright       = 26,// 版权机构，版权专区下的一个具体的版权机构
    EntityPublishTypeVIPMember       = 27,// VIP会员页面
    EntityPublishTypeLazymanProduct  = 28,// 懒人出品
    EntityPublishTypeReadBoy         = 29,// 阅读男生频道
    EntityPublishTypeReadGirl        = 30,// 阅读女生频道
    EntityPublishTypeReadSubCategory = 31,// 阅读三级分类
    EntityPublishTypeBoutiqueBook    = 32,// 收费书籍，精品首发
    EntityPublishTypeChargeZoneRecommend = 34,// 付费专区推荐页
    EntityPublishTypeChargeZoneCategory  = 35,// 付费专区分类页
    EntityPublishTypeReaderAuthorCategory = 36, // 阅读作者专栏分类页
    EntityPublishTypeReaderFolderList     = 37, // 阅读书单列表
    EntityPublishTypeReaderAuthorDetail   = 38, // 阅读作者详情
    EntityPublishTypeCompleteUserInfo    = 39,// 完善用户资料
    EntityPublishTypeSecurity            = 40,// 安全设置（任务列表中的验证邮箱）
    EntityPublishTypeBindSocailAccount   = 41,// 绑定社交帐号
    EntityPublishTypeRechange            = 42,// 我的钱包>充值
    EntityPublishTypeInnerCPCAd          = 43,// 程序内部浏览器（cpc广告，需要5秒统计）
    EntityPublishTypeExchangeIntegral    = 44,// 积分兑换页面
    EntityPublishTypeMissionList         = 45,// 任务列表页面
    EntityPublishTypeVipZoneHome         = 46,// 会员专区首页
    EntityPublishTypeDailySign           = 47,// 每日签到
    EntityPublishTypeInnerCPAAd          = 48,// 程序内部浏览器（cpa广告）
    EntityPublishTypeListenReadTicket    = 50,// 我的听读券
    EntityPublishTypeReaderFolderDetail  = 51,// 阅读书单详情
    EntityPublishTypeReadFreeLimits      = 52,// 阅读限免首页
    EntityPublishTypeListenFreeLimits    = 53,// 收听限免首页
    EntityPublishTypeBoysLoveToListen    = 54,// 男生爱听
    EntityPublishTypeGirlsLoveToListen   = 55,// 女生爱听
    EntityPublishTypeListenGroupsTrends  = 56,// 听友动态首页
    EntityPublishTypeEditingRecommand    = 57,// 小编推荐
    EntityPublishTypeNewBookRecommand    = 58,// 新书推荐
    EntityPublishTypeHomeBannerAdvert    = 59,// 首页广告，首页广告位
    EntityPublishTypeOuterActivity       = 60,// 外部活动
    EntityPublishTypeInnerAdvert         = 61,// 内部广告
    EntityPublishTypeListenBarRecommend  = 62,// 听吧推荐页
    EntityPublishTypeMine                = 63,// 我的页
    EntityPublishTypeDiscovery           = 64,// 发现页
    EntityPublishTypeAccount             = 65,// 账号页
    EntityPublishTypeListenBarRank       = 66,// 有声榜单页
    EntityPublishTypeListenBarRankDetail = 67,// 有声榜单详情页
    EntityPublishTypeReadRank            = 68,// 阅读榜单页
    EntityPublishTypeReadCategoryList    = 69,// 阅读分类列表
    EntityPublishTypeReadRankDetail      = 70,// 阅读榜单详情
    EntityPublishTypeVIPBookStore        = 71,// 会员书库
    EntityPublishTypeVIPFreeListen       = 72,// 会员限免听
    EntityPublishTypeVIPFreeRead         = 73,// 会员限免读
    EntityPublishTypeVIPQuickListen      = 74,// 会员抢先听
    EntityPublishTypeListenBarCategory   = 76,// 听吧分类页
    EntityPublishTypeDownload            = 77,// 下载
    EntityPublishTypeProgramRankDetail   = 78,// 节目榜单详情
    EntityPublishTypeAnnouncerRankDetail = 79,// 主播榜单详情
    EntityPublishTypeRewardProgramRankDetail    = 80,// 打赏节目榜单详情
    EntityPublishTypeRewardBookRankDetail       = 81,// 打赏书籍榜单详情
    EntityPublishTypeRewardUserRankDetail       = 82,// 打赏用户榜单详情
    EntityPublishTypeRewardAnnouncerRankDetail  = 83,// 打赏主播榜单详情
    EntityPublishTypeBookPlayer                 = 84,// 书籍播放器页面 值模式例子：书籍id_声音id 1054_12
    EntityPublishTypeProgramPlayer              = 85,// 节目播放器页面
    EntityPublishTypeListenGroupPostDetail      = 86,// 听友会帖子详情
    EntityPublishBoutiqueProgramList            = 87,// 更多精选节目
    EntityPublishTypeListenBarPayAlbum          = 88,// 有声付费合辑
    EntityPublishTypeReadPayAlbum               = 89,// 阅读付费合辑
    EntityPublishTypeListenBarDiscountActivity  = 90,// 有声折扣专区
    EntityPublishTypeReadDiscountActivity       = 91,// 阅读折扣专区
    EntityPublishTypeBindPhone                  = 92,// 绑定手机号
    EntityPublishTypeMyWallet                   = 93,// 我的钱包
    EntityPublishTypeInviteFriend               = 94,// 邀请好友
    EntityPublishTypeFeedback                   = 95,// 提交反馈（网易七鱼）
    EntityPublishTypeTopicDetail                = 96,// 话题详情
    EntityPublishTypeMyListenGroupList          = 97, // 我的听友会列表
    EntityPublishTypeListenGroupCategoryList    = 98, // 分类听友会列表
    EntityPublishTypeGuessYouWantToListen       = 99, // 猜你想听列表
    EntityPublishTypeProgramNavRecommend        = 100, // 节目导航推荐页（原节目分类热播页面）
    EntityPublishTypeBookNavRecommend           = 101, // 书籍导航推荐页（原书籍一级分类推荐页）
    EntityPublishTypeLabelList                  = 102, // 标签列表
    EntityPublishTypeLabelHomePage              = 103, // 标签主页
    EntityPublishTypeLabelRecommendBook         = 104, // 标签类别推荐页-书籍
    EntityPublishTypeLabelRecommendMix          = 105, // 标签类别推荐页-混合
    EntityPublishTypeLabelRecommendResource     = 106, // 标签类别推荐页-资源列表
    EntityPublishTypeLabelFilter                = 107, // 标签类型筛选页
    EntityPublishTypeLabelSubFilter             = 108, // 标签类型子标签筛选页,值模式例子：标签类别id_子标签ID 1054_10
    
    // 自定义跳转
    EntityPublishTypeReader          = 1001,// 跳转到阅读器
    EntityPublishTypeMaila           = 1002,// 跳转到麦啦广告页面
    EntityPublishTypeChooseLike      = 1003,// 跳转兴趣选择
    EntityPublishTypeChoosedInterest = 1004,// 跳转已选择兴趣页
};

#endif /* LRTSDBPublicTypeDefine_h */
