//
//  NSString+LRTSAddition.m
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import "NSString+LRTSAddition.h"
#import "LRTSGTMBase64.h"
#import <CoreText/CoreText.h>

#define SECONDS_ONEMINITE             60
#define SECONDS_ONEHOUR               3540
#define SECONDS_ONEDAY                84960
#define SECONDS_ONEWEEK               594720
#define SECONDS_ONEMONTH              2592000
#define SECONDS_ONEYEAR               31104000

@implementation NSString (Security)

- (NSString *)BASE64Encode {
    NSData *data = [LRTSGTMBase64 encodeData:[self dataUsingEncoding:NSUTF8StringEncoding]];
    NSString *base64Str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    return base64Str;
}

- (NSString *)BASE64Decode {
    NSData *data = [LRTSGTMBase64 decodeData:[self dataUsingEncoding:NSUTF8StringEncoding]];
    NSString *decodeStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    return decodeStr;
}

@end

@implementation NSString (MD5)

- (NSString *)MD5DigestToNSString {
    //    const char* str = [self UTF8String];
    //    unsigned char result[CC_MD5_DIGEST_LENGTH];
    //    CC_MD5(str, strlen(str), result);
    //    NSMutableString *ret = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH*2];
    //
    //    for(int i = 0; i<CC_MD5_DIGEST_LENGTH; i++) {
    //        [ret appendFormat:@"%02x",result[i]];
    //    }
    //    return ret;
    
    const char *value = [self UTF8String];
    
    unsigned char outputBuffer[CC_MD5_DIGEST_LENGTH];
    CC_MD5(value, (CC_LONG)strlen(value), outputBuffer);
    
    NSMutableString *outputString = [[NSMutableString alloc] initWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for(NSInteger count = 0; count < CC_MD5_DIGEST_LENGTH; count++){
        [outputString appendFormat:@"%02x",outputBuffer[count]];
    }
    
    return outputString;
}

@end


@implementation NSString (JSONParser)

- (id)JSONObject
{
    if (!self) {
        return nil;
    }
    
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSError *error = nil;
    id jsonObject = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:&error];
    
    if (error) {
        //        NSException *e = [NSException exceptionWithName:@"JSONParser Error" reason:error.localizedDescription userInfo:nil];
        //        [e raise];
        jsonObject = nil;
    }
    
    return jsonObject;
}

+ (NSString *)stringWithJSONObject:(id)object
{
    if (!object) {
        return nil;
    }
    
    NSError *error = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:object options:0 error:&error];
    
    if (error) {
        NSException *e = [NSException exceptionWithName:@"JSONParser Error" reason:error.localizedDescription userInfo:nil];
        [e raise];
    }
    
    return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
}

@end

@implementation NSString (Date)

+ (NSDateFormatter *)shareDataFormater {
    static NSDateFormatter *shareDataFormater = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        shareDataFormater = [[NSDateFormatter alloc] init];
    });
    
    return shareDataFormater;
    
}

+ (NSString *)formatSecondsToString:(NSTimeInterval)seconds
{
    NSString *time;
    long secs = (long)seconds;
    int min = (int)(secs/60);
    int sec = (int)secs%60;
    time = [NSString stringWithFormat:@"%02d:%02d",min,sec];
    return time;
}

+ (NSString *)formatSecondsToDate:(NSTimeInterval)seconds hideYear:(BOOL)hide;
{
    NSTimeInterval nowTime = [[NSDate date] timeIntervalSince1970];
    NSString *nowYear = [NSString formatSecondsToStringWithformat:@"yyyy" timeSeconds:nowTime];
    NSString *formatYear = [NSString formatSecondsToStringWithformat:@"yyyy" timeSeconds:seconds];
    if ([formatYear compare:@"2000"] == NSOrderedAscending) {
        //解决低版本升级上来时没有收听时间显示1970-1-1的问题
        return @"";
    }else {
        if ([formatYear compare:nowYear] == NSOrderedAscending && !hide) {
            return [self formatSecondsToStringWithformat:@"yyyy-M-d" timeSeconds:seconds];
        }else {
            return [self formatSecondsToStringWithformat:@"M月d日" timeSeconds:seconds];
        }
    }
}

// 将时间字符串转用NSTimeInterval表示
- (NSTimeInterval)formatStringToSecondsWithformat:(NSString *)formatStr {
    NSTimeInterval timeSeconds = 0;
    
    NSDateFormatter *formattter = [NSString shareDataFormater];
    
    NSTimeZone *formatZone = [NSTimeZone localTimeZone];
    [formattter setTimeZone:formatZone];
    
    [formattter setDateFormat:formatStr];
    NSDate *formatDate = [formattter dateFromString:self];
    
    timeSeconds = [formatDate timeIntervalSince1970];
    
    return timeSeconds;
}

//将NSTimeInterval转化为指定的时间字符串格式
+ (NSString *)formatSecondsToStringWithformat:(NSString *)formatStr timeSeconds:(NSTimeInterval)seconds {
    NSString *formatDateStr = nil;
    
    NSDate *formatDate = [NSDate dateWithTimeIntervalSince1970:seconds];
    
    NSDateFormatter *formattter = [NSString shareDataFormater];
    formattter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"];
    
    NSTimeZone *formatZone = [NSTimeZone localTimeZone];
    [formattter setTimeZone:formatZone];
    
    [formattter setDateFormat:formatStr];
    
    formatDateStr = [formattter stringFromDate:formatDate];
    
    return formatDateStr;
}

+ (NSString *)autoBeforeTimeStringFormatFromSeconds:(NSTimeInterval)seconds
{
    return [self autoBeforeTimeStringFormatFromSeconds:seconds hideYear:NO];
}

+ (NSString *)autoBeforeTimeStringFormatFromSeconds:(NSTimeInterval)seconds hideYear:(BOOL)hide {
    
    return [self autoBeforeTimeStringFormatFromSeconds:seconds hideYear:hide shortYear:NO];
}

+ (NSString *)autoBeforeTimeStringFormatFromSeconds:(NSTimeInterval)seconds hideYear:(BOOL)hide shortYear:(BOOL)shortYear {
    
    NSTimeInterval nowTime = [[NSDate date] timeIntervalSince1970];
    NSTimeInterval interval = nowTime - seconds;
    
    if (interval < 1) // within one minute
    {
        return @"刚刚";
    }
    else if (interval < SECONDS_ONEMINITE) {
        return [NSString stringWithFormat:@"%@秒前",@(floor(interval))];
    }
    else if (interval < SECONDS_ONEHOUR)
    {
        NSInteger minute = floorf(interval / 60);
        return [NSString stringWithFormat:@"%@分钟前", minute==0?@(1):@(minute)];
    }
    else if (interval < 3 * SECONDS_ONEDAY)
    {
        if (interval < SECONDS_ONEDAY) {
            NSInteger hours = floorf(interval / 3600);
            return [NSString stringWithFormat:@"%@小时前", hours==0?@(1):@(hours)];
        }else {
            NSInteger days = floorf(interval / 3600 / 24);
            return [NSString stringWithFormat:@"%@天前", days==0?@(1):@(days)];
        }
        
    }
    else
    {
        NSString *nowYear = [NSString formatSecondsToStringWithformat:@"yyyy" timeSeconds:nowTime];
        NSString *formatYear = [NSString formatSecondsToStringWithformat:@"yyyy" timeSeconds:seconds];
        if ([formatYear compare:@"2000"] == NSOrderedAscending) {
            //解决低版本升级上来时没有收听时间显示1970-1-1的问题
            return @"";
        }else {
            if ([formatYear compare:nowYear] == NSOrderedAscending && !hide) {
                if (shortYear == YES) {
                    return [self formatSecondsToStringWithformat:@"yy-M-d" timeSeconds:seconds];
                }else {
                    return [self formatSecondsToStringWithformat:@"yyyy-M-d" timeSeconds:seconds];
                }
            }else {
                return [self formatSecondsToStringWithformat:@"M月d日" timeSeconds:seconds];
            }
        }
    }
}

+ (NSString *)autoBeforeTimeStringFormatFromDateString:(NSString *)dateString{
    NSTimeInterval interval = [dateString formatStringToSecondsWithformat:@"yyyy-MM-dd HH:mm:ss"];
    return [NSString autoBeforeTimeStringFormatFromSeconds:interval];
}

+ (NSString *)autoMonthAndDayStringFormatFromSeconds:(NSTimeInterval)seconds
{
    NSTimeInterval nowTimeInterval = [[NSDate date] timeIntervalSince1970];
    
    NSInteger oldDays = seconds / SECONDS_ONEDAY;
    NSInteger newDays = nowTimeInterval / SECONDS_ONEDAY;
    
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:seconds];
    NSDateFormatter *formatter = [NSString shareDataFormater];
    formatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"];
    
    if (oldDays == newDays)
    {
        [formatter setDateFormat:@"HH:mm"];
        return [NSString stringWithFormat:@"今天 %@", [formatter stringFromDate:date]];
    }
    else
    {
        NSInteger oldYear = seconds / SECONDS_ONEYEAR;
        NSInteger thisYear = seconds / SECONDS_ONEYEAR;
        
        if (oldYear == thisYear)
        {
            [formatter setDateFormat:@"MM-dd HH:mm"];
            return [formatter stringFromDate:date];
        }
        else
        {
            [formatter setDateFormat:@"yyyy-MM-dd HH:mm"];
            return [formatter stringFromDate:date];
        }
    }
}

+ (NSString *)formatStringWithInterval:(NSTimeInterval)secs {
    long long timeInterval = (long long)secs;
    NSInteger days = timeInterval / (3600 * 24);
    NSInteger hours = timeInterval % (3600 * 24) / 3600;
    NSInteger minutes = timeInterval % 3600 / 60;
    NSInteger seconds = timeInterval % 60;
    
    if (days > 0) {
        if (hours >= 12 || (hours == 11 && minutes >= 30)) {
            return [NSString stringWithFormat:@"%@天", @(days + 1)];
        }
        else {
            return [NSString stringWithFormat:@"%@天", @(days)];
        }
    }
    else {
        if (hours > 0) {
            if (minutes >= 30) {
                return [NSString stringWithFormat:@"%@小时", @(hours + 1)];
            }
            else {
                return [NSString stringWithFormat:@"%@小时", @(hours)];
            }
        }
        else {
            if (seconds >= 30) {
                return [NSString stringWithFormat:@"%@分钟", @(minutes + 1)];
            }
            else {
                return [NSString stringWithFormat:@"%@分钟", @(minutes)];
            }
        }
    }
}

@end

@implementation NSString (FileSize)

+ (NSString *)formatStringWithFileSize:(long long)size
{
    double convertedValue = size * 1e-9;
    int multiplyFactor = 0;
    // 如果自动显示单位的话，取消注释
    //    NSArray *tokens = [NSArray arrayWithObjects:@"bytes"@"KB",@"MB",@"GB",@"TB",nil];
    
    while (convertedValue > 1024) {
        convertedValue /= 1024;
        multiplyFactor++;
    }
    convertedValue *= 1024;
    return [NSString stringWithFormat:@"%2.1fM",convertedValue];
}

@end

@implementation NSString (FormatNumber)

+ (NSString *)formatStringWithNumber:(long)number showDecimal:(BOOL)isShowDecimal {
    NSString *formatStr = @"";
    
    double wan = 1e+4 * 1.0;
    double yi = 1e+8 * 1.0;
    
    if (isShowDecimal) {
        if (number < wan) {
            formatStr = [NSString stringWithFormat:@"%@",@(number)];
        }else if(number < yi) {
            formatStr = [NSString stringWithFormat:@"%.1f%@",number/wan,@"万"];
        }else {
            formatStr = [NSString stringWithFormat:@"%.1f%@",number/yi,@"亿"];
        }
    }
    else {
        if (number < wan) {
            formatStr = [NSString stringWithFormat:@"%@",@(number)];
        }else if(number < yi) {
            formatStr = [NSString stringWithFormat:@"%.0f%@",number/wan,@"万"];
        }else {
            formatStr = [NSString stringWithFormat:@"%.0f%@",number/yi,@"亿"];
        }
    }
    
    
    return formatStr;
}

+ (NSString *)formatStringWithNumber:(long)number {
    return [NSString formatStringWithNumber:number showDecimal:YES];
}

+ (NSString *)formatDoubleValue:(NSNumber *)doubleValue withAccuracy:(NSInteger)accuracy {
    return [self formatDoubleValue:doubleValue withAccuracy:accuracy mode:NSNumberFormatterRoundDown];
}

+ (NSString *)formatDoubleValue:(NSNumber *)doubleValue withAccuracy:(NSInteger)accuracy mode:(NSNumberFormatterRoundingMode)mode {
    NSNumberFormatter *format = [[NSNumberFormatter alloc] init];
    format.numberStyle = NSNumberFormatterDecimalStyle;
    format.maximumFractionDigits = accuracy;
    format.roundingMode = mode;
    
    NSString *ret = [format stringFromNumber:doubleValue];
    return ret;
}

@end

@implementation NSString (Length)

- (NSUInteger)unicodeLength
{
    NSUInteger asciiLength = 0;
    for (NSUInteger i = 0; i < self.length; i++) {
        unichar uc = [self characterAtIndex: i];
        asciiLength += isascii(uc) ? 1 : 2;
    }
    return asciiLength;
}

@end

@implementation NSString (Emoji)

+ (BOOL)stringContainsEmoji:(NSString *)string
{
    __block BOOL returnValue = NO;
    
    [string enumerateSubstringsInRange:NSMakeRange(0, [string length]) options:NSStringEnumerationByComposedCharacterSequences usingBlock:^(NSString *substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop) {
        const unichar hs = [substring characterAtIndex:0];
        // surrogate pair
        if (0xd800 <= hs && hs <= 0xdbff) {
            if (substring.length > 1) {
                const unichar ls = [substring characterAtIndex:1];
                const int uc = ((hs - 0xd800) * 0x400) + (ls - 0xdc00) + 0x10000;
                if (0x1d000 <= uc && uc <= 0x1f77f) {
                    returnValue = YES;
                }
            }
        } else if (substring.length > 1) {
            const unichar ls = [substring characterAtIndex:1];
            if (ls == 0x20e3) {
                returnValue = YES;
            }
            
        } else {
            // non surrogate
            if (0x2100 <= hs && hs <= 0x27ff) {
                returnValue = YES;
            } else if (0x2B05 <= hs && hs <= 0x2b07) {
                returnValue = YES;
            } else if (0x2934 <= hs && hs <= 0x2935) {
                returnValue = YES;
            } else if (0x3297 <= hs && hs <= 0x3299) {
                returnValue = YES;
            } else if (hs == 0xa9 || hs == 0xae || hs == 0x303d || hs == 0x3030 || hs == 0x2b55 || hs == 0x2b1c || hs == 0x2b1b || hs == 0x2b50) {
                returnValue = YES;
            }
        }
    }];
    
    return returnValue;
}


@end

@implementation NSString (URLString)

+ (NSString *)createURLStringWithPath:(NSString *)path andParams:(NSDictionary *)params {
    
    if (!path) {
        return nil;
    }
    
    NSMutableString * mutStr = [NSMutableString stringWithString:path];
    
    [mutStr appendString:@"?"];
    
    NSInteger count = params.allKeys.count;
    NSArray * allKeys = params.allKeys;
    
    // 对allKeys中的元素进行排序（ascii升序）
    NSSortDescriptor *sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"description" ascending:YES selector:@selector(compare:)];
    NSArray *allKeysOrder = [allKeys sortedArrayUsingDescriptors:@[ sortDescriptor ]];
    
    for (int i = 0; i < count; i++) {
        NSString * key = allKeysOrder[i];
        [mutStr appendFormat:@"%@=%@", key, params[key]];
        if (i < count - 1) {
            [mutStr appendString:@"&"];
        }
    }
    return [mutStr copy];
}

static NSString * const kAFCharactersToBeEscapedInQueryString = @":/?&=;+!@#$()',*";

static NSString * AFPercentEscapedQueryStringValueFromStringWithEncoding(NSString *string, NSStringEncoding encoding) {
    return (__bridge_transfer  NSString *)CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault, (__bridge CFStringRef)string, NULL, (__bridge CFStringRef)kAFCharactersToBeEscapedInQueryString, CFStringConvertNSStringEncodingToEncoding(encoding));
}

+ (NSString *)createEncodeURLStringWithPath:(NSString *)path andParams:(NSDictionary *)params {
    if (!path) {
        return nil;
    }
    
    NSMutableString * mutStr = [NSMutableString stringWithString:path];
    
    [mutStr appendString:@"?"];
    
    NSInteger count = params.allKeys.count;
    NSArray * allKeys = params.allKeys;
    
    // 对allKeys中的元素进行排序（ascii升序）
    NSSortDescriptor *sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"description" ascending:YES selector:@selector(compare:)];
    NSArray *allKeysOrder = [allKeys sortedArrayUsingDescriptors:@[ sortDescriptor ]];
    
    for (int i = 0; i < count; i++) {
        NSString * key = allKeysOrder[i];
        [mutStr appendFormat:@"%@=%@", key, AFPercentEscapedQueryStringValueFromStringWithEncoding([params[key] description], NSUTF8StringEncoding)];
        if (i < count - 1) {
            [mutStr appendString:@"&"];
        }
    }
    return [mutStr copy];
}

@end

@implementation NSString (LRTSAddition)

// 将字符串数组用指定字符组合成新的字符串
+ (NSString *)componentsUnionStrArray:(NSArray *)strArray withString:(NSString *)unionStr {
    if (![unionStr isKindOfClass:[NSString class]]) {
        return nil;
    }
    
    NSMutableString *afterComponentStr = nil;
    
    for (id arrayValue in strArray) {
        if ([arrayValue isKindOfClass:[NSNumber class]]) {
            NSString *value = [arrayValue stringValue];
            
            if (nil == afterComponentStr) {
                afterComponentStr = [NSMutableString new];
                [afterComponentStr appendString:value];
            }else {
                [afterComponentStr appendFormat:@"%@%@",unionStr,value];
            }
        }
    }
    
    return afterComponentStr;
}

- (NSString *)stringByRemoveBlankLins {
    NSArray * lines = [self componentsSeparatedByString:@"\n"];
    NSMutableArray * newLines = [[NSMutableArray alloc] init];
    for (NSString * lineStr in lines) {
        if (!lineStr.length) {
            continue;
        }
        [newLines addObject:[NSString stringWithFormat:@"%@", lineStr]];
    }
    NSString * result = [newLines componentsJoinedByString:@"\n"];
    if (!result) {
        result = @"";
    }
    return result;
}

@end


@implementation NSString (WebViewUrl)

- (NSString *)converToWebViewUrl {
    if ([self rangeOfString:@"?"].location != NSNotFound) {
        return [self stringByAppendingString:@"&lazyref=app&embed=app"];
    }
    else {
        return [self stringByAppendingString:@"?lazyref=app&embed=app"];
    }
}

@end


@implementation NSString (Calculate)

- (CGSize)sizeWithAttributes:(NSDictionary *)attrs constrainedToSize:(CGSize)size {
    NSAttributedString *attributedString = [[NSAttributedString alloc] initWithString:self
                                                                           attributes:attrs];
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString((__bridge CFAttributedStringRef) attributedString);
    CGSize fitSize = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, CFRangeMake(0, 0), NULL, size, NULL);
    
    CFRelease(framesetter);
    
    return fitSize;
}

- (CGSize)sizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size {
    NSMutableParagraphStyle *style = [[NSMutableParagraphStyle alloc] init];
    style.lineBreakMode = NSLineBreakByCharWrapping;
    return [self boundingRectWithSize:size options:NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading attributes:@{NSFontAttributeName:font, NSParagraphStyleAttributeName:style} context:NULL].size;
}

- (BOOL)isPureNumberStr{
    NSString *trimmedStr = [self stringByTrimmingCharactersInSet:[NSCharacterSet decimalDigitCharacterSet]];
    return trimmedStr.length==0;
}

@end

@implementation NSString (Order)

+ (NSString *)paymentV3OutOrderNoWithUserId:(NSInteger)userId {
    NSAssert(userId > 0, @"userId 不能够小于1");
    NSTimeInterval time = [[NSDate date] timeIntervalSince1970];
    NSString *uniqueOrderNo = [NSString stringWithFormat:@"i:%ld-%f", userId, time];
    return uniqueOrderNo;
}

+(NSString *)chineseCharacterConvertFromArebicNumStr:(NSString *)arebicNumStr{
    NSString *str = arebicNumStr;
    NSArray *arabic_numerals = @[@"1",@"2",@"3",@"4",@"5",@"6",@"7",@"8",@"9",@"0"];
    NSArray *chinese_numerals = @[@"一",@"二",@"三",@"四",@"五",@"六",@"七",@"八",@"九",@"零"];
    NSArray *digits = @[@"个",@"十",@"百",@"千",@"万",@"十",@"百",@"千",@"亿",@"十",@"百",@"千",@"兆"];
    NSDictionary *dictionary = [NSDictionary dictionaryWithObjects:chinese_numerals forKeys:arabic_numerals];
    
    NSMutableArray *sums = [NSMutableArray array];
    for (int i = 0; i < str.length; i ++) {
        NSString *substr = [str substringWithRange:NSMakeRange(i, 1)];
        NSString *a = [dictionary objectForKey:substr];
        NSString *b = digits[str.length -i-1];
        NSString *sum = [a stringByAppendingString:b];
        if ([a isEqualToString:chinese_numerals[9]])
        {
            if([b isEqualToString:digits[4]] || [b isEqualToString:digits[8]])
            {
                sum = b;
                if ([[sums lastObject] isEqualToString:chinese_numerals[9]])
                {
                    [sums removeLastObject];
                }
            }else
            {
                sum = chinese_numerals[9];
            }
            
            if ([[sums lastObject] isEqualToString:sum])
            {
                continue;
            }
        }
        
        [sums addObject:sum];
    }
    
    NSString *sumStr = [sums  componentsJoinedByString:@""];
    NSString *chinese = [sumStr substringToIndex:sumStr.length-1];
    
    if ([chinese hasPrefix:@"一十"]) {
        chinese = [chinese substringFromIndex:1];
    }
    
    return chinese;
}

@end

@implementation NSString (Reverse)

+ (NSString *)reverseString:(NSString *)reverseStr {
    if (nil == reverseStr || reverseStr.length == 0) {
        return @"";
    }
    
    NSMutableString * returnStr = [NSMutableString string];
    
    for (int i = 0; i < reverseStr.length; i++) {
        unichar c = [reverseStr characterAtIndex:reverseStr.length- i -1];
        [returnStr appendFormat:@"%c",c];
    }
    
    return returnStr;
}

@end

@implementation NSString (Range)

+ (BOOL)containNumber:(NSInteger)number inRangeString:(NSString *)rangeString {
    NSArray *list = [rangeString componentsSeparatedByString:@";"];
    for (NSString *string in list) {
        NSRange range = [self rangeWtihString:string];
        if (number >= range.location && number < range.location + range.length) {
            return YES;
        }
    }
    return NO;
}

/// 将字符串转换为range，例如：'120'转为NSMakeRange(120, 1), '[120, 130)'转为NSMakeRange(120, 10)
+ (NSRange)rangeWtihString:(NSString *)string {
    if (![string hasPrefix:@"["] && ![string hasPrefix:@"("]) {
        NSInteger value = [string integerValue];
        if (value == 0) {
            return NSMakeRange(NSNotFound, 0);
        }
        else {
            return NSMakeRange(value, 1);
        }
    }
    else {
        NSArray *numbers = [string componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"[(,)]"]];
        NSParameterAssert(numbers.count == 4);
        NSInteger firstNumber = [[numbers objectAtIndex:1] integerValue];
        NSInteger secondNumber = [[numbers objectAtIndex:2] integerValue];
        NSParameterAssert(secondNumber >= firstNumber);
        NSInteger locate = NSNotFound;
        NSInteger length = 0;
        if ([string hasPrefix:@"["]) {
            locate = firstNumber;
        }
        else if([string hasPrefix:@"("]) {
            locate = firstNumber + 1;
        }
        if ([string hasSuffix:@"]"]) {
            length = secondNumber - firstNumber + 1;
        }
        else if([string hasSuffix:@")"]) {
            length = secondNumber - firstNumber;
        }
        return NSMakeRange(locate, length);
    }
}

+ (NSString *)formatStringWithTenThousandThresholdWithNumber:(NSInteger)number {
    return [self formatStringWithNumber:number thresholds:@[@(1), @(10000)] suffixTexts:@[@"万", @"亿"] step:10000];
}

+ (NSString *)formatStringWithNumber:(NSInteger)num thresholds:(NSArray *)thresholds suffixTexts:(NSArray *)suffixs step:(NSInteger)step {
    
    if ((thresholds.count != suffixs.count) ||
        (thresholds.count == 0 && suffixs.count == 0)) {
        return nil;
    }
    
    NSInteger threshold = 1;
    float convertCount = num;
    BOOL matched = NO;
    NSString *suffix = @"";
    
    for (NSInteger i = thresholds.count - 1; i >= 0; i--) {
        threshold = 10000 * [thresholds[i] integerValue];
        if (num >= threshold) {
            double numerator = threshold * 1.0;
            suffix = suffixs[i];
            convertCount = num / numerator;
            matched = YES;
            break;
        }
    }
    if (!matched) {
        return [NSString stringWithFormat:@"%d%@", (int)convertCount, suffix];
    }
    return [NSString stringWithFormat:@"%.1f%@", convertCount, suffix];
}

@end

@implementation NSString (AssetsLibrary)

- (BOOL)isAssetsLibraryUrl {
    NSURL *url = [NSURL URLWithString:self];
    return [url.scheme isEqualToString:@"assets-library"];
}

@end

@implementation NSString (Ids)

+ (NSString *)stringFroIds:(NSArray *)ids {
    if (!ids.count) return nil;
    NSString *tempIds = [ids componentsJoinedByString:@","];
    return [NSString stringWithFormat:@"[%@]",tempIds?:@""];
}

@end
