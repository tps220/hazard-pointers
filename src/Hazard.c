//Thomas Salemy

#ifndef HAZARD_C
#define HAZARD_C

void scan(HazardContainer_t* container, HazardNode_t* hazardNode) {
    LinkedList_t* ptrList = constructLinkedList();
    HazardNode_t* runner = container -> head;
    while (runner != NULL) {
        if (runner -> hp0 != NULL) {
            push(ptrList, runner -> hp0);
        }
        if (runner -> hp1 != NULL) {
            push(ptrList, runner -> hp1);
        }
        runner = runner -> next;
    }
    void** tmpList = (void**)malloc((hazardNode -> retiredList -> size + 1) * sizeof(void*));
    int length = popAll(hazardNode -> retiredList, tmpList);
    for (int i = 0; i < length; i++) {
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
