//
//  LRTSDownloadState.h
//  Pods
//
//  Created by JackJin on 2017/11/9.
//

// 下载基础类的状态
typedef NS_ENUM(NSInteger, LRTSDownloadOperationState){
    LMDonwloadOperationUnknown          = 0,
    LRTSDownloadOperationStateReadyState       = 1,
    LRTSDownloadOperationStateExecutingState   = 2,
    LRTSDownloadOperationStatePausedState      = 3,
    LRTSDownloadOperationStateFinishedState    = 4,
    LRTSDownloadOperationStateErrorState       = 5
};

// 下载状态类型枚举
typedef NS_ENUM(NSInteger, LRTSDownloadStatus) {
    LRTSDownloadStatusNone        = 0,// 未下载
    LRTSDownloadStatusWaited      = 1,// 下载等待
    LRTSDownloadStatusDownloading = 2,// 下载中
    LRTSDownloadStatusPaused      = 3,// 下载暂停
    LRTSDownloadStatusCompleted   = 4,// 下载完成
    LRTSDownloadStatusPreparing   = 5,// 正在获取新地址
};
