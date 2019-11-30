/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode *curr, *tmp;
    curr = A;
    //tmp = A->next;
    if(curr == NULL){
        return A;
    }
    while(curr->next != NULL){
        if(curr->next->val == curr->val){
            tmp = curr->next->next;
            curr->next = tmp;
        }
        else{
            curr = curr->next;
        }
    }
    return A;
    
}
