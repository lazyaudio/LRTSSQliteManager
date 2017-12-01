//
//  LRTSDBEntityModel.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import <LRTSSQliteManager/LRTSSQliteManager.h>
#import "LRTSDBLaunchAdModel.h"
#import "LRTSDBPublicTypeDefine.h"
#import "LRTSTagModel.h"
#import "LRTSDBModel.h"



@interface LRTSDBEntityModel : LRTSDBModel

/** 实体基本属性 */
@property (nonatomic,strong) NSString *et_id;           // 实体id
@property (nonatomic,strong) NSString *et_name;         // 实体名称
@property (nonatomic,strong) NSString *et_desc;         // 实体描述
@property (nonatomic,strong) NSString *et_cover;        // 实体封面
@property (nonatomic,assign) LRTSEntityPublishType et_type; // 实体类型

/** 以下为实体扩展属性 */

/** 实体排序，某个模块的数据的来源多余一个接口时，需要根据排序字段来确定显示顺序
 1、如首页banner、书籍节目分类推荐banner（包含推荐的banner和商业banner广告数据）
 */
@property (nonatomic,assign) NSInteger et_sort;

// 实体标签数组（主要用于书籍、节目封面或者列表中显示指定的标签）
//TODO  注册掉
//@property (nonatomic,strong) LRTSTagModel *et_tag;

// 附加的广告模型
//TODO  注册掉
//@property (nonatomic, strong) LRTSDBLaunchAdModel *et_attatchAd;


/** 附带模型类信息
 由于实体类型为通用数据模型，通常做为混合展示界面的数据源，有些情况下基
 础属性不足以支撑界面的展示，此时可以自定义数据模型类用来辅助展示，如
 1、（因为腾讯广告的模型类使用et_attatchAd的话需要转换一次，
 字段不匹配，所以加个id类型的属性用于携带附属信息）
 */
//TODO  注册掉
//@property (nonatomic,strong) id et_attatchModel;

// 友盟统计时需要的名称
@property (nonatomic,strong) NSString *et_umCountName;

@property (nonatomic,strong) NSString *author;// 作者
@property (nonatomic,assign) long long playCount;// 播放数
@property (nonatomic,assign) long long userCount;// 听友会成员数
@property (nonatomic,assign) long long contentCount;// 听友会帖子数
@property (nonatomic,assign) long long userState;       //用户状态

// vip策略
@property (nonatomic,assign) NSInteger strategy;


#pragma mark - WVDB 数据绑定

WCDB_PROPERTY(et_id)
WCDB_PROPERTY(et_name)
WCDB_PROPERTY(et_desc)
WCDB_PROPERTY(et_cover)

WCDB_PROPERTY(et_type)
WCDB_PROPERTY(et_sort)
WCDB_PROPERTY(et_tag)
WCDB_PROPERTY(et_attatchAd)
WCDB_PROPERTY(et_attatchModel)
WCDB_PROPERTY(et_umCountName)
WCDB_PROPERTY(author)
WCDB_PROPERTY(playCount)
WCDB_PROPERTY(userCount)
WCDB_PROPERTY(contentCount)
WCDB_PROPERTY(userState)
WCDB_PROPERTY(strategy)

@end
