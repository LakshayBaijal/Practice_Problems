/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) 
    {
        // code here
        unordered_map<Node*,int>mp;
        Node* read = head;
        int cnt = 0;
        
        while(read != NULL)
        {
            if(mp.count(read))
            {
                return cnt - mp[read] ;
            }
            
            mp[read] = cnt;
            cnt ++;
            read = read -> next;
        }
        
        
        return 0;
    }
};
