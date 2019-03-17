//Thomas Salemy

#ifndef HAZARD_H
#define HAZARD_H

#include "LinkedList.h"
#define MAX_DEPTH 5

typedef struct HazardNode {
    void* hp0;
    void* hp1;
    struct HazardNode* next;
} HazardNode_t;

HazardNode_t* constructHazardNode();

typedef struct HazardContainer {
    HazardNode_t* head;
    int H;
} HazardContainer_t;

HazardContainer_t* constructHazardContainer();

extern HazardContainer_t* memoryLedger;

void retireElement(LinkedList_t* retiredList, void* ptr);
void scan(LinkedList_t* retiredList);
void reclaimMemory(void* ptr);

#endif
