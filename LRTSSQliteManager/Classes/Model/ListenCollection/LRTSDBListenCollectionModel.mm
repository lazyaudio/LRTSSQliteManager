//
//  LRTSDBListenCollectionModel.m
//  Kiwi
//
//  Created by JackJin on 2017/11/9.
//

#import "LRTSDBListenCollectionModel.h"

@implementation LRTSDBListenCollectionModel

WCDB_IMPLEMENTATION(LRTSDBListenCollectionModel)

WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, folderId)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, collectFolderId)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, collectionName)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, collectionCover)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, itemsCount)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, collectedCount)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, updateTime)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, collectFolderTime)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, entityUpdateTime)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, commentCount)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, desc)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, colectionType)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, updateCount)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, lc_state)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, authorId)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, backFolderType)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, coverValid)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, referId)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, nickName)
WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, subEntitys)


//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
////
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )
//WCDB_SYNTHESIZE(LRTSDBListenCollectionModel, )

@end

@implementation LMSubEntity

WCDB_IMPLEMENTATION(LMSubEntity)

WCDB_SYNTHESIZE(LMSubEntity, cover)
WCDB_SYNTHESIZE(LMSubEntity, entityId)
WCDB_SYNTHESIZE(LMSubEntity, entityType)
WCDB_SYNTHESIZE(LMSubEntity, name)
WCDB_SYNTHESIZE(LMSubEntity, strategy)
WCDB_SYNTHESIZE(LMSubEntity, tag)


//WCDB_SYNTHESIZE(LMSubEntity, )
//WCDB_SYNTHESIZE(LMSubEntity, )
//WCDB_SYNTHESIZE(LMSubEntity, )


@end

