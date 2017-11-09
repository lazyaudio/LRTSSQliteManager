//
//  LRTSDBBookDetailModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBBookDetailModel.h"

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
//WCDB_PROPERTY()


@end
