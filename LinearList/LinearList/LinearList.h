//
//  LinearList.h
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//

#ifndef LinearList_h
#define LinearList_h
#include <stdio.h>

#ifndef LinerList_STRUCT
typedef void* LinerListNodeValue;
typedef void LinerList;
#endif

LinerList * listCreate(int capacity);
int listSize(LinerList *list);

void listClear(LinerList *list);

void listRelease(LinerList *list);

void listInsert(LinerList *list,int index,LinerListNodeValue value);

void listSet(LinerList *list,int index,LinerListNodeValue value);

void listAdd(LinerList *list,LinerListNodeValue value);

void listRemove(LinerList *list,int index);

void listRemoveValue(LinerList *list,LinerListNodeValue value);

LinerListNodeValue listGetValue(LinerList *list,int index);

void listPrintValues(LinerList *list);
#endif /* LinearList_h */
