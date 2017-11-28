#
# Be sure to run `pod lib lint LRTSSQliteManager.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LRTSSQliteManager'
  s.version          = '0.1.1'
  s.summary          = 'LRTSSQliteManager 实现对公司的数据库操作的 SQL 的增删改查的操作语句替换的一种解决方案'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
依据微信的 WCDB 的开源函数库来实现对于数据库 SQL 中增删改和多种情况下的查找情况，来解决 “胶水代码问题”
                       DESC

  s.homepage         = 'https://github.com/boilwater/LRTSSQliteManager'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'boilwater' => 'baill@adnonstop.com' }
  s.source           = { :git => 'https://github.com/boilwater/LRTSSQliteManager.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'LRTSSQliteManager/Classes/**/*'
  
  # s.resource_bundles = {
  #   'LRTSSQliteManager' => ['LRTSSQliteManager/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
    s.dependency  'WCDB'
end
