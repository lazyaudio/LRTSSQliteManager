//
//  LRTSDBBookModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/7.
//

#import "LRTSDBBookModel.h"
#import <WCDB/WCDB.h>

@interface LRTSDBBookModel (WCTTableCoding)<WCTTableCoding>

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

- (id)initWithDict:(NSDictionary *)data;

@end
