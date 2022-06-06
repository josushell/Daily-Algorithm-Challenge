class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA;
        ListNode *tempB;
        ListNode *result = NULL;
        
        tempA = headA;
        int countA = 0;
        while(tempA != NULL)
        {
            countA++;
            tempA = tempA->next;
        }
        
        tempB = headB;
        int countB = 0;
        while(tempB != NULL)
        {
            countB++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        while(countA > countB)
        {
            countA--;
            tempA = tempA->next;
        }
        
        tempB = headB;
        while(countB > countA)
        {
            countB--;
            tempB = tempB->next;
        }
        
        while(tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return tempA;
    }
};

