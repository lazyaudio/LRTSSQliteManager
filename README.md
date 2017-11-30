# LRTSSQliteManager

[![CI Status](http://img.shields.io/travis/boilwater/LRTSSQliteManager.svg?style=flat)](https://travis-ci.org/boilwater/LRTSSQliteManager)
[![Version](https://img.shields.io/cocoapods/v/LRTSSQliteManager.svg?style=flat)](http://cocoapods.org/pods/LRTSSQliteManager)
[![License](https://img.shields.io/cocoapods/l/LRTSSQliteManager.svg?style=flat)](http://cocoapods.org/pods/LRTSSQliteManager)
[![Platform](https://img.shields.io/cocoapods/p/LRTSSQliteManager.svg?style=flat)](http://cocoapods.org/pods/LRTSSQliteManager)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

* 在 `WCDB` 基础之上进行再次封装，需要瞒住版本：`iOS 7.0` 及其之后版本
* `Xcode 8.0` 及其之后版本
* `Model` 和 调用的类需要 `Objective-C++`

## Installation

`LRTSSQliteManager` 是基于第三方开源库 `WCDB` 之上来进行解决在数据操作过程中使用大量胶水代码和防止反注入问题，在使用时需要在项目中加入 `WCDB` 第三方开源库代码。

* 使用 `CocoaPods` 来进行安装：
<ul>
<li>(1)安装[CocoaPods](https://guides.cocoapods.org/using/getting-started.html)</li>
<li>(2)通过 `pod repo update` 来更新 `LRTSSQliteManager` 版本</li>
<li>(3)在项目的 `podfile` 对应的 `target` 中添加 `pod 'LRTSSQliteManager'`，并且执行 `pod install --verbose`</li>
<li>(4)在项目中会会生成 `.xcworkspace` 的运行工程</li>
<li>(5)在需要使用的项目中引入 `#import <LRTSSQliteManager/LRTSOperation>` 来进行封装对数据库多种操作</li>
<li>(6)在使用 `LRTSOperation` 过程中会引入 `C++` 文件，项目的后缀由 `.m` 变为 `.mm`</li>
</ul>

## 基础接口使用说明

在基础接口中包括常用的数据操作的增、删、改和查。详细的接口内容可以参考：[`LRTSOperation.h`](https://github.com/lazyaudio/LRTSSQliteManager/blob/master/LRTSSQliteManager/Classes/SqliteOperation/LRTSOperation.h)

### `Model` 实现数据绑定

> 在 Model 数据绑定需要三个文件：**`BookDetail.h`、`BookDetail.m`和`BookDetail+WCTTableCoding`**

* **`BookDetail.h`数据解析**

```objc
#import <Foundation/Foundation.h>
#import "LRTSDBModel.h"

//Model 继承与 LRTSDBModel 
@interface BookDetail : LRTSDBModel

@property(assign, nonatomic) NSInteger bookID;
@property(strong, nonatomic) NSString *bookName;
@property(strong, nonatomic) NSDate *upLoad;
@property(copy, nonatomic) NSString *pubilsher;

//WCDB_PROPERTY(BookDetail);

@end
```

* **`BookDetail.m`属性综合**

```objc
#import "BookDetail.h"
#import <WCDB/WCDB.h>

@implementation BookDetail

//数据库名字的 WING 绑定
WCDB_IMPLEMENTATION(BookDetail)

//Model 类中属性 WING 到表中列名
WCDB_SYNTHESIZE(BookDetail, bookID)
WCDB_SYNTHESIZE(BookDetail, bookName)
WCDB_SYNTHESIZE(BookDetail, upLoad)
WCDB_SYNTHESIZE(BookDetail, pubilsher)

//Model 类中属性 WING 到数据表中重命名 
WCDB_SYNTHESIZE_COLUMN(BookDetail, pubilsher, @"出版")

//设置 bookID 为 UNIQUE 
WCDB_UNIQUE(BookDetail, bookID)

@end
```

* **`BookDetail+WCTTableCoding`属性声明**

```objc
#import "BookDetail.h"
#import <WCDB/WCDB.h>

@interface BookDetail (WCTTableCoding)<WCTTableCoding>

//属性声明的绑定
WCDB_PROPERTY(bookID)
WCDB_PROPERTY(bookName)
WCDB_PROPERTY(upLoad)
WCDB_PROPERTY(pubilsher)

@end
```


### `LRTSOperation` 接口使用

* 数据表创建代码实例

```objc
//定义创建数据库的名字：lazyAudioPlayer.db
#define LAZY_AUDIO_PLAYER @"lazyAudioPlayer"

@interface LRTSDBOperation ()

@property (nonatomic, strong) LRTSOperation *operation;

@property (nonatomic, strong) BookDetail *bookDetail;

@end

//Lazy Loading Operation 的操作
//创建数据库 lazyAudioPlayer.db，默认创建地址：Documents/
- (LRTSOperation *)operation {
    if (!_operation) {
        _operation = [[LRTSOperation alloc] initWCDBWithName:LAZY_AUDIO_PLAYER];
    }
    return _operation;
}

//Lazy Loading BookDetail 书籍详细 Model
- (BookDetail *)bookDetail {
    if (!_bookDetail) {
        _bookDetail = [[BookDetail alloc] init];
    }
    return _bookDetail;
}

//创建 BookDetail ROM 绑定的 Table 表，默认表明是：BookDetail
[self.operation createTableWithDBModel:self.bookDetail];
```

* 数据库添加或者是更新操作代码实例

```objc
// model 是 BookDetail 实例化的对象
[self.operation insertOrReplaceObject:model into:NSStringFromClass(BookDetail.class)];
```


* 数据库删除操作代码实例

```objc
// BookDetail.bookID 是删除的条件
[self.operation deleteObjectsFromTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
```


* 数据库更新操作代码实例

```objc
//BookDetail.bookName 是要更新的字段
//model 是要更新内容的实例化变量
//BookDetail.bookID 是更新在具体的字段
[self.operation updateRowsInTable:NSStringFromClass(BookDetail.class) onValue:BookDetail.bookName withObject:model where:BookDetail.bookID == bookId];
```


* 数据库查找操作代码实例

```objc
//BookDetail.bookID 需要查找的条件
[self.operation getObjectsForTable:NSStringFromClass(BookDetail.class) where:BookDetail.bookID == bookId];
```

* 多个数据表数据查询

```objc
//{BookDetail.bookName.inTable(nameBookDetail), Book.autor.inTable(nameBook)} 获取数据的列数
//@[nameBook, nameBookDetail] 获取内容来自的表格
//Book.bookID 来自查找的条件
NSString *nameBookDetail = NSStringFromClass(BookDetail.class);
NSString *nameBook = NSStringFromClass(Book.class);
[self.operation selectRowsOnResults:{BookDetail.bookName.inTable(nameBookDetail), Book.autor.inTable(nameBook)} fromTables:@[nameBook, nameBookDetail] where:Book.bookID == 1000];
```


## Author

boilwater, baill@adnonstop.com

## License

LRTSSQliteManager is available under the MIT license. See the LICENSE file for more info.
