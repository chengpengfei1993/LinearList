//
//  MutableArray.h
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//

#import "Array.h"

@interface MutableArray<__covariant T> : Array
- (void)addObject:(T)anObject;
- (void)insertObject:(T)anObject atIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(T)anObject;
@end
