/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        unordered_set<ListNode*> mp;
        while(tempA != NULL)
        {
            mp.insert(tempA);
            tempA = tempA -> next;
        } 

        while(tempB != NULL)
        {
            if(mp.count(tempB))
            {
                return tempB;
            }
            tempB = tempB -> next;
        }

        return NULL;
    }
};
