//
//  LRTSDBBookDetailModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBBookDetailModel.h"
#import <WCDB/WCDB.h>

@interface LRTSDBBookDetailModel (WCTTableCoding)

WCDB_PROPERTY(length)
WCDB_PROPERTY(download)
WCDB_PROPERTY(cantDown)
WCDB_PROPERTY(marked)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(commentMean)
WCDB_PROPERTY(listenPrice)
WCDB_PROPERTY(downloadPrice)
WCDB_PROPERTY(announcerIds)
WCDB_PROPERTY(bookReward)
WCDB_PROPERTY(extraInfos)
WCDB_PROPERTY(bookPrice)
WCDB_PROPERTY(bookVersion)
WCDB_PROPERTY(sysLabels)
WCDB_PROPERTY(tags)
WCDB_PROPERTY(typeId)
WCDB_PROPERTY(haveLink)
WCDB_PROPERTY(linkRanges)
WCDB_PROPERTY(linkAddresses)
WCDB_PROPERTY(descWithLink)
WCDB_PROPERTY(createTime)
WCDB_PROPERTY(latestFollowLabel)
WCDB_PROPERTY(latestFollowLabelTime)


//WCDB_PROPERTY()
//WCDB_PROPERTY(bookID)

#pragma mark - BookModel

WCDB_PROPERTY(bId)
WCDB_PROPERTY(hot)
WCDB_PROPERTY(sections)
WCDB_PROPERTY(state)

WCDB_PROPERTY(sort)

WCDB_PROPERTY(commentCount)
WCDB_PROPERTY(isMarked)

WCDB_PROPERTY(name)
WCDB_PROPERTY(author)
WCDB_PROPERTY(announcer)
WCDB_PROPERTY(cover)
WCDB_PROPERTY(update)

WCDB_PROPERTY(refId)

WCDB_PROPERTY(categoryName)
WCDB_PROPERTY(lastUpdateTime)

WCDB_PROPERTY(enterPlayType)

WCDB_PROPERTY(bParentId)
WCDB_PROPERTY(bCategoryId)

WCDB_PROPERTY(downloadedSectionCount)

WCDB_PROPERTY(recordId)
WCDB_PROPERTY(recordStatus)
WCDB_PROPERTY(like)
WCDB_PROPERTY(entityType)

WCDB_PROPERTY(extInfo)

WCDB_PROPERTY(strategy)
WCDB_PROPERTY(freeEndTime)
WCDB_PROPERTY(overEndTime)
WCDB_PROPERTY(updateState)


@end
