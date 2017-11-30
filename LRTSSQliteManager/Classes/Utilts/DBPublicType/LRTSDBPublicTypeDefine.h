//
//  LRTSDBPublicTypeDefine.h
//  Pods
//
//  Created by JackJin on 2017/11/9.
//

#ifndef LRTSDBPublicTypeDefine_h
#define LRTSDBPublicTypeDefine_h

//LRTSEntityPublish

typedef NS_ENUM(NSInteger,LRTSEntityPublishType) {
    LRTSEntityPublishTypeNone                = -1,// 没有跳转动作
    // 与服务器约定的跳转
    LRTSEntityPublishBookDetail          = 0,// 书籍详情
    LRTSEntityPublishInnerActivity       = 1,// 内部活动
    LRTSEntityPublishProgramDetail       = 2,// 节目详情
    LRTSEntityPublishTopicDetail         = 3,// 专题详情
    LRTSEntityPublishAnnouncerHome       = 4,// 主播首页
    LRTSEntityPublishBookSubCategory     = 5,// 书籍分类（二级分类）
    LRTSEntityPublishAnnouncerRadio      = 6,// 主播电台
    LRTSEntityPublishOuterAds            = 7,// 外部广告
    LRTSEntityPublishBookTopCategory     = 8,// 书籍分类（一级分类）
    LRTSEntityPublishListenGroupHome     = 9,// 听友会详情
    LRTSEntityPublishGameCenter          = 10,// 游戏中心
    LRTSEntityPublishGameDetail          = 11,// 游戏详情
    LRTSEntityPublishUnHyperLinkAds      = 12,// 无连接广告
    LRTSEntityPublishListenFolderDetail  = 13,// 听单详情
    LRTSEntityPublishProgramCategoryList = 14,// 节目分类列表
    LRTSEntityPublishTopicList           = 15,// 专题列表
    LRTSEntityPublishAnnouncerList       = 16,// 主播列表
    LRTSEntityPublishListenGroupList     = 17,// 听友会列表
    LRTSEntityPublishListenFolderList    = 18,// 听单列表
    LRTSEntityPublishReadDetail          = 19,// 阅读书籍详情
    LRTSEntityPublishBookSigleCategory   = 20,// 书籍独立分类，没有二级分类的一级分类(听书)
    LRTSEntityPublishTypeReadHome        = 21,// 阅读书城首页
    LRTSEntityPublishTypeReadCategory    = 22,// 阅读二级分类
    LRTSEntityPublishTypeReadShelf       = 23,// 阅读书架
    LRTSEntityPublishTypeHotChannel      = 24,// 热门频道（不能跳转）
    LRTSEntityPublishTypeCopyrightZone   = 25,// 版权专区
    LRTSEntityPublishTypeCopyright       = 26,// 版权机构，版权专区下的一个具体的版权机构
    LRTSEntityPublishTypeVIPMember       = 27,// VIP会员页面
    LRTSEntityPublishTypeLazymanProduct  = 28,// 懒人出品
    LRTSEntityPublishTypeReadBoy         = 29,// 阅读男生频道
    LRTSEntityPublishTypeReadGirl        = 30,// 阅读女生频道
    LRTSEntityPublishTypeReadSubCategory = 31,// 阅读三级分类
    LRTSEntityPublishTypeBoutiqueBook    = 32,// 收费书籍，精品首发
    LRTSEntityPublishTypeChargeZoneRecommend = 34,// 付费专区推荐页
    LRTSEntityPublishTypeChargeZoneCategory  = 35,// 付费专区分类页
    LRTSEntityPublishTypeReaderAuthorCategory = 36, // 阅读作者专栏分类页
    LRTSEntityPublishTypeReaderFolderList     = 37, // 阅读书单列表
    LRTSEntityPublishTypeReaderAuthorDetail   = 38, // 阅读作者详情
    LRTSEntityPublishTypeCompleteUserInfo    = 39,// 完善用户资料
    LRTSEntityPublishTypeSecurity            = 40,// 安全设置（任务列表中的验证邮箱）
    LRTSEntityPublishTypeBindSocailAccount   = 41,// 绑定社交帐号
    LRTSEntityPublishTypeRechange            = 42,// 我的钱包>充值
    LRTSEntityPublishTypeInnerCPCAd          = 43,// 程序内部浏览器（cpc广告，需要5秒统计）
    LRTSEntityPublishTypeExchangeIntegral    = 44,// 积分兑换页面
    LRTSEntityPublishTypeMissionList         = 45,// 任务列表页面
    LRTSEntityPublishTypeVipZoneHome         = 46,// 会员专区首页
    LRTSEntityPublishTypeDailySign           = 47,// 每日签到
    LRTSEntityPublishTypeInnerCPAAd          = 48,// 程序内部浏览器（cpa广告）
    LRTSEntityPublishTypeListenReadTicket    = 50,// 我的听读券
    LRTSEntityPublishTypeReaderFolderDetail  = 51,// 阅读书单详情
    LRTSEntityPublishTypeReadFreeLimits      = 52,// 阅读限免首页
    LRTSEntityPublishTypeListenFreeLimits    = 53,// 收听限免首页
    LRTSEntityPublishTypeBoysLoveToListen    = 54,// 男生爱听
    LRTSEntityPublishTypeGirlsLoveToListen   = 55,// 女生爱听
    LRTSEntityPublishTypeListenGroupsTrends  = 56,// 听友动态首页
    LRTSEntityPublishTypeEditingRecommand    = 57,// 小编推荐
    LRTSEntityPublishTypeNewBookRecommand    = 58,// 新书推荐
    LRTSEntityPublishTypeHomeBannerAdvert    = 59,// 首页广告，首页广告位
    LRTSEntityPublishTypeOuterActivity       = 60,// 外部活动
    LRTSEntityPublishTypeInnerAdvert         = 61,// 内部广告
    LRTSEntityPublishTypeListenBarRecommend  = 62,// 听吧推荐页
    LRTSEntityPublishTypeMine                = 63,// 我的页
    LRTSEntityPublishTypeDiscovery           = 64,// 发现页
    LRTSEntityPublishTypeAccount             = 65,// 账号页
    LRTSEntityPublishTypeListenBarRank       = 66,// 有声榜单页
    LRTSEntityPublishTypeListenBarRankDetail = 67,// 有声榜单详情页
    LRTSEntityPublishTypeReadRank            = 68,// 阅读榜单页
    LRTSEntityPublishTypeReadCategoryList    = 69,// 阅读分类列表
    LRTSEntityPublishTypeReadRankDetail      = 70,// 阅读榜单详情
    LRTSEntityPublishTypeVIPBookStore        = 71,// 会员书库
    LRTSEntityPublishTypeVIPFreeListen       = 72,// 会员限免听
    LRTSEntityPublishTypeVIPFreeRead         = 73,// 会员限免读
    LRTSEntityPublishTypeVIPQuickListen      = 74,// 会员抢先听
    LRTSEntityPublishTypeListenBarCategory   = 76,// 听吧分类页
    LRTSEntityPublishTypeDownload            = 77,// 下载
    LRTSEntityPublishTypeProgramRankDetail   = 78,// 节目榜单详情
    LRTSEntityPublishTypeAnnouncerRankDetail = 79,// 主播榜单详情
    LRTSEntityPublishTypeRewardProgramRankDetail    = 80,// 打赏节目榜单详情
    LRTSEntityPublishTypeRewardBookRankDetail       = 81,// 打赏书籍榜单详情
    LRTSEntityPublishTypeRewardUserRankDetail       = 82,// 打赏用户榜单详情
    LRTSEntityPublishTypeRewardAnnouncerRankDetail  = 83,// 打赏主播榜单详情
    LRTSEntityPublishTypeBookPlayer                 = 84,// 书籍播放器页面 值模式例子：书籍id_声音id 1054_12
    LRTSEntityPublishTypeProgramPlayer              = 85,// 节目播放器页面
    LRTSEntityPublishTypeListenGroupPostDetail      = 86,// 听友会帖子详情
    LRTSEntityPublishBoutiqueProgramList            = 87,// 更多精选节目
    LRTSEntityPublishTypeListenBarPayAlbum          = 88,// 有声付费合辑
    LRTSEntityPublishTypeReadPayAlbum               = 89,// 阅读付费合辑
    LRTSEntityPublishTypeListenBarDiscountActivity  = 90,// 有声折扣专区
    LRTSEntityPublishTypeReadDiscountActivity       = 91,// 阅读折扣专区
    LRTSEntityPublishTypeBindPhone                  = 92,// 绑定手机号
    LRTSEntityPublishTypeMyWallet                   = 93,// 我的钱包
    LRTSEntityPublishTypeInviteFriend               = 94,// 邀请好友
    LRTSEntityPublishTypeFeedback                   = 95,// 提交反馈（网易七鱼）
    LRTSEntityPublishTypeTopicDetail                = 96,// 话题详情
    LRTSEntityPublishTypeMyListenGroupList          = 97, // 我的听友会列表
    LRTSEntityPublishTypeListenGroupCategoryList    = 98, // 分类听友会列表
    LRTSEntityPublishTypeGuessYouWantToListen       = 99, // 猜你想听列表
    LRTSEntityPublishTypeProgramNavRecommend        = 100, // 节目导航推荐页（原节目分类热播页面）
    LRTSEntityPublishTypeBookNavRecommend           = 101, // 书籍导航推荐页（原书籍一级分类推荐页）
    LRTSEntityPublishTypeLabelList                  = 102, // 标签列表
    LRTSEntityPublishTypeLabelHomePage              = 103, // 标签主页
    LRTSEntityPublishTypeLabelRecommendBook         = 104, // 标签类别推荐页-书籍
    LRTSEntityPublishTypeLabelRecommendMix          = 105, // 标签类别推荐页-混合
    LRTSEntityPublishTypeLabelRecommendResource     = 106, // 标签类别推荐页-资源列表
    LRTSEntityPublishTypeLabelFilter                = 107, // 标签类型筛选页
    LRTSEntityPublishTypeLabelSubFilter             = 108, // 标签类型子标签筛选页,值模式例子：标签类别id_子标签ID 1054_10
    
    // 自定义跳转
    LRTSEntityPublishTypeReader          = 1001,// 跳转到阅读器
    LRTSEntityPublishTypeMaila           = 1002,// 跳转到麦啦广告页面
    LRTSEntityPublishTypeChooseLike      = 1003,// 跳转兴趣选择
    LRTSEntityPublishTypeChoosedInterest = 1004,// 跳转已选择兴趣页
};

#endif /* LRTSDBPublicTypeDefine_h */
