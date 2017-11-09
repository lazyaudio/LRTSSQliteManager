//
//  LRTSDownloadState.h
//  Pods
//
//  Created by JackJin on 2017/11/9.
//

// 下载基础类的状态
typedef NS_ENUM(NSInteger, LMDownloadOperationState){
    LMDonwloadOperationUnknown          = 0,
    LMDownloadOperationReadyState       = 1,
    LMDownloadOperationExecutingState   = 2,
    LMDownloadOperationPausedState      = 3,
    LMDownloadOperationFinishedState    = 4,
    LMDownloadOperationErrorState       = 5
};

// 下载状态类型枚举
typedef NS_ENUM(NSInteger, DownloadStatus) {
    DownloadStatusNone        = 0,// 未下载
    DownloadStatusWaited      = 1,// 下载等待
    DownloadStatusDownloading = 2,// 下载中
    DownloadStatusPaused      = 3,// 下载暂停
    DownloadStatusCompleted   = 4,// 下载完成
    DownloadStatusPreparing   = 5,// 正在获取新地址
};
