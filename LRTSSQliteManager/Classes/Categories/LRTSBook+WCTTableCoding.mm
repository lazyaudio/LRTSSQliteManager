//
//  LRTSBook+WCTTableCoding.m
//  Kiwi
//
//  Created by Jack Bai on 2017/11/1.
//

#import "LRTSBook+WCTTableCoding.h"

//@interface LRTSBook ()
//
//@property(readwrite, nonatomic) NSString *cover;
//
//@end

@implementation LRTSBook (WCTTableCoding)

- (id)initWithDict:(NSDictionary *)data {
    if (self && data) {
        self.bId = [[data valueForKey:@"id"] integerValue];
        self.hot = [[data valueForKey:@"hot"] integerValue];
        self.sections = [[data valueForKey:@"sections"] integerValue];
        
        self.state = [[data valueForKey:@"state"] integerValue];
        
        self.name = [data valueForKey:@"name"];
        self.author = [data valueForKey:@"author"];
        self.announcer = [data valueForKey:@"announcer"];
        self.cover = [data valueForKey:@"cover"];
        self.payType = (LMPriceModelPayType)
                        [[data valueForKey:@"payType"] integerValue] ;
        self.freeEndTime = [[data objectForKey:@"freeEndTime"] doubleValue];
    }
    return self;
}

- (void)setName:(NSString *)name {
    if ([name isKindOfClass:[NSString class]] && name.length > 0) {
        self.name = [name copy];
    }else {
        self.name = @"";
    }
}

- (void)setAnnouncer:(NSString *)announcer {
    if ([announcer isKindOfClass:[NSString class]] && announcer.length > 0) {
        self.announcer = [announcer copy];
    }else {
        self.announcer = @"佚名";
    }
}

- (void)setAuthor:(NSString *)author {
    if ([author isKindOfClass:[NSString class]] && author.length > 0) {
        self.author = [author copy];
    }else {
        self.author = @"佚名";
    }
}

- (BOOL)isEqual:(id)object
{
    if (![object isKindOfClass:[self class]]) {
        return NO;
    }
    
    LRTSBook *book = (LRTSBook *)object;
    if (book.bId == self.bId) {
        return YES;
    }
    return NO;
}

- (void)setCover:(NSString *)cover {
    if ([cover isKindOfClass:[NSString class]]) {
        self.cover = cover;
    }else {
        self.cover = @"";
    }
}

- (NSString *)cover {
    if ([self.cover rangeOfString:@"180x254"].location != NSNotFound) {
        return self.cover;
    }
    else {
        return [self getNewImageUrlWithTail:@"180x254" fromOldImageUrl:self.cover];
    }
}

- (BOOL)isOverEndTime {
    NSTimeInterval now = [[NSDate date] timeIntervalSince1970];
    NSTimeInterval endTime = self.freeEndTime;
    return now * 1000 >= endTime;
}

#pragma mark - privated Methods

- (NSString *)getNewImageUrlWithTail:(NSString *)tailStr fromOldImageUrl:(NSString *)urlStr {
    if (urlStr.length <= 0 || [urlStr isEqual:[NSNull null]] || ![urlStr isKindOfClass:[NSString class]]) {
        return @"";
    }
    
    if ([tailStr isEqual:[NSNull null]] || ![tailStr isKindOfClass:[NSString class]]) {
        return urlStr;
    }
    
    NSString *formatTailStr = [NSString stringWithFormat:@"_%@.",tailStr];
    
    NSRange makerange = [urlStr rangeOfString:@"." options:NSBackwardsSearch];
    NSString *newImageUrlStr = [urlStr stringByReplacingOccurrencesOfString:@"." withString:formatTailStr options:NSBackwardsSearch range:makerange];
    
    return [newImageUrlStr stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
}

@end
