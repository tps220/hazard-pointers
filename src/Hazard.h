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

void retireElement(HazardNode_t* hazardNode, void* ptr);
void scan(HazardContainer_t* container, HazardNode_t* hazardNode);

#endif
