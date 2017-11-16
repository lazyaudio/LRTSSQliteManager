//
//  LRTSDBBookDetailModel+LinkAndConfiguration.m
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//
//  getUpdateStatusWithBook 方法被注册掉
//  原因：在调用过程中会引入其他的类，使模块臃肿
//

#import "LRTSDBBookDetailModel+LinkAndConfiguration.h"
#import "NSString+LRTSAddition.h"
#import "LRTSDBListenerPriceModel.h"
#import "LRTSMacroStoreCache.h"
#import "LRTSTagModel.h"
#import "LRTSTagModel+InitializationAndConfiguration.h"


@implementation LRTSDBBookDetailModel (LinkAndConfiguration)

- (id)initWithBook:(LRTSDBBookModel *)book
{
    self = [super init];
    if (self) {
        self.recordId = book.recordId;
        self.updateState = book.updateState;
        self.bId = book.bId;
        self.hot = book.hot;
        self.state = book.state;
        self.sort = book.sort;
        self.sections = book.sections;
        
        self.name = book.name;
        self.author = book.author;
        self.announcer = book.announcer;
        self.cover = book.cover;
//        self.update = book.update;
        
        self.lastUpdateTime = book.lastUpdateTime;
        
        self.bParentId = book.bParentId;
        self.bCategoryId = book.bCategoryId;
        self.extInfo = book.extInfo;
        self.payType = book.payType;
        self.strategy = book.strategy;
        [self checkLink];
    }
    return self;
}

#pragma mark - Link

- (void)checkLink
{
    // 从desc中取出extInfo信息，注意此处不能用self.desc
    if (self.desc.length && [self.desc rangeOfString:kSeparateMark].location != NSNotFound) {
        NSArray *strArr = [self.desc componentsSeparatedByString:kSeparateMark];
        self.extInfo = [[strArr objectAtIndex:1] BASE64Decode];
    }
    
    NSString *extInfo = self.extInfo;
    if (extInfo.length == 0) {
        self.haveLink = NO;
        return;
    }
    
    self.haveLink = YES;
    NSArray *linkList = [extInfo componentsSeparatedByString:@"||"];
    NSMutableArray *linkRanges = [[NSMutableArray alloc] init];
    NSMutableArray *linkAddresses = [[NSMutableArray alloc] init];
    
    NSMutableString *desc = [self.desc mutableCopy];
    NSMutableString *stringWithLink = [[NSMutableString alloc] init];
    
    // 解析链接
    NSInteger loc = 0;
    for (NSString *linkInfoStr in linkList) {
        NSArray *linkPart = [linkInfoStr componentsSeparatedByString:@"|"];
        if (linkPart.count < 3) {
            continue;
        }
        
        [stringWithLink appendFormat:@"%@%@\n", linkPart[0], linkPart[2]];
        [linkAddresses addObject:linkPart[1]];
        NSString *linkStr = linkPart[2];
        NSRange linkRange = NSMakeRange(loc + [linkPart[0] length], linkStr.length);
        [linkRanges addObject:[NSValue valueWithRange:linkRange]];
        loc = NSMaxRange(linkRange) + 1;
    }
    
    [desc insertString:stringWithLink atIndex:0];
    self.linkRanges = [linkRanges copy];
    self.linkAddresses = [linkAddresses copy];
    self.descWithLink = [desc copy];
    self.desc = [NSString stringWithFormat:@"%@%@%@", [self.desc BASE64Encode], kSeparateMark, [self.extInfo BASE64Encode]];
}

// 用于保存到数据库的desc信息，结构为 Base64(desc) + kSeparateMark + Base64(extInfo)
- (NSString *)saveDesc {
    return [NSString stringWithFormat:@"%@%@%@", [self.desc BASE64Encode], kSeparateMark, [self.extInfo BASE64Encode]];
}


+ (NSArray<LRTSDBBookDetailModel *> *)bookListForListDict:(NSArray *)listDict {
    NSMutableArray *resultArray = nil;
    if (listDict && [listDict isKindOfClass:[NSArray class]]) {
        resultArray = [[NSMutableArray alloc] init];
        for (NSDictionary *dic in listDict) {
            LRTSDBBookDetailModel *book = [[LRTSDBBookDetailModel alloc] init];
            book.bId = [[dic objectForKey:@"id"] intValue];
            book.name = [dic objectForKey:@"name"];
            book.announcer = [dic objectForKey:@"announcer"];
            book.author = [dic objectForKey:@"author"];
            book.hot = [[dic objectForKey:@"hot"] intValue];
            book.cover = [dic objectForKey:@"cover"];
            book.desc = [dic objectForKey:@"desc"];
            book.state = [[dic objectForKey:@"state"] intValue];
            book.createTime = [[dic objectForKey:@"onlineTime"] doubleValue];
            book.latestFollowLabel = [dic objectForKey:@"latestFollowLabel"];
            book.latestFollowLabelTime = [[dic objectForKey:@"latestFollowLabelTime"] doubleValue];
            LRTSTagModel *tag = [LRTSTagModel filterViewTagFromTags:[LRTSTagModel convertToTagsFromDataSource:[dic objectForKey:@"tags"]] enableTagTypes:[LRTSTagModel normalTags]];
            if (tag) {
                book.tags = @[tag];
            }
            if (book.latestFollowLabelTime > 0) {
//
//
//TOMD 此参数注册
//                book.updateState = [LRTSDBBookDetailModel getUpdateStatusWithBook:book];
            }
            
            [resultArray addObject:book];
        }
    }
    return [resultArray copy];
}

#pragma mark - private Method

/*
+ (NSInteger)getUpdateStatusWithBook:(LRTSDBBookDetailModel *)book {
    NSInteger returnValue = 0;
    
    // 如果userdefault中有保存状态，则直接返回（只保存由1变为0的）
    NSArray *statusArrays = [[NSUserDefaults standardUserDefaults] objectForKey:kBookUpdateStatusForAttentionLabel];
    
    if (nil == statusArrays) {
        statusArrays = [NSMutableArray arrayWithCapacity:0];
        [[NSUserDefaults standardUserDefaults] setObject:statusArrays forKey:kBookUpdateStatusForAttentionLabel];
    }
    
    if ([statusArrays containsObject:@(book.bId)]) {
        returnValue = 0;
    }else {
        NSUInteger intervalDay = 604800;
        id interval = [LMOnlineConfig getConfigParam:kLabelEntityIntervalDays];
        if (interval) {
            intervalDay = [interval integerValue];
        }
        
        if (book.createTime > book.latestFollowLabelTime && [[NSDate date] timeIntervalSince1970]*1000 - book.createTime <= intervalDay*1000) {
            returnValue = 1;
        }else {
            returnValue = 0;
        }
    }
    
    return returnValue;
}
*/

@end
