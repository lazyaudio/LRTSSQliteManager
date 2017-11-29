//
//  LRTSDBSection.m
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "LRTSDBSectionModel.h"
#import <WCDB/WCDB.h>


@implementation LRTSDBSectionModel

WCDB_IMPLEMENTATION(LRTSDBSectionModel)

WCDB_SYNTHESIZE(LRTSDBSectionModel, sId)
WCDB_SYNTHESIZE(LRTSDBSectionModel, sBookId)

WCDB_SYNTHESIZE(LRTSDBSectionModel, section)
WCDB_SYNTHESIZE(LRTSDBSectionModel, length)
WCDB_SYNTHESIZE(LRTSDBSectionModel, size)

WCDB_SYNTHESIZE(LRTSDBSectionModel, name)
WCDB_SYNTHESIZE(LRTSDBSectionModel, path)
WCDB_SYNTHESIZE(LRTSDBSectionModel, localPath)

WCDB_SYNTHESIZE(LRTSDBSectionModel, downloadPrice)
WCDB_SYNTHESIZE(LRTSDBSectionModel, listenPrice)
WCDB_SYNTHESIZE(LRTSDBSectionModel, haslyric)
WCDB_SYNTHESIZE(LRTSDBSectionModel, pageNumber)

WCDB_SYNTHESIZE(LRTSDBSectionModel, hasBuy)
WCDB_SYNTHESIZE(LRTSDBSectionModel, payType)

WCDB_SYNTHESIZE(LRTSDBSectionModel, playTime)

WCDB_SYNTHESIZE(LRTSDBSectionModel, announcer)
WCDB_SYNTHESIZE(LRTSDBSectionModel, desc)
WCDB_SYNTHESIZE(LRTSDBSectionModel, text)

WCDB_SYNTHESIZE(LRTSDBSectionModel, downloadStatus)
WCDB_SYNTHESIZE(LRTSDBSectionModel, downloadProgress)

WCDB_SYNTHESIZE(LRTSDBSectionModel, strategy)

//WCDB_SYNTHESIZE(LRTSDBSectionModel, )
//WCDB_SYNTHESIZE(LRTSDBSectionModel, )
//WCDB_SYNTHESIZE(LRTSDBSectionModel, )


@end
