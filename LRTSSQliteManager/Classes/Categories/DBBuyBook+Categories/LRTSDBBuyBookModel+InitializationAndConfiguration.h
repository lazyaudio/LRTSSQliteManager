//
//  LRTSDBBuyBookModel+InitializationAndConfiguration.h
//  Kiwi
//
//  Created by JackJin on 2017/11/10.
//

#import "LRTSDBBuyBookModel.h"
#import "LRTSCellDataSourceDelegate.h"


@interface LRTSDBBuyBookModel (InitializationAndConfiguration)<LRTSCellDataSourceDelegate>

+ (NSArray *)getBuyBookWithData:(id)dataSource;

@end
