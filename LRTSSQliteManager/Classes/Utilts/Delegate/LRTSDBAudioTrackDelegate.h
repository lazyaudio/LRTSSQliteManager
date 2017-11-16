//
//  LRTSDBAudioTrackDelegate.h
//  Kiwi
//
//  Created by JackJin on 2017/11/16.
//

#import <Foundation/Foundation.h>
#import "LRTSDBAudioAlbumDelegate.h"

typedef NS_ENUM(NSInteger, AudioTrackLyricType) {
    AudioLyricTypeNone,     // 没有歌词
    AudioLyricTypeText,     // 静态文本
};

/**
 * 定义可用于播放的最小单元需要具有的属性
 */
@protocol LRTSDBAudioTrackDelegate <NSObject>

@property (nonatomic, assign) NSInteger trackIndex; //对应的索引即section
@property (nonatomic, strong) NSObject<LRTSDBAudioAlbumDelegate> *albumObject;


- (NSInteger)trackId;
/** 艺术家   */
- (NSString *)audioArtist;
/** 曲目标题 */
- (NSString *)audioTitle;
/** 专辑名称 */
- (NSString *)audioAlbumName;
/** 音轨封面图片 */
- (UIImage *)trackArtwork;
/** 音轨的封面路径 */
- (NSString *)trackArtworkUrl;
/** 播放URL */
- (NSURL*)audioURL;

- (NSString *)trackUniqId;

/** 歌词类型*/
- (AudioTrackLyricType)lyricType;
- (NSInteger)albumId;
/** 最后一个track */
- (BOOL)isLastTrack;
- (BOOL)isFirstTrack;


@end
