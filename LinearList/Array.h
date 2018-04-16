//
//  Array.h
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface Array <__covariant T> : NSObject
@property (readonly) NSUInteger count;
- (T)objectAtIndex:(int)index;
- (instancetype)initWithObjects:(T)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
@end
