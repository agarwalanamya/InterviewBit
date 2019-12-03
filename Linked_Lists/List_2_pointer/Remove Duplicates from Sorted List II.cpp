/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    //int size = 0;
    if(A == NULL || A->next == NULL){
        return A;
    }
    ListNode *curr, *prev;
    struct ListNode* tmp = new struct ListNode(0);
    tmp->next = A;
    prev = tmp;
    curr = A;
    while(curr != NULL){
        while(curr->next != NULL && curr->next->val == prev->next->val){
            curr = curr->next;
        }
        if(prev->next == curr){
            prev = prev->next;
        }
        else{
            prev->next = curr->next;
        }
        curr = curr->next;
    }
    return tmp->next;
}
