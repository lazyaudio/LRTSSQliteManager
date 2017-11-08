//
//  LMMacroStoreCache.h
//  lazyaudio
//
//  Created by lazyaudio on 15/7/14.
//
//  定义缓存宏

#ifndef lazyaudio_LMMacroStoreCache_h
#define lazyaudio_LMMacroStoreCache_h

#pragma mark - userDefault cache

// 存储我的模块 最近收听中更多上面的小红点是否显示 value为0不显示，否则显示
#define LMMoreHistoryPlayUpdateStateCountKey   @"MoreHistoryPlayUpdateStateCountKey"

// 标示发现按钮上的小红点是否显示的Key
#define kDiscoverBadgeShowKey @"DiscoverBadgeShowKey"

// 标记友盟更新时间
#define kUpdateUmParamKey @"upadteUmParamKey"

// 存储推荐用户收听的书籍节目（用户没有收听记录时）
#define kRecommendListenWhenNoHistory @"RecommendListenWhenNoHistoryKey"
#define kParamEntityId  @"ParamEntityIdKey"
#define kParamEntityType @"ParamEntityTypeKey"
#define kParamEntityCover @"ParamEntityCoverKey"

// 保存我关注标签相关的书籍节目中的更新标记
#define kBookUpdateStatusForAttentionLabel @"BookUpdateStatusForAttentionLabelKey"
#define kProgramUpdateStatusForAttentionLabel @"ProgramUpdateStatusForAttentionLabelKey"

#define UniqueId    @"UniqueId"     //保存设备唯一性id的key
#define UserToken   @"token"        //保存用户token的key
#define UserId      @"userId"       //保存用户id的key
#define InstallDateKey @"InstallDate" //记录用户安装应用的时间

/**
 1.用来保存在userDefault中记录最后更新的key值，value为NSTimeInterval格式(V2.1.1之前版本)
 #define kRecordUpdateTimeKey    @"RecordUpdateTime"
 2.用来保存在userDefault中记录最后更新的key值(区分收听收藏)，value为NSTimeInterval格式(V2.1.1之后版本)
 */
#define kRecordHistoryUpdateTimeKey     @"RecordHistoryUpDateTime"
#define kRecordCollectUpdateTimeKey     @"RecordCollectUpDateTime"
#define kPersonCenterGetUserInfoTimeKey @"PersonCenterGetUserInfoTimeKey"

//收听收藏记录同步更新间隔时间
#if DEBUG
#define kRecordIntervalTime (60)
#else
#define kRecordIntervalTime (24*60*60)
#endif

//记录显示个人中心页面获取用户个人信息的时间间隔
#define kGetUserInfoInterValTime (30*60)


#pragma mark - keyedArchiver cache


#pragma mark - db cache

#define LMSandboxCacheDirPath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0];
#define LMSandboxDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define LMDBFilePath  [LMSandboxDocumentPath stringByAppendingPathComponent:@"lazyman"]
#define LMRDBFilePath [LMSandboxDocumentPath stringByAppendingPathComponent:@"lazymanRead.realm"]

#pragma mark -keyValue cache

#define YTK_TABLE_RADIO  @"ytk_table_radio"
#define YTK_TABLE_FOLDER @"ytk_table_folder"

/**
 * 2.2.5版本开始，采用keyValueStore方式持久化的数据都放在一个关系型数据库表中，采用唯一的key标识来存储数据
 *
 * key生成规则：kv+classname+store,如果相同class需要分开存储，则classname加上后缀（kv+classname_banner+stroe）
 */
#define TABLE_NAME_KEYVALUE @"KeyValueStore"

#define TABLE_NAME_ONLINGPARAM @"OnlineParam"

#define TABLE_NAME_REMOTEEVENT @"RemoteEvent"

#pragma mark - cache key

/**
 *  使用LMBaseVCModel默认是使用类名作为键进行缓存，但有时也需要自己指定缓存的键值，例如组合接口中，某一个接口的缓存被多个地方
 *  用到，这时就需要特殊指定缓存键值。
 *
 *  命名规则：#define XXXX_CACHEK_KEY @"xxxx_cache_key"
 */
#define PROGRAM_CATEGORIES_CACHE_KEY @"program_categories_cache_key" // 节目分类缓存

#pragma mark -relativeDB cache

#endif

