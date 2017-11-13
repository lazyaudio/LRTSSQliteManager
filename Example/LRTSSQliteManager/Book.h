//
//  Book.h
//  LRTSSQliteManager_Example
//
//  Created by JackJin on 2017/11/13.
//  Copyright © 2017年 boilwater. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WCDB/WCDB.h>
#import "BookDetail.h"

@interface Book : NSObject<WCTTableCoding>

@property (nonatomic, assign) NSUInteger bookID;
@property (nonatomic, strong) NSString *autor;
@property (nonatomic, assign) NSUInteger version;
@property (nonatomic, assign) NSUInteger totalPage;
@property (nonatomic, strong) BookDetail *bookeDetail;

WCDB_PROPERTY(autor)
WCDB_PROPERTY(version)
WCDB_PROPERTY(totalPage)



@end
