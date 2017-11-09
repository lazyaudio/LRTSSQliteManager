//
//  LRTSDBSectionModel+WCTTableCoding.h
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBSectionModel.h"

@interface LRTSDBSectionModel (WCTTableCoding)

WCDB_PROPERTY(sId)
WCDB_PROPERTY(sBookId)

WCDB_PROPERTY(section)
WCDB_PROPERTY(length)
WCDB_PROPERTY(size)

WCDB_PROPERTY(name)
WCDB_PROPERTY(path)
WCDB_PROPERTY(localPath)

WCDB_PROPERTY(downloadPrice)
WCDB_PROPERTY(listenPrice)
WCDB_PROPERTY(haslyric)
WCDB_PROPERTY(pageNumber)

WCDB_PROPERTY(hasBuy)
WCDB_PROPERTY(payType)

WCDB_PROPERTY(playTime)

WCDB_PROPERTY(announcer)
WCDB_PROPERTY(desc)
WCDB_PROPERTY(text)

WCDB_PROPERTY(downloadStatus)
WCDB_PROPERTY(downloadProgress)

WCDB_PROPERTY(strategy)

@end
