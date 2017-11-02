//
//  BookDetail.h
//  CTPersistance
//
//  Created by liangbai on 2017/10/27.
//  Copyright © 2017年 casa. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BookDetail : NSObject

@property(assign, nonatomic) int bookID;
@property(copy, nonatomic) NSString *bookName;
@property(strong, nonatomic) NSDate *upLoad;
@property(copy, nonatomic) NSString *pubilsher;

//WCDB_PROPERTY(BookDetail);

@end
