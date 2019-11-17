/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p;
    struct ListNode *pbefore;
    struct ListNode *remNode;
    int i = 0;
    p= head;
    while(p != NULL) {
        i++;
        p = p->next;
    }
    
    remNode = head + (i-n);
    if(remNode == head) {
        head = head->next;
        free(remNode);
        return head;
    }
    
    p = head;
    pbefore = p;
    while((p != remNode) && (p != NULL)) {
        pbefore = p;
        p = p->next;
    }
    pbefore->next = p->next;
    free(remNode);
    return head;
}


struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode *next;
    if( (head == NULL) || (head->next == NULL))
    {
        return head;
    }
    next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
}


void print(int* nums, int numsSize) 
{
    int i = 0;
    for(i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() 
{
    struct ListNode *testHead;
    struct ListNode *newHead;
    int array[]={1,2,3,4};
    testHead = createList(array, 4);
    //print(array, 5);
    //printList(head);
    newHead = swapPairs(testHead);

    //free(testHead);

    return 0;
}