/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
If n is greater than the size of the list, remove the first node of the list.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    ListNode *curr, *tmp;
    curr = A;
    tmp = A;
    int size = 0;
    while(curr!= NULL){
        size++;
        curr = curr -> next;
    }
    if(B >= size){
        tmp = A;
        A = A->next;
        free(tmp);
        return A;
    }
    else{
        curr = A;
        for(int i = 0; i<size - B - 1; i++){
            curr = curr->next;
        }
        tmp = curr->next;
        curr->next = tmp->next;
        free(tmp);
        return A;
    }
}
