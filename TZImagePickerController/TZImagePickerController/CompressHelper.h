//
//  CompressHelper.h
//  CompressTest
//
//  Created by IMAC on 2019/7/4.
//  Copyright © 2019 leslie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    VideoQualityTypeHigh,//>= 1280 * 720
    VideoQualityTypeStandard,//>= 640 * 480
    VideoQualityTypeLow//320 * 180
} VideoQualityType;

@interface CompressSetting : NSObject
@property (nonatomic, assign) VideoQualityType videoQuality;
/// 视频帧率 '<= 0不更改视频帧率'
@property (nonatomic, assign) CGFloat videoFrameRate;

@property (nonatomic, assign) float audioBitRate;
@property (nonatomic, assign) int audioSampleRate;

@property (nonatomic, strong) NSURL *inputURL;
@property (nonatomic, strong) NSURL *outputURL;

- (instancetype)initWithInputURL:(NSURL *)inputURL outputURL:(NSURL *)outputURL;

@end



@interface CompressHelper : NSObject
+ (void)compressVideoBySetting:(CompressSetting *)setting completionHandler:(void (^)(NSError * _Nullable error))handler;

@end

NS_ASSUME_NONNULL_END
