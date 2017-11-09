//
//  LRTSDBCommentNoticeModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBCommentNoticeModel.h"

@interface LRTSDBCommentNoticeModel (InitializationAndConfiguration)

// 听单的信息（书籍数，被收藏数和最后更新时间）
- (NSString *)collectionFolderInfo;

// 听吧动态产生的原因
- (NSString *)dynamicReasonInfo;

// 检测评论的内容是否已经被删除
- (BOOL)checkRemove;

// 转换成LMComment
- (LMComment *)commentModel;

@end
