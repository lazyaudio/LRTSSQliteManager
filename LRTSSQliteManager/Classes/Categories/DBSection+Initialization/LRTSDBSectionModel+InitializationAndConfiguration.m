//
//  LRTSDBSectionModel+InitializationAndConfiguration.m
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBSectionModel+InitializationAndConfiguration.h"

@implementation LRTSDBSectionModel (InitializationAndConfiguration)


#pragma mark - public Method

-(id)initWithDict:(NSDictionary *)data{
    if (self && data) {
        NSNumber *rnum = [data valueForKey:@"id"];
        self.sId = [rnum intValue];
        NSNumber *snum = [data valueForKey:@"section"];
        self.section = [snum intValue];
        NSNumber *len = [data valueForKey:@"length"];
        self.length = [len intValue];
        self.name = [data valueForKey:@"name"];
        self.path = [data valueForKey:@"path"];
    }
    return self;
}

-(BOOL)isEqualToLMSection:(LRTSDBSectionModel *)ls{
    BOOL ret = YES;
    if (self.sId != ls.sId) {
        ret = NO;
    }else if(self.section != ls.section){
        ret = NO;
    }else if (NO == [self.name isEqualToString:ls.name]) {
        ret = NO;
    }else if (NO == [self.path isEqualToString:ls.path]) {
        ret = NO;
    }else if (self.length != ls.length) {
        ret = NO;
    }
    return ret;
}

- (BOOL)isEqual:(id)object
{
    if (![object isKindOfClass:[LRTSDBSectionModel class]) {
        return NO;
    }
    LRTSDBSectionModel *section = (LRTSDBSectionModel *)object;
    if (section.sId == self.sId) {
        return YES;
    }
    return NO;
}

- (NSString *)description
{
//    NSString *desc = [super description];
    return [[NSString alloc] stringByAppendingFormat:@"id:%@ | section:%@ | name:%@ | szie:%@", @(self.sId), @(self.section), self.name, @(self.size)];
}

#pragma mark - Delagete

#pragma mark - Playable Protocol Methods
          
- (LMPlayItem *)convertToPlayItem
{
    LMPlayItem *playItem = [[LMPlayItem alloc] init];

    playItem.pId = self.sId;
    playItem.pName = self.name;
    playItem.pUrl = self.path;
    playItem.duration = self.length;
    playItem.section = self.section;
    playItem.entityType = EntityTypeBook;
    playItem.haslyric = self.haslyric;
    return playItem;
}
  
+ (LMBaseModel *)convertToBaseModel:(LMPlayItem *)playItem {
  //mark for downloader debug
    LMSection *section = [[LMSection alloc] init];
    section.sBookId = [playItem albumId];
    section.sId = playItem.pId;
    section.name = playItem.pName;
    section.section = playItem.section;
    section.path = playItem.pUrl;
    section.haslyric = playItem.haslyric;
    return section;
}
  
#pragma mark - Downloadable Protocol Methods
  
- (LMDownloadItem *)convertToDownloadItem
{
    LMDownloadItem *downloadItem = [[LMDownloadItem alloc] init];

    downloadItem.dId = self.sId;
    downloadItem.dEntityId = self.sBookId;
    downloadItem.name = self.name;
    downloadItem.fileSize = self.size;
    downloadItem.downloadStatus = self.downloadStatus;
    downloadItem.downloadProgress = self.downloadProgress;
    downloadItem.dHasLyric = self.haslyric;
    downloadItem.dSection = self.section;
// 设置免流的下载地址，后台下载不能用NSURLProtocol截取
    if ([LMProxyManager shareManager].isProxyOn) {
        downloadItem.dSourceUrl = [[LMProxyManager shareManager] freeUrlWithOriginUrl:self.path];
    }
    else {
        downloadItem.dSourceUrl = self.path;
    }
    return downloadItem;
}
  
- (EntityType )entityType{
    return EntityTypeBook;
}

@end
