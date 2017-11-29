//
//  BookDetail.h
//  CTPersistance
//
//  Created by liangbai on 2017/10/27.
//  Copyright © 2017年 casa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LRTSDBModel.h"

@interface BookDetail : LRTSDBModel

@property(assign, nonatomic) NSInteger bookID;
@property(strong, nonatomic) NSString *bookName;
@property(strong, nonatomic) NSDate *upLoad;
@property(copy, nonatomic) NSString *pubilsher;

//WCDB_PROPERTY(BookDetail);

@end
