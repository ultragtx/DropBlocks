Pod::Spec.new do |s|
  s.name         = 'DropBlocks'
  s.version      = '0.0.1
  s.platform     = :ios
  s.license      = { :type => 'BSD', file: 'LICENSE' }
  s.homepage     = 'http://github.com/natep/DropBlocks'
  s.summary      = 'A blocks-based wrapper for the Dropbox iOS SDK.'
  s.author       = { 'Nate Petersen' => 'nate@ihatenate.net' }
  s.source       = { :git => 'https://github.com/natep/DropBlocks.git', :tag => '0.0.1' }
  s.source_files = 'Classes'
  s.dependency     'Dropbox-iOS-SDK', '1.3.2'
end