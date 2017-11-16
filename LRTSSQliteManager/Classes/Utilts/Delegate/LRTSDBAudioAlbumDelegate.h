//
//  LRTSDBAudioAlbumDelegate.h
//  Kiwi
//
//  Created by JackJin on 2017/11/16.
//

#import <Foundation/Foundation.h>

/**
 * 定义可用于播放的最小专辑
 * 等同于书籍详情或者节目，这里使用音乐播放的专辑概念统一行为
 */
@protocol LRTSDBAudioAlbumDelegate <NSObject>

/**
 * 专辑ID
 */
- (NSInteger)albumId;
/**
 * 专辑名称
 */
- (NSString *)albumName;
/**
 * 艺术家名称
 */
- (NSString *)albumArtistName;
/**
 * 艺术家ID
 */
- (NSArray *)albumArtistIds;
/**
 * 专辑封面url
 */
- (NSString *)albumArtworkUrl;
/**
 * 专辑发行时间
 */
- (NSString *)albumPublishDate;
/**
 * LMBaseModel的实例
 */
- (id)originModel;
/**
 * 专辑曲目总数
 */
- (NSUInteger)albumTrackCount;

@end
