//
//  main.m
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MutableArray.h"
#import "Array.h"
#import "Person.h"
void testRemove(void);
void testArray(void);
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        testRemove();
//        testArray();
        Person *p1 = Person.new;
        p1.name = @"p1";
        Person *p2 = Person.new;
        p2.name = @"p2";
        MutableArray *array = [[MutableArray alloc] init];
        [array addObject:p2];
        NSLog(@"%@",array);
    }
    return 0;
}

void testRemove(){
    NSString *str1 = @"789";
    NSString *str2 = @"123";
    NSString *str3 = @"123";
    NSString *str4 = @"123";
    NSString *str5 = @"456";
    NSString *str6 = @"456";
    NSMutableArray *arr = [@[str1,str2,str3,str4,str5,str6] mutableCopy];
    NSLog(@"%@",arr);
    [arr removeObject:str2];
    NSLog(@"%@",arr);
}

void testArray(){
    Array *arr1 = [[Array alloc] initWithObjects:@"123456",@"132434", nil];
    NSLog(@"%@",arr1);
    MutableArray *arr2 = [[MutableArray alloc] initWithObjects:@"你好",@"师姐", nil];
    [arr2 addObject:@"。"];
    [arr2 insertObject:@"xxxc" atIndex:1];
    [arr2 removeLastObject];
    NSLog(@"%@",arr2);
}
