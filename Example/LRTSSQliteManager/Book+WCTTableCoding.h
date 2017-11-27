//
//  Book+WCTTableCoding.h
//  LRTSSQliteManager
//
//  Created by JackJin on 2017/11/24.
//Copyright © 2017年 boilwater. All rights reserved.
//

#import "Book+WCTTableCoding.h"
#import <WCDB/WCDB.h>

@interface Book (WCTTableCoding) <WCTTableCoding>

WCDB_PROPERTY(bookName)
WCDB_PROPERTY(bookID)
WCDB_PROPERTY(autor)
WCDB_PROPERTY(version)
WCDB_PROPERTY(totalPage)

//WCDB_SYNTHESIZE(Book, bookName)
//WCDB_SYNTHESIZE(Book, bookID)
//WCDB_SYNTHESIZE(Book, autor)
//WCDB_SYNTHESIZE(Book, version)
//WCDB_SYNTHESIZE(Book, totalPage)
//WCDB_SYNTHESIZE(Book, bookeDetail)
//WCDB_SYNTHESIZE(Book, pubilsher)

@end
