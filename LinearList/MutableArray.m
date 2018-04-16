//
//  MutableArray.m
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//

#import "MutableArray.h"
#import "LinearList.h"
#import <objc/message.h>
@interface MutableArray ()
@property(nonatomic, assign) LinerList *list;
@end
@implementation MutableArray
- (LinerList *)list {
    struct objc_super s;
    s.receiver = self;
    s.super_class = [Array class];
    return (__bridge LinerList *)(objc_msgSendSuper(&s, @selector(list)));
}
- (void)addObject:(id)anObject {
    
    listAdd(self.list, (__bridge LinerListNodeValue)(anObject));
}
- (void)insertObject:(id)anObject atIndex:(NSUInteger)index {
    listInsert(self.list, (int)index, (__bridge LinerListNodeValue)(anObject));
}

- (void)removeLastObject {
    listRemove(self.list, (int) self.count - 1);
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    listRemove(_list, (int)index);
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
    listSet(self.list, (int)index, (__bridge LinerListNodeValue)(anObject));
}

@end
