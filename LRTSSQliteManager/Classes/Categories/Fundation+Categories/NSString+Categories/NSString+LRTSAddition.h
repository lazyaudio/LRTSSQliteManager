//
//  NSString+LRTSAddition.h
//  Kiwi
//
//  Created by JackJin on 2017/11/8.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>
#import <CommonCrypto/CommonDigest.h>

#define DateFormatterStr @"yyyy-MM-dd HH:mm:ss"


@interface NSString (Base64)

- (NSString *)BASE64Encode;

- (NSString *)BASE64Decode;

@end

@interface NSString (MD5)

- (NSString *)MD5DigestToNSString;

@end

@interface NSString (JSONParser)

- (id)JSONObject;

+ (NSString *)stringWithJSONObject:(id)object;

@end

@interface NSString (Date)

+ (NSDateFormatter *)shareDataFormater;

// 将秒数表示的时间格式化成字符串
+ (NSString *)formatSecondsToString:(NSTimeInterval)seconds;

// 将秒数转化为日期格式
+ (NSString *)formatSecondsToDate:(NSTimeInterval)seconds hideYear:(BOOL)hide;

// 将时间字符串转用NSTimeInterval表示
- (NSTimeInterval)formatStringToSecondsWithformat:(NSString *)formatStr;

//将NSTimeInterval转化为指定的时间字符串格式
+ (NSString *)formatSecondsToStringWithformat:(NSString *)formatStr timeSeconds:(NSTimeInterval)seconds;

// 将秒数表示的时间格式化成多少时间前
//+ (NSString *)formatSecondsIntervalFromNow:(NSTimeInterval)seconds;

/**
 *  获取自动格式化的时间字符串
 *
 *  @param seconds 需要格式化的时间（从1970开始的秒数）
 *  @return 如果是今天内发布则显示为（今天 时：分），
 *          如果不是今天但是是今年内发布则显示为（月－日 时：分），
 *          如果不是今年发布的则显示为（年－月－日 时：分）
 */
+ (NSString *)autoMonthAndDayStringFormatFromSeconds:(NSTimeInterval)seconds;
/**
 *  获取自动格式化为多少＊前的时间字符串（＊表示分钟，小时，天）
 *
 *  @param seconds 需要格式化的时间（从1970开始的秒数）
 *  @return 多少分钟前，多少小时前，多少天前
 */
+ (NSString *)autoBeforeTimeStringFormatFromSeconds:(NSTimeInterval)seconds;

+ (NSString *)autoBeforeTimeStringFormatFromSeconds:(NSTimeInterval)seconds hideYear:(BOOL)hide;

+ (NSString *)autoBeforeTimeStringFormatFromSeconds:(NSTimeInterval)seconds hideYear:(BOOL)hide shortYear:(BOOL)shortYear;

/**
 *  获取自动格式化为多少＊前的时间字符串（＊表示分钟，小时，天）
 *
 *  @param dateString 日期字符串格式: yyyy-MM-dd HH:mm:ss
 *  @return 多少分钟前，多少小时前，多少天前
 */
+ (NSString *)autoBeforeTimeStringFormatFromDateString:(NSString *)dateString;

/**
 *  将时间间隔转换成对应的字符串
 *
 *  转换格式："XX天"，"XX小时","XX分钟"，时间四舍五入
 */
+ (NSString *)formatStringWithInterval:(NSTimeInterval)secs;
@end


@interface NSString (FileSize)
/**
 *  装换文件大小为人可读的字符串
 *  @param size 文件大小
 *  @return 可读的字符串（如 2.0M）
 */
+ (NSString *)formatStringWithFileSize:(long long)size;
@end

@interface NSString (FormatNumber)

+ (NSString *)formatStringWithNumber:(long)number showDecimal:(BOOL)isShowDecimal;
+ (NSString *)formatStringWithNumber:(long)number;

/**
 *  根据设置的精度返回格式化后的浮点数，即如果精度为1，则返回的字符串最多有一位小数或没有小数位
 *  例如：精度为1，输入1.39，则返回“1.4”，精度为1，输入1.08，则返回“1”
 *
 *  注意：跟金额相关的计算请务必使用double类型
 *
 *  @param doubleValue 要格式化的浮点数
 *  @param accuracy    精度，即小数位数
 *
 *  @return 格式化后的浮点数
 */
+ (NSString *)formatDoubleValue:(NSNumber *)doubleValue withAccuracy:(NSInteger)accuracy;

+ (NSString *)formatDoubleValue:(NSNumber *)doubleValue withAccuracy:(NSInteger)accuracy mode:(NSNumberFormatterRoundingMode)mode;

@end

@interface NSString (Length)

- (NSUInteger)unicodeLength;

@end

@interface NSString (Emoji)

/**
 *  判断字符串中是否有Emoji表情
 *
 *  @param string 要判断的字符串
 *
 *  @return 判断结果
 */
+ (BOOL)stringContainsEmoji:(NSString *)string;

@end

@interface NSString (URLString)

/**
 *  更具URL路径和参数，创建url
 *  例如：路径为/yyting/getGroupList.action
 *  参数为:{"groupId":"123", "num":"111"}
 *  则返回:"/yyting/getGroupList.action?groupId=123&num=111"
 *
 *  @param path   url路径
 *  @param params 参数
 *
 *  @return 创建好的URLString
 */
+ (NSString *)createURLStringWithPath:(NSString *)path andParams:(NSDictionary *)params;

// batch request的时候调用，用来encode批量的url，批量url中有中文的话，服务器会验证错误（读取的中文不对）
+ (NSString *)createEncodeURLStringWithPath:(NSString *)path andParams:(NSDictionary *)params;

@end


@interface NSString (LRTSAddition)

// 将字符串数组用指定字符组合成新的字符串
+ (NSString *)componentsUnionStrArray:(NSArray *)strArray withString:(NSString *)unionStr;

/**
 *  获取删除空行后的字符串
 *
 */
- (NSString *)stringByRemoveBlankLins;

@end

@interface NSString (WebViewUrl)

/**
 *  将字符串url转换为适用于webView的url（添加参数"lazyref=app&embed=app"）
 *
 *  @return 返回转换后的字符串
 */
- (NSString *)converToWebViewUrl;

@end


@interface NSString (Calculate)

- (CGSize)sizeWithAttributes:(NSDictionary *)attrs constrainedToSize:(CGSize)size;

// 计算文字所占大小
- (CGSize)sizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size;
- (BOOL)isPureNumberStr;

@end


@interface NSString (Order)

+ (NSString *)paymentV3OutOrderNoWithUserId:(NSInteger)userId;

+ (NSString *)chineseCharacterConvertFromArebicNumStr:(NSString *)arebicNumStr;

@end

@interface NSString (Reverse)

+ (NSString *)reverseString:(NSString *)reverseStr;

@end

@interface NSString (Range)
/// 判断某个数字是否在字符串的范围内，字符串的格式为“200；206；[300,399)；[400,499)”
+ (BOOL)containNumber:(NSInteger)number inRangeString:(NSString *)rangeString;
/// 格式化数字，比如10000转成1万。number：要转换的数字， thresholds：大于该数字就会转换，比如（10000，100000000）15000，就会转成1.5万。setp：范围的区间步长，比如1万和1亿之间的步长是10000
+ (NSString *)formatStringWithNumber:(NSInteger)number thresholds:(NSArray *)thresholds suffixTexts:(NSArray *)suffixs step:(NSInteger)step;

+ (NSString *)formatStringWithTenThousandThresholdWithNumber:(NSInteger)number;
@end

/// AssetsLibrary相关的操作
@interface NSString (AssetsLibrary)
/// 判断是否是assets-library地址，以assets-library开头
- (BOOL)isAssetsLibraryUrl;
@end

@interface NSString (Ids)
+ (NSString *)stringFroIds:(NSArray *)ids;


@end



