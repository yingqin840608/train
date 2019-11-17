#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*1->5->7, 2->6->9*/
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

void createList(ListNode **head, int *array, int num)
{
    int i = 0;
    ListNode *newNode, *p;
    if((array == NULL) || (num == 0)) {
        *head = NULL;
        return;
    }
    *head = (ListNode *)malloc(sizeof(ListNode));
    (*head)->val = array[0];
    p = *head;
    for(i = 1; i < num; i++) {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->val = array[i];
        p->next = newNode;
        p = p->next;
    }
    return;
}

void printList(ListNode *head) 
{
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    return;
}

int main()
{
    printf("hello, world");
    return 0;
}