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
    ListNode *detectCycle(ListNode *head) 
    {
        unordered_set<ListNode*>mp;
        ListNode* read = head;


        while(read != NULL)
        {
            
            if(mp.count(read))
            {
                return read;
            }
            
            mp.insert(read);
            read = read -> next;
        }

        return NULL;
    }
};
