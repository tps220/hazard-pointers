//Thomas Salemy

#ifndef HAZARD_C
#define HAZARD_C
#include "Hazard.h"

void retireElement(HazardNode_t* hazardNode, void* ptr) {
    push(hazardNode -> retiredList, ptr);
    if (hazardNode -> retiredList -> size == MAX_DEPTH) {
        scan(hazardNode);
    }
}

void scan(HazardNode_t* hazardNode) {
    //Collect all valid hazard pointers across application threads
    LinkedList_t* ptrList = constructLinkedList();
    HazardNode_t* runner = memoryLedger -> head;
    while (runner != NULL) {
        if (runner -> hp0 != NULL) {
            push(ptrList, runner -> hp0);
        }
        if (runner -> hp1 != NULL) {
            push(ptrList, runner -> hp1);
        }
        runner = runner -> next;
    }
    
    //Compare retired candidates against active hazard nodes, reclaiming or procastinating
    int listSize = hazardNode -> retiredList -> size;
    void** tmpList = (void**)malloc(listSize * sizeof(void*));
    popAll(hazardNode -> retiredList, tmpList);
    for (int i = 0; i < listSize; i++) {
        if (findElement(ptrList, tmpList[i])) {
            push(hazardNode -> retiredList);
        }
        else {
            free(tmpList[i]);
        }
    }
    free(tmpList);
}


#endif
