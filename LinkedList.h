#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "stdlib.h"

typedef struct ListNode {
    void* data;
    struct ListNode* next;
} ListNode_t;

ListNode_t* constructListNode(void* ptr) {
    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    node -> data = ptr;
    node -> next = NULL;
    return node;
}

void destructListNode(ListNode_t* node) {
    free(node -> data);
    free(node);
}

typedef struct LinkedList {
    ListNode* head;
    ListNode* tail;
    int size;
} LinkedList_t;

LinkedList_t* constructLinkedList(int size) {
    LinkedList_t* ll = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    ll -> head = ll -> tail = NULL;
    ll -> size = 0;
    return ll;
}

void push(LinkedList_t* ll, void* ptr) {
    if (ll -> head == NULL) {
        ll -> head = ll -> tail = constructNode(ptr);
    }
    else {
        ll -> tail -> next = constructNode(ptr);
        ll -> tail = ll -> tail -> next;
    }
    ll -> size++;
}

void* pop(LinkedList_t* ll) {
    if (ll -> head == NULL) {
        return NULL;
    }
    void* data = ll -> head -> data;
    if (ll -> head == ll -> tail) {
        free(ll -> head);
        ll -> head = ll -> tail = NULL;
    }
    else {
        ListNode_t* temp = ll -> head;
        ll -> head = ll -> head -> next;
        free(temp);
    }
    ll -> size--;
    return data;
}

int popAll(LinkedList_t* ll, void** output) {
    ListNode_t* runner = ll -> head;
    int count = 0;
    while (runner != NULL) {
        output[count] = runner -> data;
        count++;

        ListNode_t* temp = runner;
        runner = runner -> next;
        free(temp);
    }
    ll -> size = 0;
    return count;
}

#endif
