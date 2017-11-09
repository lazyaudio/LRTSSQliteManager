//
//  LRTSDBPlayItemModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBPlayItemModel.h"

@interface LRTSDBPlayItemModel (WCTTableCoding)

WCDB_PROPERTY(pId)
WCDB_PROPERTY(pName)
WCDB_PROPERTY(pUrl)
WCDB_PROPERTY(coverUrl)
WCDB_PROPERTY(section)
WCDB_PROPERTY(entityType)
WCDB_PROPERTY(haslyric)
WCDB_PROPERTY(currentTime)
WCDB_PROPERTY(duration)
WCDB_PROPERTY(enterType)
WCDB_PROPERTY(playSeconds)
WCDB_PROPERTY(freeUrl)

WCDB_PROPERTY(isRequestedCoverUrl)

WCDB_PROPERTY(validCoverUrl)

//WCDB_PROPERTY()
//WCDB_PROPERTY()
//WCDB_PROPERTY()
//
//WCDB_PROPERTY()

@end
