//
//  DropBlocks.h
//
//  Created by Nate Petersen on 10/8/12.
//  Copyright (c) 2012 Nate Petersen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Dropbox-iOS-SDK/DropboxSDK.h>
#import <Dropbox-iOS-SDK/DBDeltaEntry.h>

typedef void (^LoadMetadataCallback)(DBMetadata *metadata, NSError *error);
typedef void (^LoadDeltaCallback)(NSArray *entries, BOOL shouldReset, NSString *cursor, BOOL hasMore, NSError *error);
typedef void (^LoadStreamableURLCallback)(NSURL *url, NSError *error);
typedef void (^LoadFileCallback)(NSString *contentType, DBMetadata *metadata, NSError *error);
typedef void (^LoadFileProgressCallback)(CGFloat progress);
typedef void (^LoadThumbnailCallback)(DBMetadata *metadata, NSError *error);
typedef void (^UploadFileCallback)(NSString*, DBMetadata *metadata, NSError *error);
typedef void (^UploadFileProgressCallback)(CGFloat progress);
typedef void (^UploadFileChunkCallback)(NSString *uploadId, unsigned long long offset, NSDate *expiresDate, NSError *error);
typedef void (^LoadRevisionsCallback)(NSArray *revisions, NSError *error);
typedef void (^RestoreFileCallback)(DBMetadata *metadata, NSError *error);
typedef void (^CreateFolderCallback)(DBMetadata *metadata, NSError *error);
typedef void (^DeletePathCallback)(NSError *error);
typedef void (^CopyPathCallback)(DBMetadata *metadata, NSError *error);
typedef void (^CreateCopyRefCallback)(NSString *copyRef, NSError *error);
typedef void (^CopyFromRefCallback)(DBMetadata *metadata, NSError *error);
typedef void (^MovePathCallback)(DBMetadata *metadata, NSError *error);
typedef void (^LoadAccountInfoCallback)(DBAccountInfo *metadata, NSError *error);
typedef void (^SearchPathCallback)(NSArray *results, NSError *error);
typedef void (^LoadSharableLinkCallback)(NSString *link, NSError *error);


@interface DropBlocks : NSObject

+ (void)cancelAllRequests;

+ (DropBlocks *)loadMetadata:(NSString*)path completionBlock:(LoadMetadataCallback)completionBlock;
+ (DropBlocks *)loadMetadata:(NSString*)path withHash:(NSString*)hash completionBlock:(LoadMetadataCallback)completionBlock;
+ (DropBlocks *)loadMetadata:(NSString*)path atRev:(NSString *)rev completionBlock:(LoadMetadataCallback)completionBlock;

+ (DropBlocks *)loadDelta:(NSString *)cursor completionBlock:(LoadDeltaCallback)completionBlock;

+ (DropBlocks *)loadFile:(NSString *)path intoPath:(NSString *)destinationPath completionBlock:(LoadFileCallback)completionBlock progressBlock:(LoadFileProgressCallback)progressBlock;
+ (DropBlocks *)loadFile:(NSString *)path atRev:(NSString *)rev intoPath:(NSString *)destinationPath completionBlock:(LoadFileCallback)completionBlock progressBlock:(LoadFileProgressCallback)progressBlock;

+ (DropBlocks *)loadThumbnail:(NSString *)path ofSize:(NSString *)size intoPath:(NSString *)destinationPath completionBlock:(LoadThumbnailCallback)completionBlock;

+ (DropBlocks *)uploadFile:(NSString *)filename toPath:(NSString *)path withParentRev:(NSString *)parentRev fromPath:(NSString *)sourcePath completionBlock:(UploadFileCallback)completionBlock progressBlock:(UploadFileProgressCallback)progressBlock;

+ (DropBlocks *)uploadFileChunk:(NSString *)uploadId offset:(unsigned long long)offset fromPath:(NSString *)localPath completionBlock:(UploadFileChunkCallback)completionBlock;

+ (DropBlocks *)uploadFile:(NSString *)filename toPath:(NSString *)parentFolder withParentRev:(NSString *)parentRev fromUploadId:(NSString *)uploadId completionBlock:(UploadFileCallback)completionBlock;

+ (DropBlocks *)loadRevisionsForFile:(NSString *)path completionBlock:(LoadRevisionsCallback)completionBlock;

+ (DropBlocks *)loadRevisionsForFile:(NSString *)path limit:(NSInteger)limit completionBlock:(LoadRevisionsCallback)completionBlock;

+ (DropBlocks *)restoreFile:(NSString *)path toRev:(NSString *)rev completionBlock:(RestoreFileCallback)completionBlock;

+ (DropBlocks *)createFolder:(NSString*)path completionBlock:(CreateFolderCallback)completionBlock;

+ (DropBlocks *)deletePath:(NSString*)path completionBlock:(DeletePathCallback)completionBlock;

+ (DropBlocks *)copyFrom:(NSString*)fromPath toPath:(NSString *)toPath completionBlock:(CopyPathCallback)completionBlock;

+ (DropBlocks *)createCopyRef:(NSString *)path completionBlock:(CreateCopyRefCallback)completionBlock;

+ (DropBlocks *)copyFromRef:(NSString*)copyRef toPath:(NSString *)toPath completionBlock:(CopyFromRefCallback)completionBlock;

+ (DropBlocks *)moveFrom:(NSString*)fromPath toPath:(NSString *)toPath completionBlock:(MovePathCallback)completionBlock;

+ (DropBlocks *)loadAccountInfo:(LoadAccountInfoCallback)completionBlock;

+ (DropBlocks *)searchPath:(NSString*)path forKeyword:(NSString*)keyword completionBlock:(SearchPathCallback)completionBlock;

+ (DropBlocks *)loadSharableLinkForFile:(NSString *)path shortUrl:(BOOL)createShortUrl completionBlock:(LoadSharableLinkCallback)completionBlock;

+ (DropBlocks *)loadStreamableURLForFile:(NSString *)path completionBlock:(LoadStreamableURLCallback)completionBlock;

- (void)cancel;

@end
