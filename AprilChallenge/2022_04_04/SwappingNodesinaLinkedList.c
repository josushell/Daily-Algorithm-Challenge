/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    int len = 0, index = 1;
    int val1, val2;
    struct ListNode *temp;
    
    temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    temp = head;
    while (index++ < k)
        temp = temp->next;
    val1 = temp->val;
    
    temp = head;
    index = 1;
    while (index++ < len - k + 1)
        temp = temp->next;
    val2 = temp->val;
    temp->val = val1;
    
    temp = head;
    index = 1;
    while (index++ < k)
        temp = temp->next;
    temp->val = val2;
    
    return head;
}
