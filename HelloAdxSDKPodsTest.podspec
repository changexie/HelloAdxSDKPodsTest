Pod::Spec.new do |s|
  s.authors 	 = "HelloAdx"
  s.name         = "HelloAdxSDKPodsTest"
  s.version      = "1.0.0"
  s.summary      = "HelloAdx iOS SDK"
  s.description  = "iOS library for HelloAdx advertising related business."
  s.homepage     = "http://www.helloadx.com/"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "HelloAdx" => "helloadx@helloadx.com" }
  s.source       = { :git => "https://github.com/changexie/HelloAdxSDKPodsTest.git", :tag => s.version.to_s }
  s.requires_arc = true  
  s.platform     = :ios

  s.ios.deployment_target = '8.0'
  s.vendored_frameworks ='HelloAdxSDKPodsTest/HelloAdxSDK.framework'

  s.frameworks = ['AVFoundation', 'CoreLocation', 'CoreMedia', 'GLKit']
end
