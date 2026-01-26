/*
class NodeLL {
  public:
    int data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = NULL;
    }
};
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *linkedListToBinaryTree(NodeLL *head) 
    {
        // code here
        Node* root = new Node(head->data);
        
        head = head ->next;
        
        queue<Node*>q;
        q.push(root);
        
        while(head != NULL)
        {
            Node* parent = q.front();
            q.pop();
            
            Node* leftchild = new Node(head -> data);
            parent -> left = leftchild;
            q.push(leftchild);
            head = head -> next;
            
            if(head!=NULL)
            {
                Node* rightchild = new Node(head -> data);
                parent -> right = rightchild;
                q.push(rightchild);
                head = head -> next;
            }
            
        }
        
        return root;
    }
};
