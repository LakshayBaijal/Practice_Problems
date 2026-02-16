/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto list : lists)
        {
            ListNode* temp = list;
            while(temp != NULL)
            {
                int data = temp -> val;
                pq.push(data);
                temp = temp -> next;
            }
        }
        if (pq.empty()) return NULL;
        int first = pq.top();
        pq.pop();
        ListNode* head = new ListNode(first);
        ListNode* mover = head;
        while(!pq.empty())
        {
            int ele = pq.top();
            pq.pop();
            ListNode* temp = new ListNode(ele);
            mover -> next = temp;
            mover = temp;
        }

        return head;
    }
};
