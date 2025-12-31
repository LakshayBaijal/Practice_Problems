#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* VectortoLinkList(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}



void print(Node* x)
{
    while(x)
    {
        cout << x -> data << " ";
        x = x -> next;
    }
    cout << endl;
}

Node* deletehead(Node* x)
{
    if(x == NULL)
    {
        return x;
    }

    x = x->next;
    return x;
}

Node* deletelast(Node* x)
{
    if(x == NULL || x->next == NULL)
    {
        return NULL;
    }

    Node* temp = x;
    while(temp -> next -> next)
    {
        temp = temp -> next;
    }
    free(temp->next);
    temp->next = nullptr;
    return x;
}

int main()
{

    vector<int>arr = {1,6,3,7};
    Node* x = VectortoLinkList(arr);

    print(x);
    x = deletehead(x);

    print(x);
    
    x = deletelast(x);

    print(x);
    return 0;
}
