/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* createTree(vector<int>& parent) 
    {
        // code here
        int n = parent.size();
        vector<Node*> node(n,nullptr);
        
        for(int i = 0;i<parent.size();i++)
        {
            node[i] = new Node(i);
        }
        
        Node* root = NULL;
        for(int i = 0; i<parent.size();i++)
        {
            if(parent[i] == -1)
            {
                root = node[i];
            }
            else
            {
                Node* p = node[parent[i]];
                if(p->left == NULL)
                {
                    p->left = node[i];
                }
                else
                {
                    p->right = node[i];
                }
            }
        }
        return root;
    }
};
