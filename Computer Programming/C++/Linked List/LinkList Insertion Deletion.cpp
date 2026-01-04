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

Node * deleteK(Node* x, int k)
{
    if (x == NULL)
    {
        return x;
    }

    if (k == 1)
    {
        x = x -> next;
        return x;
    }

    int count = 0;
    Node* temp = x;
    Node* prev = NULL;

    while(temp!=NULL)
    {
        count++;
        if(count == k)
        {
            prev -> next = prev -> next -> next;
            break;
        }
        prev = temp;
        temp = temp ->next;
    }
    return x;
}

Node *inserthead(Node* x,int i)
{
    Node* temp = new Node(i,x);
    return temp;
}

Node *inserttail(Node* x,int i)
{
    if(x == NULL)
    {
        return new Node(i);
    }

    Node* temp = x;

    while(temp->next != NULL)
    {
        temp = temp->next;
    } 

    Node* add = new Node(i);
    temp -> next = add;

    return x;

}

Node* insertele(Node* x,int ele,int pos)
{
    if(x == NULL)
    {
        return new Node(ele);
    }
    if(pos == 1)
    {
        return new Node(ele,x);
    }

    int count = 0;
    Node* temp = x;

    while(temp!=NULL)
    {
        count++;
        temp = temp -> next;
        if(count == pos - 1)
        {
            Node* newnode = new Node(ele,temp->next);
            temp -> next = newnode;
            break;
        }
        
    }
    

    return x;
}

int main()
{

    vector<int>arr = {1,6,3,7,2,5,7,3};
    Node* x = VectortoLinkList(arr);

    print(x);
    x = deletehead(x);

    print(x);
    
    x = deletelast(x);

    print(x);
    x = deleteK(x,4);

    print(x);
    
    x = inserthead(x,10);

    print(x);

    x = inserttail(x,20);

    print(x);


    x = insertele(x,40,4);

    print(x);
    return 0;
}
