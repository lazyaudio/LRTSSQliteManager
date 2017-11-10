//
//  LRTSCellDataSourceProtocol.h
//  Pods
//
//  Created by JackJin on 2017/11/10.
//

#ifndef LRTSCellDataSourceProtocol_h
#define LRTSCellDataSourceProtocol_h

@class LRTSTagModel;

@protocol LRTSCellDataSourceDelegate <NSObject>

- (NSString *)defaultCoverStr;
- (NSString *)coverUrlStr;
- (NSString *)titleStr;
- (NSString *)describeStr;
- (NSString *)announcerStr;
- (NSString *)authorStr;
- (NSUInteger)playHot;
- (NSUInteger) stateMark;
- (LRTSTagModel *)tagMark;

@optional
- (NSUInteger)dataSourceId;
- (NSString *)categoryNameStr;


@end



#endif /* LRTSCellDataSourceProtocol_h */
