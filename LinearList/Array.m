//
//  Array.m
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//

#import "Array.h"
#import "LinearList.h"
@interface Array ()
@property(nonatomic, assign) LinerList *list;
@end
@implementation Array
- (instancetype)init {
    if (self = [super init]) {
        _list = listCreate(0);
    }
    return self;
}
- (instancetype)initWithObjects:(id)firstObj, ...{
    if (self = [super init]) {
        id eachObject;
        va_list argumentList;
        if (firstObj)
        {
            listAdd(_list, (__bridge LinerListNodeValue)(firstObj));
            va_start(argumentList, firstObj);
            while ((eachObject = va_arg(argumentList, id))) {
                listAdd(_list, (__bridge LinerListNodeValue)(eachObject));
            }
            va_end(argumentList);
        }
    }
    return self;
}

- (id)objectAtIndex:(int)index {
    return (__bridge id)listGetValue(_list, index);
}

- (NSUInteger)count {
    return listSize(_list);
}

- (LinerList *)list {
    return _list;
}
- (void)dealloc {
    listRelease(_list);
}

- (NSString *)description {
    NSMutableString *descriptionStr = [NSMutableString string];
    [descriptionStr appendFormat:@"%p = [",self];
    for (int i = 0; i < listSize(_list); i ++) {
        if (i != listSize(_list) - 1) {
            [descriptionStr appendFormat:@"%@,",[self objectAtIndex:i]];
        }else {
            [descriptionStr appendFormat:@"%@",[self objectAtIndex:i]];
        }
    }
    [descriptionStr appendString:@"]"];
    return [descriptionStr copy];
}
@end
