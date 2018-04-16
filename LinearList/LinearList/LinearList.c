//
//  LinearList.c
//  LinearList
//
//  Created by apple on 2018/4/13.
//  Copyright © 2018年 ALD. All rights reserved.
//
typedef void * LinerListNodeValue;
typedef struct{
    int length;
    int capacity;
    LinerListNodeValue *values;
}LinerList;
#define LinerList_STRUCT
#include "LinearList.h"
#include "stdlib.h"
int const defaultCapacity = 10;
LinerList * listCreate(int capacity) {
    if (capacity < 1) {
        capacity = defaultCapacity;
    }
    LinerList * list = malloc(sizeof(LinerList));
    if (list == NULL) {
        return NULL;
    }
    list->capacity = capacity;
    list->length = 0;
    list->values = malloc(sizeof(LinerListNodeValue) * capacity);
    if (list->values == NULL) {
        free(list);
        return NULL;
    }
    return list;
}

int listSize(LinerList *list) {
    if (list == NULL) {
        return 0;
    }
    return list->length;
}

void listClear(LinerList *list) {
    if (list == NULL) {
        return;
    }
    list->length = 0;
}

void listRelease(LinerList *list) {
    if (list == NULL) {
        return;
    }
    free(list->values);
    free(list);
}

int doubleCapacity(LinerList *list) {
    if (list == NULL) {
        return 1;
    }
    list->capacity = list->capacity * 2;
    LinerListNodeValue *newValues = malloc(sizeof(LinerListNodeValue) * list->capacity);
    if (newValues == NULL) {
        return 1;
    }
    for (int i = 0; i < list->length; i ++) {
        newValues[i] = list->values[i];
    }
    free(list->values);
    list->values = newValues;
    return 0;
}

void listInsert(LinerList *list,int index,LinerListNodeValue value) {
    if (list == NULL || index < 0 || index > list->length) {
        return;
    }
    
    // 扩容
    if (list->length == list->capacity){
        int result = doubleCapacity(list);
        if (result != 0) {
            return;
        }
    }
    
    for (int i = list->length; i > index; i --) {
        list->values[i] = list->values[i - 1];
    }
    list->values[index] = value;
    list->length ++;
}

void listSet(LinerList *list,int index,LinerListNodeValue value) {
    if (list == NULL || index < 0 || index >= list->length) {
        return;
    }
    list->values[index] = value;
}

void listAdd(LinerList *list,LinerListNodeValue value) {
    if (list == NULL) {
        return;
    }
    listInsert(list, list->length, value);
}

LinerListNodeValue listGetValue(LinerList *list,int index) {
    if (list == NULL || index < 0 || index >= list->length) {
        printf("index error\n");
        abort();
    }
    return list->values[index];
}

void listRemove(LinerList *list,int index) {
    if (list == NULL || index < 0 || index >= list->length) {
        return;
    }
    for (int i = index + 1; i < list->length; i ++) {
        list->values[i-1] = list->values[i];
    }
    list->length--;
}

void listRemoveValue(LinerList *list,LinerListNodeValue value) {
    if (list == NULL) {
        return;
    }
    int removeCount = 0;
    for (int i = 0; i < list->length; i ++) {
        if (list->values[i] == value) {
            removeCount ++;
        }else {
            list->values[i-removeCount] = list->values[i];
        }
    }
    list->length -= removeCount;
}

void listPrintValues(LinerList *list) {
    if (list == NULL) {
        return;
    }
    printf("%p = [",list);
    for (int i = 0; i < list->length; i ++) {
        if (i < list->length - 1) {
            printf("%p,",list->values[i]);
        }else {
            printf("%p",list->values[i]);
        }
    }
    printf("]\n");
}


