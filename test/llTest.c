#include "LinkedList.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char** argv) {
    //Constants
    int SIZE = 400;
    int RANGE = 100000;
    int ELEMENT_SIZE = 128;
    
    //Initialize
    LinkedList_t* ll = constructLinkedList();
    void** arr = (void**)malloc(SIZE * sizeof(void*));
    
    //Test Insert
    for (int i = 0; i < SIZE; i++) {
        void* element = malloc(ELEMENT_SIZE);
        arr[i] = element;
        push(ll, element);
    }
    
    if (ll -> size != SIZE) {
        fprintf(stderr, "Invalid size of %d, expected %d\n", ll -> size, SIZE);
        return -1;
    }

    //Test Find
    for (int i = 0; i < SIZE; i++) {
        if (!findElement(ll, arr[i])) {
            fprintf(stderr, "Could not find element\n");
            return -1;
        }
    }

    //Test Pop All
    void** elements = (void**)malloc(SIZE * sizeof(void*));
    if (popAll(ll, elements) != SIZE) { 
        fprintf(stderr, "Pop all did not return correct number of elements\n");
    }
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != elements[i]) {
            fprintf(stderr, "Pop all did not work\n");
            return -1;
        }
    } 
    if (ll -> size != 0) {
        fprintf(stderr, "After pop all, invalid size of %d, expected %d\n", ll -> size, 0);
        return -1;
    }
    
    //Test Pop
    for (int i = 0; i < SIZE; i++) {
        push(ll, arr[i]);
    } 
    if (ll -> size != SIZE) {
        fprintf(stderr, "After reinserting, Invalid size of %d, expected %d\n", ll -> size, SIZE);
        return -1;
    }
    for (int i = 0; i < SIZE; i++) {
        if (pop(ll) != arr[i]) {
            fprintf(stderr, "Pop did not work on iteration %d\n", i);
            return -1;
        } 
        if (ll -> size != SIZE - i - 1) {
            fprintf(stderr, "Invalid size of %d, expected %d\n", ll -> size, SIZE);
            return -1;
        }
    }
    
    //Test Destructor
    destructLinkedList(ll);
}
