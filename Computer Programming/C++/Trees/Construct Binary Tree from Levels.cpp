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
        queue<Node*> q;
        Node* root = new Node(parent[0]);
        int i = 1;
        q.push(root);
        
        while(!q.empty() && i < parent.size())
        {
            Node* temp = q.front();
            q.pop();
            
            if(i<v.size() && parent[i] != -1)
            {
                temp -> left = new Node(parent[i]);
                q.push(root -> left);
            }
            i++;
            
            if(i<v.size() && parent[i] != -1)
            {
                temp -> right = new Node(parent[i]);
                q.push(root -> right);
            }
            
            i++;
        }
        
        return root;
    }
};
