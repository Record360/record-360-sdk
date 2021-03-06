//
// Copyright © 2016 Record360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "Record360Constants.h"

@protocol Record360Delegate <NSObject>

- (void)onTransactionUploadedForReferenceNumber:(nonnull NSString *)referenceNumber;
- (void)onTransactionUploadFailedForReferenceNumber:(nonnull NSString *)referenceNumber withError:(nonnull NSError *)error;
- (void)onTransactionUploadDeletedForReferenceNumber:(nonnull NSString *)referenceNumber;

@optional
- (void)onUploadBytesComplete:(long long)bytesComplete ofTotal:(long long)bytesTotal forReferenceNumber:(nonnull NSString *)referenceNumber;

@end

@interface Record360 : NSObject

@property (nonatomic, assign) UploadMode uploadMode;

+ (void)setBaseAPIUrl:(nonnull NSString *)baseApiUrl;
- (nonnull Record360 *)initWithDelegate:(nullable id <Record360Delegate>)delegate;
- (NSUInteger)getTransactionsReadyForUploadCount;
- (void)startUploading;
- (void)stopUploading;
- (void)showProgressDialogOnViewController:(nonnull UIViewController *)rootViewController onControllerClose:(nullable void (^)(void))onClose;

@end
