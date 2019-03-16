//Thomas Salemy

#ifndef HAZARD_H
#define HAZARD_H

#include "LinkedList.h"
#define MAX_DEPTH 20

typedef struct HazardNode {
    void* hp0;
    void* hp1;
    LinkedList_t* retiredList;
    struct HazardNode* next;
} HazardNode_t;

typedef struct HazardContainer {
    HazardNode_t* head;
    int H;
} HazardContainer_t;

extern HazardContainer_t* memoryLedger;

void retireElement(HazardNode_t* hazardNode, void* ptr);
void scan(HazardNode_t* hazardNode);

#endif
